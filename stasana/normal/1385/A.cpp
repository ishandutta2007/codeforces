// Bipolar disorder is very cool

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef int64_t ll;

void solve() {
    ll x, y, z;
    cin >> x >> y >> z;
    vector<ll> a;
    a.emplace_back(x);
    a.emplace_back(y);
    a.emplace_back(z);
    a.emplace_back(1);
    for (ll i = 0; i < 4; ++i) {
        for (ll j = 0; j < 4; ++j) {
            for (ll q = 0; q < 4; ++q) {
                if (max(a[i], a[j]) != x || max(a[j], a[q]) != y || max(a[q], a[i]) != z) {
                    continue;
                }
                cout << "YES" << "\n";
                cout << a[i] << " " << a[j] << " " << a[q] << "\n";
                return;
            }
        }
    }
    cout << "NO" << "\n";
}

int main() {
    ll t;
    cin >> t;
    while (t) {
        --t;
        solve();
    }
    return 0;
}