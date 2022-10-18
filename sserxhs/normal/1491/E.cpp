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
vector<int> lj[N];
char s[N];
int a[N],b[N],siz[N],fib[N],isf[N],f[N];
int T,n,m,c,i,j,k,x,y,z,ans,la,ksiz;
bool ed[N],ct[N],flg;
void dfs1(int x)
{
	ed[x]=1;
	siz[x]=1;
	for (auto v:lj[x]) if (!ed[v]&&!ct[v]) f[v]=x,dfs1(v),siz[x]+=siz[v];
		ed[x]=0;
}
void dfs2(int x,int &cp,int tar)
{
	ed[x]=1;
	for (auto v:lj[x]) if (!ed[v]&&!ct[v])
	{
		if (siz[v]==tar&&!cp) cp=v;
		dfs2(v,cp,tar);
	}
	if (ksiz-siz[x]==tar&&!cp) cp=x;
	ed[x]=0;
}
bool pd(int x)
{
	dfs1(x);
	if (siz[x]==1||siz[x]==2||siz[x]==3) return 1;
	if (!isf[siz[x]]) return 0;
	int cp=0;ksiz=siz[x];
	dfs2(x,cp,fib[isf[ksiz]-2]);//printf("%d %d %d\n",x,cp1,cp2);
	if (flg||!cp) return 0;
	ct[f[cp]]=1;
	if (pd(cp)==0) return 0;
	ct[f[cp]]=0;ct[cp]=1;
	return pd(x);
}
int main()
{
	read(n);
	fib[0]=fib[1]=1;isf[1]=1;
	for (i=2;fib[i-1]<=n;i++) fib[i]=fib[i-1]+fib[i-2],isf[fib[i]]=i;
	for (i=1;i<n;i++) read(x),read(y),lj[x].push_back(y),lj[y].push_back(x);
	if (pd(1)) puts("YES"); else puts("NO");
}