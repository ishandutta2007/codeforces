#include <bits/stdc++.h>
#define N 26
#define modabs(x) ((x % mod + mod) % mod)
using namespace std;
int n , c[30] , noww , las;
long long dp[2][440][440][3][3] , sum[440][440] , ans = 1;
const int mod = 998244353;
int main()
{
	scanf("%d" , &n);
	for(int i = 1 ; i <= N ; i++ ) scanf("%d" , &c[i]);
	ans = 26 * 26;
	for(int i = 3 ; i <= n ; i++ ) ans = ans * 25 % mod;
	dp[0][0][0][0][0] = 24 * 24;
	dp[0][1][0][0][1] = dp[0][1][0][1][0] = dp[0][0][1][0][2] = dp[0][0][1][2][0] = 24;
	dp[0][1][1][2][1] = dp[0][1][1][1][2] = dp[0][2][0][1][1] = dp[0][0][2][2][2] = 1;
	for(int i = 3 ; i <= n ; i++ )
	{
		las = noww; noww ^= 1;
		memset(dp[noww] , 0 , sizeof(dp[noww]));
		for(int j = 0 ; j <= n ; j++ )
		{
			for(int k = 0 ; k <= n ; k++ )
			{
				for(int x = 0 ; x <= 2 ; x++ )
				{
					for(int y = 0 ; y <= 2 ; y++ )
					{
						dp[las][j][k][x][y] %= mod;
						if(x == 0)
						{
							dp[noww][j][k][y][0] += dp[las][j][k][x][y] * 23;
							dp[noww][j + 1][k][y][1] += dp[las][j][k][x][y];
							dp[noww][j][k + 1][y][2] += dp[las][j][k][x][y];
						}
						if(x == 1)
						{
							dp[noww][j][k][y][0] += dp[las][j][k][x][y] * 24;
							dp[noww][j][k + 1][y][2] += dp[las][j][k][x][y];
						}
						if(x == 2)
						{
							dp[noww][j][k][y][0] += dp[las][j][k][x][y] * 24;
							dp[noww][j + 1][k][y][1] += dp[las][j][k][x][y];
						}
					}
				}
			}
		}
	}
	for(int i = 0 ; i <= n ; i++ )
		for(int j = 0 ; j <= n ; j++ )
			for(int x = 0 ; x <= 2 ; x++ )
				for(int y = 0 ; y <= 2 ; y++ )
					(sum[i][j] += dp[noww][i][j][x][y]) %= mod;
//	cerr << sum[2][2] << endl;
	for(int i = 0 ; i <= n ; i++ )
	{
		for(int j = 0 ; j <= n ; j++ )
		{
			if(i) sum[i][j] += sum[i - 1][j];
			if(j) sum[i][j] += sum[i][j - 1];
			if(i && j) sum[i][j] -= sum[i - 1][j - 1];
			sum[i][j] %= mod;
		}
	}
//	cerr << sum[4][4] - sum[1][4] - sum[4][1] + sum[1][1] << endl;
//	cerr << ans << endl;
//	cerr << ans << endl;
	for(int i = 1 ; i <= N ; i++ )
	{
		for(int j = i + 1 ; j <= N ; j++ )
			ans = modabs(ans + sum[n][n] - sum[c[i]][n] - sum[n][c[j]] + sum[c[i]][c[j]]);
		ans = modabs(ans - sum[n][n] + sum[n][c[i]]);
	}
	printf("%lld" , ans);
	return 0;
}
/*
4
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
*/