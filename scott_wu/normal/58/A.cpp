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
	
	string h = "hello";
	
	int cur = 0;
	for (int i = 0; i < h.length(); i++)
	{
		bool check = true;
		for (int j = cur; j < str.length(); j++)
		{
			if (str[j] == h[i])
			{
				cur = j + 1;
				check = false;
				break;
			}
		}
		if (check)
		{
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}