#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int dp[101][101][2][2]; // 1 = A wins

int32_t main() {
    for (int i = 0; i <= 100; i++) { // even
        for (int j = 0; j <= 100; j++) { // odd
            for (int turn = 0; turn < 2; turn++) { // 0 = A's turn
                for (int taken = 0; taken < 2; taken++) {
                    if (i == 0 && j == 0) {
                        dp[i][j][turn][taken] = taken == 0;
                        continue;
                    }
                    if (turn == 0) {
                        dp[i][j][turn][taken] = 0;
                        if (i) {
                            dp[i][j][turn][taken] = max(dp[i][j][turn][taken], dp[i - 1][j][1 - turn][taken]);
                        }
                        if (j) {
                            dp[i][j][turn][taken] = max(dp[i][j][turn][taken], dp[i][j - 1][1 - turn][1 - taken]);
                        }
                    } else {
                        dp[i][j][turn][taken] = 1;
                        if (i) {
                            dp[i][j][turn][taken] = min(dp[i][j][turn][taken], dp[i - 1][j][1 - turn][taken]);
                        }
                        if (j) {
                            dp[i][j][turn][taken] = min(dp[i][j][turn][taken], dp[i][j - 1][1 - turn][taken]);
                        }
                    }
                }
            }
        }
    }
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int even = 0, odd = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x % 2) {
                odd++;
            } else {
                even++;
            }
        }
        cout << (dp[even][odd][0][0] ? "Alice\n" : "Bob\n");
    }
}