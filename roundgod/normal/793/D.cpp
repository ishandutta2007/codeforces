#include<bits/stdc++.h>
#define MAXN 85
#define MAXM 2005
#define INF 1000000000
using namespace std;
int n,m,k;
struct edge
{
	int to,cost;
};
vector<edge> G[MAXN];
int dp[MAXN][MAXN][MAXN][2];
int find_ans(int l,int r,int num,int color)
{
	if(dp[l][r][num][color]!=-1) return dp[l][r][num][color];
	if(num==0) return dp[l][r][num][color]=0;
	int v=(color==0?l:r);
	int res=INF;
	for(int i=0;i<G[v].size();i++)
	{
		int t=G[v][i].to,c=G[v][i].cost;
		if(t>l&&t<r) res=min(res,min(find_ans(l,t,num-1,1),find_ans(t,r,num-1,0))+c);
	}
	return dp[l][r][num][color]=res;
}
int main()
{
	scanf("%d%d%d",&n,&k,&m);
	for(int i=0;i<m;i++)
	{	
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		G[x].push_back((edge){y,z});
	}
	int ans=INF;
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<=n;i++)
		ans=min(ans,min(find_ans(0,i,k-1,1),find_ans(i,n+1,k-1,0)));
	if(ans==INF) puts("-1"); else printf("%d\n",ans);
	return 0;
}