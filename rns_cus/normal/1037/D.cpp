#include <bits/stdc++.h>
using namespace std;

#define N 200020
#define pb push_back

int n, q[N], rk[N];
bool vis[N];
vector <int> adj[N];
queue <int> Q;

void bfs(int u) {
    int m = 0;
    Q.push(u); vis[u] = 1;
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        q[++m] = u;
        for (int v : adj[u]) {
            if (vis[v]) continue;
            Q.push(v), vis[v] = 1;
        }
    }
}

bool cmp(int i, int j) {
    return rk[i] < rk[j];
}

int main() {
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; i ++) {
        scanf("%d %d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for (int i = 1, j; i <= n; i ++) {
        scanf("%d", &j);
        rk[j] = i;
    }
    for (int i = 1; i <= n; i ++) sort(adj[i].begin(), adj[i].end(), cmp);
    bfs(1);
    bool fg = 1;
    for (int i = 1; i <= n; i ++)
        if (rk[q[i]] != i) fg = 0;
    puts(fg ? "Yes" : "No");
}