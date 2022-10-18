#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair

const int N = 2000 + 11;
const int MOD = 998244353;

ll dp[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m,k;
    cin>>n>>m>>k;
    dp[1][0]=m;
    for (int i=2; i<=n; i++)
    for (int kol=0; kol<=k; kol++)
    {
        dp[i][kol]=(dp[i][kol]+dp[i-1][kol])%MOD;
        dp[i][kol+1]=(dp[i][kol+1]*1ll+dp[i-1][kol]*1ll*(m-1))%MOD;
    }
    cout<<dp[n][k]<<endl;
}