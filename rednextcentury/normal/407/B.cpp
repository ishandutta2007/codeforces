#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
long long a[1000000];
long long dp[1000000];
#define MOD 1000000007
int main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dp[1]=2;
    long long ans=2;
    for (int i=2;i<=n;i++)
    {
        for (int j=i;j>=a[i];j--)
            dp[i]+=dp[j],dp[i]%=MOD;
        dp[i]+=2;
        dp[i]%=MOD;
        ans+=dp[i];
        ans%=MOD;
    }
    cout<<ans<<endl;
}