#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 100001;
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
pair<ll,ll> a[N];
int main()
{
    ll n,m,k;
    cin>>n>>m>>k;
    k*=n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i].s>>a[i].f;
        k-=a[i].s;
    }
    if (k<0) {cout<<0<<endl; return 0;}
    sort(a+1,a+n+1);
    ll ans=0;
    for (int i=1; i<=n; i++)
    {
        ll t=min(k,m-a[i].s);
        k-=t;
        ans+=t*a[i].f;
    }
    cout<<ans<<endl;
}