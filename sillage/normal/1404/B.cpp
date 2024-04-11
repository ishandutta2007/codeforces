#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
vector<int> g[maxn];
int mx, dis[maxn];
void dfs(int u, int fa){
    if (dis[u] > dis[mx]) mx = u;
    for (auto v : g[u]) if (v != fa) dis[v] = dis[u] + 1, dfs(v, u);
}
void solve(){
    int n, a, b, da, db;
    scanf("%d%d%d%d%d", &n, &a, &b, &da, &db);
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int len = 2 * da;
    if (db <= len){
        puts("Alice");
        return;
    }
    mx = a;  dis[a] = 0;
    dfs(a, -1);
    if (dis[b] <= da){
        puts("Alice");
        return;
    }
    int p = mx; dis[p] = 0;
    dfs(p, -1);
    if (dis[mx] <= len){
        puts("Alice");
    }else{
        puts("Bob");
    }

}
int main(){
    int T;
    scanf("%d", &T);
    while (T--) solve();
}