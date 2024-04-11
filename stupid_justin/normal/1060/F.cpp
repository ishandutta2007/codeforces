#include<bits/stdc++.h>
#define int long long
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define wt(x) write(x)
using namespace std;
const int N=55;
const int mod=1e9+7;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if (x<0){putchar('-');x=-x;}if (x>=10)write(x/10);putchar(x%10+'0');}
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
int n;
vector<int> T[N];
double c[N][N];
double f[N][N],g[N][N],tmp[N];
int sz[N];
void dfs(int u,int fa)
{
	for (int v:T[u]) if (v!=fa) dfs(v,u);
	sz[u]=1;f[u][0]=1;
	for (int v:T[u]) if (v!=fa)
	{
		memset(tmp,0,sizeof(tmp));
		for (int i=0;i<sz[u];i++) for (int j=0;j<=sz[v];j++) tmp[i+j]+=f[u][i]*g[v][j];
		memcpy(f[u],tmp,sizeof(tmp));
        sz[u]+=sz[v];
	}
    for (int i=0;i<=sz[u];i++) g[u][i]=f[u][i];
    for (int i=0;i<=sz[u];i++) for (int j=0;j<i;j++) g[u][i]+=(c[sz[u]-j-1][i-j-1]*f[u][j])/(c[i-1][i-j-1]*i*2);
}
signed main()
{
	rd(n);
	for (int i=0;i<=n;i++){c[i][0]=c[i][i]=1;for (int j=1;j<i;j++) c[i][j]=c[i-1][j-1]+c[i-1][j];}
	for (int i=1,x,y;i<=n-1;i++) rd(x),rd(y),T[x].push_back(y),T[y].push_back(x);
	for (int i=1;i<=n;i++) memset(f,0,sizeof(f)),memset(g,0,sizeof(g)),dfs(i,0),printf("%.10lf\n",f[i][n-1]);
}
//