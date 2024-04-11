#include <bits/stdc++.h>
using namespace std;

#define N 1010

int t, n, p[N];
bool vis[N], vB[N];
vector <int> adj[N];

void dfs(int u, int pa = 0) {
    p[u] = pa;
    for (auto v : adj[u]) {
        if (v == pa) continue;
        dfs(v, u);
    }
}

int main() {
    scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        for (int i = 1, x; i <= n; i ++) vis[i] = 0, vB[i] = 0, adj[i].clear();
        for (int i = 1, u, v; i < n; i ++) scanf("%d %d", &u, &v), adj[u].push_back(v), adj[v].push_back(u);
        int q, x, y;
        scanf("%d", &q);
        while (q --) scanf("%d", &x), vis[x] = 1;
        dfs(x);
        scanf("%d", &q);
        while (q --) scanf("%d", &y), vB[y] = 1;
        printf("B %d\n", y);
        fflush(stdout);
        scanf("%d", &x);
        while (!vis[x]) x = p[x];
        printf("A %d\n", x);
        fflush(stdout);
        scanf("%d", &q);
        if (vB[q]) printf("C %d\n", x);
        else puts("C -1");
        fflush(stdout);
    }
}