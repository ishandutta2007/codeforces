#include <iostream>
#include "vector"
#include "algorithm"
#include "numeric"
#include "climits"
#include "iomanip"
#include "bitset"
#include "cmath"
#include "map"
#include "deque"
#include "array"
#include "set"
#define all(x) x.begin(), x.end()
using namespace std;
vector<vector<int>> g;
int blk;
vector<int> seen;
bool dfs(int v) {
    if (seen[v] == 2)
        return 0;
    if (seen[v] == 1)
        return 1;
    seen[v] = 1;
    bool ok = 0;
    for (auto i : g[v])
        ok = max(ok, dfs(i));
    seen[v] = 2;
    return ok;
}
void solve() {
    int n;
    cin >> n;g.assign(n, {});
    blk = 0;
    seen.assign(n, {});
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        b[i]--;
        g[a[i]].push_back(b[i]);
    }
    for (int i = 0; i < n; ++i) {
        if (g[blk].size() < g[i].size())
            blk = i;
    }
    bool cyc = 0;
    seen[blk] = 2;
    for (int i = 0; i < n; ++i) {
        if (dfs(i)) {
            cyc = 1;
            break;
        }
    }
    if (cyc) {
        cout << "WA\n";
    } else {
        cout << "AC\n";
    }
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