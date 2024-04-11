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
vector<vector<int>> g, gobr;
vector<int> cnt;
void djkstr(int n) {
    int v = n-1;
    vector<int> dp(n, -1);
    set<pair<int, int>> que;
    que.insert({0, v});
    while (!que.empty()) {
        auto [val, u] = *que.begin();
        que.erase(que.begin());
        if (dp[u] != -1)
            continue;
        dp[u] = val;
        for (auto i : gobr[u]) {
            que.insert({cnt[i] + val, i});
            cnt[i]--;
        }
    }
    cout << dp[0] << '\n';
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    g.assign(n, {});
    gobr.assign(n, {});
    cnt.assign(n, {});
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        gobr[b].push_back(a);
    }
    for (int i = 0; i < n; ++i) {
        cnt[i] = g[i].size();
    }
    djkstr(n);
}