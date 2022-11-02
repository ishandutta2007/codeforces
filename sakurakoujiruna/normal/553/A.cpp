#include <bits/stdc++.h>
using namespace std;

const int N = 1011;
typedef long long ll;
const ll Mod = (ll)1e9 + 7;

int c[N];
ll com[N][N];
ll dp[N][N];
ll pre[N][N];

int main()
{
	ios :: sync_with_stdio(false);
	com[0][0] = 1;
	for(int i = 1; i < N; i ++)
	{
		com[i][0] = 1;
		for(int j = 1; j <= i; j ++)
			com[i][j] = (com[i - 1][j] + com[i - 1][j - 1]) % Mod;
	}

	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		cin >> c[i];
		c[i] += c[i - 1];
	}
	int m = c[n];

	dp[0][0] = 1;
	for(int i = 0; i <= m; i ++)
		pre[0][i] = 1;

	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
		{
			if(j - c[i - 1] - 1 >= 0)
			{
				dp[i][j] = pre[i - 1][j - 1] * com[j - c[i - 1] - 1][c[i] - c[i - 1] - 1];
				dp[i][j] %= Mod;
			}
			pre[i][j] = pre[i][j - 1] + dp[i][j];
			pre[i][j] %= Mod;
		}
	cout << dp[n][m] << '\n';
	return 0;
}