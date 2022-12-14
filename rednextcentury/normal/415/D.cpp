# include <iostream>
# include <string>
# include <map>
# include <stdio.h>
# include <cmath>
# include <cstdio>
# include <queue>
# include <algorithm>
# include <stack>
# include <cstring>
# include <iomanip>
# include<ios>
using namespace std;
long long dp[3000][3000];
int main()
{   
    int n,k;
    cin>>k>>n;
    for (int i=1;i<=k;i++)
    {
        dp[0][i]=1;
        dp[1][i]=1;
    }
    for (int i=2;i<=n;i++)
    {
        for (int j=1;j<=k;j++)
        {
            for (int x=1;x*x<=j;x++)
            {
                if (j%x==0)
                {
                    if (x*x==j)
                    {
                        dp[i][j]+=dp[i-1][x];
                    }
                    else
                    {
                    dp[i][j]+=dp[i-1][x]+dp[i-1][j/x];
                    }
                    dp[i][j]=dp[i][j]%1000000007;
                }
            }
        }
    }
    long long ans=0;
    for (int i=1;i<=k;i++)
    {
        ans+=dp[n][i];
        ans=ans%1000000007;
    }
    cout<<ans<<endl;
}