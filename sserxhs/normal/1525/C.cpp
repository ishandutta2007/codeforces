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
	int u,v,w;
	//Q(int a=0,int b=0):u(a),v(b){}
	bool operator<(const Q &o) const {return u<o.u;}
};
const int N=1e6+2,M=1e6+2,inf=1e9;
char s[N];
int ans[N];
Q a[N],b[N],d[N],e[N],st[N];
int T,n,m,c,i,j,k,x,y,z,la,ksiz,ks,n1,n2,tp;
void cal()
{
	sort(a+1,a+n+1);tp=0;
	//for (i=1;i<=n;i++) printf("%d%c",a[i].u,i==n?10:32);
	for (i=1;i<=n;i++) if (a[i].v)
	{
		if (!tp)
		{
			a[i].u=-a[i].u;a[i].v=0;
			st[++tp]=a[i];
		}
		else
		{
			ans[a[i].w]=ans[st[tp].w]=a[i].u-st[tp].u>>1;
			--tp;
		}
	}
	else
	{
		st[++tp]=a[i];
	}
	//printf("%d\n",tp);
	if (tp<=1) return;
	//for (i=1;i<=tp;i++) printf("%d%c",st[i].u,i==tp?10:32);
	if (tp&1) {for (i=1;i<tp;i++) st[i]=st[i+1];--tp;}
	for (i=2;i<=tp;i+=2) st[i].u=2*m-st[i].u;
	for (i=1;i<=tp;i+=2) ans[st[i].w]=ans[st[i+1].w]=st[i+1].u-st[i].u>>1;
}//6:4,5:4,4:3
int main()
{
	//ios::sync_with_stdio(false);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	T=1;
	read(T);
	while (T--)
	{
		read(n,m);memset(ans+1,-1,n<<2);int nn=n;
		for (i=1;i<=n;i++) read(a[i].u);n1=n2=0;
		for (i=1;i<=n;i++)
		{
			c=getchar();
			while (c!='L'&&c!='R') c=getchar();
			a[i].v=(c=='L');a[i].w=i;
			if (a[i].u&1) b[++n1]=a[i]; else d[++n2]=a[i];
		}
		for (i=1;i<=n1;i++) a[i]=b[i];
		n=n1;
		cal();
		for (i=1;i<=n2;i++) a[i]=d[i];
		n=n2;cal();//printf("AKK");
		write(ans,nn);
	}
}