#include <bits/stdc++.h>

using LL = long long;

const int max_N = (int) 5e5 + 21;
const int mod = (int) 1e9 + 7;

int n, m, k, u[max_N], v[max_N], Q[max_N], siz[max_N], f[max_N];

LL a[max_N], w[max_N];

inline int qpow(int x, int k) {
    int res = 1;
    for (; k; x = 1ll * x * x % mod, k >>= 1)
        if (k & 1) res = 1ll * res * x % mod;
    return res;
}

inline int find(int x) {
    while (f[x] != x) x = f[x];
    return x;
}

inline bool merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return false;
    if (siz[u] > siz[v]) std::swap(u, v);
    f[u] = v, siz[v] += siz[u];
    return true;
}

inline void reset(int i) {
    f[i] = i, siz[i] = 1;
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", a + i);
        reset(i);
    }
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", u + i, v + i);
        w[i] = a[u[i]] ^ a[v[i]];
        Q[i] = i;
    }
    std::sort(Q + 1, Q + 1 + m, [&](int x, int y) { return w[x] < w[y]; });
    int ans = 0, sum = qpow(2, k);
    for (int i = 1, j; i <= m; i = j) {
        for (j = i; j <= m && w[Q[i]] == w[Q[j]]; ++j);
        int cnt = n;
        for (k = i; k < j; ++k)
            if (merge(u[Q[k]], v[Q[k]])) {
                --cnt;
            }
        ans = (ans + qpow(2, cnt)) % mod;
        for (k = i; k < j; ++k) {
            reset(u[Q[k]]);
            reset(v[Q[k]]);
        }
        --sum;
    }
    ans = (ans + 1ll * sum * qpow(2, n)) % mod;
    printf("%d\n", ans);
    return 0;
}