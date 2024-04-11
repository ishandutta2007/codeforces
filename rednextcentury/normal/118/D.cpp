# include <iostream>
# include <string>
#include <cstdio>
#include <iomanip>
#include <queue>
# include <stack>
#include <ios>
using namespace std;
long long n[2], k[2];
long long dp[201][101][11][2];
int main()
{
	cin >> n[0] >> n[1] >> k[0] >> k[1];
	long long m = n[0] + n[1];
	dp[1][1][1][0] = dp[1][1][1][1] = 1;
	dp[1][0][0][0] = dp[1][0][0][1] = 1;
	for (long long i = 2; i <= m; i++)
	{
		for (long long g = 0; g < 2; g++)
		{
			for (long long j = 1; j <= min(n[g],i); j++)
			{
				for (long long x = 1; x <= min(k[g], j); x++)
				{
					if (x >= 2)
						dp[i][j][x][g] += dp[i - 1][j - 1][x - 1][g],dp[i][j][x][g] %= 100000000;
					else
					{
						for (long long h = 1; h <= min(k[1 - g], i - j); h++)
						{
							//if (i - j == 0) continue;
							dp[i][j][x][g] += dp[i - x][i - j][h][1 - g];
							dp[i][j][x][g] %= 100000000;
						}
					}
				}
			}
		}
	}
	long long ans = 0;
	for (long long g = 0; g < 2; g++)
	{
			for (long long x = 1; x <=k[g]; x++)
			{
				ans += dp[m][n[g]][x][g];
				ans %= 100000000;
			}
	}
	cout << ans << endl;
}