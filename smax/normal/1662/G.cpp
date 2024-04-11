#include <bits/stdc++.h>
using namespace std;

// #define int long long
// #define pb push_back
// #define mp make_pair
// #define pi pair<int, int>
// #define endl "\n"
// const int inf = 1e18;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i=1; i<n; i++) {
        int p;
        cin >> p;
        p--;
        adj[p].push_back(i);
        adj[i].push_back(p);
    }

    vector<int> sz(n), centroid;
    bool init = true;

    auto dfs = [&] (auto &self, int u, int p) -> void {
        sz[u] = 1;
        bool ok = true;
        for (int v : adj[u])
            if (v != p) {
                self(self, v, u);
                sz[u] += sz[v];
                ok &= sz[v] * 2 <= n;
            }
        ok &= (n - sz[u]) * 2 <= n;
        if (ok && init)
            centroid.push_back(u);
    };

    dfs(dfs, 0, -1);
    long long ret = 0;
    for (int r : centroid) {
        init = false;
        dfs(dfs, r, -1);

        vector<int> cnt(n + 1);
        for (int v : adj[r])
            cnt[sz[v]]++;

        bitset<500001> dp;
        dp[0] = 1;
        for (int i=1; i<=n; i++) {
            if (cnt[i] > 2) {
                int tot = (cnt[i] - 1) / 2;
                cnt[i] -= 2 * tot;
                cnt[2*i] += tot;
            }
            for (int j=0; j<cnt[i]; j++)
                dp |= dp << i;
        }

        long long cur = 0;
        for (int i=0; i<n; i++)
            if (i != r)
                cur += sz[i];
        for (int i=n/2; i>=0; i--)
            if (dp[i]) {
                cur += (long long) (i + 1) * (n - i);
                break;
            }
        ret = max(ret, cur);
    }
    cout << ret << "\n";

    return 0;
}