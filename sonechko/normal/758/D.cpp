#include<bits/stdc++.h>
using namespace std;
const int N = 100 + 11;
const long long MOD = 1e9 + 7;
#define mod %MOD
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ss second
#define ff first
#define ll long long
#define mp make_pair
#define endl "\n"
#define pb push_back
#define y1 ijdj
#define next lzk
#define ld long double
#define ull unsigned long long
ull dp[N][N];
int main()
{
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    #endif // LOCAL
    sync;
    ull n;
    cin>>n;
    string s;
    cin>>s;
    ull m=s.size();
    s='.'+s;
    for (ull i=0; i<=m+2; i++)
        for (ull j=0; j<=60; j++)
        dp[i][j]=LONG_LONG_MAX;
    dp[m+1][0]=0;
    ll fuu=0;
    for (ull i=m; i>=1; i--)
    {
    ull step=1;
    for (ull j=1; j<=60; j++)
    {
    for (ull p=i; p<=min(m,p+10); p++)
    {
        ull ss=0;
        for (ull k=i; k<=p; k++)
            ss=ss*10+(s[k]-'0');
        if (s[i]=='0'&&p!=i) break;
        if (ss<n&&(ss==0||(ll)5e18/ss>=step)) dp[i][j]=min(dp[i][j],dp[p+1][j-1]+ss*step);
    }
    if ((ll)2e18/step>=n) step*=n; else break;
    }
    }
    ull ans=LONG_LONG_MAX;
    for (ull j=1; j<=60; j++)
    ans=min(ans,dp[1][j]);
    cout<<ans<<endl;
}