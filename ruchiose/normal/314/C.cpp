#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

const i64 MOD = 1000000007ll;
const i64 MAXA = 1000000;
const i64 CTRA = 1000010;
const i64 MAXN = 200010;

i64 Pre[CTRA];
i64 N, i, j, A[MAXN], dp[MAXN], sim[MAXN];

i64 V[CTRA];

void Att(i64 x, i64 v)
{
    for (; x <= MAXA; x += x & (-x))
        V[x] = (V[x] + v) % MOD;
}

i64 Qry(i64 x)
{
    i64 r = 0;
    for (; x; x -= x & (-x))
        r = (r + V[x]) % MOD;
    return r;
}

int main()
{
    scanf("%I64d", &N);
    fortodo(i, 1, N) scanf("%I64d", &A[i]);
    fortodo(i, 1, MAXA) V[i] = Pre[i] = 0;
    Att(1, 1);
    fortodo(i, 1, N)
        {
            sim[i] = dp[i] = (Qry(A[i]) * A[i]) % MOD;
            if (Pre[A[i]])
                {
                    dp[i] -= sim[Pre[A[i]]];
                    if (dp[i] < 0) dp[i] += MOD;
                }
            Att(A[i], dp[i]);
            Pre[A[i]] = i;
        }
    i64 ans = 0;
    fortodo(i, 1, N) ans = (ans + dp[i]) % MOD;
    printf("%I64d\n", ans);
}