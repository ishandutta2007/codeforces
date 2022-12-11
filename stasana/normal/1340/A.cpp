// Bipolar disorder is very cool

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef int64_t ll;

inline void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

inline void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> index(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        if (a[i] - a[i - 1] > 1) {
            cout << "No" << "\n";
            return;
        }
    }
    cout << "Yes" << "\n";
}

int main() {
    start();
    ll t;
    cin >> t;
    for (ll i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}