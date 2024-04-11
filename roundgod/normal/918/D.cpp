#include<bits/stdc++.h>
#define F first
#define S second
#define MAXN 105
using namespace std;
int n,m;
int dp[MAXN][MAXN][26][2];
struct edge
{
	int to;
	char c;
};
vector<edge> G[MAXN];
int win(int u,int v,char ch,int state)
{
	if(dp[u][v][ch-'a'][state]!=-1) return dp[u][v][ch-'a'][state];
	if(state==0)
	{
		for(int i=0;i<G[u].size();i++)
		{
			int to=G[u][i].to;char c=G[u][i].c;
			if(c<ch) continue;
			if(win(G[u][i].to,v,c,1)==0) return dp[u][v][ch-'a'][state]=1;
		}
		return dp[u][v][ch-'a'][state]=0;
	}
	else
	{
		for(int i=0;i<G[v].size();i++)
		{
			int to=G[v][i].to;char c=G[v][i].c;
			if(c<ch) continue;
			if(win(u,G[v][i].to,c,0)==0) return dp[u][v][ch-'a'][state]=1;
		}
		return dp[u][v][ch-'a'][state]=0;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int u,v;
		char ch;
		scanf("%d %d %c",&u,&v,&ch);
		G[u-1].push_back((edge){v-1,ch});
	}
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			if(win(i,j,'a',0)) printf("A"); else printf("B");
		printf("\n");
	}
	return 0;
}