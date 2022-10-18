#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define write(x) wt(x),putchar(10)
#define pos(x) (((x)-1)/SZ+1)
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
using namespace std;
const int N=4005;
const int M=2e6+5;
const int SZ=550;
const double eps=1e-9;
const int mod=1e9+7;
const int inf=0x3f3f3f3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void wt(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int inv[M],fac[M],ifc[M]; 
void Init(int n)
{
    inv[1]=1;for (int i=2;i<=n;i++) inv[i]=1ll*inv[mod%i]*(mod-mod/i)%mod;
    fac[0]=1;for (int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%mod;
    ifc[0]=1;for (int i=1;i<=n;i++) ifc[i]=1ll*ifc[i-1]*inv[i]%mod;
}
int C(int n,int m){if (m<0 || m>n) return 0;return 1ll*fac[n]*ifc[m]%mod*ifc[n-m]%mod;}

int n,m,ans,now;
int a[N],b[N],in[N];
bool vis[N];
vector<int> G[N];

bool dfs(int u,int fa)
{
	if (vis[u] || in[u]) return 1;if (now<a[u]) return 0;
	vis[u]=1;now+=b[u];
	for (int v:G[u]) if(v!=fa && dfs(v,u)) {vis[u]=0,in[u]=1;return 1;}
	vis[u]=0;now-=b[u];
	return 0;
}
bool chk(int x)
{
	for (int i=1;i<=n;i++) in[i]=0;
	in[1]=1,now=x;
	while(1)
    {
        for (int i=1;i<=n;i++) if (in[i]) for (int u:G[i]) if (!in[u]) if (dfs(u,i)) goto find;
		return 0;
		find:if (count(in+1,in+1+n,1)==n) return 1;
	}
}
void DOIT()
{
    rd(n);rd(m);ans=0;
    for (int i=1;i<=n;i++) G[i].clear();
    for (int i=2;i<=n;i++) rd(a[i]);for (int i=2;i<=n;i++) rd(b[i]);
    for (int i=1,x,y;i<=m;i++) rd(x),rd(y),G[x].push_back(y),G[y].push_back(x);
    int l=0,r=1e9;
    while (l<=r){int mid=(l+r)>>1;if (chk(mid)) r=mid-1,ans=mid;else l=mid+1;}
    cout<<ans+1<<endl;
}
signed main()
{
    int JYZ;rd(JYZ);while (JYZ--) DOIT();
}