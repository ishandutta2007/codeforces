#include <bits/stdc++.h>
using namespace std;

#define N 50100

int n, r1, r2, p[N];
vector <int> adj[N];

void dfs(int u, int pa = 0) {
    p[u] = pa;
    for (auto v : adj[u]) if (v != pa) dfs(v, u);
}

int main() {
    scanf("%d %d %d", &n, &r1, &r2);
    for (int i = 1; i <= n; i ++) if (i != r1) {
        int p; scanf("%d", &p);
        adj[i].push_back(p);
        adj[p].push_back(i);
    }
    dfs(r2);
    for (int i = 1; i <= n; i ++) if (i != r2) printf("%d ", p[i]); puts("");

    return 0;
}