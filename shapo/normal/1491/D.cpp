#include <bits/stdc++.h>

using namespace std;

#define ve vector
#define pa pair
#define tu tuple

typedef uint32_t uint;
typedef int64_t ll;

typedef ve<int> vi;
typedef ve<vi> v2i;
typedef pa<int, int> pii;

bool
can(int u, int v)
{
    v2i dp(31, vi(31, 0));
    dp[30][0] = 1;
    for (int i = 29; i >= 0; --i) {
        int u_b = (u >> i) & 1;
        int v_b = (v >> i) & 1;
        if (u_b == v_b) {
            dp[i] = dp[i + 1];
        } else if (u_b == 0 && v_b == 1) {
            for (int j = 1; j <= 30; ++j) {
                dp[i][j] = dp[i + 1][j - 1];
            }
        } else if (u_b == 1 && v_b == 0) {
            dp[i][0] = dp[i + 1][1];
            for (int j = 1; j < 30; ++j) {
                dp[i][j] = max(dp[i + 1][j + 1], dp[i + 1][j]);
            }
            dp[i][30] = dp[i + 1][30];
        }
    }
    return dp[0][0];
}


int
main()
{
    ios_base::sync_with_stdio(false);
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int u, v;
        cin >> u >> v;
        if (can(u, v)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}