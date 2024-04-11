#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

inline int read() {
    char c = getchar(); int n = 0; bool f = false;
    while (c < '0' || c > '9') { if (c == '-') { f = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
    return f ? -n : n;
}

const int maxN = 1005, maxE = maxN << 1;

int n, m, k, root, pos, f[maxN];
bool tag[maxN], used[maxN];

struct List {
    int len, fst[maxN], nxt[maxE], v[maxE];
    
    inline void reset() { memset(fst, -1, sizeof(fst)); len = 0; }
    inline void insert(int u, int vv) { v[len] = vv, nxt[len] = fst[u], fst[u] = len++; }
    inline void connect(int u, int vv) { insert(u, vv), insert(vv, u); }
} ls;

void dfs(int u, int fa) {
    f[u] = fa;
    for (int i = ls.fst[u]; ~i; i = ls.nxt[i]) {
        int v = ls.v[i];
        if (v != fa) { dfs(v, u); }
    }
}

int main() {
    for (int tn = read(); tn; tn--) {
        n = read(); ls.reset();
        for (int i = 2; i <= n; i++) { ls.connect(read(), read()); }
        m = read(); memset(tag, false, sizeof(tag));
        for (int i = 1; i <= m; i++) { tag[root = read()] = true; }
        k = read(); memset(used, false, sizeof(used));
        for (int i = 1; i <= k; i++) { used[pos = read()] = true; }
        std::cout << "B " << pos << std::endl; pos = read();
        dfs(root, 0);
        for (; !tag[pos]; ) { pos = f[pos]; }
        std::cout << "A " << pos << std::endl;
        if (used[read()]) { std::cout << "C " << pos << std::endl; } else { std::cout << "C -1" << std::endl; }
    }
    return 0;
}