#include <bits/stdc++.h>
#define pii pair<int, int >
#define LL long long
using namespace std;
const int N = 1e5 + 7, M = 1e6 + 7;
const LL MOD = 1e9 + 7;

int a[M], c[N], L[N], R[N], type[N], par[N][20], dep[N], n, m, cnt = 0;
vector<pii > p[N], g[N];
LL b[M];

void dfs(int x, int fa, int r){
    par[x][0] = fa; dep[x] = dep[fa] + 1; type[x] = r;
    L[x] = ++cnt;
    for (pii v : p[x]) if (v.first != fa){
        dfs(v.first, x, v.second);
    }
    R[x] = cnt;
}
int lca(int u, int v){
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = 19; i >= 0; i--) if ((dep[u] - dep[v]) >> i & 1) u = par[u][i];
    if (u == v) return u;
    for (int i = 19; i >= 0; i--) if (par[u][i] != par[v][i]) u = par[u][i], v = par[v][i];
    return par[u][0];
}
int lowbit(int x) {return x & -x;}
void add(int x, int y){
    while (x <= n){
        c[x] += y;
        x += lowbit(x);
    }
}
int get(int x){
    int y = 0;
    while (x > 0){
        y += c[x];
        x -= lowbit(x);
    }
    return y;
}

long long ans = 0;
void gao(int op){
    int cnt = 0;
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 0; i < m; i++){
        int u = a[i], v = a[i + 1];
        int lc = lca(u, v);
        if (op == 1){
            g[R[u]].push_back({L[u], 1});
            g[R[lc]].push_back({L[lc], -1});
        } else {
            g[R[v]].push_back({L[v], 1});
            g[R[lc]].push_back({L[lc], -1});
        }
    }
    for (int i = 1; i <= n; i++) if (type[i] == op){
        g[R[i]].push_back({L[i], i});
    }
    for (int i = 1; i <= n; i++) c[i] = 0;
    for (int i = 1; i <= n; i++){
        for (pii v : g[i]) if (v.second <= 1){
            add(v.first, v.second);
        }
        for (pii v : g[i]) if (v.second > 1){
            int t = get(i) - get(v.first - 1);
            ans = (ans + b[t] - 1 + MOD) % MOD;
        }
    }
}

int main(){
    b[0] = 1;
    for (int i = 1; i < M; i++) b[i] = b[i - 1] * 2 % MOD;
    scanf("%d", &n);
    for (int i = 1; i < n; i++){
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        p[u].push_back({v, w}); p[v].push_back({u, -w});
    }
    dfs(1, 0, 0);
    for (int i = 1; i < 20; i++){
        for (int j = 1; j <= n; j++){
            par[j][i] = par[par[j][i - 1]][i - 1];
        }
    }
    scanf("%d", &m); a[0] = 1;
    for (int i = 1; i <= m; i++) scanf("%d", &a[i]);
    gao(1);
    gao(-1);
    printf("%lld", ans);
    return 0;
}