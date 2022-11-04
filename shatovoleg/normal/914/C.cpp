#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define len(v) ((int)v.size())
#define pb push_back

int count_steps(int a)
{
	int cnt = 0;
	for (; a > 1; a = __builtin_popcount(a), ++cnt);
	return cnt;
}

int conv_to_int_base_2(string t)
{
	int cur = 0;
	for (auto x : t)
	{
		cur <<= 1;
		cur += x - '0';
	}
	return cur;
}

string s;
const int p = 1000000007;
const int c = 1500;

int main()
{
	cin >> s;
	int k;
	cin >> k;
	if (k == 0)
	{
		cout << 1 << endl;
		return 0;
	}
	if (len(s) <= 5)
	{
		int cnt = 0;
		int asdf = conv_to_int_base_2(s);
		for (int i = 1; i <= asdf; ++i)
			if (count_steps(i) == k)
				++cnt;
		cout << cnt << endl;
		return 0;
	}
	vector<vector<vector<int>>> dp(len(s), vector<vector<int>>(c, vector<int>(2, 0)));
	dp[0][0][0] = 1;
	dp[0][1][1] = 1;
	for (int i = 0; i < len(s) - 1; ++i)
		for (int j = 0; j < c; ++j)
		{
			if (j == c - 1)
			{
				dp[i + 1][j][0] += dp[i][j][0];
				dp[i + 1][j][0] %= p;
				if ('0' < s[i + 1])
				{
					dp[i + 1][j][0] += dp[i][j][1];
					dp[i + 1][j][0] %= p;
				}
				else
				{
					dp[i + 1][j][1] += dp[i][j][1];
					dp[i + 1][j][1] %= p;
				}
			}
			else
			{
				dp[i + 1][j][0] += dp[i][j][0];
				dp[i + 1][j][0] %= p;
				dp[i + 1][j + 1][0] += dp[i][j][0];
				dp[i + 1][j + 1][0] %= p;
				if ('0' < s[i + 1])
				{
					dp[i + 1][j][0] += dp[i][j][1];
					dp[i + 1][j][0] %= p;
					dp[i + 1][j + 1][1] += dp[i][j][1];
					dp[i + 1][j + 1][1] %= p;
				}
				else
				{
					dp[i + 1][j][1] += dp[i][j][1];
					dp[i + 1][j][1] %= p;
				}
			}
		}
	int cnt = 0;
	for (int i = 1; i < c; ++i)
		if (count_steps(i) == k - 1)
		{
			// cout << i << " " << dp[len(s) - 1][i][0] << " " << dp[len(s) - 1][i][1] << endl;
			cnt += dp[len(s) - 1][i][0] + dp[len(s) - 1][i][1];
			cnt %= p;
		}
	if (k == 1)
		--cnt;
	cout << cnt << endl;
}