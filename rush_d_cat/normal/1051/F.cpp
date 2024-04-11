#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 100000 + 100;
const LL INF = 1e16;
int n,m,q;
vector< pair<int,int> > g[N];
LL min(LL x, LL y) {
    return x<y?x:y;
}
int par[N];
int find(int x) {
    return par[x]==x?x:par[x]=find(par[x]);
}
struct Edge {
    int u,v,w,id;
    bool operator < (const Edge & o) const {
        return w < o.w;
    }
} edge[N];

LL dis[42][N];int src;
LL f[42][42];
void dfs(int u,int p) {
    for(int i=0;i<g[u].size();i++) {
        int v=g[u][i].first; if(p==v) continue;
        dis[src][v] = dis[src][u] + g[u][i].second;
        dfs(v, u);
    }
}
LL dep[N],sum[N],fa[N][20];
void pre(int u,int p) {
    for(int i=0;i<g[u].size();i++) {
        int v=g[u][i].first; if(p==v) continue;
        sum[v] = sum[u] + g[u][i].second; 
        dep[v] = dep[u] + 1;
        fa[v][0] = u;
        pre(v, u);
    }
}
void init() {
    for(int i=1;i<20;i++) {
        for(int j=1;j<=n;j++) {
            fa[j][i] = fa[fa[j][i-1]][i-1];
        }
    }
}
int lca(int u,int v) {
    if(dep[u] < dep[v]) swap(u, v);
    int dd = dep[u]-dep[v];
    for(int i=0;i<20;i++) {
        if(dd>>i&1) u=fa[u][i];
    }
    if(u==v) return u;
    for(int i=19;i>=0;i--) {
        if(fa[u][i]!=fa[v][i]) {
            u=fa[u][i], v=fa[v][i];
        }
    }
    return fa[u][0];
}
LL getdis(int u,int v) {
    int p = lca(u,v);
    return sum[u]+sum[v]-2*sum[p];
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) par[i]=i;
    for(int i=1;i<=m;i++) {
        int u,v,w; scanf("%d%d%d",&u,&v,&w);
        edge[i].u = u, edge[i].v = v, edge[i].w = w;
    }
    sort(edge+1,edge+1+m);

    vector<int> vec, rt; 
    
    for(int i=1;i<=m;i++) {
        if(find(edge[i].u) != find(edge[i].v)) {
            g[edge[i].u].push_back(make_pair(edge[i].v, edge[i].w));
            g[edge[i].v].push_back(make_pair(edge[i].u, edge[i].w));
            par[find(edge[i].u)] = find(edge[i].v);
        } else {
            vec.push_back(i);
            rt.push_back(edge[i].u);
            rt.push_back(edge[i].v);
        }
    }
    sort(rt.begin(), rt.end());
    rt.erase(unique(rt.begin(), rt.end()), rt.end());

    for(int i=0;i<rt.size();i++) {
        src = i;
        dfs(rt[i], -1);
    }
    for(int i=0;i<rt.size();i++) {
        for(int j=0;j<rt.size();j++) {
            f[i][j] = (i==j)?0:INF;
        }
    }
    for(int i=0;i<rt.size();i++) {
        for(int j=0;j<rt.size();j++) {
            f[i][j] = dis[i][rt[j]];
        }
    }
    for(int i=0;i<vec.size();i++) {
        int u = edge[vec[i]].u; u = lower_bound(rt.begin(), rt.end(), u) - rt.begin();
        int v = edge[vec[i]].v; v = lower_bound(rt.begin(), rt.end(), v) - rt.begin();
        f[u][v] = min(f[u][v], edge[vec[i]].w);
        f[v][u] = f[u][v];
    }
    for(int k=0;k<rt.size();k++) {
        for(int i=0;i<rt.size();i++) {
            for(int j=0;j<rt.size();j++) {
                f[i][j] = min(f[i][k]+f[k][j], f[i][j]);
            }
        }
    }
    pre(1, 1); init();
    scanf("%d",&q);
    //for(int i=1;i<=n;i++) printf("%d %d\n", i, sum[i]);
    while(q--) {
        int u,v; scanf("%d%d",&u,&v);
        LL ans = getdis(u,v);
        //printf("%d %d %d\n", u, v, lca(u,v));
        for(int i=0;i<rt.size();i++){
            for(int j=0;j<rt.size();j++) {
                ans = min(ans, dis[i][u]+dis[j][v]+f[i][j]);
            }
        }
        printf("%lld\n", ans);
    }
}
/*
4 4
1 2 1
2 3 1
3 4 1
4 1 2
10
2 3
*/