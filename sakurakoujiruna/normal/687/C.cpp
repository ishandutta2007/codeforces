#include <bits/stdc++.h>
using namespace std;

const int N = 511;

int c[N];
bool dp[N][N][N];
bool ans[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
		cin >> c[i];

	dp[0][0][0] = true;
	for(int i = 0; i < n; i ++)
		for(int j = 0; j <= m; j ++)
			for(int k = 0; k <= m; k ++)
				if(dp[i][j][k])
				{
					if(j + c[i + 1] <= m)
						dp[i + 1][j + c[i + 1]][k] = true;
					if(k + c[i + 1] <= m)
						dp[i + 1][j][k + c[i + 1]] = true;
					dp[i + 1][j][k] = true;
				}

	int cnt = 0;
	for(int i = 0; i <= m; i ++)
		if(dp[n][i][m - i])
		{
			cnt ++;
			ans[i] = true;
		}

	cout << cnt << '\n';
	for(int i = 0; i <= m; i ++)
		if(ans[i])
			cout << i << ' ';
	cout << '\n';

	return 0;
}