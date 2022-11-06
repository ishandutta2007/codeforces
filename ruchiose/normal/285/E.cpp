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

const int MOD = int(1e+9) + 7;

int dp[1010][1010][3], bino[1010][1010];
int N, K;
i64 ans[1010], fact[1010];

i64 arithInv(i64 x)
{
    return (x == 0) ? 0 : (MOD - x);
}

int main()
{
    int i, j, o;
    scanf("%d%d", &N, &K);
    fortodo(i, 0, N)
        {
            bino[i][0] = bino[i][i] = 1;
            fortodo(j, 1, i - 1)
                bino[i][j] = (bino[i - 1][j - 1] + bino[i - 1][j]) % MOD;
        }
    fact[0] = 1;
    fortodo(i, 1, N) fact[i] = (fact[i - 1] * i) % MOD;
    fortodo(i, 0, N)
        fortodo(j, 0, N)
            fortodo(o, 0, 2)
                dp[i][j][o] = 0;
    dp[0][0][0] = 1;
    fortodo(i, 0, N - 1)
        fortodo(j, 0, N)
            {
                if ((dp[i + 1][j][0] += dp[i][j][0]) >= MOD)
                    dp[i + 1][j][0] -= MOD;
                if ((dp[i + 1][j + 1][1] += (dp[i][j][0] * 2 % MOD)) >= MOD)
                    dp[i + 1][j + 1][1] -= MOD;
                if ((dp[i + 1][j + 2][2] += dp[i][j][0]) >= MOD)    
                    dp[i + 1][j + 2][2] -= MOD;
                if ((dp[i + 1][j][0] += dp[i][j][1]) >= MOD)
                    dp[i + 1][j][0] -= MOD;
                if ((dp[i + 1][j + 1][1] += dp[i][j][1]) >= MOD)
                    dp[i + 1][j + 1][1] -= MOD;
                if ((dp[i + 1][j][0] += dp[i][j][2]) >= MOD)
                    dp[i + 1][j][0] -= MOD;
            }
    fortodo(i, 0, N) ans[i] = dp[N][i][0] * fact[N - i] % MOD;
    i64 ret = 0;
    fortodo(i, K, N)
        if ((i - K) % 2 == 0)
            ret = (ret + (bino[i][K] * ans[i] % MOD)) % MOD;
        else
            ret = (ret + arithInv(bino[i][K] * ans[i] % MOD)) % MOD;
    cout << ret << endl;
}