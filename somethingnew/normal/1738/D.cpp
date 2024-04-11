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
#define int long long 

vector<vector<int>> g;
vector<int> res;
void dfs(int v) {
    if (g[v].size() == 0)
        return;
    int mxsz = g[v][0];
    for (auto i : g[v]) {
        if (g[mxsz].size() < g[i].size())
            mxsz = i;
    }
    for (auto i : g[v]) {
        if (mxsz != i)
            res.push_back(i);
    }
    res.push_back(mxsz);
    dfs(mxsz);
}
void solve() {
    int n;
    int k;
    res.clear();
    cin >> n;
    k = n;
    g.assign(n + 1, {});
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (k == n and x <= i)
            k = i;
        if (x == n + 1) {
            g[0].push_back(i + 1);
        } else {
            g[x].push_back(i + 1);
        }
    }
    cout << k << '\n';
    dfs(0);
    for (auto i : res)
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