#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, m;
long long f[N], g[N];

bool compare(long long x, long long y) {
    return x > y;
}

struct List {
    int tot, fst[N], nxt[N], to[N], val[N];

    void reset(int n) {
        memset(fst, -1, sizeof(int) * (n + 1)); tot = 0;
    }
    inline void insert(int u, int v, int w) {
        nxt[tot] = fst[u]; to[tot] = v; val[tot] = w; fst[u] = tot++;
    }
    inline void link(int u, int v, int w) {
        insert(u, v, w); insert(v, u, w);
    }
} e;

void dfs(int u, int fa, int fw) {
    std::vector<long long> vec;
    f[u] = g[u] = 0;
    for (int i = e.fst[u]; ~i; i = e.nxt[i]) {
        int v = e.to[i], w = e.val[i];
        if (v != fa) {
            dfs(v, u, w);
            f[u] += g[v]; g[u] += g[v];
            vec.push_back(f[v] - g[v]);
        }
    }
    std::sort(vec.begin(), vec.end(), compare);
    for (int i = 0; i < std::min(m - 1, (int) vec.size()); i++) {
        f[u] += std::max(0ll, vec[i]);
    }
    for (int i = 0; i < std::min(m, (int) vec.size()); i++) {
        g[u] += std::max(0ll, vec[i]);
    }
    f[u] += fw;
}

int main() {
    for (int T = read(); T; T--) {
        n = read(); m = read(); e.reset(n);
        for (int i = 1; i < n; i++) {
            int u = read(), v = read(), w = read();
            e.link(u, v, w);
        }
        dfs(1, 0, 0);
        printf("%I64d\n", g[1]);
    }
    return 0;
}