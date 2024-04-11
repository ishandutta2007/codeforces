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
const int N=2e5+2,M=8e5+2,inf=1e9;
Q q[N];
int l[M],r[M],s[2][M],lz[M];
int a[N],b[N],ans1[N],ans2[N],pa[N];
int T,n,m,c,i,j,k,x,y,z,dt,ans,la,ksiz,ks;
void pushup(int x)
{
	int c=x<<1;
	s[0][x]=min(s[0][c],s[0][c|1]);
	s[1][x]=max(s[1][c],s[1][c|1]);
}
void pushdown(int x)
{
	if (lz[x])
	{
		int c=x<<1;
		lz[c]+=lz[x];s[0][c]+=lz[x];s[1][c]+=lz[x];c|=1;
		lz[c]+=lz[x];s[0][c]+=lz[x];s[1][c]+=lz[x];lz[x]=0;
	}
}
void build(int x)
{
	lz[x]=0;
	if (l[x]==r[x]) return s[0][x]=s[1][x]=l[x],void();
	int c=x<<1;
	l[c]=l[x];r[c]=l[x]+r[x]>>1;
	l[c|1]=r[c]+1;r[c|1]=r[x];
	build(c);build(c|1);
	pushup(x);
}
void mdf(int x)
{
	if (z<=l[x]&&r[x]<=y)
	{
		lz[x]+=dt;s[0][x]+=dt;s[1][x]+=dt;
		return;
	}
	pushdown(x);
	int c=x<<1;
	if (z<=r[c]) mdf(c);
	if (y>r[c]) mdf(c|1);
	pushup(x);
}
void sol1(int x)
{
	if (z<=l[x]&&r[x]<=y)
	{
		la=max(la,s[1][x]);
		return;
	}
	pushdown(x);
	int c=x<<1;
	if (z<=r[c]) sol1(c);
	if (y>r[c]) sol1(c|1);
}
void sol2(int x)
{
	if (z<=l[x]&&r[x]<=y)
	{
		la=min(la,s[0][x]);
		return;
	}
	pushdown(x);
	int c=x<<1;
	if (z<=r[c]) sol2(c);
	if (y>r[c]) sol2(c|1);
}
void sol3(int x)
{
	if (z<=l[x]&&r[x]<=y)
	{
		la+=s[0][x];
		return;
	}
	pushdown(x);
	int c=x<<1;
	if (z<=r[c]) sol3(c);
	if (y>r[c]) sol3(c|1);
}
vector<int> bel[N];
int flg;
void sol(int *ans)
{
	int i,j,k;
	for (i=1;i<=n;i++) bel[i].clear();
	for (i=1;i<=n;i++) bel[a[i]].push_back(i);
	r[l[1]=1]=n;build(1);
	for (k=1;k<=n;k++) if (bel[k].size())
	{
		for (auto u:bel[k])
		{
			z=u,y=n;pa[k]=u;la=-n;sol1(1);x=la;
			//if (k==1) cout<<x<<endl;
			if (pa[k]==1)
			{
				ans[pa[k]]=(x-flg)/2;
				continue;
			}
			z=1;y=pa[k]-1;la=0;sol2(1);x-=la;
			//if (k==1) cout<<x<<endl;
			ans[pa[k]]=(x-flg)/2;
		}
		for (auto u:bel[k]) z=u,y=n,dt=-2,mdf(1);
	}
}
int main()
{
	//ios::sync_with_stdio(false);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	T=1;
	read(n,a,n);
	sol(ans1);
	//write(ans1,n);
	for (i=1;i<=n;i++) a[i]=n-a[i]+1;flg=1;
	sol(ans2);
	//write(ans2,n);
	for (i=1;i<=n;i++) cout<<max(ans1[i],ans2[i])<<" \n"[i==n];
}