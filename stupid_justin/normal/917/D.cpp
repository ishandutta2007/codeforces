#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define wt(x) write(x)
using namespace std;
const int N=8000+5;
const int M=2e6+5;
const int mod=1e9+7;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(1ll*ret*x)%z;x=(1ll*x*x)%z;y>>=1;}return ret;}
int fac[N],inv[N];
void Init(int n)
{
    fac[0]=1;for (int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%mod;
    inv[n]=ksm(fac[n]);for (int i=n-1;i>=0;i--) inv[i]=1ll*inv[i+1]*(i+1)%mod;
}
int C(int x,int y){return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;}
vector<int>T[N];
int sz[N];
void add(int &x,int y){x+=y;if (x>=mod) x-=mod;}
void dec(int &x,int y){x-=y;if (x<0) x+=mod;}
int mul(int x,int y){return 1ll*x*y%mod;}
vector<int>f[N][2];
void dfs(int u,int fa)
{
    f[u][0].push_back(1);f[u][1].push_back(1);sz[u]=1;
    for (int v:T[u]) if (v!=fa)
    {
        dfs(v,u);auto &h=f[v],&w=f[u];
        static int T[2][N];
        for (int i=0;i<sz[u];i++) T[0][i]=w[0][i],T[1][i]=w[1][i],w[0][i]=w[1][i]=0;
        w[0].resize(sz[u]+sz[v]);w[1].resize(sz[u]+sz[v]);
        for (int i=0;i<sz[u];i++) for (int j=0;j<sz[v];j++)
        {
            add(w[0][i+j+1],mul(T[0][i],h[0][j]));
            add(w[1][i+j+1],mul(T[1][i],h[0][j]));
            add(w[1][i+j+1],mul(T[0][i],h[1][j]));
            add(w[0][i+j],mul(T[0][i],h[1][j]));
            add(w[1][i+j],mul(T[1][i],h[1][j]));
        }
        sz[u]+=sz[v];h[0].clear();h[1].clear();
    }
}

int n,ans[N];
int main()
{
    Init(N-1);rd(n);
    for (int i=1,u,v;i<n;i++) rd(u),rd(v),T[u].push_back(v),T[v].push_back(u);
    dfs(1,0);for (int i=0;i<n-1;i++) ans[i]=mul(f[1][1][i],ksm(n,n-i-2));
    ans[n-1]=1;for (int i=n-1;i>=0;i--) for (int j=i+1;j<n;j++) dec(ans[i],mul(ans[j],C(j,i)));
    for (int i=0;i<n;i++) cout<<ans[i]<<" ";cout<<"\n";
}