#include <bits/stdc++.h>
using namespace std;

#define N 100100

int dp[N];
const int mod = 1e9 + 7;

int main() {
    dp[0] = dp[1] = 1;
    for (int i = 2; i < N; i ++) {
        dp[i] = dp[i-1] + dp[i-2];
        if (dp[i] >= mod) dp[i] -= mod;
    }
    int n, m;
    scanf("%d %d", &n, &m);
    printf("%d\n", 2ll * (dp[n] + dp[m] - 1) % mod);

    return 0;
}