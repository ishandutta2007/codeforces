#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int N = 1002;

int par[N];
int find(int x) {
    return par[x] == x ? x: par[x] = find(par[x]);
}

int n, m, col[N], ring = 0;
vector<int> g[N];

void dfs(int u) {
    for (auto v: g[u]) {
        if (col[v] == 0) {
            col[v] = 3 - col[u];
            dfs(v);
        } else { 
            if (col[u] == col[v]) ring = 1; 
        }
    }
}

int dis[N];
void bfs(int u) {
    queue<int> q;
    int d[N] = {0};
    memset(d, -1, sizeof(d));
    d[u] = 0; q.push(u);
    while (q.size()) {
        int x = q.front(); q.pop();
        for (auto v: g[x]) {
            if (d[v] == -1) {
                d[v] = d[x] + 1; q.push(v);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i ++) ans = max(ans, d[i]);
    // printf("u = %d, %d\n", u, ans);
    dis[find(u)] = max(ans, dis[find(u)]);
}
 
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++) par[i] = i;
    for (int i = 1; i <= m; i ++) {
        int u, v; scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
        par[find(u)] = find(v);
    }
    for (int i = 1; i <= n; i ++) {
        if (col[i] == 0) {
            col[i] = 1;
            dfs(i);
        }
    }
    if (ring) return !printf("-1\n");
    for (int i = 1; i <= n; i ++) {
        bfs(i);
    }
    int res = 0, cnt = 0;
    for (int i = 1; i <= n; i ++) if (dis[i]) {
        res = res + dis[i];
    }
    cout << res << endl;
}