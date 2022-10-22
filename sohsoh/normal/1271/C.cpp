/*
    Soheil Mohammadkhani
    I will change this text here when i've got "Expert" :)
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
#define debug2(x)                   cerr << #x << ": " <<  x <<  " ";
#define debug_p(x)                  cerr << #x << ": " <<  x.X <<  " " << x.Y << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define FOR(n)                      for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define kill(x)                     return cout << x << endl, 0;

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, sx, sy;

int main() {
    fast_io;
    cin >> n >> sx >> sy;
    map<pll, ll> mp;
    mp.insert({{1, 0}, 0});
    mp.insert({{0, 1}, 0});
    mp.insert({{0, -1}, 0});
    mp.insert({{-1, 0}, 0});

    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;

        x -= sx;
        y -= sy;
        if (x > 0) mp[{1, 0}]++;
        if (x < 0) mp[{-1, 0}]++;
        if (y > 0) mp[{0, 1}]++;
        if (y < 0) mp[{0, -1}]++;

    }

    pair<pll, ll> p;
    p.Y = 0;
    for (pair<pll, ll> e : mp) {
        if (e.Y > p.Y) {
            p = e;
        }
    }

    cout << p.Y << endl;
    cout << sx + p.X.X << " " << p.X.Y + sy << endl;

    return 0;
}