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
const int N=1e6+2,M=1e6+2,inf=1e9;
char s[N];
int a[N],b[N],c[N],d[N],sum[N];
int T,n,m,i,j,k,x,y,z,ans,la,ksiz,ks;
int f[N];
int bel[N];
int main()
{
	//ios::sync_with_stdio(false);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	T=1;
	read(n);
	for (i=1;i<=n;i++) read(a[i],b[i],c[i]),d[++m]=a[i],d[++m]=b[i];
	sort(d+1,d+m+1);m=unique(d+1,d+m+1)-d-1;assert(m==n*2);
	for (i=1;i<=n;i++) a[i]=lower_bound(d+1,d+m+1,a[i])-d,b[i]=lower_bound(d+1,d+m+1,b[i])-d;
	for (i=1;i<=n;i++) bel[b[i]]=bel[a[i]]=i;d[m+1]=d[m]+1;
	f[m+1]=1;//enter(sum[6]);
	for (i=m;i;i--) if (a[bel[i]]==i) f[i]=(f[i+1]*2+c[bel[i]])%p,dec(f[i],1); else
	{
		x=bel[i];
		f[i]=f[i+1];
		dec(f[i],f[a[x]+1]);dec(f[i],c[x]);inc(f[i],1);
	}
	f[0]=1;
	//for (i=1;i<=m+1;i++) printf("[%d,%d] %d\n",d[i-1],d[i],f[i]);
	for (i=1;i<=m+1;i++) ans=(ans+(ll)(d[i]-d[i-1])*f[i])%p;
	enter(ans);
}