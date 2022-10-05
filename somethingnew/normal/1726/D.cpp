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
struct dsu {
    vector<int> p;
    dsu(int n) {
        p.assign(n, {});
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
    }
    int getv(int v) {
        if (p[v] == v)
            return v;
        return p[v] = getv(p[v]);
    }
    bool merge(int a, int b) {
        a = getv(a);
        b = getv(b);
        if (a == b)
            return 0;
        p[a] = b;
        return 1;
    }
};
void solve() {
    int n, m;
    cin >> n >> m;
    vector<bool> ans(m);
    vector<int> nonadded;
    vector<pair<int, int>> vv(m);
    dsu usd(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        x--;y--;
        vv[i] = {x, y};
        if (usd.merge(x, y)) {
            ans[i] = 1;
        } else {
            nonadded.push_back(i);
        }
    }
    set<int> beb;
    for (auto i : nonadded) {
        beb.insert(vv[i].first);
        beb.insert(vv[i].second);
    }
    if (beb.size() == 3 and nonadded.size() == 3) {
        int v = nonadded[0];
        dsu usd2(n);
        usd2.merge(vv[v].first, vv[v].second);
        ans[v] = 1;
        for (int i = 0; i < m; ++i) {
            if (v == i)
                continue;
            if (usd2.merge(vv[i].first, vv[i].second)) {
                ans[i] = 1;
            } else {
                ans[i] = 0;
            }
        }
    }
    for (auto i : ans)
        cout << i;
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