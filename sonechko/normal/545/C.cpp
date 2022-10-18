#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 100005;
const int M = 10;
const string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
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
#define next ljjdfienf
pair<int,int> a[N];
int dp[N][2];
int main()
{
    sync;
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i].f>>a[i].s;
    sort(a+1,a+n+1);
    dp[1][0]=1;
    if (a[1].f+a[1].s<a[2].f) dp[1][1]=1;
    for (int i=2; i<=n; i++)
    {
        if (a[i].f-a[i].s>a[i-1].f+a[i-1].s)
            dp[i][0]=max(dp[i-1][1],dp[i-1][0])+1; else
        if (a[i].f-a[i].s>a[i-1].f)
            dp[i][0]=dp[i-1][0]+1; else
        if (a[i-1].f+a[i-1].s<a[i].f)
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]); else
            dp[i][0]=dp[i-1][0];

        if (a[i].f+a[i].s<a[i+1].f||i==n)
        {
            if (a[i-1].f+a[i-1].s<a[i].f)
                dp[i][1]=max(dp[i-1][0],dp[i-1][1])+1; else
            dp[i][1]=dp[i-1][0]+1;
        }
    }
    int ans=0;
    for (int i=1; i<=n; i++)
        ans=max(ans,max(dp[i][0],dp[i][1]));
    cout<<ans<<endl;
}