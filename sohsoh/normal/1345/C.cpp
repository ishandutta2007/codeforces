/*
    Soheil Mohammadkhani
    IDK :)
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define bug(x)                      cerr << #x << ": " <<  x <<  " ";
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define FOR(n)                      for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    if (b == -1) return poww(a, md - 2, md);
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 250000 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll NMAX = 1e6 + 10;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll calc(ll n) {
    return n * n + n + (n * n - n) / 2;
}

ll nxt(ll k, ll x, ll n) {
    return (k + x) % n;
}

ll mod(ll a, ll b)
{
    ll r = a % b;
    return r < 0 ? r + b : r;
}

ll solve() {
    ll n;
    cin >> n;
    ll* a = new ll[n];
    ll* cnt = new ll[n];
    fill(cnt, cnt + n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        cnt[mod(i + a[i], n)]++;
        if (cnt[mod(i + a[i], n)] > 1) return cout << "NO" << endl, 0;
    }

    cout << "YES" << endl;
    return 0;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}