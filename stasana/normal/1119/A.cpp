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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll id = 1;
    while (a[id] == a[0]) {
        ++id;
    }
    ll result = 0;
    for (ll i = 1; i < n; ++i) {
        if (a[i] == a[0]) {
            result = max(result, i - id);
        }
        else {
            result = max(result, i);
        }
    }
    cout << result << endl;
}

int32_t main() {
    start();
    solve();
    return 0;
}