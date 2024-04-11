#include<bits/stdc++.h>
using namespace std;

int dp[5005];
char c[5005];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    dp[0]=1;
    for (int ii=1; ii<=n; ii++)
    {
        cin>>c[ii];
        if (ii>0&&c[ii-1]=='f')
        {
            for (int i=n; i>=1; i--)
                dp[i]=dp[i-1];
            dp[0]=0;
        } else
        {
            int sum=0;
            for (int i=n; i>=0; i--)
            {
                sum=(sum+dp[i])%1000000007;
                dp[i]=sum;
            }
        }
    }
    int ans=0;
    for (int i=0; i<=n; i++)
        ans=(ans+dp[i])%1000000007;
    cout<<ans<<endl;
}