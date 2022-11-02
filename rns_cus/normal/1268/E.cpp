#include <bits/stdc++.h>
using namespace std;

#define N 1000100

int n, m, tot, nxt[N], head[N], to[N];

void add_edge(int u, int v) {
    nxt[tot] = head[u], to[tot] = v, head[u] = tot++;
    nxt[tot] = head[v], to[tot] = u, head[v] = tot++;
}

int vis[N], p[N];

vector <int> cyc[N];

void dfs(int u, int pa = 0) {
    vis[u] = 1;
    for (int e = head[u]; ~e; e = nxt[e]) {
        int v = to[e];
        if (v == pa || vis[v] == 2) continue;
        if (vis[v]) {
            vector <int> vec;
            int mn = N;
            vec.push_back(e >> 1);
            for (int i = u; i != v; i = to[p[i]]) {
                vec.push_back(p[i] >> 1);
            }
            for (auto x : vec) mn = min(mn, x);
            cyc[mn] = vec;
        }
        else p[v] = e ^ 1, dfs(v, u);
    }
    vis[u] = 2;
}

int a[N], b[N], f[N], dp[N];

int main() {
    memset(head, -1, sizeof head);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i ++) {
        scanf("%d %d", &a[i], &b[i]);
        add_edge(a[i], b[i]);
    }
    dfs(1);
    for (int i = 1; i <= n; i ++) dp[i] = 1;
    for (int i = m - 1; ~i; i --) {
        int u = a[i], v = b[i];
        dp[u] = dp[v] = f[i] = dp[u] + dp[v];
        if (cyc[i].empty()) continue;
        int sz = cyc[i].size(), k, mx = 0, l;
        for (k = 0; k < sz; k ++) if (cyc[i][k] == i) break;
        for (auto x : cyc[i]) mx = max(mx, x);
        cyc[i].resize(sz << 1);
        for (int j = 0; j < sz; j ++) cyc[i][j+sz] = cyc[i][j];
        for (l = k + 1; l < k + sz; l ++) if (cyc[i][l] == mx) break;
        bool fg = 1;
        for (int j = k + 1; j < l; j ++) if (cyc[i][j-1] > cyc[i][j]) fg = 0;
        for (int j = l + 1; j < k + sz; j ++) if (cyc[i][j-1] < cyc[i][j]) fg = 0;
        if (fg) dp[u] = dp[v] = f[i] = f[i] - f[mx];
    }
    for (int i = 1; i <= n; i ++) printf("%d ", dp[i] - 1);
    return 0;
}