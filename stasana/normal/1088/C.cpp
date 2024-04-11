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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << n + 1 << endl;
    ll cnt = 0;
    for (ll i = n; i > 0; --i) {
        cout << 1 << " " << i << " " << n - (a[i - 1] + cnt) % n + i - 1 << "\n";
        cnt += n - (a[i - 1] + cnt) % n + i - 1;
    }
    cout << 2 << " " << n << " " << n << endl;
}

int main() {
    start();
    solve();
    return 0;
}