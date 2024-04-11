#include <bits/stdc++.h>

using namespace std;
using nagai = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<string> ss(n);
	for (auto& x : ss)
		cin >> x;
	vector<pair<int, int>> v;
	map<int, int> mp1, mp2;
	int c0 = 0;
	for (auto& x : ss)
	{
		int bal = 0;
		int mn = 0;
		for (char ch : x)
		{
			if (ch == '(')
				++bal;
			else
				--bal;
			mn = min(mn, bal);
		}
		if (bal == 0 && mn >= 0)
			c0++;
		else if (bal > 0 && mn >= 0)
			mp1[bal]++;
		else if (bal < 0 && mn - bal >= 0)
			mp2[-bal]++;
	}
	int ans = c0 / 2;
	for (auto& [x, y] : mp2)
	{
		ans += min(mp1[x], mp2[x]);
	}
	cout << ans << '\n';

	return 0;
}