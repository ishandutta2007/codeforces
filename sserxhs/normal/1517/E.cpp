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
const int N=2e5+2,M=1e6+2,p=998244353;
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
ll ans;
int a[N];
ll sf[N],sb[N],sod[N],sev[N],dt,bs;
int T,n,m,c,i,j,k,x,y,z,la,l,r,mid;
bool pd(int mid)
{
	dt=bs+sb[mid+1]-sf[i];
				dt-=sod[mid]-sod[i];
				dt+=sod[mid-1]-sod[i-1];
				return (dt>0);
}
int main()
{
	T=1;read(T);
	while (T--)
	{
		read(n);ans=0;
		for (i=1;i<=n;i++) read(a[i]);sf[0]=0;sb[n+1]=0;sod[1]=a[1];
		for (i=1;i<=n;i++) sf[i]=sf[i-1]+a[i];
		for (i=n;i;i--) sb[i]=sb[i+1]+a[i];
		for (i=3;i<=n;i+=2) sod[i]=sod[i-2]+a[i];
		for (i=2;i<=n;i+=2) sod[i]=sod[i-2]+a[i];
		for (i=1;i<n;i++)
		{
			l=i;r=n;if (r-l&1) --r;bs=0;
			while (l<r)
			{
				mid=l+r>>1;
				if (mid-l&1) ++mid;
				if (pd(mid)) l=mid; else r=mid-2;
			}
			if (l==r&&pd(l)) ans+=(l-i)/2+1;//printf("ans %d %d\n",i,ans);
			if (i!=1)
			{
				bs=a[1]*2;
				l=i;r=n;if (r-l&1) --r;//bs=0;
				while (l<r)
				{
					mid=l+r>>1;
					if (mid-l&1) ++mid;
					if (pd(mid)) l=mid; else r=mid-2;
				}
				if (l==r&&pd(l)) ans+=(l-i)/2+1;//printf("ans %d %d\n",i,ans);
				bs=(a[1]-a[n])*2;
				l=i;r=n-3;
				if (r-l&1) --r;//bs=0;
				while (l<r)
				{
					mid=l+r>>1;
					if (mid-l&1) ++mid;
					if (pd(mid)) l=mid; else r=mid-2;
				}
				if (l==r&&pd(l)) ans+=(l-i)/2+1;//printf("ans %d %d\n",i,ans);
			}
			bs=-a[n]*2;
			l=i;r=n-3;
			if (r-l&1) --r;//bs=0;
			while (l<r)
			{
				mid=l+r>>1;
				if (mid-l&1) ++mid;
				if (pd(mid)) l=mid; else r=mid-2;
			}
			if (l==r&&pd(l)) ans+=(l-i)/2+1;//printf("ans %d %d\n",i,ans);
		}
		for (i=1;i<=n;i++) if (sf[i]>sb[i+1]) break;
		ans+=(n-i+1);
		ans%=p;printf("%lld\n",ans);
	}
}
/*
PPPP, PCCP, PPPC, PPCC, PCCC
 */