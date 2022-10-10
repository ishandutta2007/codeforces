#include <bits/stdc++.h>
using namespace std;

int animal[50][20000], pref[50][20000], dp[50][20000], pmax[50][20000], smax[50][20000];

int query(int i, int j, int k) {
    return pref[i][k] - (j > 0 ? pref[i][j-1] : 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m, k;
    cin >> n >> m >> k;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) {
            cin >> animal[i][j];
            pref[i][j] = (j > 0 ? pref[i][j-1] : 0) + animal[i][j];
        }

    for (int i=0; i<n; i++) {
        for (int j=0; j<=m-k; j++) {
            int seen = query(i, j, j + k - 1) + (i < n - 1 ? query(i + 1, j, j + k - 1) : 0);
            if (i == 0) {
                dp[i][j] = seen;
                continue;
            }
            dp[i][j] = 0;
            for (int l=max(0, j-k+1); l<=min(m-k, j+k-1); l++)
                dp[i][j] = max(dp[i][j], dp[i-1][l] + seen - query(i, max(l, j), min(l + k - 1, j + k - 1)));
            if (j >= k)
                dp[i][j] = max(dp[i][j], pmax[i-1][j-k] + seen);
            if (j + k <= m - k)
                dp[i][j] = max(dp[i][j], smax[i-1][j+k] + seen);
        }
        for (int j=0; j<=m-k; j++)
            pmax[i][j] = max(j > 0 ? pmax[i][j-1] : 0, dp[i][j]);
        for (int j=m-k; j>=0; j--)
            smax[i][j] = max(j < m - k ? smax[i][j+1] : 0, dp[i][j]);
    }

    cout << *max_element(dp[n-1], dp[n-1] + m - k + 1) << "\n";

    return 0;
}