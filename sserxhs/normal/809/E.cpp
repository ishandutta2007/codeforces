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
template<typename typC, typename... Args> void read(typC &first, Args& ... args) {
	read(first);
	read(args...);
}
template<typename typC> void read(register typC *a,int num)
{
	for (register int i=1;i<=num;i++) read(a[i]);
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
struct Q
{
	int u,v;
	Q(int a=0,int b=0):u(a),v(b){}
	bool operator<(const Q &o) const {return v<o.v;}
};
const int N=2e5+2;
vector<int> lj[N];
char s[N];
int a[N],b[N],phi[N],ss[N],top[N],hc[N],siz[N],dep[N],f[N],dfn[N],st[N],g[N],mu[N],inp[N];
int T,n,m,c,i,j,k,x,y,z,ans,gs,na,la,tp;
void dfs1(int x)
{
	siz[x]=1;
	for (auto v:lj[x]) if (v!=f[x])
	{
		f[v]=x;dep[v]=dep[x]+1;
		dfs1(v);siz[x]+=siz[v];
		if (siz[v]>siz[hc[x]]) hc[x]=v;
	}
}
void dfs2(int x)
{
	dfn[x]=++m;
	if (hc[x])
	{
		top[hc[x]]=top[x];
		dfs2(hc[x]);
		for (auto v:lj[x]) if (v!=f[x]&&v!=hc[x]) dfs2(top[v]=v);
	}
}
int lca(int x,int y)
{
	while (top[x]!=top[y]) if (dep[top[x]]>dep[top[y]]) x=f[top[x]]; else y=f[top[y]];
	if (dep[x]<dep[y]) return x;return y;
}
void add(int x,int y)
{
	lj[x].push_back(y);
}
void ins(int x)
{
	if (tp==0)
	{
		st[tp=1]=x;
		return;
	}
	int ance=lca(st[tp],x);
	while (tp>1&&dep[ance]<dep[st[tp-1]])
	{
		add(st[tp-1],st[tp]);
		--tp;
	}
	if (dep[ance]<dep[st[tp]]) add(ance,st[tp--]);
	if (!tp||st[tp]!=ance) st[++tp]=ance;
	st[++tp]=x;
}
bool cmp(int &x,int &y)
{
	return dfn[x]<dfn[y];
}
void dfs3(int x)
{
	na=(na+(ll)siz[x]*siz[x]%p*dep[x])%p;
	for (auto v:lj[x])
	{
		dfs3(v);
		na=(na+2ll*siz[x]*siz[v]%p*dep[x])%p;
		inc(siz[x],siz[v]);
	}
}
void dfs4(int x)
{
	for (auto v:lj[x]) dfs4(v);
	siz[x]=0;lj[x].clear();
}
int dis(int x,int y)
{
	return dep[x]+dep[y]-dep[lca(x,y)]*2;
}
int main()
{
	read(n);phi[1]=1;mu[1]=1;
	for (i=2;i<=n;i++)
	{
		if (!phi[i]) phi[ss[++gs]=i]=i-1,mu[i]=-1;
		for (j=1;j<=gs&&i*ss[j]<=n;j++)
		{
			if (i%ss[j]==0) {phi[i*ss[j]]=phi[i]*ss[j];break;}
			phi[i*ss[j]]=phi[i]*(ss[j]-1);
			mu[i*ss[j]]=-mu[i];
		}
	}
	for (i=1;i<=n;i++)
	{
		inp[i]=ksm(phi[i],p-2);
		if (mu[i]<0) mu[i]=p-1;
	}
	for (i=1;i<=n;i++) for (j=1;j*i<=n;j++) g[j*i]=(g[j*i]+(ll)mu[j]*inp[i]%p*i)%p;
	for (i=1;i<=n;i++) read(a[i]),b[a[i]]=i;
	for (i=1;i<n;i++) read(x,y),add(x,y),add(y,x);
	dfs1(dep[1]=1);dfs2(top[1]=1);
	for (i=1;i<=n;i++) siz[i]=0,lj[i].clear();
	for (i=1;i<=n;i++)
	{
		na=m=tp=la=0;
		for (j=i;j<=n;j+=i) a[++m]=b[j],siz[b[j]]=phi[j],inc(na,phi[j]),la=(la+(ll)phi[j]*dep[b[j]])%p;
		la=(ll)la*na%p;na=0;
		sort(a+1,a+m+1,cmp);
		if (a[1]!=1) st[tp=1]=1;
		for (j=1;j<=m;j++) ins(a[j]);
		if (tp) while (--tp) add(st[tp],st[tp+1]);
		dfs3(1);dfs4(1);
		ans=(ans+(ll)(p+la-na)*g[i])%p;
	}
	ans=(ll)ans*ksm((ll)n*(n-1)/2%p,p-2)%p;
	write(ans);
}