// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10, Mod = 1e9 + 7;
int n, m, q, A[N], dp[N];
int main()
{
    scanf("%d%d", &n, &m);
    dp[0] = 1;
    for (int i = 1; i < N; i ++)
    {
        dp[i] = dp[i - 1];
        if (i > 1)
            dp[i] += dp[i - 2];
        dp[i] %= Mod;
    }
    int tot = (dp[n] + dp[m]) % Mod * 2LL % Mod;
    tot = (tot - 2 + Mod) % Mod;
    printf("%d\n", tot);
    return 0;
}