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
typedef pair<int,int> pa;
const int N=2e5+2,M=8e5+2;
const ll inf=9e18;
ll s[M],lz[M],tot,ans[N];
int a[N],b[N],l[M],r[M];
vector<pa> lj[N];
int n,m,q,i,x,y,z,dt;
struct heap
{
	priority_queue<ll,vector<ll>,greater<ll> > p,q;
	heap(){while (!p.empty()) p.pop();while (!q.empty()) q.pop();}
	void push(ll x)
	{
		if (!q.empty()&&q.top()==x)
		{
			q.pop();
			while (!q.empty()&&p.top()==q.top()) p.pop(),q.pop();
		}else p.push(x);
	}
	void pop(ll x)
	{
		if (p.top()==x)
		{
			p.pop();
			while (!q.empty()&&p.top()==q.top()) p.pop(),q.pop();
		} else q.push(x);
	}
	ll top()
	{
		return p.empty()?inf:p.top();
	}
};
void build(int x)
{
	if (l[x]==r[x]) return s[x]=b[l[x]],void();
	int c=x<<1;
	l[c]=l[x];r[c]=l[x]+r[x]>>1;
	l[c|1]=r[c]+1;r[c|1]=r[x];
	build(c);build(c|1);
	s[x]=min(s[c],s[c|1]);
}
void mdf(int x)
{
	if (z<=l[x]&&r[x]<=y) return s[x]+=dt,lz[x]+=dt,void();
	int c=x<<1;
	if (lz[x])
	{
		lz[c]+=lz[x];lz[c|1]+=lz[x];
		s[c]+=lz[x];s[c|1]+=lz[x];
		lz[x]=0;
	}
	if (z<=r[c]) mdf(c);
	if (y>r[c]) mdf(c|1);
	s[x]=min(s[c],s[c|1]);
}
heap p;
int main()
{
	read(n);read(m);read(q);
	for (i=1;i<n;i++) read(a[i]),read(b[i+1]);
	while (m--) read(x),read(y),read(z),lj[x].push_back(pa(y,z)),tot+=z;
	r[l[1]=1]=n;build(1);
	for (i=1;i<=n;i++)
	{
		for (auto [u,v]:lj[i]) if (u) z=1,y=u,dt=v,mdf(1);
		p.push(a[i]+(ans[i]=s[1]));
	}
	enter(min(tot,p.top()));
	while (q--)
	{
		read(x);read(y);
		p.pop(a[x]+ans[x]);
		a[x]=y;
		p.push(a[x]+ans[x]);
		enter(min(tot,p.top()));
	}
}