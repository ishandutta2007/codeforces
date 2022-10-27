#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
typedef long long LL;
const int N=3002;
int n;
int sz[N],dis[N][N],f[N][N];
vector<int> g[N];
void dfs1(int u,int p,int rt){
    if(u!=p) dis[rt][u]=dis[rt][p]+1;
    sz[u]=1;
    for(auto v:g[u]){
        if(v==p)continue;
        dfs1(v,u,rt);
        sz[u]+=sz[v];
    }   
}
int mx[N];
void dfs2(int u,int p,int rt1,int rt2){
    f[rt2][u]=f[u][rt2]=sz[u]*(n-sz[rt1]);
    for(auto v:g[u]){
        if(v==p)continue;
        dfs2(v,u,rt1,rt2);
    }   
}

LL dp[N][N];
LL solve(int u,int v){
    //printf("dis[%d][%d] = %d\n", u,v,dis[u][v]);
    if(dp[u][v]) return dp[u][v];
    if(u==v) return 0;
    for(auto x: g[u]) {
        if(dis[x][v]+1==dis[u][v]){
            dp[u][v]=max(solve(x,v)+f[u][v],dp[u][v]);
        }
    }
    for(auto x: g[v]) {
        if(dis[u][x]+1==dis[u][v]){
            dp[u][v]=max(solve(u,x)+f[u][v],dp[u][v]);
        }
    }
    //printf("dp[%d][%d] = %d\n", u,v,dp[u][v]);
    return dp[u][v];
}

int main() {
    scanf("%d", &n);
    for(int i=1;i<n;i++){
        int u,v; scanf("%d%d",&u,&v);
        g[u].push_back(v); 
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        memset(sz,0,sizeof(sz));
        dfs1(i,i,i);
        for(auto v: g[i]) {
            dfs2(v,i,v,i);
        }
    }
    LL ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            ans=max(ans,solve(i,j));
        }
    }
    cout<<ans<<endl;
}