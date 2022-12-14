# include <iostream>
# include <stdio.h>
# include <algorithm>
# include <vector>
using namespace std;
long long dp[100][100];
int main()
{
    int n,h;
    cin>>n>>h;
    dp[0][0]=1;
    for (int j=1;j<=n;j++)
    {
        for (int i=j;i<=n;i++)
        {
            for (int x=0;x<i;x++)
            {
                long long a=0,b=0;
                a=dp[x][j-1];
                for (int k=0;k<j-1;k++)
                    b+=dp[i-x-1][k];
                dp[i][j]+=2*a*b;
                dp[i][j]+=dp[x][j-1]*dp[i-x-1][j-1];
            }
        }
    }
    long long ans=0;
    for (int i=h;i<=n;i++)
        ans+=dp[n][i];
    cout<<ans<<endl;
}