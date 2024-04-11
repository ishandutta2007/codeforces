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

struct gr{
    vector<vector<int>> g;
    vector<int> cmp;
    int n;
    void ini1(int N) {
        n = N;
        cmp.assign(n, {});
        g.assign(n, {});
    }
    void add(int a, int b) {
        g[a].push_back(b);g[b].push_back(a);
    }
    void dfs(int v,  int c) {
        if (cmp[v] != 0) return;
        cmp[v] = c;
        for (auto i : g[v])
            dfs(i, c);
    }
    void count() {
        int c = 1;
        for (int i = 0; i < n; ++i) {
            if (cmp[i] == 0) {
                dfs(i, c);
                c++;
            }
        }
        g.clear();
    }
    bool ans(int a, int b) {
        return cmp[a] == cmp[b];
    }
};

struct gr2{
    vector<vector<int>> g;
    vector<int> cmp, good;
    vector<int> goodcmp;
    int n;
    void ini1(int N) {
        n = N;
        cmp.assign(n, {});
        g.assign(n, {});
        good.assign(n, 0);
    }
    void add(int a, int b) {
        g[a].push_back(b);g[b].push_back(a);
    }
    void add2(int a, int b) {
        good[a] = 1;
        good[b] = 1;
    }
    void dfs(int v,  int c) {
        if (cmp[v] != 0) return;
        cmp[v] = c;
        for (auto i : g[v])
            dfs(i, c);
    }
    void count() {
        int c = 1;
        for (int i = 0; i < n; ++i) {
            if (cmp[i] == 0) {
                dfs(i, c);
                c++;
            }
        }
        g.clear();
        goodcmp.assign(c, 0);
        for (int i = 0; i < n; ++i) {
            if (good[i])
                goodcmp[cmp[i]] = 1;
        }
    }
    bool ans(int a, int b) {
        return goodcmp[cmp[a]];
    }
};
void solve() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> ed(m);
    vector<gr> bt(30);
    vector<gr2> bt1(30);
    for (int i = 0; i < 30; ++i) {
        bt[i].ini1(n);
        bt1[i].ini1(n);
    }
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;b--;
        ed[i] ={a, b, c};
        
    }
    int q;
    for (int j = 0; j < 30; ++j) {
        for (auto [a, b, c] : ed) {
    if ((1 << j) & c)
                bt[j].add(a, b);
            if (((1 << j) & c) and (1 & c))
                bt1[j].add(a, b);
            if ((1 & c) == 0)
                bt1[j].add2(a, b);     
}
        bt[j].count();
        bt1[j].count();
    }
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        int ok = 2;
        for (int j = 1; j < 30; ++j) {
            if (bt1[j].ans(a, b))
                ok = 1;
        }
        for (int j = 0; j < 30; ++j) {
            if (bt[j].ans(a, b))
                ok = 0;
        }
        cout << ok << '\n';
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
}