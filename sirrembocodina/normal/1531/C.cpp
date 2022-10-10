#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    if (n == 2) {
        cout << -1 << endl;
        return 0;
    }
    int len = 1 + (n % 2 == 0);
    while ((len + 2) * (len + 2) <= n) {
        len += 2;
    }
    n -= len * len;
    n /= 2;
    int ans = len + (n + len - 1) / len;
    cout << ans << '\n';
    if (n > 0) {
        int rem = n % len + (n % len == 0) * len;
        forn (i, rem) {
            cout << 'o';
        }
        forn (i, ans - rem) {
            cout << '.';
        }
        cout << '\n';
        forn (i, (n - 1) / len) {
            forn (i, len) {
                cout << 'o';
            }
            forn (i, ans - len) {
                cout << '.';
            }
            cout << '\n';
        }
    }
    forn (i, len) {
        int cur = len + n / len + (i >= len - n % len);
        forn (i, cur) {
            cout << 'o';
        }
        forn (i, ans - cur) {
            cout << '.';
        }
        cout << '\n';
    }
}