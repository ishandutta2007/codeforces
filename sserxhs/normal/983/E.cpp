#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int N=2e5+2,M=4e5+20,K=20;
int dfn[N],f[N],top[N],lj[N],nxt[N],fir[N],s[N],bz[N][21],zd[N],siz[N];
int clj[M],cnxt[M],cfir[N],deep[N],qlj[N][2],qnxt[N],qs[N],qfir[N],ans[N];
int xlj[N][2],xnxt[N],xfir[N],hc[N],st[N];
int n,m,q,i,j,x,y,z,c,bs,ds,cbs,qbs,xbs,si,tp;
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
inline void add(int x,int y)
{
	lj[++bs]=y;
	nxt[bs]=fir[x];
	fir[x]=bs;
}
inline void cadd(int x,int y)
{
	clj[++cbs]=y;
	cnxt[cbs]=cfir[x];
	cfir[x]=cbs;
	clj[++cbs]=x;
	cnxt[cbs]=cfir[y];
	cfir[y]=cbs;
}
inline void qadd(int x,int y,int z)
{
	qlj[++qbs][0]=y;
	qlj[qbs][1]=z;
	qnxt[qbs]=qfir[x];
	qfir[x]=qbs;
}
inline void xadd(int x,int y,int z)
{
	xlj[++xbs][0]=y;
	xlj[xbs][1]=z;
	xnxt[xbs]=xfir[x];
	xfir[x]=xbs;
}
inline int lca(int x,int y)
{
	while (top[x]!=top[y])
	{
		if (deep[top[x]]<deep[top[y]]) swap(x,y);
		x=f[top[x]];
	}
	if (deep[x]>deep[y]) swap(x,y);
	return x;
}
inline int lb(int x)
{
	return x&(-x);
}
inline void change(int x)
{
	for (si=x;si<=n;si+=lb(si)) ++s[si];
}
inline int sum(int x)
{
	int ans=0;
	for (si=x;si;si-=lb(si)) ans+=s[si];
	return ans;
}
void dfs1(int x)
{
	siz[x]=1;
	for (st[++tp]=fir[x];st[tp];st[tp]=nxt[st[tp]])
	{
		deep[lj[st[tp]]]=deep[x]+1;
		dfs1(lj[st[tp]]);
		siz[x]+=siz[lj[st[tp]]];
	}
	--tp;
}
void dfs2(int x)
{
	zd[x]=dfn[x]=++ds;
	for (i=fir[x];i;i=nxt[i]) if (siz[hc[x]]<siz[lj[i]]) hc[x]=lj[i];
	if (hc[x])
	{
		top[hc[x]]=top[x];
		dfs2(hc[x]);
		zd[x]=max(zd[x],zd[hc[x]]);
		for (st[++tp]=fir[x];st[tp];st[tp]=nxt[st[tp]]) if (lj[st[tp]]!=hc[x])
		{
			top[lj[st[tp]]]=lj[st[tp]];
			dfs2(lj[st[tp]]);
			zd[x]=max(zd[x],zd[lj[st[tp]]]);
		}
		--tp;
	}
}
void dfs3(int x)
{
	bz[x][0]=x;
	for (i=cfir[x];i;i=cnxt[i])
	{
		y=lca(x,clj[i]);
		if (deep[y]<deep[bz[x][0]]) bz[x][0]=y;
	}
	for (st[++tp]=fir[x];st[tp];st[tp]=nxt[st[tp]])
	{
		dfs3(lj[st[tp]]);
		if (deep[bz[lj[st[tp]]][0]]<deep[bz[x][0]]) bz[x][0]=bz[lj[st[tp]]][0];
	}
	--tp;
}
void dfs5(int x)
{
	for (i=qfir[x];i;i=qnxt[i])
	{
		y=x;z=qlj[i][0];c=lca(y,z);
		if ((deep[bz[y][K]]>deep[c])||(deep[bz[z][K]]>deep[c]))
		{
			ans[qlj[i][1]]=-1;
			continue;
		}
		if ((c==y)||(c==z))
		{
			if (y==z) continue;
			if (c!=y) swap(y,z);
			for (j=K;j>=0;j--) if (deep[bz[z][j]]>deep[y])
			{
				z=bz[z][j];
				ans[qlj[i][1]]+=(1<<j);
			}
			++ans[qlj[i][1]];
			continue;
		}
		for (j=K;j>=0;j--) if (deep[bz[bz[y][j]][0]]>deep[c])
		{
			y=bz[y][j];
			ans[qlj[i][1]]+=(1<<j);
		}
		for (j=K;j>=0;j--) if (deep[bz[bz[z][j]][0]]>deep[c])
		{
			z=bz[z][j];
			ans[qlj[i][1]]+=1<<j;
		}
		if (deep[bz[y][0]]>deep[c])
		{
			++ans[qlj[i][1]];
			y=bz[y][0];
		}
		if (deep[bz[z][0]]>deep[c])
		{
			++ans[qlj[i][1]];
			z=bz[z][0];
		}
		xadd(y,z,qlj[i][1]);
	}
	for (st[++tp]=fir[x];st[tp];st[tp]=nxt[st[tp]]) dfs5(lj[st[tp]]);
	--tp;
}
void dfs6(int x)
{
	for (i=xfir[x];i;i=xnxt[i])
	{
		qs[i]=sum(zd[xlj[i][0]])-sum(dfn[xlj[i][0]]-1);
	}
	for (i=cfir[x];i;i=cnxt[i]) change(dfn[clj[i]]);
	for (st[++tp]=fir[x];st[tp];st[tp]=nxt[st[tp]]) dfs6(lj[st[tp]]);
	--tp;
	for (i=xfir[x];i;i=xnxt[i]) if (qs[i]!=sum(zd[xlj[i][0]])-sum(dfn[xlj[i][0]]-1)) ++ans[xlj[i][1]]; else ans[xlj[i][1]]+=2;
}
void dfs4(int x)
{
	for (i=1;i<=K;i++) bz[x][i]=bz[bz[x][i-1]][i-1];
	for (st[++tp]=fir[x];st[tp];st[tp]=nxt[st[tp]]) dfs4(lj[st[tp]]);
	--tp;
}
int main()
{
	//freopen("car.in","r",stdin);
	//freopen("car.out","w",stdout);
	read(n);
	for (i=2;i<=n;i++)
	{
		read(x);
		add(x,i);
		f[i]=x;
	}
	read(m);
	while (m--)
	{
		read(x);read(y);
		cadd(x,y);
	}
	read(q);
	for (i=1;i<=q;i++)
	{
		read(x);read(y);
		qadd(x,y,i);
	}
	dfs1(top[1]=1);
	dfs2(1);
	dfs3(1);
	dfs4(1);
	dfs5(1);
	dfs6(1);
	for (i=1;i<=q;i++) printf("%d\n",ans[i]);
}