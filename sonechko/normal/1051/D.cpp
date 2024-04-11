#include<bits/stdc++.h>
using namespace std;

#define pb push_back

const int N = 2000 + 11;
const int MOD = 998244353;

int dp[N][N][2][2];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    dp[1][1][0][0]=1;
    dp[1][2][0][1]=1;
    dp[1][2][1][0]=1;
    dp[1][1][1][1]=1;
    for (int i=2; i<=n; i++)
    for (int k1=0; k1<=k; k1++)
    for (int t1=0; t1<=1; t1++)
    for (int t2=0; t2<=1; t2++)
    for (int p1=0; p1<=1; p1++)
    for (int p2=0; p2<=1; p2++)
    {
        int c=dp[i-1][k1][t1][t2];
        int k2=k1;
        if (p1==p2&&t1!=p1&&t2!=p2) k2++;
        if (p1!=t1&&p1!=p2) k2++;
        if (p2!=t2&&p2!=p1) k2++;
        dp[i][k2][p1][p2]=(dp[i][k2][p1][p2]+c)%MOD;
    }
    int ans=0;
    for (int t1=0; t1<=1; t1++)
    for (int t2=0; t2<=1; t2++)
        ans=(ans+dp[n][k][t1][t2])%MOD;
    cout<<ans;
}
/**

**/