#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=300010;
int n,m;
int pa[MAXN];
int find(int x){return pa[x]?pa[x]=find(pa[x]):x;}
inline void onion(int x,int y){pa[find(x)]=pa[find(y)];}
struct edge
{
	int v,id;
	edge *next;
}*h[MAXN],pool[MAXN*2];
int top;
inline void addedge(int u,int v,int id)
{
	edge *tmp=&pool[top++];tmp->v=v;tmp->id=id;tmp->next=h[u];h[u]=tmp;
	edge *pmt=&pool[top++];pmt->v=u;pmt->id=id;pmt->next=h[v];h[v]=pmt;
}
int d[MAXN],vis[MAXN];
int dp[MAXN],ch[MAXN],chcnt;
inline void dfs(int x)
{
	vis[x]=1;
	int cnt=0;
	for(edge *tmp=h[x];tmp;tmp=tmp->next)
	{
		if(!vis[tmp->v])
		{
			dfs(tmp->v);
			if(dp[tmp->v])
			{
				cnt+=dp[tmp->v];
				ch[tmp->id]=1;
				++chcnt;
			}
		}
	}
	cnt+=d[x];
	dp[x]=cnt%2;
}
int main()
{
	scanf("%d%d",&n,&m);
	int cnt=0,flag=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&d[i]);
		if(d[i]==1)cnt++;
		if(d[i]==-1&&!flag)
		{
			flag=i;
		}
		else if(d[i]==-1)
		{
			d[i]=0;
		}
	}
	if(flag)
	{
		if(cnt%2)d[flag]=1;
		else d[flag]=0;
	}
	else if(cnt%2)
	{
		printf("-1\n");
		return 0;
	}
	int u,v;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		if(find(u)!=find(v))
		{
			onion(u,v);
			addedge(u,v,i);
		}
	}
	dfs(1);
	printf("%d\n",chcnt);
	for(int i=1;i<=m;i++)
	{
		if(ch[i])printf("%d ",i);
	}
	return 0;
}