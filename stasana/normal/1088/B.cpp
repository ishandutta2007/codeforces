// Megumin top

#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <queue>

using namespace std;

typedef int64_t ll;

void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll ptr = 0, cnt = 0;
    for (ll i = 0; i < k; ++i) {
        if (ptr == n) {
            cout << 0 << "\n";
        }
        else {
            cout << a[ptr] - cnt << "\n";
            cnt = a[ptr];
        }
        while (ptr < n && a[ptr] <= cnt) {
            ++ptr;
        }
    }
}

int main() {
    start();
    solve();
    return 0;
}