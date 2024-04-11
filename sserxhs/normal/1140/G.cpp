#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N=3e5+2,M=6e5+2,O=1.2e6+2;
ll len1[M],len2[M],v[N],g[N][4],ans[M];
ll lx,ly;
int lj[M],nxt[M],fir[N],f[N],qlj[O],qnxt[O],qfir[N],xw[O][3];
int flj[M],fnxt[M],ffir[N];
int n,q,i,x,y,c,bs,qs,fs;
bool ed[N];
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
inline void read(ll &x)
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
inline void add()
{
	lj[++bs]=y;
	len1[bs]=lx;
	len2[bs]=ly;
	nxt[bs]=fir[x];
	fir[x]=bs;
	lj[++bs]=x;
	len1[bs]=lx;
	len2[bs]=ly;
	nxt[bs]=fir[y];
	fir[y]=bs;
}
inline void fadd(int x,int y)
{
	flj[++fs]=y;
	fnxt[fs]=ffir[x];
	ffir[x]=fs;
}
inline void qadd(int x,int y,int i)
{
	qlj[++qs]=i;
	qnxt[qs]=qfir[x];
	qfir[x]=qs;
}
void dfs1(int x)
{
	ed[x]=1;
	for (int i=fir[x];i;i=nxt[i]) if (!ed[lj[i]])
	{
		dfs1(lj[i]);
		v[x]=min(v[x],v[lj[i]]+len1[i]+len2[i]);
	}
	ed[x]=0;
}
void dfs2(int x)
{
	ed[x]=1;
	for (int i=fir[x];i;i=nxt[i]) if (!ed[lj[i]])
	{
		v[lj[i]]=min(v[lj[i]],v[x]+len1[i]+len2[i]);
		dfs2(lj[i]);
	}
	ed[x]=0;
}
void dfs3(int x)
{
	ed[x]=1;
	for (int i=fir[x];i;i=nxt[i]) if (!ed[lj[i]])
	{
		g[lj[i]][0]=min(len2[i],v[x]+v[lj[i]]+len1[i]);
		g[lj[i]][1]=min(len2[i]+v[lj[i]],len1[i]+v[x]);
		g[lj[i]][2]=min(len1[i]+v[lj[i]],len2[i]+v[x]);
		g[lj[i]][3]=min(len1[i],v[x]+v[lj[i]]+len2[i]);
		dfs3(lj[i]);
	}
	ed[x]=0;
}
void getf(register int x)
{
	if (f[f[x]]==f[x]) return;
	getf(f[x]);
	g[0][0]=min(g[x][0]+g[f[x]][0],g[x][2]+g[f[x]][1]);
	g[0][1]=min(g[x][1]+g[f[x]][0],g[x][3]+g[f[x]][1]);
	g[0][2]=min(g[x][0]+g[f[x]][2],g[x][2]+g[f[x]][3]);
	g[0][3]=min(g[x][1]+g[f[x]][2],g[x][3]+g[f[x]][3]);
	memcpy(g[x],g[0],32);
	f[x]=f[f[x]];
}
void dfs4(int x)
{
	ed[x]=1;int i;
	for (i=qfir[x];i;i=qnxt[i]) if (ed[y=xw[qlj[i]][2]])
	{
		getf(y);
		fadd(f[y],qlj[i]);
	}
	for (i=fir[x];i;i=nxt[i]) if (!ed[lj[i]])
	{
		dfs4(lj[i]);
		f[lj[i]]=x;
	}
	for (i=ffir[x];i;i=fnxt[i])
	{
		y=flj[i];
		if (y>q) c=y-q; else c=y;
		if (xw[y][2]!=x)
		{
			qs=xw[y][0]>>1&1;bs=xw[y][0]&1;
			getf(xw[y][1]);getf(xw[y][2]);
			ans[c]=min(g[xw[y][1]][bs]+g[xw[y][2]][qs],g[xw[y][1]][bs|2]+g[xw[y][2]][qs|2]);
		}
		else {getf(xw[y][1]);ans[c]=g[xw[y][1]][xw[y][0]];}
	}
}
int main()
{
	read(n);
	for (i=1;i<=n;i++) read(v[i]);
	for (i=1;i<n;i++)
	{
		read(x);read(y);read(lx);read(ly);
		add();f[i]=i;
	}dfs1(1);dfs2(1);dfs3(1);
	read(q);
	for (i=1;i<=q;i++)
	{
		read(x);read(y);
		if (x+1>>1==y+1>>1) {if (x!=y) ans[i]=v[x+1>>1];continue;}
		xw[i][0]=(x&1)|(y&1)<<1;
		xw[i+q][0]=(y&1)|(x&1)<<1;
		qadd(xw[i][1]=xw[i+q][2]=x=x+1>>1,xw[i][2]=xw[i+q][1]=y=y+1>>1,i);
		qadd(y,x,i+q);
	}
	dfs4(1);
	for (i=1;i<=q;i++) printf("%lld\n",ans[i]);
}