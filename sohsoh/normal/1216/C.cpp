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
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

struct shape { ll t, b, l, r; };

int main() {
    fast_io;
    shape w, b1, b2;
    cin >> w.l >> w.b >> w.r >> w.t;
    cin >> b1.l >> b1.b >> b1.r >> b1.t;
    cin >> b2.l >> b2.b >> b2.r >> b2.t;

    b1.l = max(b1.l, w.l);
    b2.l = max(b2.l, w.l);
    b1.b = max(b1.b, w.b);
    b2.b = max(b2.b, w.b);
    b1.r = min(b1.r, w.r);
    b2.r = min(b2.r, w.r);
    b1.t = min(b1.t, w.t);
    b2.t = min(b2.t, w.t);

    ll l1 = b1.r - b1.l, l2 = b1.t - b1.b, l3 = b2.r - b2.l , l4 = b2.t - b2.b, s = 0;
    if (l1 > 0 && l2 > 0) s -= l1 * l2;
    if (l3 > 0 && l4 > 0) s -= l3 * l4;
    l1 = min(b1.r, b2.r) - max(b1.l, b2.l);
    l2 = min(b1.t, b2.t) - max(b1.b, b2.b);
    if (l1 > 0 && l2 > 0) s += l1 * l2;
    s += (w.r - w.l) * (w.t - w.b);
    if (s > 0) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}