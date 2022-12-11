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
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            if (i + j == 0) {
                cout << "W";
            } else {
                cout << "B";
            }
        }
        cout << endl;
    }
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