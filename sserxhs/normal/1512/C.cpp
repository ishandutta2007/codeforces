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
int a[N],b[N],ys[200];
int T,n,m,c,i,j,k,x,y,z,ans,la;
int main()
{
	T=1;read(T);ys['0']=1;ys['1']=2;ys['?']=3;
	while (T--)
	{
		read(x);read(y);n=x+y;
		c=getchar();
		while (!ys[c]) c=getchar();
		a[1]=ys[c];
		for (i=2;i<=n;i++) a[i]=ys[getchar()];
		for (i=1;i<=n;i++) if (a[i]<=2)
		{
			if (a[n-i+1]==(a[i]^3)) {puts("-1");break;}
			a[n-i+1]=a[i];
		}
		if (i<=n) continue;
		if ((1^n&1)&&(x&1)) {puts("-1");continue;}
		if (n&1)
		{
			if (a[n+1>>1]!=3)
			{
				if ((a[n+1>>1]==1)^(x&1)) {puts("-1");continue;}
			} else if (x&1) a[n+1>>1]=1; else a[n+1>>1]=2;
		}
		for (i=1;i<=n;i++) if (a[i]==1) --x; else if (a[i]==2) --y;
		if (x<0||y<0||(x&1)||(y&1)) {puts("-1");continue;}x>>=1;y>>=1;
		for (i=1;i<=n;i++) if (a[i]==3)
		{
			if (x) a[i]=a[n-i+1]=1,--x; else a[i]=a[n-i+1]=2;
		}
		for (i=1;i<=n;i++) printf("%d",a[i]-1);puts("");
	}
}