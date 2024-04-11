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
}vector<int> lj[N];
char s[N];
int a[N],b[N],st1[N],st2[N],ed[N];
int T,n,m,c,i,j,k,x,y,z,ans,la,tp1,tp2;
int pc(int x)
{
	int r=0;
	for (int i=30;~i;i--) if (1<<i&x) ++r;
	return r;
}
void dfs(int x)
{
	ed[x]=i;
	for (auto v:lj[x]) dfs(v);
}
int main()
{
	//for (i=1;i<=15;i++) printf("%d %d\n",i,pc(i));
	T=1;read(T);
	while (T--)
	{
		read(n);read(m);
		if (n>m||pc(n)<pc(m)) {puts("NO");continue;}
		tp1=tp2=0;swap(n,m);
		for (i=0;i<=30;i++) if (1<<i&n) st1[++tp1]=i;
		for (i=0;i<=30;i++) if (1<<i&m) st2[++tp2]=i;
		for (i=1;i<=tp1;i++) if (st1[i]<st2[i]) break;
		if (i<=tp1) puts("NO"); else puts("YES");
	}
}