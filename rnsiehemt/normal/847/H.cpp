#include <bits/stdc++.h>

const int maxn = 100*1000+5;

int n;
long long a[maxn], av[maxn], ah[maxn], bv[maxn], bh[maxn];

void solve(long long *v, long long *h) {
    v[0] = 0;
    h[0] = a[0];
    for (int i = 1; i < n; i++) {
        h[i] = std::max(h[i-1] + 1, a[i]);
        v[i] = v[i-1] + h[i] - a[i];
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", a+i);
    }

    solve(av, ah);
    std::reverse(a, a+n);
    solve(bv, bh);
    std::reverse(bv, bv+n);
    std::reverse(bh, bh+n);
    std::reverse(a, a+n);

    long long ans = 1000ll*1000*1000*1000*1000*1000;
    for (int i = 0; i < n; i++) {
        ans = std::min(ans, av[i] + bv[i] - (std::min(ah[i], bh[i]) - a[i]));
    }
    printf("%lld\n", ans);
}