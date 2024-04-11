
#include<bits/stdc++.h>
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
const int N=1e5+5;
const int M=500;
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
int n,ans;
int p[N],a[N],R[N],sg[N];
bool v[N];
struct DSU
{
	int fa[N],w[N];
	void init(int n){for(int i=1;i<=n;i++) fa[i]=i,w[i]=0;}
	int getfa(int x){if (x==fa[x]) return x;return fa[x]=getfa(fa[x]);}
	void merge(int l,int r,int c){for(int i=getfa(l);i<r;i=fa[i]=getfa(i+1)) w[i]=c;}
}D[M];
int solve()
{
    int ret=0;
	rd(n);memset(p,0,sizeof(p));memset(v,0,sizeof(v));sg[n]=0;
	for (int i=1;i<=n;i++) rd(a[i]),p[a[i]]=i;
	for (int i=N-1;i>=0;i--) if(!p[i]) p[i]=p[i+1];
	for (int i=1;i<M;i++) D[i].init(n);
	for (int i=n-1,j;i>=1;i--)
    {
		R[1]=n;for (j=1;D[j].w[i];j++) R[j+1]=min(R[j],D[j].w[i]);sg[i]=j;
		for (int r=i,l;j;--j,r=l) l=p[max(2*a[i]-a[R[j]]+1,0)],D[j].merge(l,r,i);
	}
	for (int i=1;i<=n;i++) v[sg[i]]=1;
	while (v[ret]) ret++;return ret;
}
signed main()
{
    int JYZ;rd(JYZ);while (JYZ--) ans^=solve();
    if (ans) puts("YES");else puts("NO");
}
/*

*/