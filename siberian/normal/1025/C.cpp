#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

signed main()
{	
	string str;
	cin >> str;
	str = str + str;
	int ans = 0, t = 0;
	for (int i = 1; i < str.size() - 1; i++)
	{
		if (str[i] == str[i + 1])
		{
			ans = max(t, ans);
			t = 0;
		}
		else
		{
			t++;
		}
	}
	ans = max(t, ans);
	cout << min(ans + 1, (int)(str.size()) / 2);
	return 0;
}