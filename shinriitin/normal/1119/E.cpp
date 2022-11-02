#include <bits/stdc++.h>

using LL = long long;

const int max_N = (int) 3e5 + 21;

int n, a[max_N];

LL ans, tmp;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        LL t1 = std::min(tmp, a[i] / 2LL);
        ans += t1;
        a[i] -= 2 * t1;
        tmp -= t1;
        ans += a[i] / 3LL;
        tmp += a[i] % 3;
    }
    printf("%lld\n", ans);
}