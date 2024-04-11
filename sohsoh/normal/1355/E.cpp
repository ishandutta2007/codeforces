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

ll n, a, r, m, h[MAXN], pref[MAXN] = {0};

ll calc(ll x) {
    ll i = lower_bound(h, h + n, x) - h;
    ll x1 = x * i - pref[i];
    ll x2 = pref[n] - pref[i] - x * (n - i);
    ll tmp = min(x1, x2);
    x1 -= tmp;
    x2 -= tmp;
    ll res = tmp * m;
    res += x1 * a;
    res += x2 * r;
    return res;
}

int main() {
    fast_io;
    cin >> n >> a >> r >> m;
    m = min(a + r, m);
    for (int i = 0; i < n; i++) cin >> h[i];
    sort(h, h + n);

    for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + h[i];

    ll L = h[0], R = h[n - 1];
    while (R - L > 1e4) {
        ll M1 = L + (R - L) / 3, M2 = R - (R - L) / 3;
        if (calc(M1) > calc(M2)) L = M1;
        else R = M2;
    }

    ll bf = INF;
    for (int i = L; i <= R; i++) {
        bf = min(bf, calc(i));
    }

    cout << bf << endl;
    return 0;
}