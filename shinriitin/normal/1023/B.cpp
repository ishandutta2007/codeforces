#include <bits/stdc++.h>

long long n, k;

int main() {
    scanf("%lld%lld", &n, &k);
    if (n + n - 1 < k) return puts("0"), 0;
    long long ans = std::min(n, k - 1) - std::max(1ll, k - n) + 1;
    if ((k & 1) == 0 && (k >> 1) <= n) --ans;
    printf("%lld\n", ans / 2);
    return 0;
}