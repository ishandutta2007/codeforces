#include <bits/stdc++.h>
#define int int64_t

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int ans = 1;
        while (k--) {
            ans *= n;
            ans %= int(1e9 + 7);
        }
        cout << ans << endl;
    }
}