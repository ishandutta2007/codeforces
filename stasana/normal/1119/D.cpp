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
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    vector<ll> c;
    for (ll i = 1; i < a.size(); ++i) {
        c.emplace_back(a[i] - a[i - 1]);
    }
    c.emplace_back(0);
    sort(c.begin(), c.end());
    a.swap(c);
    ll m;
    cin >> m;
    vector<ll> b(a.size() - 1);
    for (ll i = 0; i < b.size(); ++i) {
        b[i] = (a.size() - i) * (a[i + 1] - a[i]);
    }
    for (ll i = 1; i < b.size(); ++i) {
        b[i] += b[i - 1];
    }
    for (ll i = 0; i < m; ++i) {
        ll left, right;
        cin >> left >> right;
        ll x = right - left + 1;
        left = -1;
        right = a.size();
        while (right - left > 1) {
            ll mid = (left + right) / 2;
            if (a[mid] <= x) {
                left = mid;
            }
            else {
                right = mid;
            }
        }
        if (left == 0) {
            cout << x * a.size() << " ";
        }
        else {
            cout << b[left - 1] + (x - a[left]) * (a.size() - left) << " ";
        }
    }
}

int32_t main() {
    start();
    solve();
    return 0;
}