#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, m, now, ans;
bool vis[N];

struct List {
    int tot, fst[N], nxt[N], to[N];

    List() { memset(fst, -1, sizeof(fst)); }
    inline void insert(int u, int v) {
        nxt[tot] = fst[u]; to[tot] = v; fst[u] = tot++;
    }
    inline void link(int u, int v) {
        insert(u, v); insert(v, u);
    }
} e;

void dfs(int u) {
    if (vis[u]) { return; }
    vis[u] = true; now++;
    for (int i = e.fst[u], v; ~i; i = e.nxt[i]) {
        v = e.to[i]; dfs(v);
    }
}

int main() {
    n = read(); m = read();
    for (int i = 0; i < m; i++) {
        int u = read(), v = read(); u--; v--;
        e.link(u, v);
    }
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            now = 0; dfs(i); ans += now - 1;
        }
    } printf("%d\n", m - ans);
    return 0;
} //