#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<queue>
using namespace std;
const int MAXN=333333;
int n,m,a,b;
char buf[MAXN];
int deg[MAXN];
struct edge
{
	int v;
	edge *next;
}*h[MAXN],pool[MAXN];
int top;
inline void addedge(int u,int v)
{
	edge *tmp=&pool[top++];tmp->v=v;tmp->next=h[u];h[u]=tmp;deg[v]++;
}
queue<int> q;
int dp[33][MAXN],ans;
int main()
{
	scanf("%d%d",&n,&m);
	scanf(" %s",buf+1);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		addedge(a,b);
	}
	for(int i=1;i<=n;i++)if(deg[i]==0)q.push(i),dp[buf[i]-'a'][i]=1;
	int cnt=0;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		cnt++;
		for(edge *tmp=h[u];tmp;tmp=tmp->next)
		{
			deg[tmp->v]--;
			for(int i=0;i<26;i++)
			{
				dp[i][tmp->v]=max(dp[i][tmp->v],dp[i][u]+(buf[tmp->v]==i+'a'));
				ans=max(ans,dp[i][tmp->v]);
			}
			if(deg[tmp->v]==0)q.push(tmp->v);
		}
	}
	if(cnt!=n)printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}