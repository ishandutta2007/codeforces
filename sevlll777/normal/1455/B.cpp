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
        int x;
        cin >> x;
        for (int y = 1; y <= x; y++) {
            if (y * (y + 1) / 2 >= x) {
                if (y * (y + 1) / 2 == x + 1) {
                    cout << y + 1 << '\n';
                } else {
                    cout << y << '\n';
                }
                break;
            }
        }
    }

}