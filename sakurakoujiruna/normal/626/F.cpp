#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 211;
const int M = 1011;

typedef long long intl;
const intl Mod = (intl)1e9 + 7;

int a[N];
intl dp[2][N][M];

void add(intl &a, intl b)
{
	a += b;
	a %= Mod;
}

int main()
{
	ios :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	sort(a + 1, a + n + 1);

	int now = 0;
	dp[0][0][0] = 1;
	for(int i = 0; i < n; i ++)
	{
		int pre = now;
		now ^= 1;
		memset(dp[now], 0, sizeof(dp[now]));
		for(int j = 0; j <= n; j ++)
			for(int k = 0; k <= m; k ++)
			{
				int tmp = j * (a[i + 1] - a[i]);
				/*
				if(j == 0)
				{
					if(k + a[i + 1] - a[i] <= m)
						add(dp[i + 1][1][k + a[i + 1] - a[i]], dp[i][0][k]);
				}
				*/
				//else
				{
					if(k + j * (a[i + 1] - a[i]) <= m)
						add(dp[now][j + 1][k + j * (a[i + 1] - a[i])], dp[pre][j][k]);

					if(k + j * (a[i + 1] - a[i]) <= m)
						add(dp[now][j][k + j * (a[i + 1] - a[i])], j * dp[pre][j][k]);

					if(j > 0 && k + j * (a[i + 1] - a[i]) <= m)
						add(dp[now][j - 1][k + j * (a[i + 1] - a[i])], j * dp[pre][j][k]);

					if(k + j * (a[i + 1] - a[i]) <= m)
						add(dp[now][j][k + j * (a[i + 1] - a[i])], dp[pre][j][k]);
				}
				//cout << i << ' ' << j << ' ' << k << ' ' << dp[i][j][k] << '\n';
			}
	}
	intl ans = 0;
	for(int k = 0; k <= m; k ++)
		add(ans, dp[now][0][k]);
	cout << ans << '\n';
	return 0;
}