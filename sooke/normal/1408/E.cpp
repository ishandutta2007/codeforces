#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, m, q, a[N], b[N], anc[N];
long long ans;

struct Edge {
    int u, v, w;
} e[N];

bool operator <(const Edge &i, const Edge &j) {
    return i.w > j.w;
}

int find(int u) {
    return anc[u] == u ? u : anc[u] = find(anc[u]);
}

int main() {
    q = read(); n = read();
    for (int i = 1; i <= q; i++) { a[i] = read(); }
    for (int u = 1; u <= n; u++) { b[u] = read(); }
    for (int u = 1; u <= q + n; u++) { anc[u] = u; }
    for (int i = 1; i <= q; i++) {
        for (int k = read(); k; k--) {
            int u = read();
            e[m++] = (Edge) {u, n + i, b[u] + a[i]};
        }
    }
    std::sort(e, e + m);
    for (int i = 0; i < m; i++) {
        int u = e[i].u, v = e[i].v, w = e[i].w;
        u = find(u); v = find(v);
        if (u == v) { ans += w; continue; }
        anc[u] = v;
    }
    printf("%lld\n", ans);
}