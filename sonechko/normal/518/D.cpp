#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ld long double
#define mod %MOD

const int N = 2000 + 11;
const int MOD = 1e9 + 7;

ld dp[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ld p;
    int t;
    int n;
    cin>>n>>p>>t;
    ld ans=0;
    dp[0][0]=1;
    for (int i=1; i<=t; i++)
    {
        for (int j=0; j<n; j++)
        {
            dp[i][j]+=dp[i-1][j]*(1-p);
            dp[i][j+1]+=dp[i-1][j]*p;
        }
        dp[i][n]+=dp[i-1][n];
    }
    cout.precision(10);
    cout<<fixed;
    for (int i=0; i<=n; i++)
        ans+=dp[t][i]*(long double)i;
    cout<<ans<<endl;
}