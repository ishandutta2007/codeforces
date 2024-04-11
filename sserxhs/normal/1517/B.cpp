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
const int N=102,M=1e6+2,p=998244353,inf=2e9;
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
char s[N];
int a[N][N],ans[N][N];
int T,n,m,c,i,j,k,x,y,z,la,mx,my;
int main()
{
	T=1;read(T);
	while (T--)
	{
		read(n);read(m);//r=0;
		for (i=1;i<=n;i++) for (j=1;j<=m;j++) read(a[i][j]);
		for (k=1;k<=m;k++)
		{
			mx=my=0;
			for (i=1;i<=n;i++) for (j=1;j<=m;j++) if (!mx) mx=i,my=j; else if (a[i][j]<a[mx][my]) mx=i,my=j;
			ans[k][mx]=a[mx][my];a[mx][my]=inf;
			for (i=1;i<=n;i++) if (i!=mx)
			{
				la=1;
				for (j=2;j<=m;j++) if (a[i][la]==inf||a[i][la]<a[i][j]&&a[i][j]!=inf) la=j;
				ans[k][i]=a[i][la];
				a[i][la]=inf;
			}
		}
		for (i=1;i<=n;i++)
		{
			for (j=1;j<=m;j++) printf("%d ",ans[j][i]);puts("");
		}
	}
}