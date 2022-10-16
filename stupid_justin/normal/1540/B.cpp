#include<bits/stdc++.h>
#define int long long
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define wt(x) write(x)
#define pos(x) (((x)-1)/SZ+1)
using namespace std;
const int N=200+5;
const int M=15;
const int SZ=450;
const int mod=1e9+7;
const int inf=0x3f3f3f3f3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
void add(int &x,int y) {x+=y;if (x>=mod) x-=mod;}
int inv[N],fac[N],ifc[N]; 
void Init(int n)
{
    inv[1]=1;for (int i=2;i<=n;i++)inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    fac[0]=1;for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
    ifc[0]=1;for (int i=1;i<=n;i++) ifc[i]=ifc[i-1]*inv[i]%mod;
}
int C(int n,int m){if (m>n || m<0) return 0;return fac[n]*ifc[m]%mod*ifc[n-m]%mod;}
int n,ans,k;
vector<int> T[N];
int sz[N],vis[N],fa[N];
int a[N],cnt;
int P[N][N];
void dfs(int u,int f)
{
    sz[u]=1;fa[u]=f;
    for (int v:T[u]) if (v!=f) dfs(v,u),sz[u]+=sz[v];
}
void Dfs(int u,int f)
{
    sz[u]=1;
    for (int v:T[u]) if (v!=f && !vis[v]) Dfs(v,u),sz[u]+=sz[v];
}
int p(int u,int v)
{
    //u  v 
    // O(n) 
    //
    ///fn
    //
    //
    // x y 
    //
    //
    int ret=0;cnt=0;
    for (int i=1;i<=n;i++) vis[i]=0,sz[i]=0;
    dfs(v,0);ret+=sz[u]*inv[n]%mod;// u ,fa[i]);
    int x=u;while (x!=v) vis[x]=1,x=fa[x],a[++cnt]=x;vis[u]=vis[v]=1;cnt--;
    for (int i=1;i<=n;i++) sz[i]=0;
    for (int i=1;i<=cnt;i++)
    {
        Dfs(a[i],0);
        // sz[a[i]]/n 
        // u  i v  cnt+1-i
        ret+=sz[a[i]]*inv[n]%mod*P[i][cnt+1-i];ret%=mod;
    }
    return ret;
}
signed main()
{
    rd(n);Init(n+1);
    for (int i=0;i<=n;i++) P[0][i]=1,P[i][0]=0;
    for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) P[i][j]=(P[i-1][j]*inv[2]+P[i][j-1]*inv[2])%mod;
    for (int i=1,x,y;i<n;i++) rd(x),rd(y),T[x].push_back(y),T[y].push_back(x);
    //
    //
    for (int i=1;i<n;i++) for (int j=i+1;j<=n;j++) add(ans,p(j,i));
    cout<<ans<<endl;
}
/*

*/