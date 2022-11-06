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

int N, A, B, K;
int dp[5010][5010];

void att(int &x, int y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

void attToSeq(int* A, int S, int E, int v)
{
    if (S <= 0) S = 1;
    if (E > N) E = N;
    att(A[S], v);
    att(A[E + 1], MOD - v);
}

int main()
{
    scanf("%d%d%d%d", &N, &A, &B, &K);
    int i, j;
    fortodo(i, 0, K)
        fortodo(j, 1, N)
            dp[i][j] = 0;
    dp[0][A] = 1;
    fortodo(i, 0, K - 1)
        {
            fortodo(j, 1, N)
                if (dp[i][j])
                    {
                        if (j < B)
                            attToSeq(dp[i + 1], 2 * j - B + 1, B - 1, dp[i][j]);
                        if (j > B)
                            attToSeq(dp[i + 1], B + 1, 2 * j - B - 1, dp[i][j]);
                    }
            fortodo(j, 2, N)
                att(dp[i + 1][j], dp[i + 1][j - 1]);
            fortodo(j, 1, N)
                att(dp[i + 1][j], MOD - dp[i][j]);
        }
    int ans = 0;
    fortodo(i, 1, N)
        att(ans, dp[K][i]);
    printf("%d\n", ans);
}