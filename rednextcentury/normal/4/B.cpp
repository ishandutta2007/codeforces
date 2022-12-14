# include <iostream>
# include <stdio.h>
# include <algorithm>
# include <map>
using namespace std;
int dp[31][300];
int a[31];
int main()
{
    int n,sum;
    cin>>n>>sum;
    dp[0][0]=1;
    for (int i=1;i<=n;i++)
    {
        int l,r;
        cin>>l>>r;
        for (int j=l;j<=r;j++)
            for (int x=j;x<=sum;x++)
                if (dp[i-1][x-j]) dp[i][x]=j+1;
    }
    cout<< (dp[n][sum]?"YES":"NO") <<endl;
    if (dp[n][sum])
    {
        for (int j=n-1;j>=0;j--)
        {
            a[j]=dp[j+1][sum]-1;
            sum-=a[j];
        }
        for (int j=0;j<n-1;j++)
            cout<<a[j]<<" ";
        cout<<a[n-1]<<endl;
    }
}