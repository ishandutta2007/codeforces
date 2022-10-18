#include <bits/stdc++.h>
using namespace std;
const int N=1e6+2,M=2e6+2;
int *f[N],g[N],hc[N],gs[N],lj[M],nxt[M],fir[N],len[N],ans[N];
int n,i,c,x,y,bs,*tp=g+1;
bool top[N],ed[N];
inline void add()
{
	lj[++bs]=y;
	nxt[bs]=fir[x];
	fir[x]=bs;
	lj[++bs]=x;
	nxt[bs]=fir[y];
	fir[y]=bs;
}
inline void read(int &x)
{
	c=getchar();
	while ((c<48)||(c>57)) c=getchar();
	x=c^48;c=getchar();
	while ((c>=48)&&(c<=57))
	{
		x=x*10+(c^48);
		c=getchar();
	}
}
void dfs1(int x)
{
	top[x]=1;
	for (int i=fir[x];i;i=nxt[i]) if (!top[lj[i]])
	{
		dfs1(lj[i]);
		if (len[lj[i]]>len[hc[x]]) hc[x]=lj[i];
	}
	len[x]=len[hc[x]]+1;top[hc[x]]=0;
}
void dfs2(int x)
{
	*f[x]=1;gs[x]=1;
	if (!hc[x]) return;
	ed[x]=1;f[hc[x]]=f[x]+1;
	for (int i=fir[x];i;i=nxt[i]) if (!ed[lj[i]]) dfs2(lj[i]);
	ans[x]=ans[hc[x]]+1;gs[x]=gs[hc[x]];
	if (gs[x]==1) ans[x]=0;
	for (int i=fir[x];i;i=nxt[i]) if ((!ed[lj[i]])&&(lj[i]!=hc[x]))
	{
		register int v=lj[i],*p;
		for (register int j=0;j<len[v];j++)
		{
			*(p=f[x]+j+1)+=*(f[v]+j);
			if (j+1==ans[x]) {gs[x]=*p;continue;}
			if ((*p>gs[x])||(*p==gs[x])&&(j+1<ans[x])) {gs[x]=*p;ans[x]=j+1;}
		}
	}
	gs[x]=*(f[x]+ans[x]);
	ed[x]=0;
}
int main()
{
	read(n);
	for (i=1;i<n;i++)
	{
		read(x);read(y);add();
	}
	dfs1(1);
	for (i=1;i<=n;i++) if (top[i]) {f[i]=tp;tp+=len[i];}
	dfs2(1);
	for (i=1;i<=n;i++) printf("%d\n",ans[i]);
}