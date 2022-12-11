// Bipolar disorder is very cool

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef int64_t ll;

void solve() {
    ll n;
    cin >> n;
    vector<ll> used(n);
    vector<ll> p;
    for (ll i = 0; i < 2 * n; ++i) {
        ll x;
        cin >> x;
        if (used[x - 1] == 0) {
            p.emplace_back(x);
        }
        used[x - 1] = 1;
    }
    for (ll i : p) {
        cout << i << " ";
    }
    cout << "\n";
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