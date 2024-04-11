
 #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int INF = 1e9 + 7;
const int N=100000+10;
bool ok[N<<1];
int n,q; vector<int> g[N];
int par[N],son[N],dep[N],sz[N],dfn[N],out[N],top[N],CLOCK;
bool cmp(int x,int y){
    return dfn[x]<dfn[y];
}
void pre(int u,int p) {
    par[u]=p,son[u]=0,dep[u]=dep[p]+1,sz[u]=1; int mx=0;
    for(auto v: g[u]) {
        if(p==v) continue;
        pre(v,u); sz[u]+=sz[v]; if(sz[v]>mx) mx=sz[v], son[u]=v;
    }
}
void dfs(int u,int p){
    top[u]=p;dfn[u]=++CLOCK;
    if(son[u]) dfs(son[u],p);
    for(auto v:g[u]) if(v!=par[u]&&v!=son[u]) dfs(v,v);
    out[u]=CLOCK;
}
int Lca(int u,int v){
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]])swap(u,v);
        u=par[top[u]];
    }
    if(dep[u]>dep[v]) swap(u,v); return u;
}
namespace Tree {
    vector<int> v;//nodes
    int top,stk[N];
    vector<int> G[N];//fake tree
    void add(int u,int v) {
        G[u].push_back(v);
    }
    void buildFakeTree(){
        sort(v.begin(),v.end(),cmp);
        int sz = v.size();
        for(int i=0;i<sz-1;i++) {
            int lca = Lca(v[i],v[i+1]); v.push_back(lca);
        }

        sort(v.begin(),v.end(),cmp);
        stk[top=1]=v[0];
  
        for(int i=1;i<v.size();i++) {
            if(v[i]==v[i-1])continue;
            while(top&&out[stk[top]]<dfn[v[i]]) top--;
            add(stk[top],v[i]); stk[++top]=v[i]; 
        }
    }
    LL dp[N][2];
    void solve(int u){
        dp[u][0]=dp[u][1]=0; 
        if(G[u].size()==0) {
            if(ok[u]) dp[u][0]=INF, dp[u][1]=0;
            return;
        }
        if(ok[u]==0) {
            LL sum=0,mx=0;
            for(auto v: G[u]) {
                solve(v);
                dp[u][0] += dp[v][0];
                sum += min(dp[v][1],dp[v][0]);
                mx = max(mx, dp[v][0]-dp[v][1]);
            }
            dp[u][1]=dp[u][0]-mx;
            dp[u][0]=min(dp[u][0],sum+1);
        } else {
            for(auto v: G[u]){
                solve(v);
                dp[u][1]+=min(dp[v][1]+1, dp[v][0]);
            }
            dp[u][0]=INF;
        }
        G[u].clear();
    }
};
using namespace Tree;
int main() {
    scanf("%d",&n);
    for(int i=1;i<n;i++) {
        int u,v; scanf("%d%d",&u,&v);
        g[u].push_back(v); g[v].push_back(u);
    }
    pre(1,1); dfs(1,1);

    scanf("%d",&q);
    while(q--) {
        int k; scanf("%d",&k);
        v.clear(); 
        while(k--) {
            int x; scanf("%d",&x); v.push_back(x); ok[x]=1;
        }
        bool gg = 0;
        for(auto x: v) {
            if(ok[par[x]] && x!=1) {
                gg = 1;
            }
        }
        if (gg) {
            for(auto x: v) ok[x]=0; 
            printf("-1\n");
            continue;
        }

        buildFakeTree(); solve(v[0]);
        printf("%lld\n", min(dp[v[0]][1],dp[v[0]][0]));
        for(auto x: v) ok[x]=0;
    }
}