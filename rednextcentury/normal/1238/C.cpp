#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mid ((l+r)/2)
#define L (x<<1)
#define R (L+1)
int dp[1000000][2];
int a[1000000];
int n;
int vis[1000000][2];
int T;
int solve(int i,int j)
{
    if (i==n)return 0;
    if (i==n-1 && j==0)return 0;
    if (i==n-1 && j==1) {
        if (a[i]==1)return 0;
        else return 1;
    }
    if (vis[i][j]==T)return dp[i][j];
    vis[i][j]=T;
    dp[i][j]=1e9;
    int l,r,x;
    if (j==0){
        l=a[i],r=a[i+1],l=r+1,x=a[i+2];
        dp[i][j]=min(dp[i][j],solve(i+2,(x!=l-2))+1-(x==l-2));
        dp[i][j]=min(dp[i][j],solve(i+1,0)+1);
    }
    else {
        l=a[i]+1;
        r=a[i];
        x=a[i+1];
        dp[i][j]=min(dp[i][j],solve(i+2-j,(x!=l-2))+1-(x==l-2));
        dp[i][j]=min(dp[i][j],solve(i+1-j,0)+1);
    }
    return dp[i][j];
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        T++;
        int h;
        cin>>h>>n;
        for (int i=1;i<=n;i++)
            cin>>a[i];
        a[++n]=0;
        cout<<solve(1,0)<<endl;
    }


}