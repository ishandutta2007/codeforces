#include<bits/stdc++.h>
#define MAXN 1005
#define MAXM 12005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,b[MAXN],c[MAXN];
int dis[MAXN];
int dp[MAXM],ndp[MAXM];
int main()
{
	for(int i=1;i<=1000;i++) dis[i]=INF;
	dis[1]=0;
	queue<int> que; que.push(1);
	while(que.size())
	{
		int v=que.front(); que.pop();
		for(int i=1,r;i<=v;i=r+1)
		{
			r=v/(v/i);
			int val=v/i;
			if(v+val<=1000&&dis[v+val]==INF)
			{
				dis[v+val]=dis[v]+1;
				que.push(v+val);
			}
		}
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		k=min(k,12*n);
		for(int i=1;i<=n;i++) scanf("%d",&b[i]);
		for(int i=1;i<=n;i++) scanf("%d",&c[i]);
		memset(dp,0,sizeof(dp)); 
		for(int i=1;i<=n;i++)
		{
			memset(ndp,0,sizeof(ndp));
			for(int j=0;j<=k;j++)
			{
				ndp[j]=dp[j];
				if(j>=dis[b[i]]) ndp[j]=max(ndp[j],dp[j-dis[b[i]]]+c[i]);
			}
			swap(dp,ndp);
		}
		printf("%d\n",dp[k]);
	}
	return 0;
}