#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
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
template<typename typC> void write(register typC x)
{
	if (x<0) putchar('-'),x=-x;
	static int st[100];
	register int tp=1,y;st[1]=x%10;x/=10;
	while (x) y=x/10,st[++tp]=x-y*10,x=y;++tp;
	while (--tp) putchar(st[tp]|48);
}
template<typename typC> void write(register typC *a,register int num)
{
	for (register int i=1;i<=num;i++) write(a[i]),putchar(i==num?10:32);
}
#define space(x) write(x),putchar(32)
#define enter(x) write(x),putchar(10)
const int N=1e6+2,M=1e6+2,p=998244353;
inline void inc(register int &x,const int y)
{
	if ((x+=y)>=p) x-=p;
}
inline void dec(register int &x,const int y)
{
	if ((x-=y)<0) x+=p;
}
char s[N];
int lj[M],f[N],nxt[M],fir[N],fa[N];
bool ed[N];
int T,n,m,c,i,bs,j,k,x,y,z,ans,la;
inline void add()
{
	lj[++bs]=y;nxt[bs]=fir[x];fir[x]=bs;
	lj[++bs]=x;nxt[bs]=fir[y];fir[y]=bs;
}
int getfa(int x){return fa[x]==x?x:fa[x]=getfa(fa[x]);}
void dfs(int x)
{
	ed[x]=1;
	if (f[x])
	{
		for (int i=fir[x];i;i=nxt[i]) f[lj[i]]=0;
	}
	for (int i=fir[x];i;i=nxt[i]) if (!ed[lj[i]])
	{
		if (-1==f[lj[i]]) f[lj[i]]=f[x]^1;
		dfs(lj[i]);
	}
}
int main()
{
	read(T);
	while (T--)
	{
		read(n);read(m);bs=0;
		memset(fir+1,0,n<<2);
		memset(f+1,-1,n<<2);
		memset(ed+1,0,n);
		for (i=1;i<=n;i++) fa[i]=i;
		while (m--) read(x),read(y),add(),fa[getfa(x)]=getfa(y);
		for (i=1;i<=n;i++) if (getfa(i)!=getfa(1)) {puts("NO");break;}
		if (i<=n) continue;
		f[x]=1;dfs(1);int cnt=0;
		for (i=1;i<=n;i++) if (f[i]) ++cnt;printf("YES\n%d\n",cnt);
		for (i=1;i<=n;i++) if (f[i]) printf("%d%c",i,i==n?10:32);
	}
}