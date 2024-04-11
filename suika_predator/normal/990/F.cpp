#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
struct edge
{
	int v,id;
	edge *next;
}*h[233333],pool[555555];
int top;
inline void addedge(int u,int v,int id)
{
	edge *tmp=&pool[top++];tmp->v=v;tmp->id=id;tmp->next=h[u];h[u]=tmp;
	edge *pmt=&pool[top++];pmt->v=u;pmt->id=-id;pmt->next=h[v];h[v]=pmt;
}
int n,m;
int s[233333],f[233333],vis[233333],pa[233333];
void dfs(int u)
{
	vis[u]=1;
	for(edge *tmp=h[u];tmp;tmp=tmp->next)
	{
		if(tmp->v!=pa[u]&&!vis[tmp->v])
		{
			pa[tmp->v]=u;
			dfs(tmp->v);
			if(s[tmp->v])
			{
				if(tmp->id>0)f[tmp->id]+=s[tmp->v];
				else f[-tmp->id]-=s[tmp->v];
				s[u]+=s[tmp->v];
			}
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&s[i]);
	scanf("%d",&m);
	int u,v;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		addedge(u,v,i);
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			dfs(i);
			if(s[i]!=0)
			{
				printf("Impossible\n");
				return 0;
			}
		}
	}
	printf("Possible\n");
	for(int i=1;i<=m;i++)printf("%d\n",f[i]);
	return 0;
}