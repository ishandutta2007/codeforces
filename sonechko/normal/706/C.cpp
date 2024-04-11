#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 200000+10;
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
#define endl "\n"
#define ld long double
#define outld(l) cout.precision(l);cout << fixed
#define se second
#define ll long long
#define fi first
#define mp make_pair
#define y1 dbfuebfwkjNBSciwbe
#define time zdfheajbrkjasghduw
#define ull unsigned long long
#define randomize srand(time(NULL))
#define next ifhiuebf
#define last dkbffjrb
ll a[N],dp[N][2];
string b[N],c[N];
bool v(string s, string t)
{
    for (int i=0; i<max(s.size(),t.size()); i++)
        if (i>t.size()-1) return 0; else
        if (i>s.size()-1) return 1; else
        if (s[i]>t[i]) return 0; else
        if (t[i]>s[i]) return 1;
    return 1;
}
int main()
{
    #ifdef LOCAL
    filestxt;
    #else
    sync;
    #endif
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=n; i++)
        {
            cin>>b[i];
            string t=b[i];
            c[i]="";
            for (int j=0; j<t.size(); j++)
                c[i]=t[j]+c[i];
        }
    dp[1][0]=0;
    dp[1][1]=a[1];
    for (int i=2; i<=n; i++)
    {
        string s1=b[i-1],s2=b[i];
        string t1=c[i-1],t2=c[i];
        dp[i][1]=LONG_LONG_MAX;
        dp[i][0]=LONG_LONG_MAX;
        if (v(s1,s2)) dp[i][0]=min(dp[i][0],dp[i-1][0]);
        if (v(t1,s2)) dp[i][0]=min(dp[i][0],dp[i-1][1]);
        if (v(s1,t2)&&dp[i-1][0]!=LONG_LONG_MAX) dp[i][1]=min(dp[i][1],dp[i-1][0]+a[i]);
        if (v(t1,t2)&&dp[i-1][1]!=LONG_LONG_MAX) dp[i][1]=min(dp[i][1],dp[i-1][1]+a[i]);
    }
    if (dp[n][0]==LONG_LONG_MAX&&dp[n][1]==LONG_LONG_MAX) {cout<<-1<<endl;} else
        cout<<min(dp[n][0],dp[n][1])<<endl;
}