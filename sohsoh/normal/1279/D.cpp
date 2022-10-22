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
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define FOR(n)                      for (int i = 0; i < n; i++)
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

map<ll, vector<ll>> mp;
ll k[MAXN] = {0};

pll res = {0, 1};

void add_to_res(pll p) {
//    ll lcm = p.Y * res.Y / __gcd(p.Y, res.Y);
    res.X = (res.X * p.Y % MOD) + ((res.Y * p.X) % MOD);
    res.X = res.X % MOD;
    res.Y = res.Y * p.Y % MOD;
}

int main() {
    fast_io;
    ll n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k[i];
        for (int j = 0; j < k[i]; j++) {
            ll x;
            cin >> x;
            if (mp.find(x) == mp.end()) {
                vector<ll> v;
                mp.insert({x, v});
            }

            mp[x].push_back(i);
        }
    }

    for (plv e : mp) {
        vector<ll> v = e.Y;
        for (ll c : v) {
            ll y = n * n % MOD * k[c] % MOD;
            ll x = SZ(v);
            add_to_res({x, y});
        }
    }

//    ll g = __gcd(res.X, res.Y);
//    res.X /= g;
//    res.Y /= g;

    cout << res.X * poww(res.Y, MOD - 2, MOD) % MOD << endl;
    return 0;
}