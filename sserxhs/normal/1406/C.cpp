#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+2,M=2e5+2;
int lj[M],nxt[M],fir[N],siz[N],f[N];
int n,c,fh,i,t,x,y,bs,minn,rt1,rt2;
inline void read(int &x)
{
	c=getchar();fh=1;
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
inline void add()
{
	lj[++bs]=y;
	nxt[bs]=fir[x];
	fir[x]=bs;
	lj[++bs]=x;
	nxt[bs]=fir[y];
	fir[y]=bs;
}
void dfs1(int x)
{
	siz[x]=1;int maxx=0;
	for (int i=fir[x];i;i=nxt[i]) if (!siz[lj[i]])
	{
		dfs1(lj[i]);
		f[lj[i]]=x;
		siz[x]+=siz[lj[i]];
		maxx=max(maxx,siz[lj[i]]);
	}
	maxx=max(maxx,n-siz[x]);
	if (maxx<minn)
	{
		minn=maxx;rt1=x;rt2=0;
	} else if (maxx==minn) rt2=x;
}
void dfs2(int x)
{
	siz[x]=1;
	for (int i=fir[x];i;i=nxt[i]) if (!siz[lj[i]])
	{
		dfs2(lj[i]);
		f[lj[i]]=x;
		siz[x]+=siz[lj[i]];
	}
}
int main()
{
	read(t);
	while (t--)
	{
		memset(fir+1,0,n<<2);
		memset(siz+1,0,n<<2);
		read(n);rt2=0;
		for (i=1;i<n;i++)
		{
			read(x);read(y);add();
		}minn=n+1;
		dfs1(1);
		if (!rt2)
		{
			printf("%d %d\n%d %d\n",x,y,x,y);
			continue;
		}
		if (rt2)
		{
			memset(siz+1,0,n<<2);
			siz[rt2]=2;
			dfs2(rt1);
			for (i=1;i<=n;i++) if (siz[i]==1)
			{
				printf("%d %d\n%d %d\n",i,f[i],i,rt2);
				break;
			}
		}
	}
}