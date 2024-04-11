#include <iostream>
#include "vector"
#include "algorithm"
#include "numeric"
#include "climits"
#include "iomanip"
#include "bitset"
#include "set"
#include "array"
#include "map"
#include "queue"
#define all(x) x.begin(), x.end()
using namespace std;

vector<int> ex;
vector<int> dep;
vector<int> good;
vector<vector<int>> g;
void bfs(queue<pair<int, int>> &tobf) {
    dep.assign(g.size(), -1);
    while (!tobf.empty()) {
        auto [v, pr] = tobf.front();
        tobf.pop();
        if (dep[v] != -1)
            continue;
        dep[v] = pr;
        for (auto i : g[v])
            tobf.push({i, pr + 1});
    }
    good.assign(g.size(), 0);
    for (int i = 0; i < g.size(); ++i) {
        for (auto j : g[i]) {
            if (dep[i] == dep[j])
                good[i] = 1;
        }
    }
}
vector<int> sz;
vector<int> ans;
void dfscalc(int v, int p, int maxprefen, int energ, vector<int> &res) {
    maxprefen = max(maxprefen, energ);
    if (good[v])
        res[maxprefen] = min(res[maxprefen], dep[v]);
    for (auto i : g[v]) {
        if (ex[i] == 0)
            continue;
        if (i == p)
            continue;
        if (dep[i] > dep[v])
            continue;
        if (dep[i] == dep[v])
            dfscalc(i, v, maxprefen, energ + 1, res);
        if (dep[i] < dep[v])
            dfscalc(i, v, maxprefen, energ - 1, res);
    }
}
void dfsfndans(int v, int p, vector<int> &res, int maxprefenerg = 0, int energ = 0) {
    maxprefenerg = max(maxprefenerg, energ);
    if (maxprefenerg <= energ) {
        ans[v] = min(ans[v], res[energ]);
    }
    for (auto i : g[v]) {
        if (ex[i] == 0)
            continue;
        if (i == p)
            continue;
        if (dep[i] < dep[v])
            continue;
        if (dep[i] == dep[v])
            dfsfndans(i, v, res, maxprefenerg, energ - 1);
        else
            dfsfndans(i, v, res, maxprefenerg, energ + 1);
    }
}
int fndsz(int v, int p = -1) {
    sz[v] = 1;
    for (auto i : g[v]) {
        if (i == p)
            continue;
        if (ex[i] == 0)
            continue;
        sz[v] += fndsz(i, v);
    }
    return sz[v];
}
int fndcntr(int v, int p, int allsz) {
    for (auto i : g[v]) {
        if (ex[i] == 0)
            continue;
        if (i == p)
            continue;
        if (sz[i] * 2 >= allsz)
            return fndcntr(i, v, allsz);
    }
    return v;
}
void calcvv(int v) {
    v = fndcntr(v, -1, fndsz(v));
    int t = sz[v];
    vector<int> res(t + 1, 1e6);
    dfscalc(v, -1, 0, 0, res);
    for (int i = 1; i < res.size(); ++i) {
        res[i] = min(res[i], res[i - 1]);
    }
    dfsfndans(v, -1, res);
    ex[v] = 0;
    for (auto i : g[v])
        if (ex[i]) calcvv(i);
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    ex.assign(n, 1);
    sz.assign(n, 0);
    g.assign(n, {});
    ans.assign(n, 1e6);
    queue<pair<int, int>> tobf;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x == 1)
            tobf.push({i, 0});
    }
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    bfs(tobf);
    //for (int i = 0; i < n; ++i) {
    calcvv(0);
    //}
    for (int i = 0; i < n; ++i) {
        int p = dep[i];
        int ad = max(0, p - ans[i]);
        cout << p + ad << ' ';
    }
}