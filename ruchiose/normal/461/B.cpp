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

const i64 MOD = 1000000007LL;
const int MAXN = 100010;

int N, P[MAXN], C[MAXN], sib[MAXN], snr[MAXN];
i64 dp[MAXN][2];

int main()
{
    scanf("%d", &N);
    int i;
    fortodo(i, 1, N - 1) scanf("%d", &P[i]);
    fortodo(i, 0, N - 1) scanf("%d", &C[i]);
    fortodo(i, 0, N - 1) snr[i] = 0;
    fortodo(i, 1, N - 1)
        {
            sib[i] = snr[P[i]];
            snr[P[i]] = i;
        }
    for (i = N - 1; i >= 0; i--)
        {
            dp[i][C[i]] = 1;
            dp[i][C[i] ^ 1] = 0;
            for (int s = snr[i]; s; s = sib[s])
                {
                    dp[i][1] = (dp[i][1] * (dp[s][0] + dp[s][1]) + dp[i][0] * dp[s][1]) % MOD;
                    dp[i][0] = (dp[i][0] * (dp[s][0] + dp[s][1])) % MOD;
                }
        }
    printf("%d\n", int(dp[0][1]));
}