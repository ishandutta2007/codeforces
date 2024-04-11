#include <bits/stdc++.h>

#define pb push_back
// #define int long long
#define ld long double
using namespace std;
const int M = 1000000007;
bitset<3009> dp[3009];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> A(n + 1), P(n + 1);
        for (int i = 1; i <= n; i++) cin >> A[i];
        map<int, int> kekw;
        kekw[0] = 0;
        for (int i = 1; i <= n; i++) {
            P[i] = P[i - 1] + A[i];
            kekw[P[i]] = i;
        }
        for (int i = 0; i <= n; i++) dp[i].reset();
        dp[0][0] = true;
        for (int i = 1; i <= n; i++) {
            for (int k = 1; k <= i; k++) {
                if (P[i] % k == 0) {
                    int num = P[i] / k;
                    if (kekw.find(P[i] - num) != kekw.end()) {
                        int l = kekw[P[i] - num] + 1;
                        if (dp[l - 1][k - 1]) dp[i][k] = true;
                    }
                }
            }
        }
        for (int k = n; k >= 1; k--) {
            if (dp[n][k]) {
                cout << n - k << '\n';
                break;
            }
        }
    }
}