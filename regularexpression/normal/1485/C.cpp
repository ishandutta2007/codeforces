#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll x, y;
        cin >> x >> y;
        ll sq = 40000;
        ll ans = 0;
        for (ll b = 1; b <= min(y, sq); b++) 
            ans += min(b - 1, x / (b + 1));
        if (y <= sq) {
            cout << ans << "\n";
            continue;
        }
        for (ll r = 1; r < sq; r++) {
            ll min_b = sq + 1;
            ll max_b = min(y, x / r - 1);
            ans += max(0ll, max_b - min_b + 1);
        }
        cout << ans << "\n";
    }
    return 0;
}