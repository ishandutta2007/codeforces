#include <bits/stdc++.h>
using namespace std;

#define N 200100

int n, vis[N];
vector <int> adj[N];

void dfs(int u, int pa = -1) {
    for (auto v : adj[u]) {
        if (v == pa) continue;
        vis[v] = vis[u] ^ 1;
        dfs(v, u);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; i ++) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    int a = 0, b = 0;
    for (int i = 1; i <= n; i ++) if (vis[i]) a ++; else b ++;
    printf("%d\n", min(a, b) - 1);

    return 0;
}