#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int N, i, j, K, FIELD;
int R[1029][12], seq[2001];
int dp[2001][1029];

const int MOD = 1000000007;

int main()
{
    scanf("%d%d", &N, &K);
    fortodo(i, 1, N) scanf("%d", &seq[i]);
    FIELD = 1 << (K - 1);
    fortodo(i, 0, FIELD)
        fortodo(j, 0, K - 1)
            if (i == 0)
                R[i][j] = 1 << j;
            else
                if (i == FIELD)
                    R[i][j] = FIELD;
                else
                    if ((i & (-i)) == (1 << j))
                        R[i][j] = R[i - (1 << j)][j + 1];
                    else
                        if ((i & (-i)) < (1 << j))
                            R[i][j] = 1 << j;
                        else
                            R[i][j] = i + (1 << j);
    fortodo(i, 0, N)
        fortodo(j, 0, FIELD)
            dp[i][j] = 0;
    dp[0][0] = 1;
    fortodo(i, 0, N - 1)
        fortodo(j, 0, FIELD)
            {
                if (seq[i + 1] != 4) dp[i + 1][R[j][0]] = (dp[i + 1][R[j][0]] + dp[i][j]) % MOD;
                if (seq[i + 1] != 2) dp[i + 1][R[j][1]] = (dp[i + 1][R[j][1]] + dp[i][j]) % MOD;
            }
    printf("%d\n", dp[N][FIELD]);
}