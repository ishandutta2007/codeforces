#include<bits/stdc++.h>
using namespace std;
long long a[1000000];
long long mask;
int n,k;
int dp[60][60];
bool check()
{
    dp[0][0]=1;
    for (int i=1;i<=n;i++)
    {
        for (int x=1;x<=k;x++)
        {
            dp[i][x]=0;
            long long sum=0;
            for (int j=i;j>=1;j--)
            {
                sum+=a[j];
                if ((sum&mask)==mask && dp[j-1][x-1])
                {
                    dp[i][x]=1;
                    break;
                }
            }
        }
    }
    return dp[n][k];
}
int main()
{
    cin>>n>>k;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (long long i=60;i>=0;i--)
    {
        mask+=(1LL<<i);
        if (!check())
            mask-=(1LL<<i);
    }
    cout<<mask<<endl;
}