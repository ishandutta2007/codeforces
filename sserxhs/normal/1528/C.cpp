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
	if (num<=0) puts("");
	for (register int i=1;i<=num;i++) write(a[i]),putchar(i==num?10:32);
}
template<typename typC> typC ab(register typC x)
{
	if (x<0) return -x;
	return x;
}
#define space(x) write(x),putchar(32)
#define enter(x) write(x),putchar(10)
#define debug(x,y) printf("%s: ",#x),write(x,y)
const int p=998244353;
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
	bool operator<(const Q &o) const {return u<o.u;}
};
set<Q> s;
const int N=1e6+2,M=1e6+2,inf=1e9;
int a[N],b[N],dfn[N],low[N];
int T,n,m,c,i,j,k,x,y,z,ans,la,ksiz,ks,cnt;
vector<int> lj[N];
void dfs1(int x)
{
	dfn[x]=low[x]=++cnt;
	for (auto u:lj[x]) dfs1(u),low[x]=max(low[x],low[u]);
}
void dfs2(int x)
{
	int y=0;
	auto u=s.lower_bound(dfn[x]);
	if (u!=s.end()&&dfn[u->v]<=dfn[x]) y=u->v,s.erase(u);
	s.insert(Q(low[x],x));
	ans=max(ans,(int)s.size());
	for (auto u:lj[x]) dfs2(u);
	s.erase(Q(low[x],x));
	if (y) s.insert(Q(low[y],y));
}
int main()
{
	//ios::sync_with_stdio(false);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	T=1;
	read(T);
	while (T--)
	{
		read(n);read(a+1,n-1);read(b+1,n-1);
		for (i=1;i<=n;i++) lj[i].clear();cnt=0;
		for (i=2;i<=n;i++) lj[b[i]].push_back(i);
		dfs1(1);s.erase(range(s));ans=0;
		for (i=1;i<=n;i++) lj[i].clear();
		for (i=2;i<=n;i++) lj[a[i]].push_back(i);
		dfs2(1);enter(ans);
	}
}