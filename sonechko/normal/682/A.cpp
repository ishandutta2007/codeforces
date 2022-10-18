#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 501;
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
#define s second
#define ll long long
#define f first
#define mp make_pair
int main()
{
    ll n,m;
    cin>>n>>m;
    ll ans=0;
    for (ll i=1; i<=n; i++)
    {
        ll k=5-i%5;
        if (k==5) k=0;
        ans+=m/5;
        if (m%5>=k) ans++;
        if (k==0) ans--;
        //cout<<ans<<endl;
    }
    cout<<ans<<endl;
}