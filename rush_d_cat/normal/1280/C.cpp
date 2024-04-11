#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
const int N=200000+10;
const LL inf=1e18;
int n; LL f[N],sz[N],w[N];
vector< pair<int,int> > g[N];
LL ans2=0;
void dfs(int u,int p){
    sz[u]=1;
    f[u]=0;
    for(auto e: g[u]) {
        int v=e.first; if(v==p)continue;
        w[v]=e.second;
        dfs(v,u);
        sz[u]+=sz[v];
        ans2+=1LL*min(n-sz[v],sz[v])*e.second;
        f[u]+=f[v];
    }
    if(sz[u]%2==1) f[u]+=w[u];
    //printf("u = %d, %lld\n", u, f[u]);
}

int main(){
    int t;scanf("%d",&t);
    while(t--){
        scanf("%d",&n); n*=2; ans2=0;
        for(int i=1;i<=n;i++){
            g[i].clear(); f[i]=inf;
        }
        for(int i=1;i<n;i++){
            int u,v,w; scanf("%d%d%d",&u,&v,&w);
            g[u].push_back(make_pair(v,w));
            g[v].push_back(make_pair(u,w));
        }
        dfs(1,1);
        printf("%lld %lld\n", f[1],ans2);
    }
}