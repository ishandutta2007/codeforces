#include<bits/stdc++.h>
using namespace std;
int best[101][101];
int a[1000];
int num[101];
int dp[101][10001];
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&num[i]);
        for (int j=0;j<num[i];j++)
            scanf("%d",&a[j]);
        int sum=0;
        a[num[i]]=0;
        for (int j=0;j<=num[i];j++)
        {
            int op=sum;
            best[i][j]=max(best[i][j],sum);
            for (int x=num[i]-1;x>j;x--)
            {
                op+=a[x];
                best[i][j+num[i]-x]=max(best[i][j+num[i]-x],op);
            }
            sum+=a[j];
        }
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            for (int x=1;x<=num[i];x++)
            {
                if (x>j)break;
                dp[i][j]=max(dp[i][j],dp[i-1][j]);
                dp[i][j]=max(dp[i][j],dp[i-1][j-x]+best[i][x]);
            }
        }
    }
    cout<<dp[n][m]<<endl;
}