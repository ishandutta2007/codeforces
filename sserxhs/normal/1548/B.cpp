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
const int N=5e5+2,M=1e6+2,inf=1e9;
char s[N];
ll a[N],st[20][N];
int ys[N];
int T,n,m,c,i,j,k,x,y,z,ans,ksiz,ks;
ll la;
ll rmq(int x,int y)
{
	int z=ys[y-x+1];
	return __gcd(st[z][x],st[z][y-(1<<z)+1]);
}
ll ab(ll x){return x>0?x:-x;}
int main()
{
	//ios::sync_with_stdio(false);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	T=1;
	read(T);ys[0]=-1;n=2e5;
	for (i=1;i<=n;i++) ys[i]=ys[i>>1]+1;
	while (T--)
	{
		read(n,a,n);
		if (n==1) {enter(1);continue;}
		for (i=1;i<n;i++) a[i]=ab(a[i+1]-a[i]);--n;
		for (i=1;i<=n;i++) st[0][i]=a[i];
		for (j=1;j<=ys[n];j++)
		{
			for (i=1;i+(1<<j-1)<=n;i++) st[j][i]=__gcd(st[j-1][i],st[j-1][i+(1<<j-1)]);
			for (;i<=n;i++) st[j][i]=st[j-1][i];
		}
		ans=0;
		la=0;
		for (i=j=1;i<=n;i++) if (a[i]!=1)
		{
			if (j<i) j=i,la=a[i]; else la=rmq(i,j);
			while (j<n&&(la=__gcd(la,a[j+1]))>1) ++j;
			ans=max(ans,j-i+1);
		}
		enter(ans+1);
	}
}