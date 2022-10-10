#include <bits/stdc++.h>
using namespace std;

long long solve(long long l, long long r) {
    if (l == r)
        return l;

    int b = log2(r);
    if (1LL << b <= l)
        return solve(l - (1LL << b), r - (1LL << b)) + (1LL << b);
    if ((1LL << (b + 1)) - 1 <= r)
        return (1LL << (b + 1)) - 1;
    return (1LL << b) - 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    while (n--) {
        long long l, r;
        cin >> l >> r;

        cout << solve(l, r) << "\n";

        // big F for the DP solution that turned out to be wrong and took forever to code
        /*// 0 - no restrictions
        // 1 - restricted by l
        // 2 - restricted by r
        // 3 - restricted by both

        if ((l & (1LL << 59)) == (r & (1LL << 59))) {
            dp[59][0] = dp[59][1] = dp[59][2] = -INF;
            dp[59][3] = l & (1LL << 59);
            pred[59][3] = make_pair(l & (1LL << 59), -1);
        } else {
            dp[59][0] = dp[59][3] = -INF;
            dp[59][1] = l & (1LL << 59);
            pred[59][1] = make_pair(l & (1LL << 59), -1);
            dp[59][2] = r & (1LL << 59);
            pred[59][2] = make_pair(r & (1LL << 59), -1);
        }
        for (int i=58; i>=0; i--) {
            int ld = l & (1LL << i), rd = r & (1LL << i);

            dp[i][0] = dp[i+1][0] + 1;
            pred[i][0] = make_pair(1, 0);
            if (ld == 0 && dp[i+1][1] + 1 > dp[i][0]) {
                dp[i][0] = dp[i+1][1] + 1;
                pred[i][0] = make_pair(1, 1);
            }
            if (rd == 1 && dp[i+1][2] > dp[i][0]) {
                dp[i][0] = dp[i+1][2];
                pred[i][0] = make_pair(0, 2);
            }

            dp[i][1] = dp[i+1][1] + ld;
            pred[i][1] = make_pair(ld, 1);
            if (ld != rd && dp[i+1][3] > dp[i][1]) {
                dp[i][1] = dp[i+1][3];
                pred[i][1] = make_pair(0, 3);
            }

            dp[i][2] = dp[i+1][2] + rd;
            pred[i][2] = make_pair(rd, 2);
            if (ld != rd && dp[i+1][3] + 1 > dp[i][2]) {
                dp[i][2] = dp[i+1][3] + 1;
                pred[i][2] = make_pair(1, 3);
            }

            dp[i][3] = -INF;
            if (ld == rd) {
                dp[i][3] = dp[i+1][3] + ld;
                pred[i][3] = make_pair(ld, 3);
            }
        }

        int mx = 0, j;
        for (int jj=0; jj<4; jj++)
            if (dp[0][jj] > mx)
                mx = dp[0][jj], j = jj;

        int i = 0;
        long long ret = 0;
        while (i < 60) {
            if (pred[i][j].first)
                ret |= 1LL << i;
            j = pred[i++][j].second;
        }

        cout << ret << "\n";*/
    }

    return 0;
}