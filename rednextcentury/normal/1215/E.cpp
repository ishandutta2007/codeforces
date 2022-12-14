#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int num[100];
long long dp[(1<<20)];
long long C[21][21];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=n;i>=1;i--)
    {
        for (int j=1;j<=20;j++)
        {
            if (a[i]==j)continue;
            C[a[i]-1][j-1]+=num[j];
        }
        num[a[i]]++;
    }
    for (int i=0;i<(1<<20);i++)
        dp[i]=1e18;
    dp[0]=0;
    for (int i=0;i<(1<<20);i++)
    {
        if (dp[i]==-1)continue;
        for (int j=0;j<20;j++)
        {
            if ((1<<j)&i)continue;
            long long c=0;
            for (int x=0;x<20;x++)
            {
                if ((1<<x)&i)
                {
                    c+=C[j][x];
                }
            }
            dp[i|(1<<j)]=min(dp[i|(1<<j)],dp[i]+c);
        }
    }
    cout<<dp[(1<<20)-1]<<endl;

}