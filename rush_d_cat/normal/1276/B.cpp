#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const int N=200000+10;
vector<int> g[N];
int t,n,m,a,b,par[N],sz[N];
bool vis[N];
int find(int x){
    return par[x]==x?x:par[x]=find(par[x]);
}
LL cac(){
    LL ans=0;
    for(int i=1;i<=n;i++)par[i]=i,sz[i]=1;
    for(int u=1;u<=n;u++){
        if(vis[u])continue;
        for(auto v:g[u]){
            if(vis[v])continue;
            if(find(u)!=find(v)){
                sz[find(v)]+=sz[find(u)];
            }
            par[find(u)]=find(v);
        }
    }
    sz[find(a)]--, sz[find(b)]--;
    for(int i=1;i<=n;i++)if(find(i)==i)ans+=1LL*sz[i]*(sz[i]-1)/2;
    for(int i=1;i<=n;i++){
        //printf("%d: %d\n", i, find(i));
    }
    return ans;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d",&n,&m,&a,&b);
        for(int i=1;i<=n;i++){
            vis[i]=0; g[i].clear();
        }
        for(int i=1;i<=m;i++){
            int u,v; 
            scanf("%d%d",&u,&v);
            g[u].push_back(v); g[v].push_back(u);
        }

        vis[a]=1; cac(); LL f1=(n-2)-sz[find(b)];
        vis[a]=0; vis[b]=1; cac(); LL f2=(n-2)-sz[find(a)];
        //printf("# %lld %lld\n", f1,f2);
        printf("%lld\n", f1*f2);
    }
}