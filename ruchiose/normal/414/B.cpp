#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

const int MOD = 1000000007;
int N, K, i, j, k, dp[2001][2001];

int main()
{
    scanf("%d%d", &N, &K);
    fortodo(i, 1, N) dp[1][i] = 1;
    fortodo(i, 2, K)
        {
            fortodo(j, 1, N) dp[i][j] = 0;
            fortodo(j, 1, N)
                for (k = j; k <= N; k += j)
                    dp[i][k] = (dp[i][k] + dp[i - 1][j]) % MOD;
        }
    int ANS = 0;
    fortodo(i, 1, N) ANS = (ANS + dp[K][i]) % MOD;
    printf("%d\n", ANS);
}