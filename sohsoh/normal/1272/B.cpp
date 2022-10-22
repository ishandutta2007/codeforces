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
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 2e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll solve() {
    string s;
    cin >> s;
    ll u = 0, d = 0, r = 0, l = 0;
    for (char c : s) {
        if (c == 'U') u++;
        if (c == 'L') l++;
        if (c == 'R') r++;
        if (c == 'D') d++;
    }

    ll x = min(l, r);
    ll y = min(u, d);

    if (x == 0 && y > 0) return cout << 2 << endl << "UD" << endl, 0;
    if (y == 0 && x > 0) return cout << 2 << endl << "RL" << endl, 0;
    cout << x + y + x + y << endl;
    for (int i = 0; i < x; i++) cout << 'R';
    for (int i = 0; i < y; i++) cout << 'D';
    for (int i = 0; i < x; i++) cout << 'L';
    for (int i = 0; i < y; i++) cout << 'U';
    cout << endl;
    return 0;
}

int main() {
    fast_io;

    ll q;
    cin >> q;
    while (q--) solve();

    return 0;
}