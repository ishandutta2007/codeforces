#include<iostream>

using namespace std;

int sum[101];
int sumDP[101];
int dp[10001];

int main ()
{
    int n,m,t,j,a,k,i;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;

    for(i=0;i<n;i++)
    {
        cin>>t;

        for(j=1;j<=t;j++)
        {
            cin>>a;
            sum[j]=sum[j-1]+a;
        }
        for(j=1;j<=t;j++)
        {
            sumDP[j]=0;
            for(k=0;k<=j;k++)
                sumDP[j]=max(sum[k]+sum[t]-sum[t-j+k],sumDP[j]);
        }
        for(j=1;j<=m;j++)
        {
            for(k=1;k<=j && k<=t;k++)
            {
                dp[j-k]=max(dp[j-k],dp[j]+sumDP[k]);
            }
        }
    }

    cout<<dp[0]<<"\n";

    return 0;
}