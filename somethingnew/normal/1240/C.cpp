#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define all(x) (x).begin(), (x).end()
#define int long long
using namespace std;
vector<vector<pair<int, int>>> g;
vector<pair<int, int>> dp;
int k;
void dfs(int v, int p) {
    dp[v] = {0, 0};
    int res = 0;
    vector<int> vals;
    for (auto [i, w] : g[v]) {
        if (i == p)
            continue;
        dfs(i, v);
        if (dp[i].first - dp[i].second + w > 0)
            vals.push_back(dp[i].first - dp[i].second + w);
        res += dp[i].second;
    }
    sort(all(vals));
    reverse(all(vals));
    for (int j = 0; j < min((int)vals.size(), k - 1); ++j) {
        res += vals[j];
    }
    dp[v].first = res;
    if (vals.size() >= k)
        res += vals[k - 1];
    dp[v].second = res;
}
void solve(){
    int n;
    cin >> n >> k;
    g.assign(n, {});
    dp.assign(n, {});
    for (int i = 0; i < n - 1; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        a--;b--;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }
    dfs(0, -1);
    cout << dp[0].second << '\n';
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}