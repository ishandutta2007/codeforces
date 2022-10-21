#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int N = 100050, INF = (int)1e9;
const int LOG_N = 17;
int root = 0;
int n,m,a,b;

set<int> G[N];
int parent[LOG_N][N];
int depth[N], par[N], sub[N], dis[N];

void dfs(int v, int p, int d){
    parent[0][v] = p;
    depth[v] = d;
    for(int nxt : G[v]){
        if(nxt != p) dfs(nxt, v, d+1);
    }
}

void init(int V){
    dfs(root, -1, 0);

    for(int k = 0; k+1 < LOG_N; k++){
        for(int v = 0; v < V; v++){
            if(parent[k][v] < 0) parent[k+1][v] = -1;
            else parent[k+1][v] = parent[k][parent[k][v]];
        }
    }
}

int lca(int u, int v){
    if(depth[u] > depth[v]){int tmp = u; u = v; v = tmp;}
    for(int k = 0; k < LOG_N; k++){
        if((depth[v] - depth[u]) >> k & 1){
            v = parent[k][v];
        }
    }
    if(u == v) return u;
    for(int k = LOG_N - 1; k >= 0; k--){
        if(parent[k][u] != parent[k][v]){
            u = parent[k][u];
            v = parent[k][v];
        }
    }
    return parent[0][u];
}

int min_dis(int u, int v){
    int ca = lca(u, v);
    return depth[u] + depth[v] - 2 * depth[ca];
}

int dfs1(int v, int p){
    sub[v] = 1;
    for(int nxt : G[v])
        if(nxt != p)
            sub[v] += dfs1(nxt, v);
    return sub[v];
}

int dfs2(int v, int p, int nn){
    for(int nxt : G[v]){
        if(nxt != p && sub[nxt] > nn/2) return dfs2(nxt, v, nn);
    }
    return v;
}

void decompose(int v, int p){
    dfs1(v, -1);
    int centroid = dfs2(v, -1, sub[v]);
    //if(p == -1) p = centroid;
    par[centroid] = p;
    for(int nxt : G[centroid]){
        G[nxt].erase(centroid);
        decompose(nxt, centroid);
    }
    G[centroid].clear();
}

void update(int v){
    int cur = v;
    while(1){
        dis[cur] = min(dis[cur], min_dis(v, cur));
        if(par[cur] == -1) break;
        cur = par[cur];
    }
}

int query(int v){
    int res = (int)1e9;
    int cur = v;
    while(1){
        res = min(dis[cur] + min_dis(v, cur), res);
        if(par[cur] == -1) break;
        cur = par[cur];
    }
    return res;
}


int main(){
    scanf("%d%d", &n, &m);
    fill(dis, dis+n, INF);
    for(int i = 0; i < n-1; i++){
        scanf("%d%d", &a, &b);
        a--, b--;
        G[a].insert(b);
        G[b].insert(a);
    }
    init(n);
    decompose(0, -1);
    update(0);

    for(int i = 0; i < m; i++){
        scanf("%d%d", &a, &b);
        b--;
        if(a == 1) update(b);
        else printf("%d\n", query(b));
    }

}