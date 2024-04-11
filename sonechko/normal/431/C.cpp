#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 1000;
const int M = 10;
const string st2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string s1 = "abcdefghijklmnopqrstuvwxyz";
#define mod % MOD
#define filesio(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout)
#define filesds(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout)
#define filestt(x) freopen(x ".txt", "r", stdin); freopen(x ".txt", "w", stdout)
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, sizeof(x), y)
#define sqr(a) ((a) * (a))
#define endl "\n"
#define ld long double
#define outld(l) cout.precision(l);cout << fixed
#define s second
#define ll long long
#define f first
#define mp make_pair
int n,m,k,dp[101][101][2];
int main()
{
    cin>>n>>k>>m;
    dp[0][0][0]=1;
    for (int i=1; i<=n; i++)
        for (int sum=1; sum<=n; sum++)
        for (int t=1; t<=min(k,sum); t++)
    {
        if (t>=m) dp[i][sum][1]=(dp[i][sum][1]+dp[i-1][sum-t][0])mod; else dp[i][sum][1]=(dp[i][sum][1]+dp[i-1][sum-t][1])mod;
         dp[i][sum][0]=(dp[i][sum][0]+dp[i-1][sum-t][0])mod;
    }
    int ans=0;
    for (int i=1; i<=n; i++)
        ans=(ans+dp[i][n][1])mod;
    cout<<ans<<endl;
}