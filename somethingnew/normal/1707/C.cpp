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
    int mrg(int a, int b) {
        a = getv(a);
        b = getv(b);
        if (a == b)return 0;
        p[a] = b;
        return 1;
    }
};
vector<vector<int>> g;
vector<vector<int>> binup;
vector<int> dep;
void dfs(int v, int p, int de = 0) {
    dep[v] = de++;
    binup[v][0] = p;
    for (auto i : g[v]) {
        if (i == p) continue;
        dfs(i, v, de);
    }
}
vector<int> dp;
vector<int> res;
void lca(int a, int b) {
    if (dep[a] > dep[b])
        swap(a, b);
    int sta = a, stb = b;
    //cerr << dep[b] << ' ' << dep[a] << endl;
    for (int i = 19; i >= 0; --i) {
        if (dep[binup[b][i]] >= dep[a])
            b = binup[b][i];
    }
    //cerr << dep[b] << ' ' << dep[a] << endl;
    if (a == b) {
        b = stb;
        for (int i = 19; i >= 0; --i) {
            if (dep[binup[b][i]] > dep[a])
                b = binup[b][i];
        }
        dp[b]--;
        dp[stb]++;
        //cerr << b << ' ' << stb << endl;
        return;
    }
    for (int i = 19; i >= 0; --i) {
        if (binup[b][i] != binup[a][i]) {
            b = binup[b][i];
            a = binup[a][i];
        }
    }
    dp[0]--;
    dp[sta]++;
    dp[stb]++;
    //cerr << b << ' ' << a << endl;
    return;
}
void dfs2(int v, int p) {
    //cout << v << ' ' << dp[v] << endl;
    for (auto i : g[v]) {
        if (i == p) continue;
        dp[i] += dp[v];
        dfs2(i, v);
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    g.assign(n, {});
    dep.assign(n, {});
    binup.assign(n, vector<int>(20, 0));
    vector<pair<int, int>> zp;
    dsu ds(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        if (ds.mrg(a, b)) {
            g[a].push_back(b);
            g[b].push_back(a);
            //cerr << a << ' ' << b << endl;
        } else {
            zp.push_back({a, b});
        }
    }
    dfs(0, 0);
    for (int k = 1; k < 20; ++k) {
        for (int i = 0; i < n; ++i) {
            binup[i][k] = binup[binup[i][k-1]][k-1];
        }
    }
    dp.assign(n, {});
    res.assign(n, {});
    for (auto [a, b] : zp) {
        lca(a, b);
    }
    dfs2(0, 0);
    for (auto i : dp) {
        if (i > 0) exit(1);
        cout << (i == 0);
    }
    cout << '\n';
}