#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

const i64 MOD = 1000000007ll;
const int MAXN = 510;

int N, K, i, j, k;
i64 bipow[MAXN], dp[2][MAXN][MAXN];

int main()
{
    scanf("%d%d", &N, &K);
    bipow[0] = 1;
    fortodo(i, 1, N) bipow[i] = bipow[i - 1] * 2 % MOD;
    fortodo(j, 0, N)
        fortodo(k, 0, K)
            dp[0][j][k] = 0;
    dp[0][0][0] = 1;
    fortodo(i, 1, N)
        {
            fortodo(j, 0, i)
                fortodo(k, 0, K)
                    dp[1][j][k] = dp[0][j][k] * bipow[j] % MOD;
            // fix <las> as i
            fortodo(j, 0, i - 1)
                fortodo(k, 0, K - 1)
                    {       
                        dp[1][i][k + 1] += dp[0][j][k] * (bipow[j] * (bipow[i - j] + MOD - 1) % MOD);
                        dp[1][i][k + 1] %= MOD;
                    }
            fortodo(j, 0, i)
                fortodo(k, 0, K)
                    dp[0][j][k] = dp[1][j][k];
        }
    i64 ans = 0;
    fortodo(i, 0, N) ans = (ans + dp[1][i][K]) % MOD;
    cout << ans << endl;
}