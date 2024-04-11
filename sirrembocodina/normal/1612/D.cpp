#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b, x;
        cin >> a >> b >> x;
        bool ok = false;
        while (a > 0 && b > 0) {
            if (a < b) {
                swap(a, b);
            }
            if (a == x || b == x || abs(a - b) == x) {
                ok = true;
            }
            if (a % b <= x && x <= a && x % b == a % b) {
                ok = true;
            }
            a %= b;
            if (a == x || b == x || abs(a - b) == x) {
                ok = true;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}