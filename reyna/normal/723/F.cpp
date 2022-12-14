// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; ++i)
const int N = (int) 1e6 + 6, mod = (int) 0;
map<int, int> mat[N];
int s, t, ds, dt, cmp = 1, comp[N], mark[N], cs[N], ct[N];
vector<int> res, ver[N], adj[N];
void dfs(int v, int c) {
    if (comp[v]) return;
    comp[v] = c;
    ver[c].push_back(v);
    for (int u : adj[v]) {
        if (u == s) 
            cs[c] = 1;
        else if (u == t) 
            ct[c] = 1;
        else {
            if (!comp[u])
                res.push_back(mat[v][u]);
            dfs(u, c);
        }
    }
}
int ff[N], ss[N];
void add_edge(int u, int v) {
    res.push_back(mat[u][v]);
}
void add_comp_edge(int x, int c) {
    for (int v : ver[c])
        if (mat[x][v]) {
            add_edge(x, v);
            return;
        }
}
void outp() {
    for (int x : res)
        cout << ff[x - 1] + 1 << ' ' << ss[x - 1] + 1 << '\n';
}
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int e = 0; e < m; ++e) {
        int &u = ff[e], &v = ss[e];
        cin >> u >> v; --u, --v;
        if (u > v) swap(u, v);
        mat[u][v] = e + 1;
        mat[v][u] = e + 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> s >> t >> ds >> dt; --s, --t;
    if (s > t) swap(s, t), swap(ds, dt);
    for (int v = 0; v < n; ++v) {
        if (v != s && v != t && !comp[v]) {
            dfs(v, cmp++);
        }
    }
    vector<int> both, js, jt;
    for (int i = 1; i < cmp; ++i) {
        if (cs[i] && ct[i]) {
            both.push_back(i);
        } else if (cs[i]) {
            js.push_back(i);
        } else if (ct[i]) {
            jt.push_back(i);
        }
    }
    if ((int) both.size() && js.size() + 1 <= ds && jt.size() + 1 <= dt && js.size() + jt.size() + both.size() + 1 <= ds + dt) {
        cout << "Yes" << endl;
        for (int x : js) add_comp_edge(s, x), ds--;
        for (int x : jt) add_comp_edge(t, x), dt--;
        add_comp_edge(s, both[0]), ds--;
        add_comp_edge(t, both[0]), dt--;
        int p = 1;
        while (ds > 0 && p < (int) both.size()) {
            add_comp_edge(s, both[p]), ds--;
            p++;
        }
        while (p < (int) both.size()) {
            add_comp_edge(t, both[p]), dt--;
            p++;
        }
        outp();
        return 0;
    }
    if ((int) both.size() + js.size() + jt.size() <= ds + dt - 2 && js.size() + 1 <= ds && jt.size() + 1 <= dt && mat[s][t]) {
        cout << "Yes" << endl;
        add_edge(s, t); ds--, dt--;
        for (int x : js) add_comp_edge(s, x), ds--;
        for (int x : jt) add_comp_edge(t, x), dt--;
        int p = 0;
        while (ds > 0 && p < (int) both.size()) {
            add_comp_edge(s, both[p]), ds--;
            p++;
        }
        while (p < (int) both.size()) {
            add_comp_edge(t, both[p]), dt--;
            p++;
        }
        outp();
        return 0;
    }
    cout << "No" << endl;
    return 0;
}