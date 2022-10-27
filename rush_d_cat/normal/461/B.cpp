#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
const LL MOD = 1e9+7;
const int N=100000+10;
int n,p[N],a[N],sz[N];
vector<int> g[N];

LL dp[N][2];
LL mpow(LL a, LL x) {
    if(x==0)return 1;
    LL t=mpow(a,x>>1);
    if(x%2==0)return t*t%MOD;
    return t*t%MOD*a%MOD;
}
void dfs(int u){
    if(a[u]) {
        sz[u]=1; dp[u][1]=1; dp[u][0]=0;
    } else {
        dp[u][0]=1;
    }


    LL sum=1;
    for(auto v:g[u]){
        dfs(v); 
        if(sz[v] == 0) continue;
        sz[u]+=sz[v];
        dp[u][0] = dp[u][0] * (dp[v][1] + dp[v][0]) % MOD;
        sum = (sum * (dp[v][0] + dp[v][1])) % MOD;
    }
    for(auto v:g[u]){
        if(sz[v] == 0) continue;
        if(a[u]==0)
            dp[u][1] = (dp[u][1] + sum * mpow(dp[v][0]+dp[v][1], MOD-2) % MOD * dp[v][1]) % MOD;
    }
    if(a[u]) dp[u][1]=sum;
    //if(sz[u]) printf("dp[%d] = (%d,%d)\n", u,dp[u][0],dp[u][1]);
}

int main(){
    scanf("%d", &n);
    for(int i=1;i<n;i++){
        scanf("%d",&p[i]); g[p[i]].push_back(i);
    }
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    dfs(0);
    cout<<dp[0][1]<<endl;
}