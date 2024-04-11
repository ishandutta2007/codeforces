#include <bits/stdc++.h>

const int max_N = (int) 2e5 + 21;

int n, a[max_N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n * 2; ++i) scanf("%d", a + i);
    std::sort(a + 1, a + 1 + 2 * n);
    long long ans = 1ll * (a[n] - a[1]) * (a[n * 2] - a[n + 1]);
    for (int i = 2; i <= n; ++i) {
        ans = std::min(ans, 1ll * (a[2 * n] - a[1]) * (a[i + n - 1] - a[i]));
    }
    printf("%lld\n", ans);
    return 0;
}