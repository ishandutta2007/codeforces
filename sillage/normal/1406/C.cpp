#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int sz[maxn], mx[maxn];
vector<int> g[maxn];
void dfs(int u, int fa){
    sz[u] = 1;
    mx[u] = 0;
    for (auto v : g[u]) if (v != fa){
        dfs(v, u);
        sz[u] += sz[v];
        if (sz[v] >= mx[u]) mx[u] = sz[v];
    }
}
void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 1, u, v; i < n; i++){
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) if (n - sz[i] > mx[i]) mx[i] = n - sz[i];
    int ans = 1e9;
    for (int i = 1; i <= n; i++) if (mx[i] < ans){
       // printf("mx: %d %d\n",i, mx[i]);
        ans = mx[i];
    }
    int cnt = 0, p, q;
    for (int i = 1; i <= n; i++) if (mx[i] == ans){
        q = p; p = i; cnt++;
        //printf("%d\n", i);
    }
    if (cnt == 1){
        printf("%d %d\n%d %d\n", p, g[p][0], p, g[p][0]);
    }
    else{
        int u = q;
        for (auto v : g[p]) if (v != q) u = v;
        printf("%d %d\n%d %d\n", p, u, q, u);
    }
}
int main(){
    int T;
    scanf("%d", &T);
    while (T--){
        solve();
    }
}