#include <bits/stdc++.h>

inline void read(int &x) {
    int c;
    while (!isdigit(c = getchar()));
    x = c - '0';
    while (isdigit(c = getchar())) {
        x = x * 10 + c - '0';
    }
}

using LL = long long;

const int max_N = (int) 1e5 + 21;

int n, m, a[max_N], cnt[max_N];

LL dp[2][max_N], *f = dp[0], *g = dp[1];

void solve(int l, int r, int L, int R, LL w) { // w[L, l)
    if (l > r) return;

    // printf("l = %d, r = %d, L = %d, R = %d, w = %lld\n", l, r, L, R, w);

    int mid = (l + r) >> 1;
    f[mid] = LLONG_MAX >> 3;

    int i, k = 0, p = std::min(mid, R);

    for (i = l; i <= mid; ++i) w += cnt[a[i]]++; // w[L, mid]

    for (i = L; i <= p; ++i) {
        w -= --cnt[a[i]]; // w(i, mid]
        if (f[mid] > g[i] + w) {
            f[mid] = g[i] + w;
            k = i;
        }
    }

    for (i = L; i <= p; ++i) w += cnt[a[i]]++;
    for (i = l; i <= mid; ++i) w -= --cnt[a[i]];

    solve(l, mid - 1, L, k, w); // w[L, l)

    for (i = l; i <= mid; ++i) w += cnt[a[i]]++; // w[L, mid]
    for (i = L; i < k; ++i) w -= --cnt[a[i]]; // w[k, mid]

    solve(mid + 1, r, k, R, w);

    for (i = L; i < k; ++i) w += cnt[a[i]]++;
    for (i = l; i <= mid; ++i) w -= --cnt[a[i]];
}

int main() {
    read(n), read(m);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
        f[i] = f[i - 1] + cnt[a[i]]++;
    }
    std::fill_n(cnt + 1, n, 0);
    for (int i = 1; i < m; ++i) {
        std::swap(f, g);
        solve(1, n, 1, n, 0);
    }
    printf("%lld\n", f[n]);
    return 0;
}