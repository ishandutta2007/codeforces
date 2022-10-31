#include<bits/stdc++.h>
using namespace std;

long long int arr[101010][3];
long long int dp[101010][3];

int main()
{
    long long int a,b,c,d,e,f,g,h,i,j,k,l,m,n;
    scanf("%lld",&n);
    a=min((long long int)10^8,n);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&arr[i][1]);
    }
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&arr[i][2]);
    }
    for(i=1;i<=n;i++)
    {
        dp[i][0]=max({dp[i-1][0],dp[i-1][1],dp[i-1][2]});
        dp[i][1]=max(dp[i-1][0],dp[i-1][2])+arr[i][1];
        dp[i][2]=max(dp[i-1][0],dp[i-1][1])+arr[i][2];
    }
    printf("%lld",max( {dp[n][0],dp[n][1],dp[n][2]} ));
}