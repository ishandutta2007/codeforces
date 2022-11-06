#include<cmath>
#include<cstdio>
#include<vector> 
#include<queue>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<ctime>
#define maxn 300020
#define inf 600020000

using namespace std;
typedef long long ll;

ll dp[maxn][40],a[maxn],ans,n;

int main()
{
	scanf("%d",&n);
	for (int i=0;i<maxn;i++)
	    for (int j=0;j<40;j++) dp[i][j]=inf;
    for (int i=1;i<=n;i++) scanf("%d",&a[i]),a[i]/=100;
    dp[0][0]=0;
    for (int i=1;i<=n;i++)
        for (int j=0;j<40;j++)
        {
        	if (a[i]>j) dp[i][0]=min(dp[i][0],dp[i-1][j]+a[i]-j);
        	if (a[i]<=j) dp[i][j-a[i]]=min(dp[i][j-a[i]],dp[i-1][j]);
        	if (a[i]/10+j<40) dp[i][j+a[i]/10]=min(dp[i][j+a[i]/10],dp[i-1][j]+a[i]);
        }
    ans=inf;
    for (int i=0;i<40;i++) ans=min(ans,dp[n][i]);
    printf("%I64d\n",ans*100);
    return 0;
}