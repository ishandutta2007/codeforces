#include <bits/stdc++.h>
using namespace std;

struct LowestCommonAncestor{
    int n,h;
    vector<vector<int>> G,par;
    vector<int> dep;
    LowestCommonAncestor(int n):n(n),G(n),dep(n){
        h=1;
        while((1<<h)<=n) ++h;
        par.assign(h,vector<int>(n,-1));
    }
    void add_edge(int u,int v){
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    void dfs(int v,int p,int d){
        par[0][v]=p;
        dep[v]=d;
        for (int u:G[v]){
            if (u!=p) dfs(u,v,d+1);
        }
    }
    void build(int r=0){
        dfs(r,-1,0);
        for (int k=0;k<h-1;++k) for (int v=0;v<n;++v){
            if (par[k][v]>=0) par[k+1][v]=par[k][par[k][v]];
        }
    }
    int lca(int u,int v){
        if (dep[u]>dep[v]) swap(u,v);
        for (int k=0;k<h;++k){
            if ((dep[v]-dep[u])&1<<k) v=par[k][v];
        }
        if (u==v) return u;
        for (int k=h-1;k>=0;--k){
            if (par[k][u]!=par[k][v]) u=par[k][u],v=par[k][v];
        }
        return par[0][u];
    }
    int distance(int u,int v){
        return dep[u]+dep[v]-dep[lca(u,v)]*2;
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    LowestCommonAncestor LCA(n);
    for (int i=0;i<n-1;++i){
        int u,v; cin >> u >> v;
        LCA.add_edge(--u,--v);
    }
    LCA.build();
    for (;m--;){
        int k; cin >> k;
        vector<int> p(k);
        for (int i=0;i<k;++i){
            int v; cin >> v; --v;
            p[i]=(v==0?0:LCA.par[0][v]);
        }
        sort(p.begin(),p.end(),[&](int u,int v){return LCA.dep[u]<LCA.dep[v];});
        int now=0,ok=1;
        for (int i=0;i<k;++i){
            if (LCA.lca(now,p[i])!=now){
                ok=0; break;
            }
            now=p[i];
        }
        cout << (ok?"YES":"NO") << '\n';
    }
}