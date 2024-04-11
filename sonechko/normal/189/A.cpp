#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1000000000000000;
const int N = 10000+10;
const int M = 10;
const string st2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string s1 = "abcdefghijklmnopqrstuvwxyz";
#define mod % MOD
#define filesio(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout)
#define filesds(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout)
#define filestt(x) freopen(x ".txt", "r", stdin); freopen(x ".txt", "w", stdout)
#define filestxt freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, sizeof(x), y)
#define sqr(a) ((a) * (a))
#define ld long double
#define outld(l) cout.precision(l);cout << fixed
#define s second
#define ll long long
#define f first
#define mp make_pair
#define y1 dbfuebfwkjNBSciwbe
#define time zdfheajbrkjasghduw
#define ull unsigned long long
#define randomize srand(time(NULL))
#define next ifhiuebf
#define last dkbffjrb
int n,l,r,k,dp[N];
int main()
{
    #ifdef LOCAL
    filestxt;
    #else
    sync;
    #endif // LOCAL
    int n,l,r,k;
    cin>>n>>l>>r>>k;
    for (int i=1; i<=n; i++)
        dp[i]=-1;
    for (int i=1; i<=n; i++)
    {
        if (i>=l&&dp[i-l]!=-1) dp[i]=max(dp[i],dp[i-l]+1);
        if (i>=r&&dp[i-r]!=-1) dp[i]=max(dp[i],dp[i-r]+1);
        if (i>=k&&dp[i-k]!=-1) dp[i]=max(dp[i],dp[i-k]+1);

    }
    cout<<dp[n]<<endl;
}