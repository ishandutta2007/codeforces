#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
#define range(x) (x).begin(),(x.end())
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
template<typename typC, typename... Args> void read(typC &first, Args& ... args) {
	read(first);
	read(args...);
}
template<typename typC> void read(register typC *a,int num)
{
	for (register int i=1;i<=num;i++) read(a[i]);
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
template<typename typC> typC ab(register typC x)
{
	if (x<0) return -x;
	return x;
}
#define space(x) write(x),putchar(32)
#define enter(x) write(x),putchar(10)
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
int a[N],b[N];
int T,n,m,q,c1,c2,c,i,j,k,x,y,z,ans,la,ksiz,ks;
void ask(int *a)
{
	printf("? ");
	write(a,m);fflush(stdout);
	read(la);ans^=la;
}
void op(int x)
{
	if (x>=0) printf("! ");
	enter(x);fflush(stdout);exit(0);
}
bool cmp(int x,int b)
{
	return a[x]>a[b];
}
int main()
{
	//ios::sync_with_stdio(false);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	read(n,m);
	if (n==m)
	{
		for (i=1;i<=n;i++) a[i]=i;
		ask(a);
		op(ans);
	}
	if (n&1)
	{
		if (1^m&1) op(-1);
		x=n/m;
		while (x*m<n) ++x;
		while (1^x&1) ++x;
		y=x*m-n>>1;c1=3;c2=1;
	}
	else
	{
		if (1^m&1)
		{
			if (m>n/2)
			{
				x=3;
				c1=3;c2=1;
				y=3*m-n>>1;
			}
			else
			{
				x=n/m;
				while (x*m<n) ++x;
				c1=3;c2=1;y=x*m-n>>1;
			}
		}
		else
		{
			if (m>n/2)
			{
				x=n/(n-m);
				while (x*(n-m)<n) ++x;
				while (x&1) ++x;
				y=(m*x-n*x+3*n)/2;c1=p-1;c2=p-3;
			}
			else
			{
				x=n/m;
				while (x*m<n) ++x;
				while (x&1) ++x;
				c1=3;c2=1;y=x*m-n>>1;
			}
		}
	}
	for (j=1;j<=y;j++) a[j]=c1;
	for (j=y+1;j<=n;j++) a[j]=c2;
	for (i=1;i<=x;i++)
	{
		for (j=1;j<=n;j++) b[j]=j;
		sort(b+1,b+n+1,cmp);
		ask(b);
		for (j=1;j<=m;j++) --a[b[j]];
	}
	op(ans);
}