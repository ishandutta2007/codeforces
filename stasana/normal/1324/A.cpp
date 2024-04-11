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
    set<ll> kek;
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        kek.insert(x & 1);
    }
    if (kek.size() == 2) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
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