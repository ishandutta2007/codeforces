#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

//#define int long long

char s[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };

signed main()
{
	int m;
	cin >> m;
	string str;
	cin >> str;
	bool flag = false;
	for (int i = 0; i < 26; i++)
	{
		int n = 0;
		for (int j = 0; j < m; j++)
		{
			if (str[j] == s[i])
			{
				n++;
			}
			if (n == 2)
			{
				flag = true;
				break;
			}
		}
		if (flag)
		{
			break;
		}
	}
	if (m == 1)
	{
		flag = true;
	}
		if (flag)
		{
			cout << "Yes\n";
		}
		else
		{
			cout << "No\n";
		}
	return 0;
}