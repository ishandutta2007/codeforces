
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
#define se second
#define mp make_pair
#define ls (rt<<1)
#define rs (rt<<1|1)
#define y1 _________
using namespace std;
const int N=2e6+5;
const int M=70;
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
vector<int> f[1505];
int n,m;
int fa[N],cnt[N],sz[N];
struct Edge{int u,v,w;}e[N];bool cmp(Edge a,Edge b){return a.w<b.w;}
int getfa(int x){if (x==fa[x]) return x;return fa[x]=getfa(fa[x]);}
vector<int> tmp;
signed main()
{
    rd(n);
	for (int i=1;i<=n;i++)
    {
		fa[i]=i,sz[i]=1,f[i].resize(2),f[i][1]=1;
		for (int j=1,x;j<=n;j++){rd(x);if (i<j) e[++m]={i,j,x};}
	}
	sort(e+1,e+m+1,cmp);
	for (int i=1;i<=m;i++)
    {
		int u=getfa(e[i].u),v=getfa(e[i].v);
		if (u==v){cnt[v]++;if(cnt[v]==sz[v]*(sz[v]-1)/2) f[v][1]=(f[v][1]+1)%mod;continue;}
		fa[u]=v,cnt[v]+=cnt[u]+1,sz[v]+=sz[u];
		tmp.clear();tmp.resize(f[u].size()+f[v].size()-1);
		for (int j=0;j<f[u].size();j++) for (int k=0;k<f[v].size();k++) tmp[j+k]=(tmp[j+k]+f[u][j]*f[v][k])%mod;
		f[v]=tmp;if (cnt[v]==sz[v]*(sz[v]-1)/2) f[v][1]=(f[v][1]+1)%mod;
	}
	for (int i=1,u=getfa(1);i<=n;i++) cout<<f[u][i]<<" ";cout<<endl;
}