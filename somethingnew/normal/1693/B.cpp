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
int cnt = 0;
vector<vector<int>> g;
vector<pair<int, int>> segs;
int dfsslv(int v, int p) {
    int val = 0;
    for (auto i : g[v]) {
        if (i != p)
            val += dfsslv(i, v);
    }
    if (val < segs[v].first) {
        val = segs[v].second;
        cnt++;
    }
    val = min(val, segs[v].second);
    return val;
}
void solve() {
    int n;
    cin >> n;
    cnt = 0;
    g.assign(n, {});
    vector<int> p(n);
    for (int i = 1; i < n; ++i) {
        cin >> p[i];
        p[i]--;
        g[p[i]].push_back(i);
    }
    segs.assign(n, {});
    for (int i = 0; i < n; ++i) {
        cin >> segs[i].first >> segs[i].second;
    }
    dfsslv(0, -1);
    cout << cnt << '\n';
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