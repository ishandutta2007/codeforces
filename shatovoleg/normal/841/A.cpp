#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	map<char, int> mp;
	for (auto x : s)
	{
		if (!mp.count(x))
			mp[x] = 0;
		++mp[x];
	}
	for (auto x : mp)
		if (x.second > k)
		{
			cout << "NO" << endl;
			return 0;
		}
	cout << "YES" << endl;
}