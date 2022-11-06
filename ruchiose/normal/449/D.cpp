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

const int MOD = 1000000007;
const int MAXN = 1000010;

int N, bipo[MAXN], dp[1<<21];

int main()
{
    scanf("%d", &N);
    bipo[0] = 1;
    int i, j;
    fortodo(i, 1, N)
        if ((bipo[i] = bipo[i - 1] << 1) >= MOD)
            bipo[i] -= MOD;
    fortodo(i, 0, 0x1FFFFF) dp[i] = 0;
    fortodo(i, 1, N)
        {
            int u;
            scanf("%d", &u);
            dp[u]++;
        }
    fortodo(i, 0, 20)
        fortodo(j, 0, 0x1FfFFF)
            if ((j & (1 << i)) == 0)
                dp[j] += dp[j + (1 << i)];
    int ans = 0;
    fortodo(i, 0, 0x1FFFFF)
        if (__builtin_popcount(i) & 1)
            if ((ans -= bipo[dp[i]]) < 0) ans += MOD;
            else {}
        else
            if ((ans += bipo[dp[i]]) >= MOD) ans -= MOD;
    printf("%d\n", ans);
}