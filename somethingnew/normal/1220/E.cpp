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
vector<int> price, seen, depth, good;
vector<pair<int, int>> dp;
vector<vector<int>> g;

void dfs(int v, int dep = 0) {
    if (seen[v])
        return;
    depth[v] = dep;
    seen[v] = 1;
    for (auto i : g[v]) {
        dfs(i, dep + 1);
    }
}
int dfsans(int v, int p = -1) {
    if (seen[v])
        return depth[v];
    seen[v] = 1;
    int res = depth[v];
    for (auto i : g[v]) {
        if (i == p)
            continue;
        res = min(res, dfsans(i, v));
    }
    if (res != depth[v]) {
        good[v] = 1;
        return 0;
    }
   // cout << v << ' ' << good[v] << endl;
    return res;
}
pair<int, int> realansdfs(int v) {
    if (seen[v])
        return {0, 0};
    seen[v] = 1;
    dp[v] = {price[v], 0};
    //cerr << v << ' ' << price[v] << endl;
    for (auto i : g[v]) {
        pair<int, int> b = realansdfs(i);
        dp[v].first += b.first;
        dp[v].second = max(dp[v].second, b.second);
    }
    //cout << v << ' ' << good[v] << ' ' << dp[v].first << ' ' << dp[v].second << endl;
    if (good[v])
        return dp[v];
    return {0, dp[v].first + dp[v].second};
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    price.assign(n, {});
    g.assign(n, {});
    seen.assign(n, 0);
    good.assign(n, 0);
    dp.assign(n, {0, 0});
    depth.assign(n, {});
    for (int i = 0; i < n; ++i) {
        cin >> price[i];
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int s;
    cin >> s;
    s--;
    dfs(s);
    seen.assign(n, 0);
    dfsans(s);
    seen.assign(n, 0);
    pair<int, int> an = realansdfs(s);
    cout << an.second;
}