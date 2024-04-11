#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, s;
        cin >> n >> s;
        n -= (n - 1) / 2;
        cout << s / n << '\n';
    }
    return 0;
}