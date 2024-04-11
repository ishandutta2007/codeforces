#include<bits/stdc++.h>
using namespace std;
int t,n,m,p[100001],h[100001],x,y,head[100001],to[200001],nxt[200001];
int tot,siz[100001],up[100001],down[100001];
bool f;
void add(int x,int y)
{
	to[++tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
}
void dfs1(int x,int fa)
{
	siz[x]=p[x];
	for(register int i=head[x];i;i=nxt[i])
	{
		int y=to[i];
		if(y==fa)
		    continue;
		dfs1(y,x);
		siz[x]+=siz[y];
	}
}
void dfs2(int x,int fa)
{
	if(h[x]>0)
	{
		if(siz[x]<h[x]||((siz[x]-h[x])&1))
		{
			f=0;
			return;
		}
		else
		{
			down[x]=(siz[x]-h[x])>>1;
			up[x]=siz[x]-down[x];
		}
	}
	else
	{
		if(siz[x]<-h[x]||((siz[x]+h[x])&1))
		{
			f=0;
			return;
		}
		else
		{
			up[x]=(siz[x]+h[x])>>1;
			down[x]=siz[x]-up[x];
		}
	}
	int ups=0,downs=0;
	for(int i=head[x];i;i=nxt[i])
	{
		int y=to[i];
		if(y==fa)
		    continue;
		dfs2(y,x);
		ups+=up[y];
		downs+=down[y];
	}
	if((ups!=0||downs!=0)&&(ups-p[x]>up[x]||downs+p[x]<down[x]))
	    f=0;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		memset(head,0,sizeof(head));
		tot=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
		    scanf("%d",&p[i]);
		for(int i=1;i<=n;++i)
		    scanf("%d",&h[i]);
		for(int i=1;i<n;++i)
		{
			scanf("%d%d",&x,&y);
			add(x,y);
			add(y,x);
		}
		memset(siz,0,sizeof(siz));
		f=1;
		dfs1(1,0);
		dfs2(1,0);
		if(f)
		    printf("YES\n");
		else
		    printf("NO\n");
	}
	return 0;
}