#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N=300000+10;
typedef long long LL;
int n;
LL dp[N],a[N],mx,cnt;
vector<int> g[N];
void dfs1(int u,int p){
    dp[u]=a[u];
    for(auto v: g[u]) {
        if(v==p)continue;
        dfs1(v,u); if(dp[v]>0)dp[u]+=dp[v];
    }
}
void dfs2(int u,int p){
    dp[u]=a[u];
    for(auto v:g[u]){
        if(v==p)continue;
        dfs2(v,u); if(dp[v]>0)dp[u]+=dp[v];
    }
    if(dp[u]==mx){
        dp[u]=0; cnt++;
    }
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<n;i++){
        int u,v;scanf("%d%d",&u,&v);
        g[u].push_back(v); g[v].push_back(u);
    }
    dfs1(1,1);
    mx = *max_element(dp+1,dp+1+n);
    dfs2(1,1);
    printf("%lld %lld\n", cnt*mx,cnt);
}