#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int MAXN=233333, MAXM=555555;
struct edge
{
	int v;
	edge *next;
}*h[MAXN],*rh[MAXN],pool[MAXM];
int top;
inline void addedge(int u,int v)
{
	edge *tmp=&pool[top++];tmp->v=v;tmp->next=h[u];h[u]=tmp;
	edge *pmt=&pool[top++];pmt->v=u;pmt->next=rh[v];rh[v]=pmt;
}
queue<int> q;
int dp[MAXN][2];
int vis[MAXN];
void dfs(int u)
{
	vis[u]=1;
	for(edge *tmp=h[u];tmp;tmp=tmp->next)
	{
		if(vis[tmp->v]==1)
		{
			printf("Draw\n");
			exit(0);
		}
		else if(!vis[tmp->v])dfs(tmp->v);
	}
	vis[u]=2;
}
vector<int> ans;
int main()
{
	int n,m,cc,v,s;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&cc);
		if(cc==0)q.push(i),dp[i][1]=-1,vis[i]=1;
		while(cc--)
		{
			scanf("%d",&v);
			addedge(i,v);
		}
	}
	scanf("%d",&s);
	while(!q.empty())
	{
		int u=q.front();q.pop();vis[u]=0;
		for(edge *tmp=rh[u];tmp;tmp=tmp->next)
		{
			if(dp[u][0]&&!dp[tmp->v][1])
			{
				dp[tmp->v][1]=u;
				if(!vis[tmp->v])q.push(tmp->v),vis[tmp->v]=1;
			}
			if(dp[u][1]&&!dp[tmp->v][0])
			{
				dp[tmp->v][0]=u;
				if(!vis[tmp->v])q.push(tmp->v),vis[tmp->v]=1;
			}
		}
	}
	if(dp[s][0])
	{
		printf("Win\n");
		int cur=s,fl=0;
		while(dp[cur][fl]!=-1)
		{
			ans.push_back(cur);
			cur=dp[cur][fl];
			fl^=1;
		}
		ans.push_back(cur);
		for(auto x:ans)printf("%d ",x);
	}
	else
	{
		dfs(s);
		printf("Lose\n");
	}
	return 0;
}