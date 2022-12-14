#include <bits/stdc++.h>
using namespace std;
long double dp[202][202][500];
long double p[1000];
long long a[10000];
int main()
{
    int n,mn,k;
    cin>>n>>mn>>k;
    for (int i=1;i<=n;i++)
        cin>>p[i],p[i]/=100.0;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    dp[0][0][k+200]=1;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<=i;j++)
        {
            for (int x=0;x<=400;x++)
            {
                if (a[i+1]==-1)
                {
                    dp[i+1][j+1][x-1]+=dp[i][j][x]*p[i+1];
                    dp[i+1][j][x]+=dp[i][j][x]*(1-p[i+1]);
                }
                else
                {
                    dp[i+1][j+1][min(400LL,a[i+1]+x)]+=dp[i][j][x]*p[i+1];
                    dp[i+1][j][x]+=dp[i][j][x]*(1-p[i+1]);
                }
            }
        }
    }
    long double ret=0;
    for (int i=mn;i<=n;i++)
        for (int j=200;j<=400;j++)
            ret+=dp[n][i][j];
    cout<<setprecision(12)<<fixed<<ret<<endl;
}