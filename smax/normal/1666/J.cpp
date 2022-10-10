#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define endl "\n"

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<vector<int>> c(n, vector<int>(n));
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin >> c[i][j];
        
    vector<vector<long long>> pref(n, vector<long long>(n)), suff(n, vector<long long>(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++)
            pref[i][j] = c[i][j] + (j > 0 ? pref[i][j-1] : 0);
        for (int j=n-1; j>=0; j--)
            suff[i][j] = c[i][j] + (j + 1 < n ? suff[i][j+1] : 0);
    }
    
    vector<vector<long long>> rect(n, vector<long long>(n));
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++) {
            rect[i][j] = c[i][j];
            if (i > 0) rect[i][j] += rect[i-1][j];
            if (j > 0) rect[i][j] += rect[i][j-1];
            if (i > 0 && j > 0) rect[i][j] -= rect[i-1][j-1];
        }
    
    // [a, b] to [c, d]
    // (a, c) to (b, d)
    auto query = [&] (int a, int b, int c, int d) -> long long {
        if (a > b || c > d) return 0;
        long long ret = rect[b][d];
        if (a > 0) ret -= rect[a-1][d];
        if (c > 0) ret -= rect[b][c-1];
        if (a > 0 && c > 0) ret += rect[a-1][c-1];
        return ret;
    };
    
    vector<vector<long long>> dp(n, vector<long long>(n, LLONG_MAX));
    vector<vector<int>> par(n, vector<int>(n));
    for (int i=n-1; i>=0; i--)
        for (int j=i; j<n; j++) {
            long long tot = 0;
            for (int k=i; k<=j; k++)
                tot += (i > 0 ? pref[k][i-1] : 0) + (j + 1 < n ? suff[k][j+1] : 0);
            for (int k=i; k<=j; k++) {
                long long cost = tot - (i > 0 ? pref[k][i-1] : 0) - (j + 1 < n ? suff[k][j+1] : 0) + (pref[k][j] - (i > 0 ? pref[k][i-1] : 0)) + 2 * query(i, k - 1, k + 1, j) + (i <= k - 1 ? dp[i][k-1] : 0) + (k + 1 <= j ? dp[k+1][j] : 0);
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    par[i][j] = k;
                }
            }
        }
    
    vector<int> ret(n);
    
    auto dfs = [&] (auto &self, int l, int r, int p) -> void {
        if (l > r)
            return;
        int u = par[l][r];
        ret[u] = p;
        self(self, l, u - 1, u);
        self(self, u + 1, r, u);
    };
    
    dfs(dfs, 0, n - 1, -1);
    cerr << dp[0][n-1] << "\n";
    for (int i=0; i<n; i++)
        cout << ret[i] + 1 << " \n"[i==n-1];
    
    return 0;
}