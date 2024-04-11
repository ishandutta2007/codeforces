#include <bits/stdc++.h>

using namespace std;
long long dp[100007];
long long mod=1000000007;
int main()
{
    long long t,k;
    cin>>t>>k;
    dp[0]=1;
    if(k==1)
        dp[1]=2;
    else
        dp[1]=1;
    long long a=1,w=0;
    for(int i=2; i<=1e5+2; i++)
    {
        if(k>i)
            dp[i]=dp[i-1];
        else
            dp[i]=dp[i-k]+dp[i-1];
        dp[i]=dp[i]%mod;
    }
    for(int i=1; i<=1e5+2; i++)
    {
        dp[i]=(dp[i]+dp[i-1]);
        dp[i]=dp[i]%mod;
    }

    while(t--)
    {
        long long a,b;
        cin>>a>>b;
        cout<<llabs(dp[b]-dp[a-1]+mod)%mod<<endl;
    }
    return 0;
}