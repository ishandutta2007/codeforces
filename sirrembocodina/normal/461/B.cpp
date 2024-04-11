#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int mod = 1e9 + 7;

vector<vector<int>> sons;
vector<vector<int>> dp;
vector<int> col;

void dfs(int v) {
    vector<int> a;
    for (int to: sons[v]) {
        dfs(to);
        a.push_back(dp[to][0] + dp[to][1]);
    }
    vector<int> pref(sons[v].size() + 1, 1);
    for (int i = 0; i < sons[v].size(); i++) {
        pref[i + 1] = pref[i] * a[i] % mod;
    }
    vector<int> suf(sons[v].size() + 1, 1);
    for (int i = int(sons[v].size()) - 1; i >= 0; i--) {
        suf[i] = suf[i + 1] * a[i] % mod;
    }
    if (col[v] == 1) {
        dp[v][1] = 0;
        dp[v][0] = pref[sons[v].size()];
        return;
    }
    dp[v][1] = pref[sons[v].size()];
    dp[v][0] = 0;
    for (int i = 0; i < sons[v].size(); i++) {
        (dp[v][0] += dp[sons[v][i]][0] * pref[i] % mod * suf[i + 1] % mod) %= mod;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    sons.resize(n);
    for (int i = 1; i < n; i++) {
        int v;
        cin >> v;
        sons[v].push_back(i);
    }
    col.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> col[i];
    }
    dp.assign(n, vector<int>(2));
    dfs(0);
    cout << dp[0][0];
}