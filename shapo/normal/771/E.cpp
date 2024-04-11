#include <bits/stdc++.h>

using namespace std;

#define ve vector
#define pa pair
#define tu tuple

#define pb push_back
#define mp make_pair
#define mt make_tuple

typedef ve<int> vi;
typedef ve<vi> v2i;
typedef ve<v2i> v3i;

typedef long long ll;

const int MAXN = 300000;

int n, d;
int arr[3][MAXN];
int pval[3][MAXN + 1];
int dp[3][MAXN + 1];

void
find_bords(int* vals, int* prev, int sz)
{
    map<ll, int> psum_idx;
    ll cur_psum = 0ll;
    psum_idx[cur_psum] = 0;
    memset(prev, -1, sz * sizeof(*prev));
    for (int i = 0; i < sz; ++i) {
        prev[i + 1] = prev[i];
        cur_psum += vals[i];
        auto it = psum_idx.find(cur_psum);
        if (it != psum_idx.end()) {
            prev[i + 1] = max(prev[i + 1], it->second);
        }
        psum_idx[cur_psum] = i + 1;
    }
}

int
main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int r = 0; r < 2; ++r) {
        for (int c = 0; c < n; ++c) {
            cin >> arr[r][c];
        }
    }
    for (int c = 0; c < n; ++c) {
        arr[2][c] = arr[0][c] + arr[1][c];
    }

    for (int r = 0; r < 3; ++r) {
        find_bords(arr[r], pval[r], n);
    }

    memset(dp, -1, sizeof(dp));
    memset(dp[2], 0, sizeof(dp[2]));

    for (int i = n; i >= 1; --i) {
        if (dp[2][i - 1] < dp[2][i]) {
            dp[2][i - 1] = dp[2][i];
            dp[0][i - 1] = dp[1][i - 1] = -1;
        }
        if (dp[2][i - 1] == dp[2][i]) {
            dp[0][i - 1] = max(dp[0][i - 1], dp[0][i]);
            dp[1][i - 1] = max(dp[1][i - 1], dp[1][i]);
        }
        int pv = pval[2][i];
        if (pv != -1 && dp[2][pv] < dp[2][i] + 1) {
            dp[2][pv] = dp[2][i] + 1;
            dp[0][pv] = dp[1][pv] = -1;
        }
        for (int r = 0; r < 2; ++r) {
            dp[r][i] = max(dp[r][i], pval[r ^ 1][i]);
            int j = dp[r][i];
            if (j == -1) {
                continue;
            }
            // no new rectangle
            if (dp[2][i - 1] == dp[2][i]) {
                dp[r][i - 1] = max(dp[r][i - 1], j);
            }
            // absolutely no rectangle
            if (dp[2][j] < dp[2][i] + 1) {
                dp[2][j] = dp[2][i] + 1;
                dp[0][j] = dp[1][j] = -1;
            }
            // new rectangle
            int pv = pval[r][i];
            if (pv == j) {
                if (dp[2][pv] < dp[2][i] + 2) {
                    dp[2][pv] = dp[2][i] + 2;
                    dp[0][pv] = dp[1][pv] = -1;
                }
            } else if (pv != -1) {
                int idx = max(pv, j);
                int row = r ^ (pv != idx);
                if (dp[2][idx] < dp[2][i] + 1) {
                    dp[2][idx] = dp[2][i] + 1;
                    dp[0][idx] = dp[1][idx] = -1;
                }
                if (dp[2][idx] == dp[2][i] + 1) {
                    dp[row][idx] = max(dp[row][idx], min(pv, j));
                }
            }
        }
        // cout << dp[0][i] << ' ' << dp[1][i] << ' ' << dp[2][i] << endl;
    }

    cout << dp[2][0] << '\n';

    return 0;
}