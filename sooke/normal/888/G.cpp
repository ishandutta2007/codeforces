#include <cctype>
#include <cstdio>
#include <algorithm>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5, V = 1e7 + 5;

int n, a[N], pos[N], f[V];
long long ans;

struct Trie {
    int rt, tot, ft[V], son[V][2];

    int insert(int &u, int fa, int i, int x) {
        if (u == 0) { u = ++tot; }
        ft[u] = fa;
        if (i == -1) { return u; }
        int d = x >> i & 1;
        return insert(son[u][d], u, i - 1, x);
    }
    int query(int u, int i, int x) {
        if (i == -1) { return 0; }
        int d = x >> i & 1;
        if (son[u][d] > 0) {
            return query(son[u][d], i - 1, x);
        } else {
            return query(son[u][d ^ 1], i - 1, x) | 1 << i;
        }
    }
} tr;

int main() {
    n = read();
    for (int i = 0; i < n; i++) { a[i] = read(); }
    std::sort(a, a + n); n = std::unique(a, a + n) - a;
    for (int i = 0; i < n; i++) { pos[i] = tr.insert(tr.rt, 0, 29, a[i]); }
    for (int u = 1; u <= tr.tot; u++) { f[u] = tr.son[u][0] && tr.son[u][1] ? 2e9 : 0; }
    for (int i = 0; i < n; i++) {
        for (int u = pos[i], j = -1; u > 0; u = tr.ft[u], j++) {
            if (tr.son[u][0] && tr.son[u][1]) {
                int d = a[i] >> j & 1 ^ 1;
                f[u] = std::min(f[u], tr.query(tr.son[u][d], j - 1, a[i]) | (1 << j));
            }
        }
    }
    for (int u = 1; u <= tr.tot; u++) { ans += f[u]; }
    printf("%lld\n", ans);
    return 0;
}