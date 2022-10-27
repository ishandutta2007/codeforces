#include <iostream>
#include <vector>
using namespace std;
const int N=200000+10;
typedef long long LL;
int n,sz[N];
vector<int> g[N];
void getsz(int u,int p){
    sz[u]=1;
    for(auto v: g[u]){
        if(v==p)continue;
        getsz(v,u); sz[u]+=sz[v];
    }
}
LL ans=0;
void dfs(int u,int p,LL tmp){
    ans=max(ans,tmp);
    for(auto v:g[u]) {
        if(v==p)continue;
        dfs(v,u,tmp+n-2*sz[v]);
    }
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int u,v; scanf("%d%d",&u,&v);
        g[u].push_back(v); g[v].push_back(u);
    }
    getsz(1,1);
    LL tmp=0;
    for(int i=1;i<=n;i++){
        tmp+=sz[i];
    }
    dfs(1,1,tmp);
    cout<<ans<<endl;
}