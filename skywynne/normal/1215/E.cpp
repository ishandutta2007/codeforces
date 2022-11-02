// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
const int N = 4e5 + 9, K = 20;
int n, A[N];
long long I[K][K], C[K][1 << K], dp[1 << K];
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i ++)
        scanf("%d", &A[i]), A[i] --;
    for (int i = 0; i < K; i ++)
        for (int j = 0; j < K; j ++)
            if (i != j)
            {
                int cnt = 0;
                for (int h = 0; h < n; h ++)
                    if (A[h] == i)
                        cnt ++;
                    else if (A[h] == j)
                        I[i][j] += cnt;
            }
    for (int i = 0; i < K; i ++)
        for (int mask = 1; mask < (1 << K); mask ++)
        {
            int lb = __builtin_ctz(mask);
            C[i][mask] = C[i][mask ^ (1 << lb)] + I[i][lb];
        }
    memset(dp, 63, sizeof(dp)); dp[0] = 0;
    for (int mask = 1; mask < (1 << K); mask ++)
        for (int i = 0; i < K; i ++)
            if (mask >> i & 1)
                dp[mask] = min(dp[mask], dp[mask ^ (1 << i)] + C[i][(1 << K) - 1 - mask]);
    return !printf("%lld\n", dp[(1 << K) - 1]);
}