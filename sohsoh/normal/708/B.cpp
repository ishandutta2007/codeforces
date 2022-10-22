/*
    Soheil Mohammadkhani
    I will change this text here when i've got "Candidate Master":)
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll ftn(ll x) {
    ll i = 0;
    while (i * (i - 1) / 2 < x) i++;
    if (i * (i - 1) / 2 > x) return -1;
    return i;
}

ll a00, a01, a10, a11;

int main() {
    fast_io;
    cin >> a00 >> a01 >> a10 >> a11;
    ll o = ftn(a11), z = ftn(a00);
    if (o == 0 && (a01 || a10)) o++;
    if (z == 0 && (a01 || a10)) z++;

    ll n = o * z;
    if (a01 == 0 && a10 == 0 && a00 == 0 && a11 == 0) return cout << 1 << endl, 0;
    if (o == -1 || z == -1 || a01 + a10 != n) return cout << "Impossible" << endl, 0;

    ll x = 0, y = 0;
    if (z > 0) x = a10 / z, y = a10 % z;

    if (x + min(y, 1ll) > o) return cout << "Impossible" << endl, 0;
    for (int i = 0; i < x; i++) cout << '1', o--;
    for (int i = 0; i < z - y; i++) cout << '0';
    if (y) cout << '1', o--;
    for (int i = 0; i < y; i++) cout << '0';
    while (o > 0) cout << '1', o--;
    cout << endl;
    return 0;
}