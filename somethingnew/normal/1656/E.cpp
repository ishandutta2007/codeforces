#include <iostream>
#include "vector"
#include "algorithm"
#include "numeric"
#include "climits"
#include "iomanip"
#include "bitset"
#include "cmath"
#include "map"
#define all(x) x.begin(), x.end()
using namespace std;
#define int long long

vector<int> nums;
vector<vector<int>> g;
void dfs(int v, int p, int mult) {
    nums[v] = g[v].size() * mult;
    for (auto i : g[v]) {
        if (i == p)
            continue;
        dfs(i, v, -mult);
    }
}
void solve() {
    int n;
    cin >> n;
    g.assign(n, {});
    nums.assign(n, 0);
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0, -1, -1);
    for (auto i : nums)
        cout << i << ' ';
    cout << '\n';
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}