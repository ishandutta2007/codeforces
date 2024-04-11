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
const int N=1e6+2,M=1e6+2,p=998244353;
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
struct P
{
	int v,w,c,wz;
	P(int a=0,int b=0,int C=0,int d=0):v(a),w(b),c(C),wz(d){}
	bool operator<(const P &o) const {return c<o.c;}
};
struct Q
{
	int u,v,w,c,wz;
	bool operator<(const Q &o) const {return w<o.w;}
};
Q lb[N];
P b[N];
int ans[N];
vector<int> lj[M];
vector<P> bel[N];
int dfn[M],low[M],st[M],fa[M];
int T,n,m,c,i,j,k,x,y,z,la,l,r,mid,tp,cnt,fs,ds;
bool ed[M];
void dfs(int x)
{
	dfn[x]=low[x]=++cnt;
	ed[st[++tp]=x]=1;
	for (auto v:lj[x]) if (!dfn[v]) dfs(v),low[x]=min(low[x],low[v]); else if (ed[v]) low[x]=min(low[x],dfn[v]);
	if (dfn[x]==low[x])
	{
		++fs;
		while (st[tp+1]!=x)
		{
			fa[st[tp]]=fs;
			ed[st[tp--]]=0;
		}
	}
}
bool pd(int lim)
{
	assert(tp==0);
	bool flg=1;
	memset(dfn+1,0,ds<<2);cnt=fs=0;//0:,1:
	for (i=lim+1;i<=m;i++) lj[lb[i].wz+m].push_back(lb[i].wz);
	for (i=1;i<=ds;i++) if (!dfn[i]) dfs(i);
	for (i=1;i<=m&&flg;i++) if (fa[i]==fa[i+m]) flg=0;
	for (i=lim+1;i<=m;i++) lj[lb[i].wz+m].pop_back();
	return flg;
}
int main()
{
	read(n);read(m);
	for (i=1;i<=m;i++) read(lb[i].u),read(lb[i].v),read(lb[i].c),read(lb[i].w),lb[i].wz=i;
	sort(lb+1,lb+m+1);
	for (i=1;i<=m;i++) bel[lb[i].u].push_back(P(lb[i].v,lb[i].w,lb[i].c,lb[i].wz)),bel[lb[i].v].push_back(P(lb[i].u,lb[i].w,lb[i].c,lb[i].wz));
	ds=m<<1;
	for (i=1;i<=n;i++) if (bel[i].size())
	{
		sort(bel[i].begin(),bel[i].end());
		for (j=0;j<bel[i].size();j=k)
		{
			k=j+1;
			while (k<bel[i].size()&&bel[i][k].c==bel[i][j].c) ++k;
			if (k-j>2) return puts("No"),0;
			if (k==j+2)
			{
				lj[bel[i][j].wz].push_back(bel[i][j+1].wz+m);
				lj[bel[i][j+1].wz+m].push_back(bel[i][j].wz);
				lj[bel[i][j+1].wz].push_back(bel[i][j].wz+m);
				lj[bel[i][j].wz+m].push_back(bel[i][j+1].wz);
			}
		}
		for (j=0;j<bel[i].size();j++) lj[ds+j+1].push_back(bel[i][j].wz);
		for (j=1;j<bel[i].size();j++) lj[ds+j+1].push_back(ds+j);ds+=bel[i].size();
		for (j=0;j<bel[i].size();j++) lj[ds+j+1].push_back(bel[i][j].wz);
		for (j=1;j<bel[i].size();j++) lj[ds+j].push_back(ds+j+1);ds-=bel[i].size();
		for (j=0;j<bel[i].size();j++)
		{
			if (j) lj[bel[i][j].wz+m].push_back(ds+j);
			if (j+1<bel[i].size()) lj[bel[i][j].wz+m].push_back(ds+bel[i].size()+j+2);
		}
		ds+=bel[i].size()<<1;
	}
	l=0;r=m;
	while (l<r)
	{
		mid=l+r>>1;
		if (pd(mid)) r=mid; else l=mid+1;
	}
	if (pd(l))
	{
		puts("Yes");cnt=0;
		for (i=1;i<=m;i++) if (fa[i]>fa[i+m]) ans[++cnt]=i;
		printf("%d %d\n",lb[l].w,cnt);
		for (i=1;i<=cnt;i++) printf("%d%c",ans[i],i==cnt?10:32);
	} else puts("No");
}