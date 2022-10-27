#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
const int N=100000+10;

int n; vector< pair<int,int> > g[N];
int sz[N],par[N],w[N];
void dfs(int u,int p) {
    sz[u]=1; par[u]=p;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i].first; if(v==p)continue;
        w[v]=g[u][i].second;
        dfs(v,u); sz[u]+=sz[v];
    }
}
LL f(LL x){
    return x*(x-1)*(x-2)/6;
}
int uu[N],vv[N],ww[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d%d%d",&uu[i],&vv[i],&ww[i]);
        g[uu[i]].push_back(make_pair(vv[i],ww[i]));
        g[vv[i]].push_back(make_pair(uu[i],ww[i]));
    }
    dfs(1,0);
    double ans=0;
    for(int i=1;i<=n;i++) {
        double p = 1 - (1.0 * f(sz[i]) + f(n-sz[i])) / f(n);
        ans += 2 * p * w[i];
    }
    //printf("ans = %.8f\n", ans);
    int q; scanf("%d",&q);
    while(q--) {
        int x,y; scanf("%d%d",&x,&y);
        int u = (par[uu[x]]==vv[x])?uu[x]:vv[x];
        double p = 1 - (1.0 * f(sz[u]) + f(n-sz[u])) / f(n);
        //printf("(%d,%d) u=%d, w=%d\n",uu[x],vv[x], u,w[u]);
        ans -= 2 * p * w[u]; w[u] = y; ans += 2 * p * w[u];
        printf("%.8f\n", ans);
    }
}