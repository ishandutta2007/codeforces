/*
    Soheil Mohammadkhani
    I will change this text here when i've got "Expert" :)
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ll, vector<ll>> plv;
typedef pair<double, double> pdd;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define debug2(x)                   cerr << #x << ": " <<  x <<  " ";
#define debug_p(x)                  cerr << #x << ": " <<  x.X <<  " " << x.Y << endl;
#define alog(a, n)                  for (ll i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define FOR(n)                      for (ll i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define kill(x)                     return cout << x << endl, 0;

ll poww(ll a, ll b, ll md) {
    if (b == -1) return poww(a, md - 2, md);
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD =  998244353; // 1e9 + 9;

ll lcm(ll a, ll b) {
    return a * b / __gcd(a, b);
}

int main() {
    fast_io;

    map<ll, ll> mp;
    ll n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        ll sq = sqrt(x);
        for (int j = 1; j <= sq; j++) {
            if (x % j == 0) {
                mp[j]++;
                if (x / j != j) mp[x / j]++;
            }
        }
    }

    vector<ll> v;
    for (pll e : mp) {
        if (e.Y < n - 1) continue;
        v.push_back(e.X);
    }

    Sort(v);
    reverse(all(v));

//    alog(v, v.size());

    ll ans = 1;
    for (ll e : v) {
        ans = lcm(ans, e);
    }

    cout << ans << endl;
    return 0;
}