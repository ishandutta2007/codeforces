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
const int p=1e9+7;
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
const int N=3e6+2,M=1e6+2,inf=1e9;
char s[N];
int fac[N],ifac[N],f[N][3];
int T,n,m,c,i,j,k,x,y,z,ans,la,ksiz,ks;
int C(int n,int m)
{
	if (n<m||n<0) return 0;
	return (ll)fac[n]*ifac[m]%p*ifac[n-m]%p;
}
int inv;
int main()
{
	inv=ksm(3,p-2);
	//ios::sync_with_stdio(false);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	T=1;
	n=3e6+2;fac[0]=1;
	for (i=1;i<=n;i++) fac[i]=(ll)fac[i-1]*i%p;ifac[n]=ksm(fac[n],p-2);
	for (i=n;i;i--) ifac[i-1]=(ll)ifac[i]*i%p;
	read(n,T);
	m=3*n;f[0][0]=f[0][1]=f[0][2]=n;
	for (i=1;i<=m;i++)
	{
		x=C(m+1,i+1);
		f[i][2]=((ll)x-2ll*f[i-1][2]-(ll)f[i-1][1]+(ll)p*10)%p*inv%p;
		//if (f[i][2]*3==)
		//f[i][2]=f[i-1][0];dec(f[i][2],C(m,i));inc(f[i][2],f[i][0]);dec(f[i][2],C(m,i-1));
		f[i][1]=f[i-1][2];inc(f[i][1],f[i][2]);
		f[i][0]=f[i-1][1];inc(f[i][0],f[i][1]);
	}
	while (T--)
	{
		read(m);ans=0;
		enter(f[m][0]);
	}
}