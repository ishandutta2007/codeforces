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
vector<int> b[N],ys[N];
int a[N],low[N],dfn[N],st[N],f[N],rd[N];
int T,n,m,c,i,j,k,x,y,z,ans,la,ksiz,ks,tp,id,fs,l;
bool ed[N];
vector<int> lj[N];
void dfs(int x)
{
	dfn[x]=low[x]=++id;
	ed[st[++tp]=x]=1;
	for (auto u:lj[x]) if (dfn[u])
	{
		if (ed[u]) low[x]=min(low[x],dfn[u]);
	}
	else
	{
		dfs(u);
		low[x]=min(low[x],low[u]);
	}
	if (dfn[x]==low[x])
	{
		++fs;st[tp+1]=0;
		while (st[tp+1]!=x)
		{
			f[st[tp]]=fs;
			ed[st[tp--]]=0;
		}
	}
}
int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int main()
{
	//ios::sync_with_stdio(false);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	T=1;
	read(n,m);
	for (i=0;i<=n+1;i++)b[i].resize(m+4),
		ys[i].resize(m+4);
	for (i=1;i<=n;i++)
	{
		
		c=getchar();
		while (c!='.'&&c!='#') c=getchar();
		for (j=1;j<=m;j++)
		{
			b[i][j]=(c=='#');
			c=getchar();
		}
	}int cnt=0;
	for (i=1;i<=n;i++) for (j=1;j<=m;j++) if (b[i][j]) ys[i][j]=++cnt;
	for (k=0;k<=3;k++) for (i=1;i<=n;i++) for (j=1;j<=m;j++) if (b[i][j]&&b[i+d[k][0]][j+d[k][1]]) lj[ys[i][j]].push_back(ys[i+d[k][0]][j+d[k][1]]);
	for (i=1;i<=n;i++) for (j=1;j<=m;j++) if (b[i][j])
	{
		for (k=i+1;k<=n&&!b[k][j];k++)
		{
			for (l=2;l<=3;l++) if (b[k+d[l][0]][j+d[l][1]]) lj[ys[i][j]].push_back(ys[k+d[l][0]][j+d[l][1]]);
		}
		if (k!=i+1&&b[k][j]) lj[ys[i][j]].push_back(ys[k][j]);
	}
	//for (i=1;i<=cnt;i++) for (auto u:lj[i]) printf("%d->%d\n",i,u);
	//for (j=1;j<=m;j++) for (i=1;i<=n;i++) if (b[i][j]) {a[j]=n-i+1;break;}
	//write(a,m);write(l,m);
	//l[0]=l[m+1]=2e9;
	/*for (j=1;j<=m;j++)
	{
		if (a[j]>=l[j+1]&&a[j+1]) lj[j].push_back(j+1);
		if (a[j]>=l[j-1]&&a[j-1]) lj[j].push_back(j-1);
	}*/
	for (i=1;i<=cnt;i++) if (!dfn[i]) dfs(i);
	for (i=1;i<=cnt;i++) for (auto u:lj[i]) if (f[i]!=f[u]) ++rd[f[u]];
	for (i=1;i<=fs;i++) if (!rd[i]) ++ans;enter(ans);
}