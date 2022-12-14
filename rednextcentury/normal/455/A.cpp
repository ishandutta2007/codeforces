#include<bits/stdc++.h>
using namespace std;
long long dp[1000000];
long long a[1000000];
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a[x]++;
    }
    dp[0]=0,dp[1]=a[1];
    long long ans=a[1];
    for (int i=2;i<=100000;i++)
    {
        dp[i]=max(dp[i-1],dp[i-2]+a[i]*i);
        ans=max(ans+0LL,dp[i]);
    }
    cout<<ans<<endl;
}