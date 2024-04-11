#include<iostream>
#include<cstdio>
#include<stack>
#include<cmath>
#include<cstring>
using namespace std;
struct edge
{
	int v;
	edge *next;
}*h[233333],pool[233333];
int top;
inline void addedge(int u,int v)
{
	edge *tmp=&pool[top++];tmp->v=v;tmp->next=h[u];h[u]=tmp;
	edge *pmt=&pool[top++];pmt->v=u;pmt->next=h[v];h[v]=pmt;
}
int n,m;
int a[233333],dep[233333],ans[233333],vis[233333];
int pr[2333333];
stack<int> st[233333];
void dfs(int u)
{
	vis[u]=1;
	int t=a[u],s=sqrt(t);
	for(int d=2;d<=s;d++)
	{
		if(t%d==0)
		{
			if(!st[pr[d]].empty()&&(!ans[u]||dep[ans[u]]<=dep[st[pr[d]].top()]))ans[u]=st[pr[d]].top();
			st[pr[d]].push(u);
			while(t%d==0)t/=d;
			s=sqrt(t);
		}
	}
	if(t!=1)
	{
		if(!st[pr[t]].empty()&&(!ans[u]||dep[ans[u]]<=dep[st[pr[t]].top()]))ans[u]=st[pr[t]].top();
		st[pr[t]].push(u);
	}
	for(edge *tmp=h[u];tmp;tmp=tmp->next)
	{
		if(!vis[tmp->v])
		{
			dep[tmp->v]=dep[u]+1;
			dfs(tmp->v);
		}
	}
	vis[u]=0;
	t=a[u],s=sqrt(t);
	for(int d=2;d<=s;d++)
	{
		if(t%d==0)
		{
			st[pr[d]].pop();
			while(t%d==0)t/=d;
			s=sqrt(t);
		}
	}
	if(t!=1)st[pr[t]].pop();
}
inline void init()
{
	int top=0;
	for(int i=2;i<=2000000;i++)
	{
		int s=sqrt(i),fl=1;
		for(int j=2;j<=s;j++)
		{
			if(i%j==0)
			{
				fl=false;
				break;
			}
		}
		if(fl)pr[i]=++top;
	}
//	cerr<<top<<endl;
}
int main()
{
	init();
	scanf("%d%d",&n,&m);
	int u,v;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<n;i++)scanf("%d%d",&u,&v),addedge(u,v);
	dep[1]=1;
	dfs(1);
	int ty;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&ty);
		if(ty==1)
		{
			scanf("%d",&u);
			if(ans[u]==0)printf("-1\n");
			else printf("%d\n",ans[u]);
		}
		else
		{
			scanf("%d",&u);
			scanf("%d",&a[u]);
			memset(ans,0,sizeof(ans));
			dfs(1);
		}
	}
	return 0;
}