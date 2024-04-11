#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k;
vector<int> G[MAXN];
int find_ans(int id,int t)
{
	int num=G[id].size()-t;
	if(num==0) return 0;
	int res=INF;
	for(int i=0;i+num-1<G[id].size();i++)
		res=min(res,G[id][i+num-1]-G[id][i]+1);
	return res;
}
int save[MAXN][MAXN];
int dp[MAXN][MAXN];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	int cnt=0;
	getchar();
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			char x;
			scanf("%c",&x);
			if(x=='1') {G[i].push_back(j); cnt++;}
		}
		getchar();
	}
	if(k>=cnt)
	{
		puts("0");
		return 0;
	}
	int sum=0;
	for(int i=0;i<n;i++)
		if(G[i].size()==0) continue; else sum+=G[i][G[i].size()-1]-G[i][0]+1;
	memset(save,-1,sizeof(save));
	for(int i=0;i<n;i++)
	{
		int t=find_ans(i,0);
		save[i][0]=0;
		for(int j=1;j<=G[i].size();j++)
		{
			int now=find_ans(i,j);
			save[i][j]=t-now;
		}
	}
	memset(dp,-1,sizeof(dp));
	dp[0][0]=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<=k;j++)
		{
			if(dp[i][j]==-1) continue;
			for(int p=0;p<=min((int)G[i].size(),k-j);p++)
				dp[i+1][p+j]=max(dp[i+1][p+j],dp[i][j]+save[i][p]);
		}
	printf("%d\n",sum-dp[n][k]);
	return 0;
}