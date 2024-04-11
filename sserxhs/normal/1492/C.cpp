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
struct sqam
{
	int c[N][26],ds,i,j,lst[26],pre[N];
	inline void csh()
	{
		ds=1;
	}
	inline void ins(int zf)
	{
		++ds;
		for (i=0;i<=25;i++) if (lst[i]) for (j=lst[i];(j)&&(c[j][zf]==0);j=pre[j]) c[j][zf]=ds;
		if (!lst[zf]) c[1][zf]=ds; else pre[ds]=lst[zf];
		lst[zf]=ds;
	}
};
sqam s,ss;
int s1[N],s2[N],l[N],r[N];
int n,m,i,c,x,ans=0;
int main()
{
	read(n);read(m);
	c=getchar();
	while (c<'a'||c>'z') c=getchar();
	s1[1]=c-'a';
	for (i=2;i<=n;i++) s1[i]=getchar()-'a';
	c=getchar();
	while (c<'a'||c>'z') c=getchar();
	s2[1]=c-'a';
	for (i=2;i<=m;i++) s2[i]=getchar()-'a';
	s.csh();ss.csh();
	for (i=1;i<=n;i++) s.ins(s1[i]);
	for (i=n;i;i--) ss.ins(s1[i]);
	x=1;
	for (i=1;i<=m;i++) x=s.c[x][s2[i]],l[i]=x-1;x=1;
	for (i=m;i;i--) x=ss.c[x][s2[i]],r[i]=n-x+2;
	for (i=1;i<m;i++) ans=max(ans,r[i+1]-l[i]);printf("%d",ans);
}