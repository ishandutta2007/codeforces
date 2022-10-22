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
#define SZ(x)                       ll(x.size());
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define bug(x)                      cerr << #x << ": " <<  x <<  " ";
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define FOR(n)                      for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    if (b == -1) return poww(a, md - 2, md);
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int solve() {
    ll n;
    cin >> n;
    ll* a = new ll[n];

    vector<ll> v;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        if (a[i] == -1) continue;
        if (i > 0 && a[i - 1] == -1) v.push_back(a[i]);
        if (i < n - 1 && a[i + 1] == -1) v.push_back(a[i]);
    }

    ll m = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] != -1 && a[i + 1] != -1) {
            m = max(abs(a[i] - a[i + 1]), m);
        }
    }

    if (v.size() == 0) return cout << m << sep << 0 << endl, 0;

    ll ma = *max_element(v.begin(), v.end());
    ll mi = *min_element(v.begin(), v.end());
    ll e = ma - mi;
    if (e % 2 == 0) m = max(e / 2, m);
    else m = max(e / 2 + 1, m);

    cout << m << sep << e / 2 + mi << endl;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}