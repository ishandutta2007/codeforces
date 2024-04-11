#include <bits/stdc++.h>
//#include <ext/pb_ds/detail/standard_policies.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>


#define f first
#define s second
#define int li

using namespace std;
//using namespace __gnu_pbds;
//using namespace pb_ds;
using li = long long;
using pii = pair<int, int>;

//typedef tree<
//int,
//null_type,
//less<int>,
//rb_tree_tag,
//tree_order_statistics_node_update>
//ordered_set;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 1e5 + 13;
const int A = 1e4 + 13;

//ordered_set st[A];

int a[N][3];
li dp[N][3];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[j][i];
        }
    }

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j < 3; j++) {
            dp[i][j] = -INF * 1ll * INF;
        }
    }

    dp[0][0] = 0;
    li cur0 = 0, cur2 = 0;
    li mx0 = -INF * 1ll * INF;
    li mx2 = mx0;
    for(int i = 0; i < n; i++) {
        dp[i][0] = max(dp[i][0], cur0 + mx0);
        dp[i][2] = max(dp[i][2], cur2 + mx2);

        mx0 = max(mx0, dp[i][2] - cur0);
        mx2 = max(mx2, dp[i][0] - cur2);

        dp[i + 1][0] = max(max(dp[i + 1][0], dp[i][0] + a[i][0]),
                           max(dp[i][1], dp[i][2] + a[i][2]) + a[i][0] + a[i][1]);

        dp[i + 1][1] = max(max(dp[i + 1][1], dp[i][0] + a[i][0] + a[i][1]),
                           max(dp[i][1], dp[i][2] + a[i][2]) + a[i][1]);

        dp[i + 1][2] = max(max(dp[i + 1][2], dp[i][2] + a[i][2]),
                           max(dp[i][1], dp[i][0] + a[i][0]) + a[i][2] + a[i][1]);

        cur0 += a[i][0] + a[i][1] + a[i][2];
        cur2 += a[i][0] + a[i][1] + a[i][2];

    }

    cout << max(dp[n][2], cur2 + mx2) << endl;
}