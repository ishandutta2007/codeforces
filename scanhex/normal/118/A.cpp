#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#define ll long long

using namespace std;
int main() 
{               
	string s;
	getline(cin, s);	int n = s.length();
	stringstream ss;
	for (int i = 0; i < n; ++i) 
	{
		if (s[i] == 'A' || s[i] == 'a' || s[i] == 'O' || s[i] == 'o' || s[i] == 'U' || s[i] == 'u' || s[i] == 'I' || s[i] == 'i' || s[i] == 'E' || s[i] == 'e' || s[i] == 'Y' || s[i] == 'y')
			continue;
		ss << '.';
		if ('A' <= s[i] && s[i] <= 'Z')
			ss << (char)(s[i] + 32);
		else
			ss << s[i]; 	
	} 
	cout << ss.str();  
}