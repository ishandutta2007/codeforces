#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const int N = 500000 + 10;
int n,m,k;
vector<LL> g[N];
LL c[N], par[N], vis[N], T, pw[N];
map<LL, vector< pair<int,int> > > vec;
int find(int x) {
    if(vis[x]!=T) {
        vis[x]=T; par[x]=x;
    }
    return par[x]==x ? x: par[x]=find(par[x]);
}
int main() {
    pw[0]=1;for(int i=1;i<N;i++) pw[i]=pw[i-1]*2LL%MOD;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++) {
        scanf("%lld",&c[i]);
    }
    for(int i=1;i<=m;i++) {
        int u,v; scanf("%d%d",&u,&v);
        vec[c[u]^c[v]].push_back(make_pair(u,v));
    }
    LL ans = 0; LL tot = (1LL<<k);
    for(auto v: vec) {
        ++ T; tot --;
        LL blk = n;
        for(auto p: v.second) {
            if (find(p.first) == find(p.second)) continue;
            par[find(p.first)] = par[find(p.second)]; blk --;
        }
        ans = (ans + pw[blk]) % MOD;
    }
    ans = ans + tot % MOD * pw[n] % MOD; ans %= MOD;
    cout << ans << endl;
}