#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,i,j,k;
int st[100001],len,tarjan_index,newdot;
struct Gragh_old
{
	int son;
	int dfn,low,from;
	bool inst;
}gragh[100001];

struct Gragh_new
{
	int son,tot,init;
}Gragh[100001];

struct Edge_node
{
	int next,ed;
}e[4000001],E[4000001];
int tot1,tot2;

void addedge(int u,int v){++tot1;e[tot1].next=gragh[u].son;gragh[u].son=tot1;e[tot1].ed=v;}
void Addedge(int u,int v){++tot2;E[tot2].next=Gragh[u].son;Gragh[u].son=tot2;E[tot2].ed=v;}

void tarjan(int now)
{
	int i;
	gragh[now].dfn=gragh[now].low=++tarjan_index;
	st[++len]=now;
	gragh[now].inst=true;
	for(i=gragh[now].son;i;i=e[i].next)
	if(!gragh[e[i].ed].dfn)
	{
		tarjan(e[i].ed);
		if(gragh[e[i].ed].low<gragh[now].low)
		gragh[now].low=gragh[e[i].ed].low;
	}
	else
	{
		if((gragh[e[i].ed].inst)&&(gragh[e[i].ed].low<gragh[now].low))
		gragh[now].low=gragh[e[i].ed].low;
	}
	if(gragh[now].dfn==gragh[now].low)
	{
		++newdot;
		for(;st[len]!=now;)
		{
			gragh[st[len]].inst=false;
			gragh[st[len]].from=newdot;
			++Gragh[newdot].tot;
			--len;
		}
		gragh[st[len]].inst=false;
		gragh[st[len]].from=newdot;
		++Gragh[newdot].tot;
		--len;
	}
}

void Tarjan()
{
	int i,j;
	for(i=1;i<=n;++i)
	if(!gragh[i].dfn)tarjan(i);
	for(i=1;i<=n;++i)
	for(j=gragh[i].son;j;j=e[j].next)
	if(gragh[i].from!=gragh[e[j].ed].from)
	{
		++Gragh[gragh[e[j].ed].from].init;
		Addedge(gragh[i].from,gragh[e[j].ed].from);
	}
}

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	for(j=1;j<=n;++j)
	{
		scanf("%d",&k);
		if(k)addedge(i,j);
	}
	Tarjan();
	if(newdot==1)printf("YES\n");
	else printf("NO\n");
}