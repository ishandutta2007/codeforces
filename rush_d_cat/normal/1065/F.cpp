#include <iostream>
#include <vector>
using namespace std;
const int N = 1000000 + 10;
vector<int> g[N];
int f[N],dp[N],d[N],n,k,p[N];
void dfs(int u) {
    if(g[u].size()==0){
        f[u]=1;d[u]=0;dp[u]=1;
        return;
    }
    d[u]=N;int sum=0;
    for(auto v: g[u]){
        dfs(v);d[u]=min(d[u],d[v]+1);
        sum+=f[v];
    }
    for(auto v: g[u]){
        dp[u]=max(dp[u],dp[v]+sum-f[v]);
    }
    if(d[u]<k) f[u]=sum;
    //printf("dp[%d]=%d\n", u,dp[u]);
}
int main() {
    scanf("%d%d",&n,&k);
    for(int i=2;i<=n;i++){
        scanf("%d",&p[i]);
        g[p[i]].push_back(i);
    }
    dfs(1); cout<<dp[1]<<endl;
}