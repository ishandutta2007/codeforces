#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
#define range(x) (x).begin(),(x).end()
std::mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
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
template<typename typC> void read(register typC *a,int num)
{
	for (register int i=1;i<=num;i++) read(a[i]);
}
template<typename typC, typename... Args> void read(typC &first, Args& ... args) {
	read(first);
	read(args...);
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
template<typename typC> typC ab(register typC x)
{
	if (x<0) return -x;
	return x;
}
#define space(x) write(x),putchar(32)
#define enter(x) write(x),putchar(10)
const int p=1e9+7;
const db eps=1e-9;
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
priority_queue<int> ONLYYFORRCOPYY;
priority_queue<int,vector<int>,greater<int> > ONLYYFORRCOPYY__;
struct Q
{
	int u,v;
	Q(int a=0,int b=0):u(a),v(b){}
	bool operator<(const Q &o) const {return v<o.v;}
};
const int N=1e3+2,M=1e6+2,inf=1e9;
char s[N];
int a[N],b[N],dep[N],dfn[N],siz[N],hc[N],top[N],f[N],g[N][N];
int T,n,m,c,i,j,k,x,y,z,la,ksiz,ks,ans,na,id;
bool ed[N];
vector<int> lj[N];
void dfs(int x)
{
	hc[x]=0;
	ed[x]=1;dfn[x]=++id;siz[x]=1;
	for (auto u:lj[x]) if (!ed[u])
	{
		dep[u]=dep[x]+1;f[u]=x;
		dfs(u);siz[x]+=siz[u];
		if (siz[u]>siz[hc[x]]) hc[x]=u;
	}
	ed[x]=0;
}
void dfss(int x)
{
	if (hc[x])
	{
		top[hc[x]]=top[x];
		dfss(hc[x]);
		for (auto u:lj[x]) if (u!=hc[x]&&u!=f[x]) dfss(top[u]=u);
	}
}
int lca(int x,int y)
{
	while (top[x]!=top[y]) if (dep[top[x]]<dep[top[y]]) y=f[top[y]]; else x=f[top[x]];
	if (dep[x]<dep[y]) return x; return y;
}
bool pd(int x,int y)
{
	return dfn[x]<=dfn[y]&&dfn[x]+siz[x]>dfn[y];
}
int main()
{
	//ios::sync_with_stdio(false);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	T=1;
	read(n);
	for (i=1;i<n;i++) read(x,y),lj[x].push_back(y),lj[y].push_back(x);
	for (i=1;i<=n;i++) g[i][0]=1,g[0][i]=0;
	for (i=1;i<=n;i++) for (j=1;j<=n;j++) g[i][j]=(ll)(g[i-1][j]+g[i][j-1])*ksm(2,p-2)%p;
	for (i=1;i<=n;i++)
	{
		id=0;//printf("%d\n",i);
		f[i]=0;
		dep[i]=1;dfs(i);dfss(top[i]=i);
		for (j=1;j<=n;j++) for (k=1;k<j;k++) if (pd(j,k)) inc(ans,1); else if (!pd(k,j))
		{
			z=lca(j,k);
			x=dep[j]-dep[z];
			y=dep[k]-dep[z];
			inc(ans,g[y][x]);//printf("%d %d %d: %d/%d\n",j,k,z,x,y);
		}
		//space(i);enter(ans);
	}
	ans=(ll)ans*ksm(n,p-2)%p;
	enter(ans);
}