#include<bits/stdc++.h>
#define MAXN 205
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,cnt1[MAXN],cnt2[MAXN];
int dp[MAXN][6000];
int main()
{
	scanf("%d%d",&n,&k);
	memset(cnt1,0,sizeof(cnt1));
	memset(cnt2,0,sizeof(cnt2));
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<=n;i++)
	{
		ll x;
		scanf("%I64d",&x);
		while(x%2==0) {x=x/2; cnt1[i]++;}
		while(x%5==0) {x=x/5; cnt2[i]++;}
	}
	dp[0][0]=0;
	int maxcnt=0;
	for(int i=0;i<n;i++)
	{
		for(int j=min(i,k-1);j>=0;j--)
			for(int p=0;p<=maxcnt;p++)
				if(dp[j][p]!=-1) dp[j+1][p+cnt2[i+1]]=max(dp[j+1][p+cnt2[i+1]],dp[j][p]+cnt1[i+1]);
		maxcnt+=cnt2[i+1];
	}
	int ans=0;
	for(int i=0;i<=maxcnt;i++)
		ans=max(ans,min(dp[k][i],i));
	printf("%d\n",ans);
	return 0;
}