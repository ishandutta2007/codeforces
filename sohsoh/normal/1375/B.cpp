/*
    Soheil Mohammadkhani
    Still nothing here :|
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

const ll MAXN = 3e3 + 10; // Change it :) **
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll G[MAXN][MAXN];

ll solve() {
    ll n, m;
    cin >> n >> m;
    bool b = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> G[i][j];
            ll neigh = 0;
            if (i > 0) neigh++;
            if (j > 0) neigh++;
            if (i + 1 < n) neigh++;
            if (j + 1 < m) neigh++;
            if (G[i][j] > neigh) b = true;
            G[i][j] = neigh;
        }
    }

    if (b) return cout << "NO" << endl, 0;

    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << G[i][j] << sep;
        }

        cout << endl;
    }
    return 0;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}