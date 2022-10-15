#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef pair<int,int> pi;
typedef long long ll;
const int M=998244353;
const int maxn=2e5+13;
vector <pi> G[maxn];
int n,a[maxn],dp[maxn][4],f[maxn],g[maxn],h[maxn];
void add(int &x,int y){x+=y;if(x>=M)x-=M;}
void dfs(int u,int fa){
    int pos=0,m=G[u].size();
    for (int i=1;i<=m;i++){
        pi e=G[u][i-1]; int v=e.S;
        if (v==fa) {continue;}
        a[v]=e.F; dfs(v,u);
        //if (u==1)cout<<'!'<<v<<' '<<i<<' '<<f[i]<<' '<<g[i]<<' '<<h[i]<<endl;
    }
    for (int i=1;i<=m;i++){
        pi e=G[u][i-1]; int v=e.S;
        if (e.F<a[u]) pos=i;
        if (v==fa) {f[i]=1;g[i]=1;h[i]=1;continue;}
        f[i]=(dp[v][0]+dp[v][2])%M; g[i]=(dp[v][1]+dp[v][3])%M;
        h[i]=((ll)dp[v][0]+dp[v][1]+dp[v][2])%M;
    }
    g[0]=1; for (int i=1;i<=m;i++) g[i]=1ll*g[i-1]*g[i]%M;
    h[m+1]=1; for (int i=m;i;i--) h[i]=1ll*h[i+1]*h[i]%M;
    for (int i=1;i<=pos;i++){
        if (G[u][i-1].S==fa) continue;
        add(dp[u][1],1ll*f[i]*g[i-1]%M*h[i+1]%M);
    }
    for (int i=pos+1;i<=m;i++){
        if (G[u][i-1].S==fa) continue;
        add(dp[u][2],1ll*f[i]*g[i-1]%M*h[i+1]%M);
        //if (u==1)cout<<i<<' '<<f[i]<<' '<<g[i-1]<<' '<<h[i+1]<<endl;
    }
    dp[u][0]=g[m];
    dp[u][3]=1ll*g[pos]*h[pos+1]%M;
    //cout<<u<<' '<<dp[u][0]<<' '<<dp[u][1]<<' '<<dp[u][2]<<' '<<dp[u][3]<<endl;
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<n;i++){
        int u,v;scanf("%d%d",&u,&v);
        G[u].pb((pi){i,v});
        G[v].pb((pi){i,u});
    }
    for (int i=1;i<=n;i++) sort(G[i].begin(),G[i].end());
    a[1]=0; dfs(1,0);
    printf("%lld\n",((ll)dp[1][0]+dp[1][1]+dp[1][2])%M);
    return 0;
}