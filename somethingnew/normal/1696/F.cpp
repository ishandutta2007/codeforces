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
#include "queue"
#define all(x) x.begin(), x.end()
using namespace std;
vector<vector<int>> cmps;
struct dsu {
    vector<pair<int, int>> edg;
    vector<int> p;
    void init(int n) {
        p.assign(n, {});
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
    }
    int getv(int v) {
        if (p[v] != v)
            return p[v] = getv(p[v]);
        return v;
    }
    bool mrg(int a, int b) {
        int aa = a, bb = b;
        a = getv(a);
        b = getv(b);
        if (a != b) {
            edg.emplace_back(aa, bb);
            p[a] = b;
            return 1;
        }
        return 0;
    }
};
vector<pair<int, int>> slv(int a, int b) {
    int n = cmps.size();
    vector<pair<int, int>> stk;
    dsu ds;
    ds.init(n);
    ds.mrg(a, b);
    stk.push_back({a, b});
    stk.push_back({b, a});
    vector<int> seen(n, {});
    while (!stk.empty()) {
        auto [x, y] = stk.back();
        //cerr << "!" << x << ' ' << y << '\n';
        stk.pop_back();
        for (int i = 0; i < n; ++i) {
            if (i != y and cmps[x][y] == cmps[x][i]) {
                if (!ds.mrg(i, x)) {
                    //cerr << i << ' ' << x << endl;
                    return {};
                }
                stk.emplace_back(i, x);
            }
        }
    }
   // cerr << ds.edg.size() << endl;
    if (ds.edg.size() != n - 1)
        return {};
    return ds.edg;
}
vector<int> calcdst(vector<vector<int>> &g, int v) {
    vector<int> dst(g.size(), -1);
    queue<pair<int, int>> que;
    que.push({v, 0});
    while (!que.empty()) {
        auto [v, p] = que.front();
        que.pop();
        if (dst[v] != -1)
            continue;
        dst[v] = p;
        for (auto i : g[v])
            que.push({i, p + 1});
    }
    return dst;
}
void solve() {
    int n;
    cin >> n;
    vector<vector<string>> strs(n, vector<string>(n));
    cmps.assign(n, {});
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            string s;
            cin >> s;
            strs[j][i] = strs[i][j] = s;
        }
        strs[i][i] = string(n, '1');
    }
    for (int i = 0; i < n; ++i) {
        vector<int> seen(n);
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            if (seen[j])
                continue;
            for (int k = 0; k < n; ++k) {
                if (strs[k][j][i] == '1') {
                    if (seen[k] != 0) {
                        cout << "No\n";
                        return;
                    }
                    seen[k] = cnt + 1;
                }
            }
            cnt++;
        }
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if ((strs[j][k][i] == '1' and seen[j] != seen[k]) or (strs[j][k][i] != '1' and seen[j] == seen[k])) {
                    cout << "No\n";
                    return;
                }
            }
        }
        cmps[i] = seen;
    }
    /*for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << cmps[i][j] << ' ';
        }
        cout << '\n';
    }*/
    for (int t = 1; t < n; ++t) {
        vector<pair<int, int>> edg = slv(0, t);
        if (edg.empty())
            continue;
        bool ok = 1;
        //cerr << "BEBa\n";
        vector<vector<int>> g(n);
        for (auto [a, b] : edg) {
            g[a].push_back(b);
            g[b].push_back(a);
            //cerr << a << ' ' << b << '\n';
        }
        vector<vector<int>> dst(n);
        for (int i = 0; i < n; ++i) {
            dst[i] = calcdst(g, i);
            vector<vector<int>> nums(n);
            for (int j = 0; j < n; ++j) {
                nums[dst[i][j]].push_back(j);
            }
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (!nums[j].empty())
                    cnt++;
                for (int k = 1; k < nums[j].size(); ++k) {
                    if (cmps[i][nums[j][k]] != cmps[i][nums[j][0]]) {
                      //  cerr << i << ' ' << nums[j][k] << ' ' << nums[j][0] << ' ' << cmps[i][nums[j][k]] << ' ' << cmps[i][nums[j][0]] << '\n';
                      //  cerr << dst[i][nums[j][k]] << ' ' << dst[i][nums[j][0]] << '\n';
                        ok = 0;
                    }
                }
            }
            int mx = 0;
            for (int j = 0; j < n; ++j) {
                mx = max(mx, cmps[i][j]);
            }
            if (mx - cnt != 0)
                ok = 0;
        }
        if (ok) {
            cout << "Yes\n";
            for (auto i : edg)
                cout << i.first + 1 << ' ' << i.second + 1 << '\n';
            return;
        }
    }
    cout << "No\n";
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