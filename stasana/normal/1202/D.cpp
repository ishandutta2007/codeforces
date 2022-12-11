#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef int64_t ll;
typedef long double ld;

const int INF = (int)(1e9) + 666;

inline void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

inline void solve() {
    ll n;
    cin >> n;
    ll x = 1;
    while (x * (x - 1) / 2 <= n) {
        ++x;
    }
    --x;
    /*
    if (x * (x - 1) / 2 == n) {
        cout << 1;
        for (ll i = 0; i < x; ++i) {
            cout << 3;
        }
        cout << 7 << "\n";
        break;
    }
    */
    cout << 1;
    for (ll i = 0; i < x - 2; ++i) {
        cout << 3;
    }
    for (ll i = 0; i < n - x * (x - 1) / 2; ++i) {
        cout << 1;
    }
    cout << 337 << "\n";
}

int main() {
    start();
    int n;
    cin >> n;
    while (n) {
        --n;
        solve();
    }
    return 0;
}