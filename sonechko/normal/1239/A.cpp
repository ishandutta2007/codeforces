#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;
const int MOD = 1e9 + 7;

ll dp[N][2][2];


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    int k=n+m-1;
    dp[1][0][1]=1;
    dp[1][1][0]=1;
    dp[0][0][1]=1;
    dp[0][1][0]=1;
    dp[0][1][1]=1;
    dp[0][0][0]=1;
    for (int i=2; i<=k; i++)
    for (int l=0; l<=1; l++)
    for (int r=0; r<=1; r++)
    for (int p=0; p<=1; p++)
    if (l==r&&r==p) {} else
    dp[i][p][l]=(dp[i][p][l]+dp[i-1][l][r])%MOD;

    ll ans=0;
    for (int pos=1; pos<m; pos++)
        ans=(ans+dp[m-pos][1][0]+dp[m-pos][0][1])%MOD;
    for (int pos=1; pos<n; pos++)
        ans=(ans+dp[n-pos][0][1]+dp[n-pos][1][0])%MOD;

    cout<<(ans+2ll)%MOD<<endl;
}