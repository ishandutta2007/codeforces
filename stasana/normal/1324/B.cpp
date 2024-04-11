// Bipolar disorder is very cool

#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef int64_t ll;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (ll i = 0; i < n; ++i) {
        for (ll j = i + 2; j < n; ++j) {
            if (a[i] == a[j]) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}

int main() {
    ll n;
    cin >> n;
    while (n) {
        --n;
        solve();
    }
    return 0;
}