#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<math.h>
#include<string.h>
#include<vector>
using namespace std;
typedef __int64 ll;
const int inf=1000000000;
int dp[102][3];
int a[102];
int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    for(int i=1;i<=n;i++)
    {
        dp[i][0]=dp[i][1]=dp[i][2]=200;
        for(int j=0;j<=2;j++)
        {
            dp[i][0]=min(dp[i-1][j]+1,dp[i][0]);

            if(((a[i]==1)||(a[i]==3))&&(j!=1)) dp[i][1]=min(dp[i][1],dp[i-1][j]);
            if(((a[i]==2)||(a[i]==3))&&(j!=2)) dp[i][2]=min(dp[i][2],dp[i-1][j]);
        }
    }
    int res=200;
    for(int i=0;i<=2;i++)
    {
        res=min(res,dp[n][i]);
    }
    cout<<res<<endl;

    return 0;
}