#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int32_t main() {
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        int x, y;
        cin >> x >> y;
        if (y < x) {
            cout << x + y << '\n';
            continue;
        }
        cout << (y + y / x * x) / 2 << '\n';
    }
    return 0;
}