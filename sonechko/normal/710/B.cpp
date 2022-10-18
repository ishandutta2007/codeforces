#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 300000+10;
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
ll a[N],b[N],c[N];
int main()
{
    #ifdef LOCAL
    filestxt;
    #else
    sync;
    #endif // LOCAL
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for (int i=2; i<=n; i++)
    {
        b[i]=b[i-1]+(a[i]-a[i-1])*(i-1);
    }
    for (int i=n-1; i>=1; i--)
    {
        c[i]=c[i+1]+(a[i+1]-a[i])*(n-i);

    }
    ll ans=LONG_LONG_MAX;
    int l;
    for (int i=1; i<=n; i++)
        if (b[i]+c[i]<ans) {l=a[i]; ans=b[i]+c[i];}
    cout<<l<<endl;
}