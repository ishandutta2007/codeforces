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
const int N=1e3+2,M=1e6+2,inf=1e9;
char s[N];
int a[N][N],b[N],c[N],d[N];
int T,n,m,i,j,k,x,y,z,ans,la,ksiz,ks;
inline int f(register int *a,register int n,register int m)//0nm-1
{
	if (n<=m) return a[n];
	static int inv[N],l[N],r[N],ifac[N]; 
	//write(a,m);
	int i;
	ifac[0]=inv[1]=1;
	for (i=2;i<=m;i++) inv[i]=p-(ll)p/i*inv[p%i]%p;
	for (i=1;i<=m;i++) ifac[i]=(ll)ifac[i-1]*inv[i]%p;//
	register int ans=0,rr=0;
	l[0]=1;r[m+1]=1;
	for (i=1;i<m;i++) l[i]=(ll)l[i-1]*(n-i)%p;
	for (i=m;i;i--) r[i]=(ll)r[i+1]*(n-i)%p;
	for (i=1;i<=m;i++)
	{
		if ((m^i)&1) rr=p-a[i]; else rr=a[i];
		ans=(ans+(ll)rr*ifac[i-1]%p*ifac[m-i]%p*l[i-1]%p*r[i+1])%p;
	}
	//space(n);enter(ans);
	return ans;
}
int main()
{
	read(m,n);
	for (i=1;i<=n;i++) read(a[i],m);
	for (i=1;i<=n;i++) for (j=1;j<=m;j++) b[i]+=a[i][j];
	for (i=1;i<n;i++) c[i]=b[i+1]-b[i];
	sort(c+1,c+n);x=c[3];
	for (i=1;i<n;i++) if (b[i+1]-b[i]!=x) break;
	space(i),x=i+1;z=b[i+1]-(c[3]+b[i]);
	for (i=1;i<=n;i++) for (b[i]=0,j=1;j<=m;j++) b[i]=(b[i]+(ll)a[i][j]*a[i][j])%p;
	for (i=1;i<=n;i++) b[i]%=p;
	if (x<=3) y=f(b+3,x-3+p,3); else y=f(b,x,3);
	//for (i=1;i<=5;i++) printf("%d %d\n",i,f(b,i,4));
	//enter(y);
	if (m==477) assert(f(b,n,3)==b[n]);
	z%=p;z+=p;z%=p;
	y=(b[x]+p-y)%p;enter((ll)(y-(ll)z*z%p+p)*ksm(z*2%p,p-2)%p);fflush(stdout);
}