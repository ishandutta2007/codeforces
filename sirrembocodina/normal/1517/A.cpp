#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n % 2050) {
            cout << "-1\n";
            continue;
        }
        n /= 2050;
        int ans = 0;
        while (n) {
            ans += n % 10;
            n /= 10;
        }
        cout << ans << endl;
    }
}