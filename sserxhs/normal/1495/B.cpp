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
char s[N];
int a[N],b[N];
int T,n,m,c,i,j,k,x,y,z,ans,la,l1,l2,pl1,pl2,pr1,pr2,kl,l3;
int main()
{
	read(n);
	for (i=1;i<=n;i++) read(a[i]);
	for (i=1,j=2;j<=n;i=j,j=i+1)
	{
		if (a[i]<a[j])
		{
			while (j<n&&a[j]<a[j+1]) ++j;la=j-i+1;
			if (la>l1) l1=la,pl1=i,pr1=j; else if (la>l2) l2=la,pl2=i,pr2=j; else if (la>l3) l3=la;
			//printf("%d %d\n",i,j);
			//[i,j]
		}
		else
		{
			while (j<n&&a[j]>a[j+1]) ++j;la=j-i+1;
			if (la>l1) l1=la,pl1=i,pr1=j; else if (la>l2) l2=la,pl2=i,pr2=j; else if (la>l3) l3=la;
			//printf("%d %d\n",i,j);
		}
	}
	if (!l2) return puts("0"),0;
	if (l1==l2&&pr1!=pl2||l1==l3) return puts("0"),0;
	if (a[pl1]>a[pr1])
	{
		if (pl1==1) return puts("0"),0;
		i=pl1;j=pl1-1;kl=pr1-pl1+1;if (kl&1) --kl;
		while (j>1&&a[j-1]<a[j]) --j;
		if (i-j+1>kl) puts("1"); else puts("0");
	}
	else
	{
		if (pr1==n) return puts("0"),0;
		i=pr1;j=pr1+1;kl=pr1-pl1+1;if (kl&1) --kl;
		while (j<n&&a[j+1]<a[j]) ++j;
		if (j-i+1>kl) puts("1"); else puts("0");
	}
}