#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

const i64 MOD = 1000000007;
const int MAXN = 1000;
const int DMAXN = 2000;
const int MAXK = 45;

int N, K;
i64 dp[MAXK+1][MAXN+1];
i64 C[DMAXN+1][DMAXN+1], FACT[MAXK+1];

int main()
{
	int x, i, j;
	fortodo(i, 0, MAXK)
		fortodo(j, 0, MAXN)
			dp[i][j] = 0;
	dp[0][0] = 1;
	fortodo(x, 1, MAXN)
		for (i = MAXK; i; i--)
			fortodo(j, x, MAXN)
				{
					dp[i][j] += dp[i - 1][j - x];
					dp[i][j] %= MOD;
				}
	C[0][0] = 1;
	fortodo(i, 1, DMAXN)
		{
			C[i][0] = C[i - 1][0];
			C[i][i] = C[i - 1][i - 1];
			fortodo(j, 1, i - 1)
				C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
		}
	FACT[0] = 1;
	fortodo(i, 1, MAXK) FACT[i] = FACT[i - 1] * i % MOD;
	int T;
	for (scanf("%d", &T); T; T--)
		{
			scanf("%d%d", &N, &K);
			if (K > MAXK)
				printf("0\n");
			else
				{
					i64 ans = 0;
					fortodo(i, 0, N)
						if (dp[K][i])
							ans += dp[K][i] * C[N - i + K][K] % MOD;
					ans %= MOD;
					ans *= FACT[K];
					ans %= MOD;
					cout << ans << endl;
				}
		}
}