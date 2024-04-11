#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

string vow = "aeiouy";

int main()
{
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] - 'A' + 'a';
		}
		
		bool check = true;
		for (int j = 0; j < 6; j++)
			if (str[i] == vow[j]) check = false;
		if (check) cout << "." << str[i];
	}
	cout << "\n";
}