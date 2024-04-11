#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
const int MAXN=200010;
struct edge
{
	int v;
	edge *next;
}*h[MAXN],pool[MAXN*2];
int top;
inline void addedge(int u,int v)
{
	edge *tmp=&pool[top++];tmp->v=v;tmp->next=h[u];h[u]=tmp;
	edge *pmt=&pool[top++];pmt->v=u;pmt->next=h[v];h[v]=pmt;
}
int n,m;
int a[MAXN];
set<int> dp[MAXN][2];
void dfs(int u,int pa)
{
	if(pa==0)
	{
		dp[u][0].insert(a[u]);
	}
	else
	{
		for(auto x:dp[pa][0])
			dp[u][0].insert(__gcd(x,a[u]));
		if(pa==1)
		{
			for(auto x:dp[pa][0])
				dp[u][1].insert(x);
			for(int x=1;x*x<=a[u];x++)
			{
				dp[u][1].insert(a[u]);
			}
		}
		else
		{
			for(auto x:dp[pa][0])
				dp[u][1].insert(x);
			for(auto x:dp[pa][1])
				dp[u][1].insert(__gcd(x,a[u]));
		}
	}
	for(edge *tmp=h[u];tmp;tmp=tmp->next)
	{
		if(tmp->v!=pa)
		{
			dfs(tmp->v,u);
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int x,y;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		addedge(x,y);
	}
	dfs(1,0);
	printf("%d ",a[1]);
	for(int i=2;i<=n;i++)printf("%d ",*(dp[i][1].rbegin()));
	/*for(int i=1;i<=n;i++)
	{
		for(int j=0;j<dp[i][0].size();j++)printf("%d ",dp[i][0][j]);printf("\n");
		for(int j=0;j<dp[i][1].size();j++)printf("%d ",dp[i][1][j]);printf("\n");
	}*/
	return 0;
}