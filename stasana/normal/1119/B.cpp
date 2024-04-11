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
    ll n, h;
    cin >> n >> h;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll left = 0;
    ll right = n + 1;
    while (right - left > 1) {
        ll mid = (left + right) / 2;
        vector<ll> b;
        for (ll i = 0; i < mid; ++i) {
            b.emplace_back(a[i]);
        }
        sort(b.begin(), b.end());
        ll sum = 0;
        for (ll i = b.size() - 1; i >= 0; i -= 2) {
            sum += b[i];
        }
        if (sum <= h) {
            left = mid;
        }
        else {
            right = mid;
        }
    }
    cout << left << endl;
}

int32_t main() {
    start();
    solve();
    return 0;
}