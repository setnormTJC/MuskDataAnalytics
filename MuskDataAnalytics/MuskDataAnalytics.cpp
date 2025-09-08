// MuskDataAnalytics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include<fstream> 
#include <iostream>
#include<sstream>
#include<string> 
#include <vector>

struct TweetRecord
{
	int tweetNumber;
	std::string date; 
	std::string tweet;
	std::string photoLink; 
	std::string videoLink;
	int nLikes; 
};

std::vector<std::string> splitRecord_withStringStream(const std::string& record, char delimiter)
{
	std::vector<std::string> fields;
	std::stringstream ss(record);
	std::string field;

	while (std::getline(ss, field, delimiter))
	{
		fields.push_back(field);
	}

	return fields;
}

int getAverageLikesOnTweet(const std::vector<TweetRecord>& records)
{
	double averageLikes{}; //similar to = 0.0

	double sum = 0.0; 
	for (const auto& currentRecord : records)
	{
		sum += currentRecord.nLikes;
	}

	averageLikes = sum / records.size(); 
	return (int)averageLikes; 

}

int main()
{
	//let's use an "absolute filepath" to read the input file 
	std::ifstream inputFile("C://Users//Work//Downloads//MuskTweets2018.csv");

	if (!inputFile)
	{
		std::cout << "FNFE\n";
		return -1; 
	}
	
	std::string currentLine; 

	std::vector<TweetRecord> records; 

	//auto splitTokens = splitRecord_withStringStream("FirstName MiddleName LastName", ' ');

	while (std::getline(inputFile, currentLine))
	{

		std::cout << currentLine << "\n\n\n";

		auto splitRecord = splitRecord_withStringStream(currentLine, ',');
		
		if (splitRecord.size() != 6)
		{
			std::cout << "The number of fields is NOT as expected (6)\n";
			__debugbreak(); 
		}


		TweetRecord currentRecord =
		{
			std::stoi(splitRecord[0]),
			splitRecord[1],
			splitRecord[2],
			splitRecord[3],
			splitRecord[4],
			std::stoi(splitRecord[5]) //beware of "invalid stoi argument errors" here 
			//std::stoi(splitRec)
		};

		records.push_back(currentRecord);
	}

	std::cout << "Average like counts is: " << getAverageLikesOnTweet(records) << "\n";

	//do data processing below: 
}

