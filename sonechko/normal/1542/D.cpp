#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 500 + 11;
const int MOD = 998244353;

int a[N];
int dp[N][N];
int res[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int ans=0;
    for (int i=1; i<=n; i++)
    {
        char c;
        cin>>c;
        if (c=='-') a[i]=-1; else cin>>a[i];
    }
    for (int i=1; i<=n; i++)
        if (a[i]>0)
    {
        for (int j=0; j<=i; j++)
        for (int k=0; k<=i; k++)
            dp[j][k]=0;
        dp[0][0]=1;
        for (int j=1; j<i; j++)
        for (int k=0; k<j; k++)
        {
            dp[j][k]=(dp[j][k]+dp[j-1][k])%MOD;
            if (a[j]<0&&k>0) dp[j][k-1]=(dp[j][k-1]+dp[j-1][k])%MOD; else
            if (a[j]>0&&a[j]<a[i]) dp[j][k+1]=(dp[j][k+1]+dp[j-1][k])%MOD; else
            dp[j][k]=(dp[j][k]+dp[j-1][k])%MOD;
        }
        for (int k=0; k<i; k++)
            res[k]=dp[i-1][k];

        for (int j=i; j<=n; j++)
        for (int k=0; k<=n; k++)
            dp[j][k]=0;
        for (int k=0; k<i; k++)
            dp[i][k]=res[k];
        for (int j=i+1; j<=n; j++)
        for (int k=0; k<j; k++)
        {
            dp[j][k]=(dp[j][k]+dp[j-1][k])%MOD;
            if (a[j]<0&&k>0) dp[j][k-1]=(dp[j][k-1]+dp[j-1][k])%MOD; else
            if (a[j]<0&&k==0) {} else
            if (a[j]>0&&a[j]<=a[i]) dp[j][k+1]=(dp[j][k+1]+dp[j-1][k])%MOD; else
            dp[j][k]=(dp[j][k]+dp[j-1][k])%MOD;
        }
        int res=0;
        for (int p=0; p<=n; p++)
            res=(res+dp[n][p])%MOD;
        ans=(ans+res*1ll*a[i])%MOD;
    }
    cout<<ans;
}