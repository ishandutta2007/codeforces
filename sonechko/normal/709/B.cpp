#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 100000+10;
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
ll a[N];
int main()
{
    #ifdef LOCAL
    filestxt;
    #else
    sync;
    #endif // LOCAL
    /**
    int n,b,d;
    cin>>n>>b>>d;
    int t=0, ans=0;
    for (int i=1; i<=n; i++)
    {
        int k;
        cin>>k;
        if (k<=b) t+=k;
        if (t>d) {ans++; t=0;}
    }
    cout<<ans<<endl;
    **/
    ll n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    if (n==1) {cout<<0<<endl; return 0;}
    sort(a+1,a+n+1);
    ll ans=LONG_LONG_MAX;
    ans=min(ans,abs(a[n-1]-a[1])+min(abs(m-a[1]),abs(m-a[n-1])));
    ans=min(ans,abs(a[n]-a[2])+min(abs(m-a[2]),abs(m-a[n])));
    cout<<ans<<endl;
}