#include <iostream>
#include <stdio.h>
#include <string>
#define ll long long

using namespace std;

int main()
{                                    
	int n;
	cin >> n;
	int x = 0;
	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		if (s[0] == '+' || s[2] == '+')
			++x;
		else
			--x;
	}    
	cout << x;
}