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

using namespace std;
#define int long long
vector<vector<int>> g;
vector<pair<int, int>> dp;
vector<pair<int, int>> val;
void dfs(int v, int p) {
    for (auto i : g[v]) {
        if (i == p)
            continue;
        dfs(i, v);
        dp[v].first += max(dp[i].first + abs(val[i].first - val[v].first), dp[i].second + abs(val[i].second - val[v].first));
        dp[v].second += max(dp[i].first + abs(val[i].first - val[v].second), dp[i].second + abs(val[i].second - val[v].second));
    }
}
void solve(){
    int n;
    cin >> n;
    val.assign(n, {});
    g.assign(n, {});
    dp.assign(n, {});
    for (auto &i : val)
        cin >> i.first >> i.second;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0, -1);
    cout << max(dp[0].first, dp[0].second) << '\n';
    g.clear();
    dp.clear();
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}