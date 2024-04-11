#include <bits/stdc++.h>
using namespace std;

#define N 100100

int n, st, ed, dep[N], mx[N], smx[N], fa[N], nxt[N];
vector <int> adj[N];
bool vis[N];

void dfs(int *mx, int u, int pa = 0) {
    dep[u] = dep[pa] + 1;
    fa[u] = pa;
    mx[u] = 0;
    for (auto v : adj[u]) {
        if (v == pa) continue;
        dfs(mx, v, u);
        mx[u] = max(mx[u], mx[v] + 1);
    }
}

int pmx[N][3], upmx[N];

void dfs_dn(int u, int pa = 0) {
    memset(pmx[u], 0, sizeof pmx[u]);
    for (auto v : adj[u]) {
        if (v == pa) continue;
        dfs_dn(v, u);
        int d = pmx[v][0] + 1;
        if (d > pmx[u][2]) pmx[u][2] = d;
        if (pmx[u][2] > pmx[u][1]) swap(pmx[u][2], pmx[u][1]);
        if (pmx[u][1] > pmx[u][0]) swap(pmx[u][1], pmx[u][0]);
    }
}

void dfs_up(int u, int pa = 0) {
    for (auto v : adj[u]) {
        if (v == pa) continue;
        int d = pmx[u][0];
        if (d == pmx[v][0] + 1) d = pmx[u][1];
        d = max(d, upmx[u]);
        upmx[v] = d + 1;
        dfs_up(v, u);
    }
}

bool vis_s[N], vis_t[N];

void DFS(bool *vvis, int u, int pa = 0) {
    if (vis[u]) vvis[u] = 1;
    for (auto v : adj[u]) if (v != pa) {
        DFS(vvis, v, u);
        if (vvis[v]) vvis[u] = 1;
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d %d %d", &n, &st, &ed);
        for (int i = 1; i <= n; i ++) vis[i] = vis_s[i] = vis_t[i] = 0, nxt[i] = -1, adj[i].clear();
        for (int i = 1, u, v; i < n; i ++) {
            scanf("%d %d", &u, &v);
            adj[u].push_back(v), adj[v].push_back(u);
        }
        dfs(mx, st), dfs(smx, ed);
        int d = dep[st] - dep[ed];

        dfs_dn(1), dfs_up(1);
        for (int i = 1; i <= n; i ++) {
            if (pmx[i][2] >= d || (pmx[i][1] >= d && upmx[i] >= d)) vis[i] = 1;
        }

        DFS(vis_s, st), DFS(vis_t, ed);

        bool ans = 0;

        vector <int> vec;
        for (int i = st; i; i = fa[i]) vec.push_back(i);
        int sz = vec.size();
        int le = 0, ri = sz - 1;
        while (1) {
            int u = vec[le], v = vec[ri];
            if (vis_s[v] || vis_t[u]) {
                ans = 1; break;
            }
            if (ri <= le) break;
            if (nxt[u] >=0 && nxt[v] >= 0) break;
            int m = le + max(0, d - smx[u]);
            m = min(m, ri);
            nxt[u] = m;
//            assert(m <= ri);
            int mm = ri - max(0, d - mx[v]);
            nxt[v] = mm;
            mm = max(mm, le);
//            assert(mm >= le);
            le = mm;
            ri = m;
        }
        puts(ans ? "YES" : "NO");

    }

    return 0;
}