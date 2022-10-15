#include<bits/stdc++.h>
#define MAXN 7005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k[2],dp[MAXN][2],cnt[MAXN][2];//0:Lose 1:Win 2:Loop
int s[2][MAXN];
bool used[MAXN];
int main()
{
	scanf("%d",&n);
	scanf("%d",&k[0]);
	for(int i=0;i<k[0];i++)
		scanf("%d",&s[0][i]);
	scanf("%d",&k[1]);
	for(int i=0;i<k[1];i++)
		scanf("%d",&s[1][i]);
	for(int i=0;i<n;i++)
		cnt[i][0]=k[0];
	for(int i=0;i<n;i++)
		cnt[i][1]=k[1];
	memset(dp,-1,sizeof(dp));
	dp[0][0]=dp[0][1]=0;
	queue<P> que;
	que.push(P(0,0));
	que.push(P(0,1));
	while(que.size())
	{
		P p=que.front();
		que.pop();
		if(dp[p.F][p.S]==0)
		{
			for(int i=0;i<k[1-p.S];i++)
			{
				int num=(p.F-s[1-p.S][i]+n)%n;
				if(dp[num][1-p.S]==-1)
				{
					dp[num][1-p.S]=1;
					que.push(P(num,1-p.S));
				}
			}
		}
		else
		{
			for(int i=0;i<k[1-p.S];i++)
			{
				int num=(p.F-s[1-p.S][i]+n)%n;
				cnt[num][1-p.S]--;
				if(cnt[num][1-p.S]==0&&dp[num][1-p.S]==-1)
				{
					dp[num][1-p.S]=0;
					que.push(P(num,1-p.S));
				}
			}
		}
	}
	for(int i=1;i<n;i++)
		if(dp[i][0]==0) printf("Lose "); else if(dp[i][0]==1) printf("Win "); else printf("Loop ");
	puts("");
	for(int i=1;i<n;i++)
		if(dp[i][1]==0) printf("Lose "); else if(dp[i][1]==1) printf("Win "); else printf("Loop ");
	return 0;
}