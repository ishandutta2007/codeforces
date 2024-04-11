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
ll ans,k,a[N],b[N];
int main()
{
    sync;
    ll n;
    cin>>n;
    if (n==1) {cout<<20<<endl; return 0;}
    a[1]=27;
    for (int i=2; i<=n; i++)
        a[i]=(a[i-1]*27)mod;
    b[n]=7;
    for (int i=n-1; i>=1; i--)
        b[i]=(b[i+1]*7)mod;
    for (ll i=2; i<n; i++)
        {
            ans=(ans+((a[i-1]*b[i+1])mod*20)mod)mod;
        }
    ans=(ans+a[n-1]*20+b[2]*20)mod;
    cout<<ans<<endl;
}