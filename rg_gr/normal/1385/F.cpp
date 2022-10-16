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
}e[400005];
int h[200005],cnt=1,qw=0;
struct Node{
	int i,v;
	bool operator<(const Node& b)const
	{
		return v<b.v;
	}
};
void addedge(int u,int v)
{
	e[cnt]=(Edge){v,h[u]};
	h[u]=cnt++;
}
int c=0;
int deg[200005],vis[200005],a[200005];
void maintain(int &ans,int o,int x)
{
//	printf("pushing %lld with %lld degs and %lld A. (ans += %lld)\n",o,deg[o],a[o],a[o]/x);
	if(a[o]<x)return;
	ans+=a[o]/x;
	deg[o]-=a[o]/x*x;
	a[o]%=x;
	if(deg[o]==1)
	{
		for(int i=h[o];i;i=e[i].nxt)
		{
			int v=e[i].v;
			if(deg[v]>1)
			{
				a[v]++;
				maintain(ans,v,x);
				return;
			}
		}
	}
}
signed main()
{
	int T=read();
	while(T--)
	{
		cnt=1,c=0;
		int n=read(),x=read();
		memset(h,0,sizeof(int)*(n+2));
		memset(deg,0,sizeof(int)*(n+2));
		memset(a,0,sizeof(int)*(n+2));
		memset(vis,0,sizeof(int)*(n+2));
		for(int i=1;i<n;i++)
		{
			int u=read(),v=read();
			addedge(u,v),addedge(v,u),deg[u]++,deg[v]++;
		}
		if(x==1){printf("%lld\n",n-1);continue;}
		for(int i=1;i<=n;i++)
		{
			if(deg[i]>1)continue;
			int v=e[h[i]].v;
			a[v]++;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>=x)maintain(ans,i,x);
			//puts("");
		}
		printf("%lld\n",ans);
	}
}