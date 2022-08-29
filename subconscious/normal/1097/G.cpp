#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define rev(i,n) for(int i=n;i;--i)
#define x0 fuck
#define y0 fuxk
#define y1 fxck
#define x1 fxxk
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const int N=1e5+5,inf=0x3f3f3f3f,MOD=1e9+7;
const ld eps=1e-9;
int n,k;
vector<int>g[N];
int dp[N][205],siz[N],tp[205];
int c[N],d[N],ans=0;
int e[205],C[205][205];
void dfs(int x,int fa){
    siz[x]=0;dp[x][0]=1;
    for(auto v:g[x])if(v!=fa){
        dfs(v,x);
        memset(tp,0,sizeof tp);
        for(int i=0;i<=min(k,siz[x]);++i)
            for(int j=0;j<=min(k-i,siz[v]);++j)
                tp[i+j]=(tp[i+j]+1ll*dp[x][i]*dp[v][j])%MOD;
        siz[x]+=siz[v];
        for(int i=0;i<=min(k,siz[x]);++i)
            dp[x][i]=tp[i];
    }
    ++siz[x];
    if(x!=1)
    for(int i=min(k-1,siz[x]-1);i>=0;--i){
        int tmp=(i==0?1ll*dp[x][i]*d[siz[x]]:1ll*dp[x][i])%MOD;
        dp[x][i+1]=(dp[x][i+1]+tmp)%MOD;
        ans=(ans+1ll*(d[n-siz[x]]-1+MOD)%MOD*e[i+1]%MOD*tmp)%MOD;
        //printf("%d %d %d\n",d[n-siz[x]],e[i+1],tmp);
        //2ans=(ans+MOD-1ll*tmp)%MOD;
    }
    else{
        //int cnt=0;
        for(int i=min(k,siz[x]);i>=0;--i)ans=(ans+1ll*e[i]*dp[x][i])%MOD;
        //printf("%d\n",cnt);
    }
}
int pw(int x,int y){
    int s=1;
    for(;y;y>>=1,x=1ll*x*x%MOD)
        if(y&1)s=1ll*s*x%MOD;
    return s;
}
int main(){
    scanf("%d%d",&n,&k);
    c[0]=d[0]=1;
    rep(i,n)c[i]=c[i-1]*2%MOD,d[i]=c[i];
    for(int i=0;i<=n;++i)c[i]=pw(c[i],MOD-2);
    for(int i=0;i<=n;++i)
        d[i]=1ll*(d[i]-1+MOD)%MOD*c[i]%MOD;
    //rep(i,n)printf("%d\n",d[i]);
    C[0][0]=1;
    rep(i,k){
        C[i][0]=1;
        rep(j,i)C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
    }
    rep(i,k)rep(j,i)e[i]=(e[i]+((i+j)%2?MOD-1ll:1ll)*C[i][j]%MOD*pw(j,k))%MOD;
    rep(i,n-1){
        int x,y;scanf("%d%d",&x,&y);
        g[x].pb(y),g[y].pb(x);
    }
    dfs(1,0);
    printf("%lld\n",1ll*ans*pw(2,n)%MOD);
}