#include <iostream>
#include <vector>
using namespace std;
const int N=500000+10;
const int INF=1e9+7;
typedef long long LL;
vector<int> g[N]; int n,a[N],par[N][22],deg[N];
void dfs(int u,int p){
    par[u][0]=p;
    for(auto v:g[u]){
        if(v==p)continue;
        dfs(v,u);
    }
}
LL ans=0;
void upd(int u){
    LL mx=3e18;
    for(int i=0;i<22;i++){
        LL dt = a[par[u][i]] - a[par[u][0]] + (LL)i * a[par[u][i]];
        mx=min(mx,dt);
    }
    ans += mx;
}
void solve(int u,int p){
    for(auto v:g[u]){
        if(v==p)continue;
        solve(v,u);
    }
    upd(u);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<n;i++){
        int u,v;scanf("%d%d",&u,&v);
        g[u].push_back(v);g[v].push_back(u);deg[u]++,deg[v]++;
    }
    int mn=INF,rt;
    for(int i=1;i<=n;i++){
        ans+=(LL)a[i]*deg[i];
        if(a[i]<mn){
            mn=a[i],rt=i;
        }
    }
    dfs(rt,rt);
    for(int i=1;i<22;i++){
        for(int j=1;j<=n;j++){
            par[j][i]=par[par[j][i-1]][i-1];
        }
    }
    solve(rt,rt);
    cout<<ans<<endl;
}