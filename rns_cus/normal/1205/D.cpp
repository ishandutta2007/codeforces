#include <bits/stdc++.h>
using namespace std;

#define N 1010

int n;
vector <int> adj[N];

int node[N], nodes, pa[N], son[N], fa[N];
int bfs(int x) {
    nodes = 0;
    pa[node[++nodes] = x] = 0;
    for (int i = 1; i <= nodes; i ++) {
        x = node[i];
        son[x] = 1;
        for (auto y : adj[x]) {
            if (y != pa[x]) pa[node[++nodes] = y] = x;
        }
    }
    int rlt = 0;
    for (int i = nodes; i >= 1; i --) {
        int x = node[i];
        if (!rlt && son[x] * 2 >= nodes) rlt = x;
        son[pa[x]] += son[x];
    }
    return rlt;
}

int find(int u) {
    return fa[u] == u ? u : fa[u] = find(fa[u]);
}

bool vis[N];
int val[N];

int main() {
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; i ++) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v), adj[v].push_back(u);
    }
    if (n == 1) return 0;
    int rt = bfs(1);
    typedef pair <int, int> pii;
    set <pii> S; bfs(rt);
    for (auto u : adj[rt]) S.insert(pii(son[u], u)), fa[u] = u;
    while (S.size() > 2) {
        set <pii> :: iterator it = S.begin();
        pii x = *it, y = *(++it); S.erase(it), S.erase(S.begin());
        fa[x.second] = y.second; y.first += x.first;
        S.insert(y);
    }
    int x = find(adj[rt][0]);
    for (int i = 2; i <= n; i ++) {
        int y = node[i];
        if (pa[y] == rt) vis[y] = find(y) == x;
        else vis[y] = vis[pa[y]];
    }
    for (int i = 1; i <= n; i ++) fa[i] = pa[i];
    for (int i = 1; i <= n; i ++) adj[i].clear();
    for (int i = 1; i <= n; i ++) {
        if (i == rt) continue;
        int j = fa[i];
        if (vis[i]) continue;
        adj[i].push_back(j), adj[j].push_back(i);
    }
    bfs(rt); val[rt] = 0;
    for (int i = 2; i <= nodes; i ++) {
        int y = node[i], z = pa[y]; val[y] = i - 1;
        printf("%d %d %d\n", y, z, val[y] - val[z]);
    }
    int cnt = son[rt];
    for (int i = 1; i <= n; i ++) adj[i].clear();
    for (int i = 1; i <= n; i ++) {
        if (i == rt) continue;
        int j = fa[i];
        if (!vis[i]) continue;
        adj[i].push_back(j), adj[j].push_back(i);
    }
    bfs(rt); val[rt] = 0;
    for (int i = 2; i <= nodes; i ++) {
        int y = node[i], z = pa[y]; val[y] = (i - 1) * cnt;
        printf("%d %d %d\n", y, z, val[y] - val[z]);
    }

    return 0;
}