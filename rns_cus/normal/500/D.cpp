#include <bits/stdc++.h>
using namespace std;

#define M 200001

map<int, int> mp[M];
vector<int> v[M];
int vis[M], deg[M], par[M];
int a[M], b[M];
int n;
double tot = 0;

void dfs(int u) {
    vis[u] = 1;
    deg[u] = 1;
    for(int i = 0; i < v[u].size(); i ++) {
        int x = v[u][i];
        if(vis[x]) continue;
        par[x] = u;
        dfs(x);
        deg[u] += deg[x];
        tot = tot + 1. * deg[x] * (n - deg[x]) * mp[u][x];
    }
}

int main() {
    ///freopen("d.in", "r", stdin);
    scanf("%d", &n);
    for(int i = 1; i < n; i ++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        v[x].push_back(y);
        v[y].push_back(x);
        a[i] = x; b[i] = y;
        mp[a[i]][b[i]] = z;
        mp[b[i]][a[i]] = z;
    }
    dfs(1);
    for(int i = 1; i <= n; i ++) if(par[a[i]] != b[i]) swap(a[i], b[i]);
    int q;
    scanf("%d", &q);
    while(q --) {
        int x, y;
        scanf("%d %d", &x, &y);
        tot -= 1. * (n - deg[a[x]]) * deg[a[x]] * (mp[a[x]][b[x]] - y);
        mp[a[x]][b[x]] = mp[b[x]][a[x]] = y;
        printf("%.10lf\n", 6. * tot / n / (n - 1));
    }
}