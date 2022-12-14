#include <bits/stdc++.h>
using namespace std;
#define ll long long
long double dp[10][100];
long double P[10][100];
long double win[100][100];
int meet[100][100];
int main()
{
    int N;
    cin>>N;
    int n=(1<<N);
    for (int i=1;i<=n;i++)
    {
        dp[0][i]=0;
        P[0][i]=1;
        for (int j=1;j<=n;j++)
        {
            int x;
            cin>>x;
            win[i][j]=x/100.0;
        }
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if (i==j)continue;
            int u=i-1,v=j-1;
            for (int k=1;k<=N;k++)
            {
                if (u/2 == v/2)
                {
                    meet[i][j]=k;
                    break;
                }
                else
                    u/=2,v/=2;
            }
        }
    }
    for (int i=1;i<=N;i++)
    {
        for (int j=1;j<=n;j++)
        {
            for (int k=1;k<=n;k++)
            {
                if (meet[j][k]==i)
                {
                    P[i][j]+=P[i-1][k]*win[j][k];
                }
            }
            P[i][j]=P[i][j]*P[i-1][j];
            for (int k=1;k<=n;k++)
            {
                if (meet[j][k]==i)
                {
                    dp[i][j]=max(dp[i][j],dp[i-1][j]+dp[i-1][k]);
                }
            }
            dp[i][j]+=P[i][j]*(1<<(i-1));
        }
    }
    long double ret=0;
    for (int i=1;i<=n;i++)
        ret=max(ret,dp[N][i]);
    cout<<setprecision(10)<<fixed<<ret<<endl;
}