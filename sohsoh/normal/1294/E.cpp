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

const ll MAXN = 2e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, m;
ll g1d[MAXN];

// NOTE THAT ITS 0 BASED CODE :)
ll calc_for_col(vector<ll> v, ll c) {
    ll* d = new ll[n];
    fill(d, d + n, 0);
    ll i = 0;
    for (ll elm : v) {
        if ((elm - c - 1) % m || (elm - c - 1) / m >= n) {
            i++;
            continue;
        }

        ll val = (elm - c - 1) / m;
        val = i - val;
        if (val < 0) val = n + val;
        d[val]++;
        i++;
    }

    ll bf = INF;
    for (int i = 0; i < n; i++) {
        bf = min(bf, i + n - d[i]);
    }

    return bf;
}

int main() {
    fast_io;
    cin >> n >> m;

    for (int i = 0; i < n * m; i++) {
        cin >> g1d[i];
    }

    ll s = 0;
    for (int i = 0; i < m; i++) {
        vector<ll> col;
        for (int j = 0; j < n; j++) {
            col.push_back(g1d[j * m + i]);
        }

        s += calc_for_col(col, i);
    }

    cout << s << endl;

    // DEBUG
//    n = 3;
//    m = 4;
//    vector<ll> v = {6, 10, 2};
//    cout << calc_for_col(v, 1) << endl;
    return 0;
}