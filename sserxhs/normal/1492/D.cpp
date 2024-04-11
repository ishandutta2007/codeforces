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
	register int tp=1,y;st[1]=x%10;x/=10;
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
int x[N],y[N];
int a,b;
int T,n,m,c,i,j,k,z,ans,la;
int main()
{
	read(a);read(b);read(k);
	if (k==0) {puts("Yes");for (i=1;i<=b;i++) putchar(49);for (i=1;i<=a;i++) putchar(48);puts("");for (i=1;i<=b;i++) putchar(49);for (i=1;i<=a;i++) putchar(48);puts("");return 0;}
    if (a==0||b==1) return puts("No"),0;
	if (a+b-2<k) return puts("No"),0;
	n=a+b;
	x[1]=y[1]=1;
	y[n]=1;x[n-k]=1;b-=2;
	for (i=2;b&&i<=n;i++) if (x[i]==0&&y[i]==0) x[i]=y[i]=1,--b;
	if (b) return puts("No"),0;
	puts("Yes");
	for (i=1;i<=n;i++) printf("%d",x[i]);puts("");
	for (i=1;i<=n;i++) printf("%d",y[i]);puts("");
}