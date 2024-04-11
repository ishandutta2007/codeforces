#include <cstdio>
#include <algorithm>

typedef long long ll;

int N;
ll p[100005];
ll dp[100005];

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int a; scanf("%d", &a);
        p[a] += ll(a);
    }

    for (int i = 1; i <= 100000; i++) {
        dp[i+1] = std::max(dp[i+1], dp[i]);
        dp[i+2] = std::max(dp[i+2], dp[i] + p[i]);
    }
    ll ans = 0ll;
    for (int i = 0; i <= 100002; i++)
        ans = std::max(ans, dp[i]);
    printf("%I64d\n", ans);
}