
#include<bits/stdc++.h>
#define int long long
#pragma GCC optize("Ofast")
#pragma GCC optize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define wt(x) write(x)
#define pos(x) (((x)-1)/SZ+1)
#define endl "\n"
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define ls (rt<<1)
#define rs (rt<<1|1)
#define y1 _________
using namespace std;
const int N=2e5+5;
const int M=20;
const int SZ=450;
const int mod=998244353;
const int inf=0x3f3f3f3f3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int inv[N],fac[N],ifc[N]; 
void Init(int n)
{
    inv[1]=1;for (int i=2;i<=n;i++) inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    fac[0]=1;for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
    ifc[0]=1;for (int i=1;i<=n;i++) ifc[i]=ifc[i-1]*inv[i]%mod;
}
int C(int n,int m){if (m<0 || m>n) return 0;return fac[n]*ifc[m]%mod*ifc[n-m]%mod;}
void add(int &x,int y) {x+=y;if (x>=mod) x-=mod;}
int n,m,k,ans;
int d[N][M],t[N];
struct edge{int v,f;};
vector<int> G[2][N];
void bfs()
{
    memset(t,0x3f,sizeof(t));
    int l=N+1,r=N;int Q[N*2];t[1]=0;Q[++r]=1;
    while (l<=r)
    {
        int u=Q[l];l++;
        int f=t[u]&1;for (int v:G[0][u]) {if (f && t[v]>t[u]+1) t[v]=t[u]+1,Q[++r]=v;if (!f && t[v]>t[u]) t[v]=t[u],Q[--l]=v;}
        f^=1;for (int v:G[1][u]) {if (f && t[v]>t[u]+1) t[v]=t[u]+1,Q[++r]=v;if (!f && t[v]>t[u]) t[v]=t[u],Q[--l]=v;}
    }
}
pii Q[N*M];
void solve()
{
    memset(d,0x3f,sizeof(d));
    int l=1,r=0;d[1][0]=0;Q[++r]=mp(1,0);
    while (l<=r)
    {
        pii u=Q[l];l++;
        int f=u.se&1;
        for (int v:G[0][u.fi]) if (u.se+f-t[v]<20) if (d[v][u.se+f-t[v]]>d[u.fi][u.se-t[u.fi]]+1) d[v][u.se+f-t[v]]=d[u.fi][u.se-t[u.fi]]+1,Q[++r]=mp(v,u.se+f);
        f^=1;
        for (int v:G[1][u.fi]) if (u.se+f-t[v]<20) if (d[v][u.se+f-t[v]]>d[u.fi][u.se-t[u.fi]]+1) d[v][u.se+f-t[v]]=d[u.fi][u.se-t[u.fi]]+1,Q[++r]=mp(v,u.se+f);
    }
}
signed main()
{
    rd(n);rd(m);
    for (int i=1,x,y;i<=m;i++) rd(x),rd(y),G[0][x].push_back(y),G[1][y].push_back(x);
    bfs();solve();k=N;
    for (int i=0;i<20;i++)
    {
        if (t[n]+i<20)
        {
            if (k>=20) ans=d[n][i],k=t[n]+i;else 
            ans=min(ans+(1LL<<k),d[n][i]+(1LL<<t[n]+i))-1,k=0;
        } else 
        {
            if (t[n]+i<k) k=t[n]+i,ans=d[n][i];else 
            if (t[n]+i==k) ans=min(ans,d[n][i]);
        }
    }
    ans=(ans+ksm(2,k)+mod-1)%mod;
    cout<<ans<<"\n";

}