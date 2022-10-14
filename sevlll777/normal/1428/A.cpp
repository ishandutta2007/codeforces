#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define ld long double
using namespace std;
const int M = 1000000007;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2) {
            cout << abs(y1 - y2);
        } else if (y1 == y2) {
            cout << abs(x1 - x2);
        } else {
            cout << 2 + abs(x1 - x2) + abs(y1 - y2);
        }
        cout << '\n';
    }

}