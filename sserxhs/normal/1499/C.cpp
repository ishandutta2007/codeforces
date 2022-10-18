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
ll s1[N],s2[N],ans;
int a[N],b[N];
int T,n,m,c,i,j,k,x,y,z,la;
int main()
{
	T=1;read(T);
	while (T--)
	{
		read(n);
		for (i=1;i<=n;i++)
		{
			read(a[i]);
		}x=1;y=2;s1[1]=a[1];s2[2]=a[2];ans=(ll)n*(a[1]+a[2]);
		for (i=3;i<=n;i++)
		{
			if (i&1) x=a[x]>a[i]?i:x,s1[i]=s1[i-2]+a[i],s2[i]=s2[i-1];
			else y=a[y]>a[i]?i:y,s2[i]=s2[i-2]+a[i],s1[i]=s1[i-1];
			ans=min(ans,(ll)a[x]*(n-(i-1)/2-1)+s1[i]+(ll)a[y]*(n-i/2)+s2[i]);
		}
		printf("%lld\n",ans);
	}
}