#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
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
struct Q
{
	int u,v;
	Q(int a=0,int b=0):u(a),v(b){}
	bool operator<(const Q &o) const {return v<o.v;}
};
const int N=1e6+2,M=1e6+2,inf=1e9;
ll b[N],y,z;
int a[1<<15],d[100],pc[1<<15];
ll ta;
int T,n,m,tp,p,c,i,j,k,x,ans,ksiz,ks;
bool ed[N];
void fwt(int *a,int n)
{
	int i,j,k,l;
	for (i=1;i<n;i=l)
	{
		l=i<<1;
		for (j=0;j<n;j+=l) for (k=0;k<i;k++)
		{
			a[j|k]=(a[j|k]+a[j|k|i]);
		}
	}
}
int main()
{
	//ios::sync_with_stdio(false);
	read(n,m,p);
	for (i=1;i<1<<15;i++) pc[i]=pc[i>>1]+(i&1);
	for (i=1;i<=n;i++)
	{
		c=getchar();
		while (c<48||c>57) c=getchar();
		for (j=1;j<=m;j++) b[i]|=(c-48ll)<<m-j,c=getchar();
	}
	for (int ii=1;ii<=min(80,n);ii++)
	{
		x=rnd()%n+1;
		while (ed[x]) x=rnd()%n+1;
		//printf("x=%d\n",x);
		ed[x]=1;y=b[x];tp=0;
		for (j=0;j<m;j++) if (1ll<<j&y) d[tp++]=j;
		assert(tp<=15);
		memset(a,0,sizeof(a));
		for (i=1;i<=n;i++)
		{
			z=b[i]&y;k=0;
			for (j=0;j<tp;j++) if (1ll<<d[j]&z) k|=1<<j;
			++a[k];//printf("ik %d %d\n",i,k);
		}
		//write(a-1,1<<tp);
		fwt(a,1<<tp);
		//write(a-1,1<<tp);
		for (i=0;i<1<<tp;i++) if (a[i]>=(n+1>>1)&&ans<pc[i])
		{
			ans=pc[i];ta=0;
			for (j=0;j<tp;j++) if (1<<j&i) ta|=1ll<<d[j];
		}
	}
	for (i=m-1;i>=0;i--) if (1ll<<i&ta) printf("1"); else printf("0");
}