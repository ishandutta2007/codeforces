#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
using ll = long long;

const int MX = 10001;
const int N = 101;
int dp[MX][N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	map<int, int> cnt;
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		++cnt[x];
	}
	if (cnt.size() == 2)
	{
		cout << n << '\n';
		return 0;
	}
	dp[0][0] = 1;
	for (auto& p : cnt)
	{
		for (int i = MX - 1; i >= 0; --i)
			for (int j = 0; j < N; ++j)
			{
				if (!dp[i][j])
					continue;
				for (int k = 1; k <= p.second; ++k)
				{
					dp[i + k * p.first][j + k] += dp[i][j];
					if (dp[i + k * p.first][j + k] > 1)
						dp[i + k * p.first][j + k] = 2;
				}
			}
	}
	for (auto& p : cnt)
	{
		for (int i = 0; i <= p.second; ++i)
		{
			if (dp[i * p.first][i] == 1)
				ans = max(ans, i);
		}
	}
	cout << ans << '\n';
	return 0;
}