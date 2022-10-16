#include <stdio.h>
#include <string.h> 
#include <queue>
#define int long long
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num*f;
}
struct Edge{
	int v,nxt;
}e[400005],f[400005];
int h[200005],cnt=1,qw=0;
void addedge(int u,int v)
{
	e[cnt]=(Edge){v,h[u]};
	h[u]=cnt++;
}
int c=0;
int deg[200005],vis[200005];
void doufu(int n)
{
	std::queue<int> q;
	for(int i=1;i<=n;i++)if(deg[i]==0){vis[i]=++c;q.push(i);}
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int i=h[u];i;i=e[i].nxt)
		{
			int v=e[i].v;
			deg[v]--;
			//printf("marked v %lld\n",v);
			if(vis[v]||deg[v])continue;
			vis[v]=++c;
			q.push(v);
		}
	}
}
signed main()
{
	int T=read();
	while(T--)
	{
		cnt=1,qw=0,c=0;
		int n=read(),m=read();
		memset(h,0,sizeof(int)*(n+2));
		memset(deg,0,sizeof(int)*(n+2));
		memset(vis,0,sizeof(int)*(n+2));
		while(m--)
		{
			int w=read(),u=read(),v=read();
			if(w)addedge(u,v),deg[v]++;
			else f[qw++]=(Edge){u,v};
		}
		doufu(n);
		for(int i=1;i<=n;i++)
		{
			if(vis[i]==0)
			{
				puts("NO");
				goto ng;
			}
			//printf("%lld ",vis[i]);
		}
		puts("YES");
		for(int i=0;i<qw;i++)
		{
			int u=f[i].v,v=f[i].nxt;
			if(vis[u]<vis[v])addedge(u,v);
			else addedge(v,u);
		}
		for(int u=1;u<=n;u++)
		{
			for(int i=h[u];i;i=e[i].nxt)
			{
				int v=e[i].v;
				printf("%lld %lld\n",u,v);
			}
		}
		ng:;
	}
}