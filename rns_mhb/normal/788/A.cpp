#include <bits/stdc++.h>
using namespace std;

#define N 100005

typedef long long ll;

int n;
ll a[N], b[N], ans;
ll dp[2][N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%I64d", &a[i]);
    for (int i = 1; i < n; i ++) b[i] = abs(a[i+1] - a[i]);
    n --;
    for (int i = 1; i <= n; i ++) {
        dp[0][i] = max(0ll, dp[1][i-1] - b[i]);
        dp[1][i] = max(dp[0][i-1] + b[i], b[i]);
        ans = max(ans, dp[0][i]);
        ans = max(ans, dp[1][i]);
    }
    printf("%I64d\n", ans);
}