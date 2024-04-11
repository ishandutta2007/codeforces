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
int use[N];
ll a[N];
int main()
{
    #ifdef LOCAL
    filestxt;
    #else
    sync;
    #endif // LOCAL
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int j=1; j<=m; j++)
    {
        int k;
        cin>>k;
        use[k]=1;
    }
    ll ans=0;
    for (int i=1; i<=n; i++)
    {
        if (i==n) ans+=a[i]*a[1]; else ans+=a[i]*a[i+1];
    }
    ll h=0;
    for (int i=1; i<=n; i++)
    {h+=a[i];}
    for (int j=1; j<=n; j++)
    if (use[j]==1)
    {
        int h1=j-1;
        if (h1==0) h1=n;
        ll p=h;
        if (use[h1]==0) p-=a[h1];
        int h2=j+1;
        if (h2==n+1) h2=1;
        p-=a[h2];

        p-=a[j];

        ans+=(p*a[j]);
        h-=a[j];
    }
    cout<<ans<<endl;
}