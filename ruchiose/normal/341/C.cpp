#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

const i64 MOD = 1000000007ll;
const int MAXN = 2010;

int N, i, j, C, R;
int A[MAXN];
bool U[MAXN];
i64 dp[MAXN];

int main()
{
    scanf("%d", &N);
    fortodo(i, 1, N) U[i] = false;
    fortodo(i, 1, N)
        {
            scanf("%d", &A[i]);
            if (A[i] != -1) U[A[i]] = true;
        }
    C = R = 0;
    fortodo(i, 1, N)
        if (A[i] == -1)
            if (U[i])
                C++;
            else
                R++;
    dp[0] = 1;
    fortodo(i, 1, C) dp[0] = (dp[0] * i) % MOD;
    fortodo(i, 1, R)
        {
            dp[i] = 0;
            dp[i] += (C + i - 1ll) * dp[i - 1];
            dp[i] %= MOD;
            if (i >= 2)
                {
                    dp[i] += (i - 1ll) * dp[i - 2];
                    dp[i] %= MOD;
                }
        }
    printf("%I64d\n", dp[R]);
}