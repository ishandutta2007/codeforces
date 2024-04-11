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
const int N=1e2+2,M=1e6+2,inf=1e9;
char s[N];
int a[N],b[N],dep[N],g[N],dc[N][N],fac[N],ifac[N];
int T,n,m,c,i,j,k,x,y,z,ans,la,ksiz,ks,cs;
vector<int> lj[N];
void dfs(int x)
{
	++dc[cs][dep[x]];
//	printf("		%d %d %d\n",x,dep[x],cs);
	for (auto u:lj[x]) if (!dep[u])
	{
		dep[u]=dep[x]+1;
		dfs(u);
	}
}
int C(int n,int m)
{
	return (ll)fac[n]*ifac[m]%p*ifac[n-m]%p;
}
int main()
{
	//ios::sync_with_stdio(false);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	T=1;n=1e2;fac[0]=1;
	for (i=1;i<=n;i++) fac[i]=(ll)fac[i-1]*i%p;ifac[n]=ksm(fac[n],p-2);
	for (i=n;i;i--) ifac[i-1]=(ll)ifac[i]*i%p;
	read(T);
	while (T--)
	{
		read(n,m);ans=0;
		for (i=1;i<=n;i++) lj[i].clear();
		for (i=1;i<n;i++) read(x,y),lj[x].push_back(y),lj[y].push_back(x);
		if (m==2)
		{
			ans=n*(n-1)/2;
			enter(ans);continue;
		}
		for (i=1;i<=n;i++)
		{
			memset(dep,0,sizeof dep);
			memset(dc,0,sizeof dc);
			dep[i]=1;cs=0;
			for (auto u:lj[i]) ++cs,dep[u]=2,dfs(u);
			int cnt=0;
			for (j=1;j<=n;j++)
			{
				cnt=0;
				memset(g,0,sizeof g);g[0]=1;
				for (k=1;k<=cs;k++)
				{
					if (dc[k][j])
					{
						for (int l=m;l;l--) g[l]=(g[l]+(ll)g[l-1]*dc[k][j])%p;
					}
				}
				//printf("%d %d %d\n",i,j,cnt);
				inc(ans,g[m]);
			}
		}
		enter(ans);
	}
}