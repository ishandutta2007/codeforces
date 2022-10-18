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
ll s[N];
vector<ll> c[N];
ll ans[N];
int a[N],b[N];
int T,n,m,i,j,k,x,y,z,la;
int main()
{
	T=1;read(T);
	while (T--)
	{
		read(n);
		for (i=1;i<=n;i++)
		{
			read(a[i]);
		}
		for (i=1;i<=n;i++) ans[i]=0;
		for (i=1;i<=n;i++) read(b[i]);
		for (i=1;i<=n;i++) c[i].clear();
		for (i=1;i<=n;i++) c[a[i]].push_back(b[i]);
		for (i=1;i<=n;i++) sort(c[i].begin(),c[i].end()),reverse(c[i].begin(),c[i].end());
		for (i=1;i<=n;i++) for (j=1;j<c[i].size();j++) c[i][j]+=c[i][j-1];
		for (i=1;i<=n;i++) if (c[i].size())
		{
			for (j=1;j<=c[i].size();j++) ans[j]+=c[i][c[i].size()-c[i].size()%j-1];
			//write(ans,n);
		}
		write(ans,n);
	}
}