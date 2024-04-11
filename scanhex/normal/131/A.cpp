#include <iostream>
#include <stdio.h>
#include <string>
#define ll long long

using namespace std;

int main()
{
	string s;
	cin >> s;
	int n = s.length();
	bool flag = true;
	for (int i = 1; i < n; ++i)
	{
		if (!('A' <= s[i] && s[i] <= 'Z'))
			flag = false;
	}
	if (!flag)
		cout << s;
	else
	{
		for (int i = 0; i < n; ++i) 
		{
			if ('A' <= s[i] && s[i] <= 'Z') 
				cout << (char)(s[i] + 32);
		 	else
		 		cout << (char)(s[i] - 32);
		}
	}    
}