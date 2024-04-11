#pragma comment(linker,"/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ss second
#define ff first
#define endl "\n"
#define ld long double
#define ll long long
#define pb push_back
const int MOD = 1e9 + 7;

const int N = 500 + 11;

int dp[N][N],a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,k,mod;
    cin>>n>>m>>k>>mod;
    for (int i=1; i<=n; i++)
    cin>>a[i];
    dp[0][0]=1;
    for (int i=1; i<=n; i++)
    {
              for (int j=0; j<m; j++)
              for (int kol=0; kol+a[i]<=k; kol++)
              dp[j+1][kol+a[i]]=(dp[j+1][kol+a[i]]+dp[j][kol])%mod;
    }
    int ans=0;
    for (int j=0; j<=k; j++)
    ans=(ans+dp[m][j])%mod;
    cout<<ans<<endl;
}