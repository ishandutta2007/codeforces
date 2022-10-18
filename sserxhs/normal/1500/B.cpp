#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
#define int ll
std::mt19937 rnd(time(0));
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
ll k,l,r,mid,lm,ans;
int a[N],b[N],pa[N],pb[N];
ll xs[N];
int exgcd(int a,int b,int c)
{
	if (a==0) return c/b;
	return (c-(ll)b*exgcd(b%a,a,c))/a%b;
}
int T,n,m,c,i,j,x,y,z,la,gg,q;
signed main()
{
	read(n);read(m);read(k);gg=__gcd(n,m);lm=(ll)n*m/gg;
	for (i=1;i<=n;i++) read(a[i]),pa[a[i]]=i;
	for (i=1;i<=m;i++) read(b[i]),pb[b[i]]=i;
	for (i=1;i<=max(n,m)<<1;i++) if (pa[i]&&pb[i])
	{
		if ((pa[i]-pb[i])%gg) continue;
		int x=exgcd(n/gg,-m/gg,(pb[i]-pa[i])/gg);
		xs[++q]=((ll)x*n+pa[i])%lm;
		if (xs[q]<=0) xs[q]+=lm;
	}
	sort(xs+1,xs+q+1);
	//for (i=1;i<=q;i++) printf("%lld ",xs[i]);puts("");
	ans=(k-1)/(lm-q)*lm;k=(k-1)%(lm-q)+1;++q;xs[q]=lm+1;
	//printf("%lld %lld\n",ans,k);
	for (i=1;i<=q;i++) if (xs[i]-xs[i-1]-1>=k) return printf("%lld",ans+k),0;
	else ans+=xs[i]-xs[i-1],k-=xs[i]-xs[i-1]-1;exit(-1);
	printf("%lld",ans);
}