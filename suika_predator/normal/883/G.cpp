#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
const int MAXN=300010;
struct edge
{
	int v,id,type;
	edge *next,*rev;
}*h[MAXN],pool[MAXN*2];
int top;
inline void addedge(int u,int v,int id,int t)
{
	edge *tmp=&pool[top++];tmp->v=v;tmp->id=id;tmp->next=h[u];h[u]=tmp;
	edge *pmt=&pool[top++];pmt->v=u;pmt->id=id;pmt->next=h[v];h[v]=pmt;
	tmp->rev=pmt;pmt->rev=tmp;
	if(t==1)tmp->type=1,pmt->type=0;
	else tmp->type=3,pmt->type=2;
}
int n,m,S;
int nt[MAXN];
int ans;
int vis[MAXN];
void dfs1(int u)//1:3;0:2
{
	vis[u]=1;
	ans++;
	for(edge *tmp=h[u];tmp;tmp=tmp->next)
	{
		if(tmp->type&&!vis[tmp->v])
		{
			nt[tmp->id]=tmp->type-2;
			dfs1(tmp->v);
		}
	}
}
void dfs2(int u)
{
	vis[u]=1;
	ans++;
	for(edge *tmp=h[u];tmp;tmp=tmp->next)
	{
		if(tmp->type==1)
		{
			if(!vis[tmp->v])
				dfs2(tmp->v);
		}
		else if(tmp->type)
		{
			nt[tmp->id]=3-tmp->type;
		}
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&S);
	int tmp,u,v;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&tmp,&u,&v);
		addedge(u,v,i,tmp);
		if(tmp==1)nt[i]=-1;
	}
	dfs1(S);
	printf("%d\n",ans);
	for(int i=1;i<=m;i++)
	{
		if(nt[i]!=-1)printf("%c","-+"[nt[i]]);
	}
	printf("\n");
	memset(vis,0,sizeof(vis));
	ans=0;
	dfs2(S);
	printf("%d\n",ans);
	for(int i=1;i<=m;i++)
	{
		if(nt[i]!=-1)printf("%c","-+"[nt[i]]);
	}
	printf("\n");
	return 0;
}