#include<bits/stdc++.h>
using namespace std;

#define N 100010
#define M 1000010
#define L 18

struct edge {
    int x, y, z;
    void in() {scanf("%d%d%d", &x, &y, &z);}
} e[M];

int id[M];
bool cmp(int i, int j) {return e[i].z < e[j].z;}

int f[N];
int find_rt(int x) {return x == f[x] ? x : f[x] = find_rt(f[x]);}

bool vis[M];
vector <int> adj[N];
int d[N], fa[N][L], mx[N][L], ans[M];

void dfs(int x, int pa) {
    fa[x][0] = pa;
    d[x] = d[pa] + 1;
    for(int i = 1; i < L; i ++) {
        int y = fa[x][i-1];
        fa[x][i] = fa[y][i-1];
        mx[x][i] = max(mx[x][i-1], mx[y][i-1]);
    }
    for(int i = 0; i < adj[x].size(); i ++) {
        int j = adj[x][i];
        int y = e[j].x ^ e[j].y ^ x;
        if(y == pa) continue;
        mx[y][0] = e[j].z;
        dfs(y, x);
    }
}

int anc(int x, int y) {
    if(!y) return x;
    for(int i = 31 - __builtin_clz(y); i >= 0; i --) if(y & (1<<i)) x = fa[x][i];
    return x;
}

int lca(int x, int y) {
    if(d[x] > d[y]) x = anc(x, d[x] - d[y]);
    else if(d[y] > d[x]) y = anc(y, d[y] - d[x]);
    if(x == y) return x;
    for(int i = 31 - __builtin_clz(d[x]); i >= 0; i --)
        if(fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
    return fa[x][0];
}

int climb(int x, int y) {
    y = d[x] - d[y];
    int ret = 0;
    if(!y) return ret;
    for(int i = 31 - __builtin_clz(y); i >= 0; i --) if(y & (1<<i)) {
        ret = max(ret, mx[x][i]);
        x = fa[x][i];
    }
    return ret;
}

int MX(int u, int v) {
    int w = lca(u, v);
    return max(climb(u, w), climb(v, w));
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i ++) e[i].in(), id[i] = i;
    sort(id + 1, id + m + 1, cmp);
    for(int i = 1; i <= n; i ++) f[i] = i;
    for(int i = 1; i <= m; i ++) {
        int j = id[i];
        int x = find_rt(e[j].x), y = find_rt(e[j].y);
        if(x == y) continue;
        vis[j] = 1;
        f[x] = y;
    }
    for(int i = 1; i <= m; i ++) if(vis[i]) adj[e[i].x].push_back(i), adj[e[i].y].push_back(i);
    dfs(1, 0);
    for(int i = 1; i <= m; i ++) if(!vis[i]) printf("%d ", ans[i] = MX(e[i].x, e[i].y));
    puts("");
}