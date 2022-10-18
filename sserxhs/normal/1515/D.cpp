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
int a[N],b[N],cnt[N];
int T,n,m,c,i,j,k,x,y,z,ans,la,l,r;
int main()
{
	T=1;read(T);
	while (T--)
	{
		read(n);read(l);read(r);
		memset(a+1,0,n<<2);
		memset(cnt+1,0,n<<2);
		memset(b+1,0,n<<2);
		for (i=1;i<=l;i++) read(a[i]);
		for (i=1;i<=r;i++) read(b[i]);
		if (l>r)
		{
			swap(l,r);
			for (i=1;i<=n;i++) swap(a[i],b[i]);
		}
		sort(a+1,a+l+1);sort(b+1,b+r+1);
		for (i=1;i<=l;i++) ++cnt[a[i]];
		for (i=1;i<=r;i++) if (cnt[b[i]])
		{
			--cnt[b[i]];b[i]=p;
		}
		sort(b+1,b+r+1);while (r&&b[r]==p) --r;
		if (!r) {puts("0");continue;}l=0;
		for (i=1;i<=n;i++) while (cnt[i]--) a[++l]=i;
		memset(cnt+1,0,n<<2);
		for (i=1;i<=r;i++) ++cnt[b[i]];ans=0;
		for (i=1;i<=n;i++) ans+=cnt[i]>>1;
		x=max(0,(r-l>>1)-ans);
		printf("%d\n",(l+r)/2+x);
	}
}