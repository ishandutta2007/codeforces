#include <iostream>
using namespace std;

const int N = 4011;
typedef long long intl;
const intl Mod = (intl)1e9 + 7;

intl c[N][N];
intl dp[N];

int main()
{
	ios :: sync_with_stdio(false);
	for(int i = 0; i < N; i ++)
	{
		c[i][0] = 1;
		for(int j = 1; j <= i; j ++)
		{
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
			c[i][j] %= Mod;
		}
	}
	int n;
	cin >> n;
	dp[0] = 1;
	for(int i = 1; i <= n; i ++)
	{
		dp[i] = 0;
		for(int j = 0; j <= i - 1; j ++)
		{
			dp[i] += c[i - 1][j] * dp[i - j - 1];
			dp[i] %= Mod;
		}
	}

	intl ans = 0;
	for(int i = 1; i <= n; i ++)
	{
		ans += c[n][i] * dp[n - i];
		ans %= Mod;
	}
	cout << ans << '\n';
	return 0;
}