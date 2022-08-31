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
	int csum = 1;
	
	for (int i = 1; i < str.length(); i++)
	{
		if (str[i] == str[i-1])
			csum++;
		else
			csum = 1;
		if (csum >= 7)
		{
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}