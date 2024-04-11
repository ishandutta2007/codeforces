#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    vector<vector<int>> r(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        r[u].push_back(v);
    }
    
    vector<int> group(n, 0);
    int ng = 1;
    map<int, int> olne;
    for (int i = 0; i < n; ++i) {
        olne.clear();
        for (int j = 0; j < r[i].size(); ++j) {
            if (olne.count(group[r[i][j]]) == 0) {
                olne.insert({group[r[i][j]], ng});
                group[r[i][j]] = ng;
                ++ng;
            } else {
                group[r[i][j]] = olne[group[r[i][j]]];
            }
        }
    }
    
    ll ans = 0;
    vector<ll> sum(ng, 0);
    for (int i = 0; i < n; ++i) {
        sum[group[i]] += c[i];
        if (group[i] != 0) {
            ans = sum[group[i]];
        }
    }
    for (int i = 1; i < ng; ++i) {
        ans = gcd(ans, sum[i]);
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;
    for (int qq = 0; qq < t; ++qq) {
        solve();
    }
    
    return 0;
}