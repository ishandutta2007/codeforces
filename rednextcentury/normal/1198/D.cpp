#include<bits/stdc++.h>
using namespace std;
int a[101][101];
int dp[51][51][51][51];
int sum(int x1,int y1,int x2,int y2)
{
    return a[x2][y2]-a[x2][y1-1]-a[x1-1][y2]+a[x1-1][y1-1];
}
int solve(int x1,int x2,int y1,int y2)
{
    if (dp[x1][x2][y1][y2]!=-1)return dp[x1][x2][y1][y2];
    if (a[x2][y2]-a[x2][y1-1]-a[x1-1][y2]+a[x1-1][y1-1]==0)return 0;
    int ans = max(x2-x1+1,y2-y1+1);
    for (int i=x1;i<x2;i++)
        //if (sum(i,y1,i,y2)==0)
            ans=min(ans,solve(x1,i,y1,y2)+solve(i+1,x2,y1,y2));
    for (int i=y1;i<y2;i++)
        //if (sum(x1,i,x2,i)==0)
            ans=min(ans,solve(x1,x2,y1,i)+solve(x1,x2,i+1,y2));
    return dp[x1][x2][y1][y2]=ans;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            char x;
            cin>>x;
            if (x=='#')
                a[i][j]=1;
            a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        }
    }
    cout<<solve(1,n,1,n)<<endl;
}