#include <bits/stdc++.h>
using namespace std;

#define N 100100
typedef pair <int, int> pii;
int n, rt, deg[N], sum[N], st[N], ed[N];
vector <pii> adj[N];

void dfs(int u, int pa = 0) {
    st[u] = ed[u] = u;
    for (auto p : adj[u]) {
        int v = p.first, w = p.second;
        if (v == pa) continue;
        sum[v] = w;
        sum[u] -= w;
        dfs(v, u);
        if (st[u] == u) st[u] = st[v];
        else ed[u] = ed[v];
    }
}
vector < tuple <int, int, int> > ans;
void add(int u, int w) {
    if (deg[u] == 1) ans.emplace_back(rt, u, w);
    else {
        ans.emplace_back(rt, st[u], w / 2);
        ans.emplace_back(rt, ed[u], w / 2);
        ans.emplace_back(st[u], ed[u], -w / 2);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1, u, v, w; i < n; i ++) {
        scanf("%d %d %d", &u, &v, &w);
        deg[u] ++, deg[v] ++;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    for (int i = 1; i <= n; i ++) if (deg[i] == 2) return puts("NO"), 0;
    puts("YES");
    for (int i = 1; i <= n; i ++) if (deg[i] == 1) rt = i;
    dfs(rt);
    for (int i = 1; i <= n; i ++) if (i != rt) add(i, sum[i]);
    int sz = ans.size();
    printf("%d\n", sz);
    for (int i = 0; i < sz; i ++) printf("%d %d %d\n", get <0> (ans[i]), get <1> (ans[i]), get <2> (ans[i]));
    return 0;
}