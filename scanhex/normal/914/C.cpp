#include <bits/stdc++.h>

using namespace std;
typedef long long nagai;

nagai mod = 1e9 + 7;

int MX = 1000;

int cnt(int x)
{
	int ans = 0;
	for (int i = 0; i < 15; ++i)
		if (x >> i & 1)
			++ans;
	return ans;
}

int main()
{
	string s;
	cin >> s;
	int k;
	cin >> k;
	if (k == 0)
	{
		cout << 1 << endl;
		return 0;
	}
	--k;
	vector<int> dp1(MX);
	dp1[1] = 0;
	for (int i = 2; i < MX; ++i)
		dp1[i] = dp1[cnt(i)] + 1;
	int n = s.size();
	vector<vector<nagai>> dp(n + 1, vector<nagai>(n + 1)), dp2 = dp;
	vector<int> good;
	for (int i = 1; i < MX; ++i)
		if (dp1[i] == k)
			good.push_back(i);
	dp[0][0] = 1;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j <= n; ++j)
		{
			dp[i][j] %= mod;
			dp2[i][j] %= mod;
			if (dp[i][j] == 0 && dp2[i][j] == 0)
				continue;
			if (s[i] == '1')
			{
				dp2[i + 1][j] += dp[i][j];
				dp[i + 1][j + 1] += dp[i][j];
				dp2[i + 1][j] += dp2[i][j];
				dp2[i + 1][j + 1] += dp2[i][j];
			}
			else
			{
				dp[i + 1][j] += dp[i][j];
				dp2[i + 1][j] += dp2[i][j];
				dp2[i + 1][j + 1] += dp2[i][j];
			}
		}
	nagai ans = 0;
	for (int x : good)
		if (x <= n)
			ans += dp2[n][x];
	if (dp1[count(s.begin(), s.end(), '1')] == k)
		++ans;
	if (k == 0)
		ans += mod - 1;
	cout << ans % mod << endl;
}