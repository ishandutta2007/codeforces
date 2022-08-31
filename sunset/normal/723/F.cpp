#include<bits/stdc++.h>

using namespace std;

const int maxn=200020;

int n,m,cnt;

int s,t,ds,dt,d1,d2,d3,d4,tp;//d1-only s d2-only t d3-s,t d4-s-t

int f[maxn<<1],head[maxn<<1],ss[maxn<<1],tt[maxn<<1],vis[maxn<<1],vis2[maxn<<1],from[maxn<<1],to[maxn<<1];

int findfa(int x)
{
	return f[x]==x?x:f[x]=findfa(f[x]);
}

void uni(int x,int y)
{
	int p=findfa(x);
	int q=findfa(y);
	f[p]=q;
}

struct edge
{
	int to,nxt;
}e[maxn<<2];

void addedge(int from,int to)
{
	e[++cnt].to=to;
	e[cnt].nxt=head[from];
	head[from]=cnt;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	}
	scanf("%d%d%d%d",&s,&t,&ds,&dt);
	for(int i=1;i<=m;i++)
	{
		if(i!=s&&i!=t)
		{
			for(int j=head[i];j;j=e[j].nxt)
			{
				int y=e[j].to;
				if(y!=s&&y!=t&&findfa(i)!=findfa(y))
				{
					uni(i,y);
					from[++tp]=i;
					to[tp]=y;
				}
			}
		}
	}
	for(int i=head[s];i;i=e[i].nxt)
	{
		int y=e[i].to;
		if(!vis[findfa(y)])
		{
			vis[findfa(y)]=y;
		}
	}
	for(int i=head[t];i;i=e[i].nxt)
	{
		int y=e[i].to;
		if(!vis2[findfa(y)])
		{
			vis2[findfa(y)]=y;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(i==s||i==t)
		{
			if(vis[i]||vis2[i])
				d4++;
		}
		else
		{
			if(vis[i]&&(!vis2[i])&&findfa(vis[i])!=findfa(s))
				d1++,from[++tp]=vis[i],to[tp]=s,uni(vis[i],s),vis[i]=0;//cout<<vis[i]<<s;
			else if((!vis[i])&&vis2[i]&&findfa(vis2[i])!=findfa(t))
				d2++,from[++tp]=vis2[i],to[tp]=t,uni(vis2[i],t),vis2[i]=0;
			else if(vis[i]&&vis2[i])
				d3++;
		}
	}
	ds-=d1;
	dt-=d2;
	if(ds<0||dt<0)
	{
		printf("No");
		return 0;
	}
	if(d3>ds+dt)
	{
		printf("No");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(i!=s&&i!=t)
		{
			if(vis[i]&&ds>0&&findfa(vis[i])!=findfa(s))
			{
				from[++tp]=vis[i];//cout<<vis[i]<<" "<<s<<endl;
				to[tp]=s;
				uni(s,vis[i]);
				ds--;
			}
			if(vis2[i]&&dt>0&&findfa(vis2[i])!=findfa(t))
			{
				from[++tp]=vis2[i];
				to[tp]=t;//cout<<vis2[i]<<" "<<t<<endl;
				uni(t,vis2[i]);
				dt--;
			}
		}
	}
	if(findfa(s)!=findfa(t))
	{
		if(ds&&dt)
		{
			from[++tp]=s;
			to[tp]=t;
		}
		else
		{
			printf("No");
			return 0;
		}
	}
	if(tp<n-1)
	{
		printf("No");
		return 0;
	}
	printf("Yes\n");
	for(int i=1;i<=tp;i++)
	{
		printf("%d %d\n",from[i],to[i]);
	}
	return 0;
}