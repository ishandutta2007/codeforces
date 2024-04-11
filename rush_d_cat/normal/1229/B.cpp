#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 100000 + 10;
const LL MOD = 1e9 + 7;
int n; LL a[N],dep[N];
vector<int> G[N];
LL par[N][20], g[N][20];

LL gcd(LL x,LL y) {
    return y==0?x:gcd(y,x%y);
}

void dfs(int u,int p) {
    dep[u]=dep[p]+1; 
    par[u][0]=p; g[u][0]=a[u];
    for(auto v: G[u]){
        if(v==p)continue;
        dfs(v,u);
    }
}

LL ans=0;
pair<int,LL> go(int u,LL val) {
    int p1 = u; LL pre = 0;
    for(int i=18;i>=0;i--){
        if(gcd(g[u][i],val) == val) {
            u = par[u][i];
        }
    }
    return make_pair(u, gcd(val, a[u]));
}

int main() {
    scanf("%d", &n);    
    for(int i=1;i<=n;i++) {
        scanf("%lld", &a[i]);
    }
    for(int i=1;i<n;i++){
        int u,v; scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    dfs(1,0);
    for(int i=1;i<20;i++)for(int j=1;j<=n;j++){
        par[j][i]=par[par[j][i-1]][i-1];
        g[j][i] = gcd(g[j][i-1], g[par[j][i-1]][i-1]);
    }
    for(int i=1;i<=n;i++) {
        int now=i,las=now; LL val=a[i];
        while(now) {
            pair<int,LL> tmp = go(i,val);
            ans = ans + val * (dep[las] - dep[tmp.first]) % MOD;
            ans = (ans % MOD + MOD) % MOD;
            now = tmp.first; val=tmp.second; las = now;
        }
        //printf("i=%d, ans = %lld\n", i ,ans);
    }
    cout << ans << endl;
}