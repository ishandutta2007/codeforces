#include <iostream>
#include <vector>
using namespace std;

const int N=300000+10;
typedef long long LL;
const LL INF = 1e16;
vector< pair<int,int> > g[N];
int n,w[N];
LL f[N],s[N];
LL dp[N];
LL premx[N],sufmx[N],ans[N];

void dfs(int u,int p){
    dp[u]=s[u]-f[u];
    //printf("ret[%d]=%d\n", u,dp[u]);
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i].first;
        if(v==p)continue;
        f[v]=f[u]+g[u][i].second;
        s[v]=s[u]+w[v];
        dfs(v,u);
        dp[u]=max(dp[u],dp[v]);
    }
    
    premx[0]=-INF,sufmx[g[u].size()+1]=-INF;
    for(int i=0;i<g[u].size();i++){
        if(g[u][i].first==p) {
            premx[i+1]=premx[i]; continue;
        }        
        premx[i+1]=max(premx[i],dp[g[u][i].first]);
    }
    for(int i=(int)g[u].size()-1;i>=0;i--){
        if(g[u][i].first==p) {
            sufmx[i+1]=sufmx[i+2]; continue;
        } 
        sufmx[i+1]=max(sufmx[i+2],dp[g[u][i].first]);
    }

    ans[u]=-INF;

    for(int i=1;i<(int)g[u].size();i++){
        ans[u]=max(ans[u],premx[i]+sufmx[i+1]);
    }
    ans[u]=max(ans[u],s[u]-f[u]+sufmx[1]);
    ans[u]=ans[u]-(2*s[u]-w[u]-2*f[u]); 

}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    for(int i=1;i<n;i++){
        int u,v,w; scanf("%d%d%d",&u,&v,&w);
        g[u].push_back(make_pair(v,w)); g[v].push_back(make_pair(u,w));
    }
    s[1]=w[1];
    dfs(1,1);
    LL ret=0;
    for(int i=1;i<=n;i++)ret=max(ret,ans[i]),ret=max(ret,(LL)w[i]);
    cout<<ret<<endl;
}