#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

int main()
{
	string str;
	cin >> str;
	
	bool seen[210];
	for (int i = 0; i < 210; i++)
		seen[i] = false;
	
	for (int i = 0; i < (int) str.length() - 2; i++)
	{
		if (str[i] == 'W' && str[i+1] == 'U' && str[i+2] == 'B')
			seen[i] = true;
	}
	int last = -3;
	bool check = true;
	for (int i = 0; i < (int) str.length() - 2; i++)
	{
		if (seen[i])
		{
			if (last + 3 < i)
			{
				if (!check)
					cout << " ";
				for (int j = last + 3; j < i; j++)
					cout << str[j];
				check = false;
			}
			last = i;
		}
	}
	cout << " ";
	for (int i = last + 3; i < str.length(); i++)
		cout << str[i];
	cout << "\n";
}