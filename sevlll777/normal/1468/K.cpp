#include <bits/stdc++.h>

#define pb push_back
// #define int long long
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
        string s;
        cin >> s;
        int b1 = 0, b2 = 0;
        bool ok = false;
        for (auto c : s) {
            if (c == 'L') {
                b1--;
            } else if (c == 'R') {
                b1++;
            } else if (c == 'U') {
                b2++;
            } else {
                b2--;
            }
            int x = 0, y = 0;
            for (auto cc : s) {
                if (cc == 'L') {
                    x--;
                } else if (cc == 'R') {
                    x++;
                } else if (cc == 'U') {
                    y++;
                } else {
                    y--;
                }
                if (x == b1 && y == b2) {
                    if (cc == 'L') {
                        x++;
                    } else if (cc == 'R') {
                        x--;
                    } else if (cc == 'U') {
                        y--;
                    } else {
                        y++;
                    }
                }
            }
            if (x == y && x == 0 && (b1 || b2)) {
                ok = true;
                cout << b1 << ' ' << b2 << '\n';
                break;
            }
        }
        if (!ok) {
            cout << "0 0\n";
        }

    }
}