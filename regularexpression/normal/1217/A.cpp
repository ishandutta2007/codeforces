#include<bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int s, t, n;
    cin >> s >> t >> n;
    if (-t + s + n <= 0) {
        cout << 0 << '\n';
        return;
    }
    int R = (-t + s + n - 1) / 2;
    R = min(R, n);
    cout << max(0LL, R + 1) << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}