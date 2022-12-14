
# include <iostream>
# include <string>
# include <algorithm>
# include <map>
#include<stdio.h>
# include <vector>
#define EPS 1e-9
using namespace std;
int a[10000],b[100000],c[100000],d[100000];
int dp[12][1001];
int main()
{
    int n,m;
    cin>>n>>m;
    a[0]=1000,b[0]=1;
    cin>>c[0]>>d[0];
    for (int i=1;i<=m;i++)
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    for (int i=0;i<=m;i++)
    {
        for (int j=0;j<=a[i]/b[i];j++)
        {
            for (int x=j*c[i];x<=n;x++)
            {
                dp[i+1][x]=max(dp[i+1][x],dp[i][x-j*c[i]]+j*d[i]);
            }
        }
    }
    int mx=0;
    for (int x=0;x<=n;x++)
    {
        mx=max(mx,dp[m+1][x]);
    }
    cout<<mx<<endl;
}