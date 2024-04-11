
#include<bits/stdc++.h>
#define int long long
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define wt(x) write(x)
#define pos(x) (((x)-1)/SZ+1)
#define endl "\n"
#define pii pair<int,int>
#define fi first
#define mp make_pair
#define ls (rt<<1)
#define rs (rt<<1|1)
#define y1 _________
using namespace std;
const int N=2e5+5;
const int M=70;
const int SZ=450;
const int mod=1e9+7;
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
vector<int> T[N];
int n,m,k,ans;
bool flag;
int f[N];
int tmp[N],cnt;
void dfs(int u,int fa)
{
    int mx=0,se=0,tot=0;
	for (int v:T[u]) if (v!=fa) {dfs(v,u);tot++;f[u]=min(f[u],f[v]+1);if (f[v]+1>mx) se=mx,mx=f[v]+1;else if(f[v]+1>se) se=f[v]+1;}
	if (tot==0){f[u]=0;return;}
	if (u==1){if (tot==1) ans=max(ans,mx);else ans=max(ans,max(se+1,mx));}
	else if(tot>=2) ans=max(ans,mx+1);
}
void DOIT()
{
    ans=0;rd(n);for (int i=1;i<=n;i++) T[i].clear(),f[i]=inf;
    for (int i=1,u,v;i<n;i++) rd(u),rd(v),T[u].push_back(v),T[v].push_back(u);
    dfs(1,0);
    cout<<ans<<"\n";
}
signed main()
{
    int JYZ;rd(JYZ);while (JYZ--) DOIT();
}
/*

*/