#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MOD=1e9+7;
const int N=100000+10;
namespace BIT{
    int bit[N],Time[N],CLOCK;
    void add(int pos,int v){
        while(pos<N){
            if(Time[pos]!=CLOCK) Time[pos]=CLOCK,bit[pos]=0;
            bit[pos]+=v; pos+=pos&(-pos);
        }
    }
    int sum(int pos){
        int ans=0;
        while(pos>0){
            if(Time[pos]!=CLOCK) Time[pos]=CLOCK,bit[pos]=0;            
            ans+=bit[pos]; pos-=pos&(-pos);
        }
        return ans;
    }
    void Rebirth(){
        CLOCK++;
    }
};

vector<int> g[N];
int n,q,k,m,r,a[N],h[N],par[N][20],dep[N],vis[N];
int dfn[N],out[N],C;
bool cmp(int x,int y){
    return h[x]<h[y];
}
void dfs(int u,int p){
    dfn[u]=++C; dep[u]=dep[p]+1;
    par[u][0]=p;
    for(auto v:g[u]){
        if(v==p)continue;
        dfs(v,u);
    }
    out[u]=C;
}
int lca(int u,int v){
    if(dep[u]<dep[v])swap(u,v);
    int d=dep[u]-dep[v];
    for(int i=19;i>=0;i--){
        if(d>>i&1)u=par[u][i];
    }
    if(u==v) return u;
    for(int i=19;i>=0;i--){
        if(par[u][i]!=par[v][i]){
            u=par[u][i], v=par[v][i];
        }
    }
    return par[u][0];
}
int dp[N][302];
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<n;i++){
        int u,v; scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,1);
    for(int i=1;i<20;i++)
        for(int j=1;j<=n;j++)
            par[j][i]=par[par[j][i-1]][i-1];
    while(q--){
        scanf("%d%d%d",&k,&m,&r);
        for(int i=1;i<=k;i++){
            scanf("%d",&a[i]); vis[a[i]]=1;
        }
        BIT::Rebirth();
        for(int i=1;i<=k;i++){
            BIT::add(dfn[a[i]], 1);
            BIT::add(out[a[i]]+1, -1);
        }
        for(int i=1;i<=k;i++){
            h[a[i]] = BIT::sum(dfn[a[i]]) + BIT::sum(dfn[r]) - 2*BIT::sum(dfn[lca(a[i], r)]) + vis[lca(a[i], r)] - 1;
        }
        for(int i=1;i<=k;i++){
            vis[a[i]]=0;
        }

        sort(a+1,a+1+k,cmp);
        dp[0][0] = 1;
        for(int i=1;i<=k;i++){
            for(int j=1;j<=m;j++){
                if (j>=h[a[i]])
                    dp[i][j] = (dp[i-1][j-1] + 1LL * dp[i-1][j] * (j - h[a[i]])) % MOD;
                else
                    dp[i][j] = 0;
            }
        }
        int ans=0;
        for(int i=1;i<=m;i++)
            ans=(ans+dp[k][i])%MOD;
        printf("%d\n", ans);
    }
}