#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define ld long double
using namespace std;
const int M = 998244353;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= k; i++) {
            if (i < k - (n - k)) {
                cout << i << ' ';
            } else {
                cout << k - (i - (k - (n - k))) << ' ';
            }
        }
        cout << '\n';
    }
}