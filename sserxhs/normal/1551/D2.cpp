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
const int N=103,M=1e6+2,inf=1e9;
char s[N];
int a[N],b[N],ans[N][N],d[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int T,n,m,q,c,i,j,k,x,y,z,la,ksiz,ks;
bool av[8];
void uni(int x,int y,int xx,int yy)
{
	fill(av,av+8,1);
	for (int i=0;i<=3;i++) av[ans[x+d[i][0]][y+d[i][1]]]=0;
	for (int i=0;i<=3;i++) av[ans[xx+d[i][0]][yy+d[i][1]]]=0;
	for (int i=1;i<=7;i++) if (av[i]) {ans[x][y]=ans[xx][yy]=i;break;}
}
void sol()
{
	int nn=n,mm=m;
	if (n&1)
	{
		y=m/2;
		for (i=1;i<=m;i+=2) uni(n,i,n,i+1);
		q-=y;--n;
		for (i=1;i<=n;i+=2) for (j=1;j<=m;j+=2) if (q) uni(i,j,i,j+1),uni(i+1,j,i+1,j+1),q-=2;
		else uni(i,j,i+1,j),uni(i,j+1,i+1,j+1);
	}
	else if (m&1)
	{
		y=n/2;
		for (i=1;i<=n;i+=2) uni(i,m,i+1,m);
		x-=y;--m;
		for (i=1;i<=n;i+=2) for (j=1;j<=m;j+=2) if (!x) uni(i,j,i,j+1),uni(i+1,j,i+1,j+1),q-=2;
		else uni(i,j,i+1,j),uni(i,j+1,i+1,j+1),x-=2;
	}
	else
	{
		for (i=1;i<=n;i+=2) for (j=1;j<=m;j+=2) if (q) uni(i,j,i,j+1),uni(i+1,j,i+1,j+1),q-=2;
		else uni(i,j,i+1,j),uni(i,j+1,i+1,j+1);
	}
	n=nn;m=mm;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++) putchar(96+ans[i][j]);
		puts("");
	}
}
int main()
{
	//ios::sync_with_stdio(false);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	T=1;
	read(T);
	while (T--)
	{
		memset(ans,0,sizeof ans);
		read(n,m,q);x=n*m/2-q;
		if (n&1)
		{
			q-=m/2;
			if (q<0||q&1) puts("NO"); else q+=m/2,puts("YES"),sol();
		}
		else if (m&1)
		{
			x-=n/2;
			if (x<0||x&1) puts("NO"); else x+=n/2,puts("YES"),sol();
		}
		else
		{
			if (q&1) puts("NO"); else puts("YES"),sol();
		}
	}
}