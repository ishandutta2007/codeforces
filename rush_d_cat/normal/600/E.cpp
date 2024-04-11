#include <iostream>
#include <vector>

using namespace std;
const int N = 100000+10;
typedef long long LL;

int n,col[N],par[N],son[N],sz[N],big[N];
vector<int> g[N];
LL ans[N];
void pre(int u,int p){
    par[u]=p, son[u]=0, sz[u]=1; 
    int mx=0;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==p) continue;
        pre(v,u); 
        sz[u] += sz[v];
        if(sz[v] > mx){
            mx=max(mx, sz[v]); son[u]=v;
        }
    }
}

int cnt[N],mx;LL sum;
void upd(int u,int p,int sgn) {
    cnt[col[u]] += sgn;
    if(sgn>0 && cnt[col[u]]>=mx){
        if(cnt[col[u]] > mx){
            sum=0, mx=cnt[col[u]];
        }
        sum += col[u];
    }
    for(auto v: g[u]){
        if(v!=p && big[v]==0)
            upd(v,u,sgn);
    }
}

void dfs(int u,int p,int keep){
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==p || v==son[u])continue;
        dfs(v,u,0);
    }
    if(son[u]) {
        dfs(son[u],u,1);
        big[son[u]]=1;
    }
    upd(u,p,1);
    ans[u]=sum;
    if(son[u]) big[son[u]]=0;
    if(keep==0) {
        upd(u,p,-1);
        sum=0; mx=0;
    }
}

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&col[i]);
    }
    for(int i=1;i<n;i++){
        int u,v; scanf("%d%d",&u,&v);
        g[u].push_back(v); g[v].push_back(u);
    }
    pre(1,1);
    dfs(1,1,1);
    for(int i=1;i<=n;i++)
        printf("%lld ", ans[i]);
}