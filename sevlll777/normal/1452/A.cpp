#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define ld long double
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        if (abs(x - y) <= 1) {
            cout << x + y << '\n';
        } else {
            cout << 2 * max({x, y}) - 1;
        }
        cout << '\n';
    }
}