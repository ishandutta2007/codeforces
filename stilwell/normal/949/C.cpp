#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,h,i,j,k,u,v;
int a[1000005];

int st[1000005],len,tarjan_index,newdot;
struct Graph_old
{
	int son;
	int dfn,low,from;
	bool inst;
}graph[1000005];

struct Graph_new
{
	int son,tot,init,outit;
}Graph[1000005];

struct Edge_node
{
	int next,ed;
}e[1000005],E[1000005];
int tot1,tot2;

void addedge(int u,int v){++tot1;e[tot1].next=graph[u].son;graph[u].son=tot1;e[tot1].ed=v;}
void Addedge(int u,int v){++tot2;E[tot2].next=Graph[u].son;Graph[u].son=tot2;E[tot2].ed=v;}

void tarjan(int now)
{
	int i;
	graph[now].dfn=graph[now].low=++tarjan_index;
	st[++len]=now;
	graph[now].inst=true;
	for(i=graph[now].son;i;i=e[i].next)
	if(!graph[e[i].ed].dfn)
	{
		tarjan(e[i].ed);
		if(graph[e[i].ed].low<graph[now].low)
		graph[now].low=graph[e[i].ed].low;
	}
	else
	{
		if((graph[e[i].ed].inst)&&(graph[e[i].ed].low<graph[now].low))
		graph[now].low=graph[e[i].ed].low;
	}
	if(graph[now].dfn==graph[now].low)
	{
		++newdot;
		for(;st[len]!=now;)
		{
			graph[st[len]].inst=false;
			graph[st[len]].from=newdot;
			++Graph[newdot].tot;
			--len;
		}
		graph[st[len]].inst=false;
		graph[st[len]].from=newdot;
		++Graph[newdot].tot;
		--len;
	}
}

void Tarjan()
{
	int i,j;
	for(i=1;i<=n;++i)
	if(!graph[i].dfn)tarjan(i);
	for(i=1;i<=n;++i)
	for(j=graph[i].son;j;j=e[j].next)
	if(graph[i].from!=graph[e[j].ed].from)
	{
		++Graph[graph[i].from].outit;
		++Graph[graph[e[j].ed].from].init;
		Addedge(graph[i].from,graph[e[j].ed].from);
	}
}

int main()
{
	scanf("%d%d%d",&n,&m,&h);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	for(;m;--m)
	{
		scanf("%d%d",&u,&v);
		if((a[u]+1)%h==a[v])addedge(u,v);
		if((a[v]+1)%h==a[u])addedge(v,u);
	}
	Tarjan();
	for(k=0,i=1;i<=newdot;++i)
	if(!Graph[i].outit)
	{
		if(k==0||Graph[i].tot<Graph[k].tot)
		k=i;
	}
	printf("%d\n",Graph[k].tot);
	for(i=1;i<=n;++i)if(graph[i].from==k)printf("%d ",i);
	printf("\n");
}