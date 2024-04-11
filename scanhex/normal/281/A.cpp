#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#define ll long long

using namespace std;
int main() 
{
	string s;
	getline(cin, s);
	if ('a' <= s[0] && s[0] <= 'z')
		s[0] -= 32;
	cout << s;     
}