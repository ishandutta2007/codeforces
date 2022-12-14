#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, k;
        cin >> n >> k;
        vector<LL> a, b;
        for (int i = 0, xi; i < n; i += 1) {
            cin >> xi;
            if (xi > 0) a.push_back(xi);
            if (xi < 0) b.push_back(-xi);
        }
        ranges::sort(a);
        ranges::sort(b);
        ranges::reverse(a);
        ranges::reverse(b);
        LL ans = 0;
        for (int i = 0; i < (int)a.size(); i += k) {
            ans += 2 * a[i];
        }
        for (int i = 0; i < (int)b.size(); i += k) {
            int j = min((int)b.size() - 1, i + k - 1);
            ans += 2 * b[i];
        }
        if (a.empty() and not b.empty()) ans -= b[0];
        if (not a.empty() and b.empty()) ans -= a[0];
        if (not a.empty() and not b.empty()) ans -= max(a[0], b[0]);
        cout << ans << "\n";
    }
    return 0;
}