#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

const int mod = 998244353;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int ans = 1;
    int last = -1;
    forn (i, n) {
        cin >> a[i];
        if (a[i] > n - k) {
            if (last != -1) {
                ans *= i - last;
                ans %= mod;
            }
            last = i;
        }
    }
    cout << (n * (n + 1) - (n - k) * (n - k + 1)) / 2 << " " << ans << endl;
}