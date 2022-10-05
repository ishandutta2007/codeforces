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
int mod = 998244353;
vector<int> seen;
vector<vector<int>> g;
vector<int> dp;

void dfs(int v) {
    if (seen[v] == 1)
        return;
    seen[v] = 1;
    for (auto i : g[v]) {
        if (seen[i] == 0)
            dfs(i);
        dp[v] += dp[i];
        if (dp[v] >= mod)
            dp[v] -= mod;
    }
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> table(n);
    for (int i = 0; i < n; ++i) {
        cin >> table[i];
    }
    g.assign(n, {});
    seen.assign(n, {});
    dp.assign(n, {});
    vector<int> tab2 = table;
    for (int i = 0; i < n; ++i) {
        tab2[i] = min(tab2[i], 10 * n);
    }
    int f = 0;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
    }
    for (int i = 0; i < n; ++i) {
        if (g[i].size() == 0)
            f = i;
    }
    int zero = 0;
    int nz = 0;
    for (int i = 0; i < n; ++i) {
        if (tab2[i] != 0)
            nz = 1;
    }
    if (nz == 0) {
        cout << "0\n";
        return;
    }
    for (int i = 0; i < 3 * n; ++i) {
        zero += (tab2[f] == 0);
        vector<int> tab22 = tab2;
        for (int j = 0; j < n; ++j) {
            if (tab2[j]) {
                tab22[j]--;
                for (auto k : g[j]) {
                    tab22[k]++;
                }
            }
        }
        tab2 = tab22;
        int nz = 0;
        for (int j = 0; j < n; ++j) {
            tab2[j] = min(tab2[j], 10 * n);
            if (tab2[j] != 0)
                nz = 1;
        }
        if (nz == 0) {
            cout << i + 1 << '\n';
            return;
        }
    }
    dp[f] = 1;
    for (int i = 0; i < n; ++i) {
        dfs(i);
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        res += dp[i] * table[i] % mod;
    }
    cout << (res + zero) % mod << '\n';
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