#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 200000+10;
int n;LL a[N];
LL up[N],down[N],sum[N];
vector<int> g[N];

void dfs(int u,int p){
    sum[u]=a[u];
    LL sumdown=0;
    for(auto v: g[u]){
        if(v==p)continue;
        dfs(v,u); sum[u]+=sum[v];
        down[u] += down[v] + sum[v];
        sumdown += down[v];
    }
    //printf("down[%d]=%d\n", u,down[u]);
    for(auto v: g[u]){
        if(v==p)continue;
        up[v] = (sumdown - down[v]) + a[u] + (sum[u]-a[u]-sum[v]) * 2;
        //printf("up[%d]=%d\n", v,up[v]);
    }
}
void dfs2(int u,int p){
    for(auto v:g[u]){
        if(v==p)continue;
        up[v]+=up[u]+sum[1]-sum[u];
        dfs2(v,u);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<n;i++){
        int u,v; scanf("%d%d",&u,&v);
        g[u].push_back(v); g[v].push_back(u);
    }
    dfs(1,1); dfs2(1,1);
    LL ans=0;
    for(int i=1;i<=n;i++)ans=max(ans,up[i]+down[i]);
    cout<<ans<<endl;
}