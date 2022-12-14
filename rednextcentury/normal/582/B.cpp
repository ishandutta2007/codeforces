# include <iostream>
# include <string>
# include <vector>
# include <stdio.h>
# include <set>
using namespace std;
int a[1000000];
int dp1[400][101];
int pre[400][10001];
int suf[400][10001];
int dp2[400][101];
int num[1000];
int main()
{
    int n,T;
    cin>>n>>T;
    for (int i=0;i<n;i++)
        cin>>a[i],num[a[i]]++;
    for (int i=n-1;i>=0;i--)
    {
        dp2[a[i]][i]=1;
        for (int x=1;x<=300;x++)
        {
            for (int j=i+1;j<n;j++)
            {
                if (a[j]<=x && a[j]>=a[i])
                    dp2[x][i]=max(dp2[x][i],dp2[x][j]+1);
            }
        }
    }
    for (int i=0;i<n;i++)
    {
        dp1[a[i]][i]=1;
        for (int x=1;x<=300;x++)
        {
            for (int j=0;j<i;j++)
            {
                if (a[j]>=x && a[j]<=a[i])
                    dp1[x][i]=max(dp1[x][i],dp1[x][j]+1);
            }
        }
    }

//    for (int j=0;j<n;j++)
//    {
//        for (int x=1;x<=a[j];x++)
//        {
//            pre[a[j]][0]=max(pre[a[j]][0],dp1[x][j]);
//        }
//    }
    for (int i=1;i<=min(T,10000);i++)
    {
        for (int j=0;j<n;j++)
        {
            for (int x=1;x<=a[j];x++)
            {
                pre[a[j]][i]=max(pre[a[j]][i],dp1[x][j]+pre[x][i-1]);
            }
        }
        for (int j=1;j<=300;j++)
            pre[j][i]=max(pre[j][i],pre[j-1][i]);
    }
//    for (int j=0;j<n;j++)
//    {
//        for (int x=a[j];x<=300;x++)
//        {
//            suf[a[j]][0]=max(suf[a[j]][0],dp2[x][j]);
//        }
//    }
    for (int i=1;i<=min(T,10000);i++)
    {
        for (int j=0;j<n;j++)
        {
            for (int x=a[j];x<=300;x++)
            {
                suf[a[j]][i]=max(suf[a[j]][i],dp2[x][j]+suf[x][i-1]);
            }
        }
        for (int j=300;j>=1;j--)
            suf[j][i]=max(suf[j][i],suf[j+1][i]);
    }
    int ans=0;
            for (int x=1;x<=300;x++)
            {
                ans=max(ans,pre[x][min(T/2+T%2,10000)]+num[x]*(T-min(T,20000)) + suf[x][min(T/2,10000)]);
            }

    cout<<ans<<endl;
}