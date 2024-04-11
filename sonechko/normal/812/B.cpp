#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
const int N = 100 + 11;
char a[N][N];
int dp[N][2];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=n; i>=1; i--)
    {
        for (int j=1; j<=m+2; j++)
            cin>>a[i][j];
    }
    for (int i=0; i<=n; i++)
    {
        dp[i][0]=1e9;
        dp[i][1]=1e9;
    }
    dp[0][0]=-1;
    for (int i=1; i<=n; i++)
    {
        int ks=0;
        for (int j=1; j<=m+2; j++)
            if (a[i][j]=='1') ks=(j-1)*2;
        dp[i][0]=min(dp[i-1][0]+1+ks,dp[i-1][1]+1+m+1);
        ks=0;
        int d=0;
        for (int j=m+2; j>=1; j--)
        {
            if (a[i][j]=='1') ks=d*2;
            d++;
        }
        dp[i][1]=min(dp[i-1][1]+1+ks,dp[i-1][0]+1+m+1);
    }
    for (int i=n; i>=1; i--)
    {
        int k=0;
        for (int j=1; j<=m+2; j++)
            if (a[i][j]=='1') k=1;
        if (k==1)
        {
            int d=0;
            for (int j=1; j<=m+2; j++)
            if (a[i][j]=='1') d=j-1;
            int dd=0,ks=0;
            for (int j=m+2; j>=1; j--)
            {
                if (a[i][j]=='1') dd=ks;
                ks++;
            }
            cout<<min(dp[i-1][0]+1+d,dp[i-1][1]+dd+1)<<endl;
            return 0;
        }
    }
    cout<<0<<endl;
}