#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
#define range(x) (x).begin(),(x).end()
std::mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
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
template<typename typC> void read(register typC *a,int num)
{
	for (register int i=1;i<=num;i++) read(a[i]);
}
template<typename typC, typename... Args> void read(typC &first, Args& ... args) {
	read(first);
	read(args...);
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
	if (num<=0) puts("");
	for (register int i=1;i<=num;i++) write(a[i]),putchar(i==num?10:32);
}
template<typename typC> typC ab(register typC x)
{
	if (x<0) return -x;
	return x;
}
#define space(x) write(x),putchar(32)
#define enter(x) write(x),putchar(10)
#define debug(x,y) printf("%s: ",#x),write(x,y)
const int p=998244353;
const db eps=1e-9;
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
priority_queue<int> ONLYYFORRCOPYY;
priority_queue<int,vector<int>,greater<int> > ONLYYFORRCOPYY__;
struct Q
{
	int u,v;
	Q(int a=0,int b=0):u(a),v(b){}
	bool operator<(const Q &o) const {return v<o.v;}
};
const int N=3e5+2,M=2e3+3,inf=1e9;
int a[N];
int T,n,m,c,i,j,k,x,y,z,la,ksiz,ks;
ll ans,t1,t2;
int f[M][M];
bool ed[N];
struct bittt
{
	ll a[N],b[N];
	int l[N],r[N],bel[N];
	int n;
	void init(int nn)
	{
		n=nn;
		for (int i=1;i<=n;i++) a[i]=b[i]=0,bel[i]=(i-1)/m+1;
		for (int i=1;i<=n;i++) r[bel[i]]=i;
		for (int i=n;i;i--) l[bel[i]]=i;
	}
	void mdf(int x,int y)
	{
		int i,j=r[bel[x]];
		for (int i=x;i<=j;i++) a[i]+=y;
		for (int i=bel[x];i<=bel[n];i++) b[i]+=y;
	}
	ll sum(int x)
	{
		return x==0?0:a[x]+b[bel[x]-1];
	}
	ll sum(int x,int y)
	{
		return sum(y)-sum(x-1);
	}
};
struct bitttt
{
	int a[N],b[N];
	int l[N],r[N],bel[N];
	int n;
	void init(int nn)
	{
		n=nn;
		for (int i=1;i<=n;i++) a[i]=b[i]=0,bel[i]=(i-1)/m+1;
		for (int i=1;i<=n;i++) r[bel[i]]=i;
		for (int i=n;i;i--) l[bel[i]]=i;
	}
	void mdf(int x,int y)
	{
		int i,j=r[bel[x]];
		for (int i=x;i<=j;i++) a[i]+=y;
		for (int i=bel[x];i<=bel[n];i++) b[i]+=y;
	}
	int sum(int x)
	{
		return x==0?0:a[x]+b[bel[x]-1];
	}
	int sum(int x,int y)
	{
		return sum(y)-sum(x-1);
	}
};
bittt sum;
bitttt siz;
int main()
{

	read(n,a,n);m=sqrt(3e5);sum.init(3e5);siz.init(3e5);
	//siz.mdf(6,1);siz.mdf(2,1);enter(siz.sum(1));
	//for (i=1;i<=n;i++) ed[a[i]]=1;
	for (i=1;i<=n;i++)
	{
		if (a[i]<=m)
		{
			for (j=0;j<a[i];j++) ans+=(ll)f[a[i]][j]*j;
		}
		else
		{
			ll lst1=0,lst2=0,n1,n2;
			for (j=0;j*a[i]<=3e5;j++)
			{
				y=j*a[i];
				x=min(y+a[i]-1,(int)3e5);
				t1=(n1=sum.sum(x))-lst1;t2=(n2=siz.sum(x))-lst2;
				lst1=n1;lst2=n2;
				t1-=t2*j*a[i];
				ans+=t1;
				//if (t1&&i==4) puts("ff"),printf("%d %d %lld %lld ",y,x,t1+t2*j,t2),enter(ans);
			}
		}
		//if (i==4) printf("GOGO%lld\n",ans);
		ll lst1=0,lst2=0,n1,n2;
		for (j=1;j<=a[i];j=k+1)
		{
			k=a[i]/(x=a[i]/j);
			ans+=(ll)a[i]*((n1=siz.sum(k))-lst1)-x*((n2=sum.sum(k))-lst2);
			lst1=n1;lst2=n2;
			//if (i==4) printf("gg\n%d %d %d %lld %lld\n",j,k,siz.sum(j,k),sum.sum(j,k),ans);
		}
		ans+=(ll)a[i]*siz.sum(a[i]+1,3e5);
		sum.mdf(a[i],a[i]);siz.mdf(a[i],1);
		for (j=1;j<=m;j++) ++f[j][a[i]%j];
		if (i==n) enter(ans); else space(ans);
	}
}