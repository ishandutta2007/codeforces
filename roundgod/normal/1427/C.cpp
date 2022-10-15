#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int r,n,x[MAXN],y[MAXN],t[MAXN],dp[MAXN],pre[MAXN];
int main()
{
    scanf("%d%d",&r,&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&t[i],&x[i],&y[i]);
    }
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        if(x[i]-1+y[i]-1<=t[i]) dp[i]=1; else {dp[i]=0; pre[i]=pre[i-1]; continue;}
        for(int j=max(i-1000,1);j<i;j++) if(max(x[i]-x[j],x[j]-x[i])+max(y[i]-y[j],y[j]-y[i])<=t[i]-t[j]) dp[i]=max(dp[i],dp[j]+1);
        if(i>1001) dp[i]=max(dp[i],pre[i-1001]+1);
        pre[i]=max(pre[i-1],dp[i]);
    }
    int ans=0;
    for(int i=1;i<=n;i++) ans=max(ans,dp[i]);
    printf("%d\n",ans);
}