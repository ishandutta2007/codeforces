#include <bits/stdc++.h>
using namespace std;

#define N 100010

int n, k, deg[N], d[N], pa[N];
vector <int> adj[N];

int bfs(int u) {
    queue <int> q;
    for (int i = 1; i <= n; i ++) d[i] = -1;
    d[u] = 0;
    q.push(u);
    while (!q.empty()) {
        u = q.front(); q.pop();
        for (auto v : adj[u]) {
            if (d[v] < 0) d[v] = d[u] + 1, pa[v] = u, q.push(v);
        }
    }
    int x = d[u];
    if (x & 1) return 0;
    x >>= 1;
    while (x --) u = pa[u];
    return u;
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1, u, v; i < n; i ++) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u] ++, deg[v] ++;
    }
    if (n == 1) return puts("No"), 0;
    int u = 0;
    for (u = 1; u <= n; u ++) if (deg[u] == 1) break;
    u = bfs(u);
    if (!u) return puts("No"), 0;
    bfs(u);
    int dp = 0;
    for (int i = 1; i <= n; i ++) dp = max(dp, d[i]);
    if (dp != k) return puts("No"), 0;
    for (int i = 1; i <= n; i ++) {
        if (d[i] == dp) continue;
        if (i != u) deg[i] --;
        if (deg[i] < 3) return puts("No"), 0;
    }
    puts("Yes");

    return 0;
}