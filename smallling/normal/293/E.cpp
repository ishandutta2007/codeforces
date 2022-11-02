#include<cstdio>
#include<algorithm>

#define fi first
#define se second
#define N 100010

using namespace std;

struct lhy{
	int x,y,next,l;
}edge[2*N];

int n,W,L,tot,h,l,r,w,Fa;
int son[N],vis[N],size[N],cost[N],c[N],flag[N],dis[N],q[N],fa[N];
long long ans;

inline void add(int x,int y,int w)
{
	edge[++tot].x=x;edge[tot].y=y;edge[tot].l=w;edge[tot].next=son[x];son[x]=tot;
}

int getroot(int x)
{
	h=l=0;
	q[++l]=x;
	flag[x]=1;
	fa[x]=0;
	while(h<l)
	{
		int v=q[++h];
		for(int i=son[v];i;i=edge[i].next)
			if(!vis[edge[i].y]&&!flag[edge[i].y])
			{
				flag[edge[i].y]=1;
				q[++l]=edge[i].y;
				fa[edge[i].y]=v;
			}
	}
	int Max=n+1,nowroot;
	for(int x=l;x;x--)
	{
		int v=q[x],nowmax=0;
		size[v]=0;
		for(int i=son[v];i;i=edge[i].next)
			if(!vis[edge[i].y]&&edge[i].y!=fa[v])
			{
				size[v]+=size[edge[i].y];
				nowmax=max(nowmax,size[edge[i].y]);
			}
		size[v]++;
		nowmax=max(nowmax,l-size[v]);
		if(nowmax<Max)
		{
			Max=nowmax;
			nowroot=v;
		}
	}
	for(int i=1;i<=l;i++)flag[q[i]]=0;
	return nowroot;
}

inline int cmp(int a,int b)
{
	return cost[a]>cost[b];
}

inline void add(int x,int o)
{
	for(;x<=n+1;x+=x&-x)c[x]+=o;
}

inline int ask(int x)
{
	if(x<0)return 0;
	int nowans=0;
	for(;x;x-=x&-x)nowans+=c[x];
	return nowans;
}

void doit(int x,int now)
{
	h=l=0;
	flag[x]=1;
	q[++l]=x;
	while(h<l)
	{
		int v=q[++h];
		for(int i=son[v];i;i=edge[i].next)
			if(!flag[edge[i].y]&&!vis[edge[i].y])
			{
				q[++l]=edge[i].y;
				flag[edge[i].y]=1;
			}
	}
	for(int i=1;i<=l;i++)flag[q[i]]=0;
	sort(q+1,q+1+l,cmp);
	r=l;
	for(int i=1;i<=l;i++)
	{
		while(cost[q[i]]+cost[q[r]]<=W&&r)add(dis[q[r]],1),r--;
		ans+=ask(L-dis[q[i]]+2)*now;
	}
	for(int i=r+1;i<=l;i++)
		add(dis[q[i]],-1);
}

void bfs(int x)
{
	dis[x]=1;
	h=l=0;
	q[++l]=x;
	flag[x]=1;
	cost[x]=0;
	while(h<l)
	{
		int v=q[++h];
		for(int i=son[v];i;i=edge[i].next)
			if(!flag[edge[i].y]&&!vis[edge[i].y])
			{
				int Y=edge[i].y;
				flag[Y]=1;
				q[++l]=Y;
				dis[Y]=dis[v]+1;
				cost[Y]=cost[v]+edge[i].l;
			}
	}
	for(int i=1;i<=l;i++)flag[q[i]]=0;
}

void work(int x)
{
	int root=getroot(x);
	vis[root]=1;
	bfs(root);
	doit(root,1);
	for(int i=son[root];i;i=edge[i].next)
		if(!vis[edge[i].y])doit(edge[i].y,-1);
	for(int i=son[root];i;i=edge[i].next)
		if(!vis[edge[i].y])work(edge[i].y);
}

int main()
{
	scanf("%d%d%d",&n,&L,&W);
	for(int i=2;i<=n;i++)
	{
		scanf("%d%d",&Fa,&w);
		add(Fa,i,w);
		add(i,Fa,w);
	}
	work(1);
	ans-=n;
	ans/=2;
	printf("%I64d\n",ans);
}