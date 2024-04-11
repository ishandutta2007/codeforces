// Author: Ruchiose
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#define i64 long long
#define d64 long double
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

const int MAXN = 2010;
const int MAXM = 2010;
const i64 MOD = int(1e+9) + 7;
int N, M;
i64 dp[MAXN][MAXM], prefix1[MAXN][MAXM], prefix2[MAXN][MAXM];

int main()
{
	scanf("%d%d", &N, &M);
	int i, j;
	fortodo(i, 1, M - 1)
		{
			dp[0][i] = 0;
			dp[1][i] = 1;
		}
	fortodo(i, 2, N)
		{
			prefix1[i - 1][0] = 0;
			fortodo(j, 1, M - 1)
				prefix1[i - 1][j] = (prefix1[i - 1][j - 1] + dp[i - 1][j]) % MOD;
			prefix2[i - 1][0] = 0;
			fortodo(j, 1, M - 1)
				prefix2[i - 1][j] = (prefix2[i - 1][j - 1] + prefix1[i - 1][j]) % MOD;
			fortodo(j, 1, M - 1)
				dp[i][j] = (prefix2[i - 1][j] + 1) % MOD;
		}
	i64 ans = 0;
	fortodo(i, 1, N) // lower_l
		fortodo(j, 1, M - 1) // len
			{
				i64 Q = dp[i][j] * (dp[N + 1 - i][j] - dp[N - i][j] + MOD) % MOD;
				ans = (ans + Q * (M - j)) % MOD;
			}
	cout << ans << endl;
}