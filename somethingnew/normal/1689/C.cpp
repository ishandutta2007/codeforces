//        
//   @roadfromroi 
//        
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
void dfs(int v, int p, int h, vector<vector<int>> &g, vector<int> &hh) {
    hh[v] = h;
    for (auto i : g[v]) {
        if (i == p)
            continue;
        dfs(i, v, h + 1, g, hh);
    }
}
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector<int> h(n);
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;--a;--b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0, 0, 1, g, h);
    int res = n;
    if (g[0].size() == 1) {
        cout << n - 2 << '\n';
        return;
    }
    for (int i = 1; i < n; ++i) {
        if (g[i].size() == 1)
            res = min(res, h[i] * 2 - 1);
        if (g[i].size() == 2) {
            res = min(res, h[i] * 2);
        }
    }
    cout << n - res << '\n';
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