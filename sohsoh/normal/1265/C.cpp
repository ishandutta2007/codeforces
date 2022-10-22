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

ll a[MAXN];

ll solve() {
    ll n;
    cin >> n;

    ll mx = n / 2;
    ll res_end = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i > 0 && a[i] != a[i - 1] && i - 1 < mx) res_end = i;
    }
//
//    cout << mx << endl;

    ll g = 1, s = 1, b = 0;
    ll i = 1;
    while (a[i] == a[i - 1] && i < res_end) {
        i++;
        g++;
    }
    i++;
    while ((a[i] == a[i - 1] || s <= g) && i < res_end ) {
        i++;
        s++;
    }

    while (i < res_end) {
        i++;
        b++;
    }

    if (g == 0 || s == 0 || b == 0 || s <= g || b <= g) kill("0 0 0");
    cout << g << sep << s << sep << b << endl;
    return 0;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}