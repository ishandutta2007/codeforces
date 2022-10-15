#include<bits/stdc++.h>
#define MAXN 300005
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
int n,m;
char str[MAXN];
vector<int> G[MAXN];
int color[MAXN],dp[MAXN][26];
deque<int> order;
bool dfs_visit(int v)
{
	color[v]=1;
	bool f=true;
	for(int i=0;i<G[v].size();i++)
	{
		int to=G[v][i];
		if(color[to]==1) return false;
		if(color[to]==0) {if(!dfs_visit(to)) f=false;}
	}
	color[v]=2;
	order.push_front(v);
	return f;
}
bool toposort()
{
	memset(color,0,sizeof(color));
	for(int i=0;i<n;i++)
		if(color[i]==0)
			if(!dfs_visit(i)) return false;
	return true;
}
void find_ans(int v)
{
	int res=-1;
	for(int i=0;i<26;i++)
		res=max(res,dp[v][i]);
	if(res!=-1) return;
	memset(dp[v],0,sizeof(dp[v]));
	dp[v][str[v]-'a']=1;
	for(int i=0;i<G[v].size();i++)
	{
		find_ans(G[v][i]);
		for(int j=0;j<26;j++)
			if(str[v]-'a'==j) dp[v][j]=max(dp[v][j],dp[G[v][i]][j]+1); else dp[v][j]=max(dp[v][j],dp[G[v][i]][j]);
	}
	return;
}
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",str);
	bool f=true;
	for(int i=0;i<m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		G[x-1].push_back(y-1);
		if(x==y) f=false;
	}
	order.clear();
	if(!f||!toposort())
	{
		printf("-1\n");
		return 0;
	}
	memset(dp,-1,sizeof(dp));
	int ans=0;
	for(int i=0;i<n;i++)
	{
		find_ans(order[i]);
		for(int j=0;j<26;j++)
			ans=max(ans,dp[order[i]][j]);
	}
	printf("%d\n",ans);
	return 0;
}