// Megumin top

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>

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
    set<ll> a;
    a.insert(0);
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        set<ll> b;
        for (ll y : a) {
            b.insert((x + y) % 360);
            b.insert((y - x + 360) % 360);
        }
        a.swap(b);
    }
    if (a.count(0)) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}

int main() {
    start();
    solve();
    return 0;
}