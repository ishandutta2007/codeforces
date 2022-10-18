#include <bits/stdc++.h>
using namespace std;
const int N=2e5+2,M=3e5+2,Q=5e5+2,O=4e5+2,P=1.6e6+2;
typedef pair<int,int> pa;
typedef long long ll;
int lb[M][2],v[O],f[O],g[Q][2],fv[N],c[O][2],dfn[O],nfd[O],siz[O],l[P],r[P],ys[O],s[P];
int n,cc,i,m,q,tp,cnt,x,y,z,ans;
bool ed[O];
inline void read(int &x)
{
	cc=getchar();
	while ((cc<48)||(cc>57)) cc=getchar();
	x=cc^48;cc=getchar();
	while ((cc>=48)&&(cc<=57))
	{
		x=x*10+(cc^48);
		cc=getchar();
	}
}
inline int getf(register int x)
{
	if (f[x]==x) return x;return f[x]=getf(f[x]);
}
inline void merge(register int x,register int y)
{
	x=getf(x);y=getf(y);
	if (x==y) return;
	c[f[x]=f[y]=++n][0]=x;c[n][1]=y;
}
void dfs(int x)
{
	siz[nfd[dfn[x]=++cnt]=x]=1;
	if (c[x][0])
	{
		dfs(c[x][0]);dfs(c[x][1]);
		siz[x]+=siz[c[x][0]]+siz[c[x][1]];
	}
}
inline void pushup(const int x)
{
	s[x]=max(s[x<<1],s[x<<1|1]);
}
void build(const int x)
{
	if (l[x]==r[x]) return fv[s[x]=v[nfd[l[x]]]]=x,void();
	const int c=x<<1;
	l[c]=l[x];r[c]=l[x]+r[x]>>1;
	l[c|1]=r[c]+1;r[c|1]=r[x];
	build(c);build(c|1);
	pushup(x);
}
inline void sol(int x)
{
	if ((z<=l[x])&&(r[x]<=y)) return ans=max(ans,s[x]),void();
	if (z<=r[x<<1]) sol(x<<1);if (y>r[x<<1]) sol(x<<1|1);
}
inline void mdf(register int x)
{
	s[x]=0;while (x=x>>1) pushup(x);
}
int main()
{
	read(n);read(m);read(q);
	for (i=1;i<=n;i++) read(v[f[i]=i]);for (i=n+1;i<=n<<1;i++) f[i]=i;
	for (i=1;i<=m;i++) {read(lb[i][0]);read(lb[i][1]);}
	for (i=1;i<=q;i++) {read(g[i][0]);read(g[i][1]);if (g[i][0]==2) ed[g[i][1]]=1; else ++tp;}
	for (i=1;i<=m;i++) if (!ed[i]) merge(lb[i][0],lb[i][1]);
	for (i=q;i;i--) if (g[i][0]==2) merge(lb[g[i][1]][0],lb[g[i][1]][1]); else ys[tp--]=getf(g[i][1]);
	memset(ed+1,0,n);
	for (i=1;i<=n;i++) if (!ed[getf(i)]) {dfs(f[i]);ed[f[i]]=1;}
	r[l[1]=1]=n;build(1);
	for (i=1;i<=q;i++) if (g[i][0]==1)
	{
		ans=0;x=ys[++tp];y=(z=dfn[x])+siz[x]-1;
		sol(1);printf("%d\n",ans);mdf(fv[ans]);
	}
}