#include<bits/stdc++.h>
#define MAXN 80
#define INF 1000000007
using namespace std;
int n;
string S;
int dp[MAXN][MAXN][MAXN][2];
vector<int> V,K,X;
int count_remaining(const vector<int> &list,int from,int limit)
{
	int cnt=0;
	for(int i=from;i<list.size()&&list[i]<limit;i++)
		cnt++;
	return cnt;
}
int main()
{
	scanf("%d",&n);
	cin>>S;
	for(int i=0;i<S.length();i++)
	{
		if(S[i]=='V') V.push_back(i);
		else if(S[i]=='K') K.push_back(i);
		else X.push_back(i);
	}
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			for(int k=0;k<=n;k++)
				for(int l=0;l<2;l++)
					dp[i][j][k][l]=INF;
	dp[0][0][0][0]=0;
	for(int v=0;v<=V.size();v++)
		for(int k=0;k<=K.size();k++)
			for(int x=0;x<=X.size();x++)
				for(int type=0;type<2;type++)
				{
					auto moving_cost=[&](int where)
					{
						return count_remaining(V,v,where)+count_remaining(K,k,where)+count_remaining(X,x,where);
					};
					int already=dp[v][k][x][type];
					if(v<V.size()) dp[v+1][k][x][1]=min(dp[v+1][k][x][1],already+moving_cost(V[v]));
					if(k<K.size()&&type!=1) dp[v][k+1][x][0]=min(dp[v][k+1][x][0],already+moving_cost(K[k]));
					if(x<X.size()) dp[v][k][x+1][0]=min(dp[v][k][x+1][0],already+moving_cost(X[x])); 
				}
	int ans=INF;
	for(int i=0;i<2;i++)
		ans=min(ans,dp[V.size()][K.size()][X.size()][i]);
	printf("%d\n",ans);
	return 0;
}