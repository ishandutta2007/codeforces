#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	bool test = false;
	int n, s, m, k;
	if (test)
		n = s = m = k = 3000;
	else
		cin >> n >> s >> m >> k;
	vector<int> a(n);
	for (auto& x : a)
		if (test)
			x = 1;
		else
			cin >> x;
	vector<pair<int, int>> segs(s);
	for (auto& x : segs)
		if (test)
			x.first = x.second = 1, --x.first;
		else
			cin >> x.first >> x.second, --x.first;
	sort(segs.begin(), segs.end(), [&](pair<int, int> a, pair<int, int> b)
			{
				return a.second < b.second;
			});
	int L = 0, R = 1e9 + 5;
	while (R - L > 1)
	{
		int M = (L + R) / 2;
		vector<int> pref(n + 1);
		for (int i = 0; i < n; ++i)
			pref[i + 1] = pref[i] + int(a[i] <= M);
		auto solve = [&](int lambda)
		{
			vector<pair<int, int>> dp(n + 1);
			dp[0] = {0, 0};
			int ptr = 0;
			for (int i = 0; i < n; ++i)
			{
				while (ptr < s && segs[ptr].second < i)
					++ptr;
				for (int j = ptr; j < s; ++j)
				{
					int x, y;
					tie(x, y) = segs[j];
					int ans1 = dp[i].first - lambda;
					ans1 += pref[y] - pref[max(x, i)];
					dp[y] = max(dp[y], {ans1, dp[i].second + 1});
				}
			}
			return *max_element(dp.begin(), dp.end());
		};
		int lL = 0, lR = 2047;
		while (lR - lL > 1)
		{
			 int lM = (lL + lR) / 2;
			 auto mem = solve(lM);
			 if (mem.second >= m)
			 {
				 lL = lM;
				 if (mem.second == m)
					 break;
			 }
			 else
				 lR = lM;
		}
		auto p = solve(lL);
		int ans = p.first + lL * m;
		if (ans >= k)
			R = M;
		else
			L = M;
	}
	if (R > 1e9)
		R = -1;
	cout << R << '\n';
	return 0;
}