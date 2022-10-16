#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=4e18;
inline int read()
{
	int x=0;
	bool flag=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			flag=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return (flag?x:~(x-1));
}
const int N=2e5+1;
struct node{
	int to,nxt,v;
}e[N<<1];
int cnt,n,top,ccnt,tot,w[N<<1],c[N<<1],is[N],st[N],vis[N],h[N],ans[N<<1],sz[N<<1],sums[N<<1],sumw[N<<1],sum[N<<1];
void add(int x,int y,int z)
{
	e[++cnt]={y,h[x],z};
	h[x]=cnt;
}
bool findc(int x,int fa)
{
	vis[x]=1;
	st[++top]=x;
	for(int i=h[x];i;i=e[i].nxt)
		if(e[i].to!=fa)
		{
			if(vis[e[i].to])
			{
				while(st[top]!=e[i].to)
				{
					is[st[top]]=1;
					c[++ccnt]=st[top--];
				}
				is[e[i].to]=1;
				c[++ccnt]=e[i].to;
				return 1;
			}
			if(findc(e[i].to,x))
				return 1;
		}
	vis[x]=0;
	top--;
	return 0;
}
void dfs(int x,int fa)
{
	sz[x]=1;
	for(int i=h[x];i;i=e[i].nxt)
		if(e[i].to!=fa&&!is[e[i].to])
		{
			dfs(e[i].to,x);
			ans[x]+=ans[e[i].to]+e[i].v*sz[e[i].to];
			sz[x]+=sz[e[i].to];
		}
}
void dfs1(int x,int fa)
{
	for(int i=h[x];i;i=e[i].nxt)
		if(e[i].to!=fa&&!is[e[i].to])
		{
			ans[e[i].to]=ans[x]+e[i].v*(n-sz[e[i].to]*2);
			dfs1(e[i].to,x); 
		}
}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		int x=read(),y=read(),z=read();
		add(x,y,z);
		add(y,x,z);
	}
	findc(1,0);
	for(int i=1;i<=n;i++)
		if(is[i])
			dfs(i,0);
	for(int i=1;i<=ccnt;i++)
	{
		c[ccnt+i]=c[i];
		tot+=ans[c[i]];
		for(int l=h[c[i]];l;l=e[l].nxt)
			if(e[l].to==c[i+1])
			{
				w[i+ccnt]=w[i]=e[l].v;
				break;
			}
	}
	for(int i=1;i<=ccnt*2;i++)
	{
		sums[i]=sums[i-1]+sz[c[i]];
		sumw[i]=sumw[i-1]+w[i];
		sum[i]=sum[i-1]+w[i]*sums[i];
	}
	for(int l=1,r=1;l<=ccnt;l++)
	{
		while(sumw[r]-sumw[l-1]<=(sumw[ccnt]>>1))
			r++;
		ans[c[l]]=tot+sums[r]*(sumw[r-1]-sumw[l-1])-sum[r-1]+sum[l-1]+sum[l+ccnt-1]-sum[r]-sums[r]*(sumw[l+ccnt-1]-sumw[r]);
		dfs1(c[l],0);
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	return 0;
}