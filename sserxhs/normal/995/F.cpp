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
const int N=3002,p=1e9+7;
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
vector<int> lj[N];
int f[N][N],siz[N];
int n,m,i,x;
void dfs(int x)
{
	for (i=1;i<=n;i++) f[x][i]=1;
	for (auto v:lj[x])
	{
		dfs(v);
		for (i=1;i<=n;i++) f[x][i]=(ll)f[x][i]*f[v][i]%p;
	}
	for (i=2;i<=n;i++) inc(f[x][i],f[x][i-1]);
}
inline int g(register int *a,register int n,register int m)//0nm-1
{
	if (n<=m) return a[n];
	static int inv[N],l[N],r[N],ifac[N]; 
	ifac[0]=inv[1]=1;
	for (i=2;i<=m;i++) inv[i]=p-(ll)p/i*inv[p%i]%p;
	for (i=1;i<=m;i++) ifac[i]=(ll)ifac[i-1]*inv[i]%p;//
	register int ans=0,rr=0;
	l[0]=n;r[m+1]=1;
	for (i=1;i<m;i++) l[i]=(ll)l[i-1]*(n-i)%p;
	for (i=m;i;i--) r[i]=(ll)r[i+1]*(n-i)%p;
	for (i=1;i<=m;i++)
	{
		if ((m^i)&1) rr=p-a[i]; else rr=a[i];
		ans=(ans+(ll)rr*ifac[i]%p*ifac[m-i]%p*l[i-1]%p*r[i+1])%p;
	}
	return ans;
}
int main()
{
	read(n);read(m);
	for (i=2;i<=n;i++) read(x),lj[x].push_back(i);
	++n;dfs(1);enter(g(f[1],m,n));
}