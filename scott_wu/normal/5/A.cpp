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
	int count = 0, ans = 0;
	while (getline (cin, str))
	{
		if (str[0] == '+')
			count++;
		else if (str[0] == '-')
			count--;
		else
		{
			for (int i = 0; i < str.length(); i++)
			{
				if (str[i] == ':')
				{
					ans += count * (str.length() - i - 1);
				}
			}
		}
	}
	cout << ans << "\n";
}