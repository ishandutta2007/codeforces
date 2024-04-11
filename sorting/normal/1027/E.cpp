#include<algorithm>
#include<iostream>

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#define endl "\n"

using namespace std;

const long long mod = 998244353;

const long long N = 507;

long long dp[N][N];

int main ()
{
    long long n,k,res=0;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>k;

    if(k==1)
    {
        cout<<"0"<<endl;
        return 0;
    }

    long long i,j,r;

    for(i=1;i<=n;i++)
        dp[n][i]=1;

    for(i=n-1;i>=0;i--)
        for(j=1;j<=n;j++)
        {
            for(r=1;r<=n-i && r<=j;r++)
                dp[i][j]+=dp[i+r][j];
            dp[i][j]%=mod;
            //cout<<dp[i][j]<<" = "<<i<<" "<<j<<endl;
        }

    for(j=1;j<=n;j++)
    {
        //dp[0][j]*=2;
        dp[0][j]%=mod;
        //cout<<dp[0][j]<<" "<<j<<endl;
    }

    dp[0][0]=0;

    for(j=n;j>=1;j--)
    {
        dp[0][j]-=dp[0][j-1];
        while(dp[0][j]<0)
            dp[0][j]+=mod;
        //cout<<dp[0][j]<<" "<<j<<endl;
    }

    for(i=1;i<k && i<=n;i++)
        for(j=1;j*i<k && j<=n;j++)
        {
            //cout<<i<<" - "<<j<<endl;
            res+=dp[0][i]*dp[0][j]*2;
            res%=mod;
        }

    cout<<res<<endl;

    return 0;
}