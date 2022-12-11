#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <ctime>
#include <set>
#include <map>

using namespace std;

typedef int64_t ll;
typedef long double ld;

inline void start() {
#ifdef BOKU_NO_PICO
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
#endif
}

inline void solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m));
    vector<vector<ll>> b(n, vector<ll>(m));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            cin >> b[i][j];
        }
    }
    vector<ll> c(n);
    vector<ll> d(m);
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            c[i] += a[i][j] - b[i][j];
            d[j] += a[i][j] - b[i][j];
        }
    }
    for (ll i = 0; i < n; ++i) {
        if (c[i] & 1) {
            cout << "No" << endl;
            return;
        }
    }
    for (ll i = 0; i < m; ++i) {
        if (d[i] & 1) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

int32_t main() {
    start();
    solve();
    return 0;
}