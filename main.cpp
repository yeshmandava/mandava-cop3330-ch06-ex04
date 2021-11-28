#include <iostream>
#include "std_lib_facilities.h"

/**
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Yeshwanth Mandava
 */

class Name_Value
{
public:
    string Name;
    int value;
};

int checkName(string name, vector<Name_Value>list);

int main()
{
    vector<Name_Value> list;
    string Name;
    int value;

    cout << "Enter a set of name-and-value pairs (Jackson 22).\nTo exit the input enter 'NoName 0'\nEnter the name followed by a space and the number:\n";

    while ((cin >> Name >> value) && (Name != "NoName" && value != 0))
    {
        if(checkName(Name, list) == 1)
        {
            cout << "Error: The name '" << Name << "' is entered twice\n";
            return -1;
        }
        else{
            list.push_back(Name_Value{Name, value});
        }
    }
    cout << "Inputted Name-Value Pairs: \n";
    for(int i = 0;i<list.size();i++)
    {
        cout << "(" << list[i].Name << "," << list[i].value << ")" << "\n";
    }
    return 0;
}

int checkName(string name,vector<Name_Value>list)
{
    for(Name_Value input : list)
    {
        if(input.Name == name)
        {
            return 1;
        }
        else
            return 0;
    }
}