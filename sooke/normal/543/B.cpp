#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e5 + 5, M = 3e3 + 5;

int n, m, s1, t1, d1, s2, t2, d2, ans, dis[M][M];

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

void bfs(int s, int dis[]) {
    for (int u = 1; u <= n; u++) { dis[u] = 1e9; }
    dis[s] = 0;
    std::queue<int> que;
    for (que.push(s); !que.empty(); que.pop()) {
        int u = que.front();
        for (int i = e.fst[u]; ~i; i = e.nxt[i]) {
            int v = e.to[i];
            if (dis[v] > dis[u] + 1) {
                dis[v] = dis[u] + 1;
                que.push(v);
            }
        }
    }
}

int main() {
    n = read(); m = read();
    for (int i = 0; i < m; i++) {
        int u = read(), v = read();
        e.link(u, v);
    }
    for (int u = 1; u <= n; u++) { bfs(u, dis[u]);}
    s1 = read(); t1 = read(); d1 = read();
    s2 = read(); t2 = read(); d2 = read();
    ans = 1e9;
    if (dis[s1][t1] <= d1 && dis[s2][t2] <= d2) {
        ans = std::min(ans, dis[s1][t1] + dis[s2][t2]);
    }
    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            if (dis[s1][u] + dis[u][v] + dis[v][t1] <= d1 && dis[s2][u] + dis[u][v] + dis[v][t2] <= d2) {
                ans = std::min(ans, dis[s1][u] + dis[s2][u] + dis[u][v] + dis[v][t1] + dis[v][t2]);
            }
            if (dis[s1][u] + dis[u][v] + dis[v][t1] <= d1 && dis[t2][u] + dis[u][v] + dis[v][s2] <= d2) {
                ans = std::min(ans, dis[s1][u] + dis[t2][u] + dis[u][v] + dis[v][t1] + dis[v][s2]);
            }
        }
    }
    printf("%d\n", std::max(-1, m - ans));
    return 0;
}