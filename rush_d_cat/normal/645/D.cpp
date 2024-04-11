#include <iostream>
#include <vector>
const int N = 100000+10;
using namespace std;
vector<int> g[N]; 
int n,m,vis[N],dp[N],in[N],u[N],v[N];
int dfs(int u){
    if(vis[u]) return dp[u];
    vis[u]=1; dp[u]=1;
    for(auto v:g[u]){
        if(vis[v]==1) {
            printf("-1\n"); exit(0);
        }
        dfs(v);
        dp[u]=max(dp[u], 1+dp[v]);
    }
    vis[u]=2;
}
bool check(int x){
    for(int i=1;i<=n;i++) g[i].clear(), in[i]=0, vis[i]=0, dp[i]=0;
    for(int i=1;i<=x;i++) g[u[i]].push_back(v[i]), in[v[i]]++;
    for(int i=1;i<=n;i++){
        if(in[i]==0){
            dfs(i); return dp[i]==n?1:0;
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&u[i],&v[i]);
    }
    if(!check(m)) {
        return !printf("-1\n");
    }
    int l=0,r=m;
    while(r-l>1){
        int mid=(l+r)>>1;
        if(check(mid))
            r=mid;
        else
            l=mid;
    }
    cout<<r<<endl;
}