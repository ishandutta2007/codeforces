#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef int64_t ll;

void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> b(n);
    for (ll i = 0; i < n; ++i) {
        cin >> b[i];
    }
    bool f1 = false;
    bool f2 = false;
    for (ll i = 0; i < n; ++i) {
        ll delta = b[i] - a[i];
        if (delta > 0 && !f1) {
            cout << "No" << "\n";
            return;
        }
        if (delta < 0 && !f2) {
            cout << "No" << "\n";
            return;
        }
        if (a[i] == 1) {
            f1 = true;
        }
        if (a[i] == -1) {
            f2 = true;
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