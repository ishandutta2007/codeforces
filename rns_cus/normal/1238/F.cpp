#include <bits/stdc++.h>
using namespace std;

#define N 300300

int n, mx[N], mx2[N];
vector <int> adj[N];

int ans;

void dfs(int u, int pa = 0) {
    mx[u] = mx2[u] = 0;
    int sz = 0;
    for (auto v : adj[u]) {
        if (v == pa) continue;
        dfs(v, u); sz ++;
        if (mx2[u] < mx[v]) mx2[u] = mx[v];
        if (mx[u] < mx2[u]) swap(mx[u], mx2[u]);
    }
    ans = max(ans, mx[u] + mx2[u] + max((int)adj[u].size() - 1, 1));
    mx[u] += max(sz, 1);
}

int main() {
    int q;
    scanf("%d", &q);
    while (q --) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++) adj[i].clear();
        for (int i = 1, u, v; i < n; i ++) {
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        ans = 0;
        dfs(1);
        printf("%d\n", ans);
    }
}