// Bipolar disorder is very cool

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

typedef int64_t ll;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll& i : a) {
        cin >> i;
    }
    for (ll x = (1 << 29); x >= 1; x >>= 1) {
        ll cnt = 0;
        for (ll i : a) {
            if (i & x) {
                ++cnt;
            }
        }
        if ((cnt & 3) == 1) {
            cout << "WIN\n";
            return;
        }
        if ((cnt & 3) == 3) {
            if ((n - cnt) & 1) {
                cout << "WIN\n";
            } else {
                cout << "LOSE\n";
            }
            return;
        }
    }
    cout << "DRAW\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t) {
        --t;
        solve();
    }

    return 0;
}