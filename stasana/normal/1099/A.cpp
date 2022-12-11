// Megumin top

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

typedef int64_t ll;

inline void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

inline void solve() {
    ll w, h;
    cin >> w >> h;
    vector<ll> a(h + 1);
    for (ll i = 0; i < 2; ++i) {
        ll u, d;
        cin >> u >> d;
        a[d] = u;
    }
    for (ll i = h; i > 0; --i) {
        w = max(0LL, w + i - a[i]);
    }
    cout << w << endl;
}

int main() {
    start();
    solve();
    return 0;
}