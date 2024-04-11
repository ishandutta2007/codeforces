#include<bits/stdc++.h>
#define MAXN 30005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q;
P w[MAXN],h[MAXN];
int pos[MAXN];
ll f[3][MAXN];
ll dp[MAXN];
void calc(int v)
{
    f[0][v]=f[1][v]=f[2][v]=-INF;
    if(w[v].S!=h[v].S) f[0][v]=1LL*w[v].F*h[v].F;
    if(v<=n-1&&w[v].S!=h[v+1].S&&w[v+1].S!=h[v].S) f[1][v]=1LL*w[v].F*h[v+1].F+1LL*w[v+1].F*h[v].F;
    if(v<=n-2&&w[v].S!=h[v+2].S&&w[v+1].S!=h[v].S&&w[v+2].S!=h[v+1].S)
    {
        f[2][v]=1LL*w[v].F*h[v+2].F+1LL*w[v+1].F*h[v].F+1LL*w[v+2].F*h[v+1].F;
    }
    if(v<=n-2&&w[v].S!=h[v+1].S&&w[v+1].S!=h[v+2].S&&w[v+2].S!=h[v].S)
    {
        f[2][v]=max(f[2][v],1LL*w[v].F*h[v+1].F+1LL*w[v+1].F*h[v+2].F+1LL*w[v+2].F*h[v].F);
    }
}
void solve()
{
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        dp[i]=-INF;
        for(int j=0;j<=2;j++)
        {
            if(j+1>i) break;
            dp[i]=max(dp[i],dp[i-j-1]+f[j][i-j]);
        }
    }
}
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&w[i].F);
        w[i].S=i;
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&h[i].F);
        h[i].S=i;
    }
    sort(w+1,w+n+1,greater<P>());
    sort(h+1,h+n+1,greater<P>());
    for(int i=1;i<=n;i++) pos[h[i].S]=i;
    for(int i=1;i<=n;i++) calc(i);
    solve();
    for(int i=0;i<q;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        swap(h[pos[u]].S,h[pos[v]].S);
        swap(pos[u],pos[v]);
        for(int i=max(1,pos[u]-2);i<=pos[u];i++) calc(i);
        for(int i=max(1,pos[v]-2);i<=pos[v];i++) calc(i);
        solve();
        printf("%lld\n",dp[n]);
    }
    return 0;
}