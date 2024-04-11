#include <iostream>
using namespace std;

int dp[11][1011];

int a[11], b[11], c[11], d[11];

int main()
{
	int n, m, c0, d0;
	cin >> n >> m >> c0 >> d0;
	for(int i = 1; i <= m; i ++)
		cin >> a[i] >> b[i] >> c[i] >> d[i];

	int ans = 0;
	for(int i = 1; i <= m; i ++)
		for(int j = 0; j <= n; j ++)
		{
			for(int k = 0; k * c[i] <= j && k * b[i] <= a[i]; k ++)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - k * c[i]] + k * d[i]);
			ans = max(ans, (n - j) / c0 * d0 + dp[i][j]);
		}
	cout << ans << '\n';
	return 0;
}