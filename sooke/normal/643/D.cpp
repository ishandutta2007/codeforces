#include <bits/stdc++.h>

inline long long read() {
    char c; long long x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 2e5 + 5;

int n, q, d[N], f[N];
long long a[N], b[N], c[N], s[N];
std::multiset<long long> set[N], all;

void modify(int u, int sgn, int flag) {
    int v = f[u];
    if (!set[v].empty()) {
        if (flag || sgn < 0) {
            all.erase(all.find(*set[v].begin() + c[v]));
            all.erase(all.find(*set[v].rbegin() + c[v]));
        }
    }
    if (sgn == 1) {
        set[v].insert(b[u] + s[u]);
    }
    if (sgn == -1) {
        set[v].erase(set[v].find(b[u] + s[u]));
    }
    if (!set[v].empty()) {
        if (flag || sgn > 0) {
            assert(!set[v].empty());
            all.insert(*set[v].begin() + c[v]);
            all.insert(*set[v].rbegin() + c[v]);
        }
    }
}

int main() {
    n = read(); q = read();
    for (int u = 1; u <= n; u++) {
        a[u] = read(); d[u] = 1;
    }
    for (int u = 1; u <= n; u++) {
        f[u] = read(); d[f[u]]++;
    }
    for (int u = 1; u <= n; u++) {
        c[u] = a[u] / (d[u] + 1);
        b[u] = a[u] - c[u] * d[u];
        s[f[u]] += c[u];
    }
    for (int u = 1; u <= n; u++) {
        modify(u, 1, 1);
    }
    for (int i = 0; i < q; i++) {
        int opt = read();
        if (opt == 1) {
            int u = read(), v = read();
            modify(u, -1, 0);
            modify(f[u], -1, 0);
            modify(f[f[u]], -1, 0);
            d[f[u]]--;
            s[f[u]] -= c[u];
            s[f[f[u]]] -= c[f[u]];
            c[f[u]] = a[f[u]] / (d[f[u]] + 1);
            b[f[u]] = a[f[u]] - c[f[u]] * d[f[u]];
            s[f[f[u]]] += c[f[u]];
            modify(u, 2, 0);
            modify(f[u], 1, 0);
            modify(f[f[u]], 1, 0);
            f[u] = v;
            modify(u, -2, 0);
            modify(f[u], -1, 0);
            modify(f[f[u]], -1, 0);
            d[f[u]]++;
            s[f[u]] += c[u];
            s[f[f[u]]] -= c[f[u]];
            c[f[u]] = a[f[u]] / (d[f[u]] + 1);
            b[f[u]] = a[f[u]] - c[f[u]] * d[f[u]];
            s[f[f[u]]] += c[f[u]];
            modify(u, 1, 0);
            modify(f[u], 1, 0);
            modify(f[f[u]], 1, 0);
        } else if (opt == 2) {
            int u = read();
            printf("%lld\n", b[u] + c[f[u]] + s[u]);
        } else {
            printf("%lld %lld\n", *all.begin(), *all.rbegin());
        }
    }
    return 0;
}