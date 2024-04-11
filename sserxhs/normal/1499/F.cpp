#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
std::mt19937 rnd(time(0));
inline int sj(int n)
{
	unsigned int x=rnd();
	return x%n+1;
}
#define rand fst
template<typename typC> void read(register typC &x)
{
	register int c=getchar(),fh=1;
	while ((c<48)||(c>57))
	{
		if (c=='-') {c=getchar();fh=-1;break;}
		c=getchar();
	}
	x=c^48;c=getchar();
	while ((c>=48)&&(c<=57))
	{
		x=x*10+(c^48);
		c=getchar();
	}
	x*=fh;
}
template<typename typC> void write(register typC x)
{
	if (x<0) putchar('-'),x=-x;
	static int st[100];
	register int tp=1;
	register typC y;st[1]=x%10;x/=10;
	while (x) y=x/10,st[++tp]=x-y*10,x=y;++tp;
	while (--tp) putchar(st[tp]|48);
}
template<typename typC> void write(register typC *a,register int num)
{
	for (register int i=1;i<=num;i++) write(a[i]),putchar(i==num?10:32);
}
#define space(x) write(x),putchar(32)
#define enter(x) write(x),putchar(10)
const int N=5e3+2,M=1e6+2,p=998244353;
vector<int> lj[N];
inline void inc(register int &x,const int y)
{
	if ((x+=y)>=p) x-=p;
}
inline void dec(register int &x,const int y)
{
	if ((x-=y)<0) x+=p;
}
inline int ksm(register int x,register int y)
{
	register int r=1;
	while (y)
	{
		if (y&1) r=(ll)r*x%p;
		x=(ll)x*x%p;
		y>>=1;
	}
	return r;
}
int f[N],h[N],*g[N],dep[N],dp[N],md[N],dc[N];
int T,n,m,c,i,j,k,x,y,z,ans,la,cnt;
bool top[N];
void dfs1(int x)
{
	md[x]=dep[x];
	for (auto v:lj[x]) if (v!=f[x])
	{
		dep[v]=dep[f[v]=x]+1;dfs1(v);
		if (md[dc[x]]<md[v]) dc[x]=v,md[x]=md[v];
	}
	top[dc[x]]=0;
}
void dfs2(int x)
{
	g[dc[x]]=g[x]+1;for (auto v:lj[x]) if (v!=f[x]) dfs2(v);
}
void dfs3(int x)
{
	//printf("in %d\n",x);
	if (!dc[x]) return g[x][0]=1,void();
	dfs3(dc[x]);
	for (k=1;k<=min(m+1,md[x]-dep[x]);k++) inc(g[x][0],g[x][k]); 
	for (auto v:lj[x]) if (v!=f[x]&&v!=dc[x])
	{
		dfs3(v);memset(dp,0,m+1<<2);//printf("%d->%d\n",x,v);
		for (k=0;k<=min(m,md[x]-dep[x]);k++) for (j=0;j<=min(m-k-1,md[v]-dep[v]);j++) dp[max(j+1,k)]=(dp[max(j+1,k)]+(ll)g[x][k]*g[v][j])%p;
		//for (k=0;k<=m;k++) printf("%d ",dp[k]);puts("");
		for (k=0;k<=min(m,md[x]-dep[x]);k++) for (j=0;j<=min(m,md[v]-dep[v]);j++) dp[k]=(dp[k]+(ll)g[x][k]*g[v][j])%p;
		//for (k=0;k<=m;k++) printf("%d ",dp[k]);puts("");
		for (k=0;k<=min(m,md[x]-dep[x]);k++) g[x][k]=dp[k];
	}
}
int main()
{
	read(n);read(m);
	for (i=1;i<=n;i++) top[i]=1;
	for (i=1;i<n;i++) read(x),read(y),lj[x].push_back(y),lj[y].push_back(x);cnt=1;
	dfs1(dep[1]=1);for (i=1;i<=n;i++) if (top[i]) g[i]=h+cnt,cnt+=md[i]-dep[i]+1; dfs2(1);
	dfs3(1);ans=0;
	for (i=0;i<=min(m,md[1]-dep[1]);i++) inc(ans,g[1][i]);
	printf("%d\n",ans);
	//for (i=1;i<=n;i++) printf("%d: ",i),write(g[i]-1,md[i]-dep[i]+1);
}