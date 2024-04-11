#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int INF = 1000000009;

int main()
{
	int n, m, b, mod;
	cin >> n >> m >> b >> mod;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	vector<vector<vector<int>>> dp(2, vector<vector<int>>(n + 1, vector<int>(b + 1, 0)));
	dp[0][0][0] = 1;
	for (int i = 0; i <= m; ++i)
	{
		for (int j = 0; j < n; ++j)
			for (int k = 0; k <= b; ++k)
			{
				if (i < m && k + a[j] <= b)
				{
					dp[(i + 1) & 1][j][k + a[j]] += dp[i & 1][j][k];
					dp[(i + 1) & 1][j][k + a[j]] %= mod;
				}
				if (j != n)
				{
					dp[i & 1][j + 1][k] += dp[i & 1][j][k];
					dp[i & 1][j + 1][k] %= mod;
				}
			}
		if (i != m)
		dp[i & 1] = vector<vector<int>>(n + 1, vector<int>(b + 1, 0));
	}
	int ans = 0;
	for (int i = 0; i <= b; ++i)
		ans += dp[m & 1][n][i], ans %= mod;
	cout << ans << endl;
#ifdef _DEBUG
			system("pause");
#endif
			return 0;	
}