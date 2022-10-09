#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

vector<int> gr;
vector<vector<int>> gr_list;
vector<vector<int>> gr_g;
vector<int> col;
vector<int> comp;
vector<bool> used;
vector<bool> bad;
vector<vector<int>> g;

void find_comps(int v, int cur_col, int cur_comp) {
    col[v] = cur_col;
    comp[v] = cur_comp;
    for (int to: gr_g[v]) {
        if (col[to] == -1) {
            find_comps(to, 1 - cur_col, cur_comp);
        } else if (col[to] == cur_col) {
            bad[gr[v]] = true;
        }
    }
}

bool BAD = false;

void dfs(int v, int cur_col) {
    col[v] = cur_col;
    g[v].push_back(v ^ 1);
    for (int to: g[v]) {
        if (col[to] == -1) {
            dfs(to, 1 - cur_col);
        } else if (col[to] == cur_col) {
            BAD = true;
        }
    }
    g[v].pop_back();
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n, m, k;
    cin >> n >> m >> k;
    gr.resize(n);
    gr_list.resize(k);
    bad.resize(k);
    col.resize(n, -1);
    comp.resize(n, -1);
    gr_g.resize(n);
    forn (i, n) {
        cin >> gr[i];
        gr[i]--;
        gr_list[gr[i]].push_back(i);
    }
    map<pair<int, int>, vector<pair<int, int>>> e_map;
    forn (i, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (gr[a] == gr[b]) {
            gr_g[a].push_back(b);
            gr_g[b].push_back(a);
        } else {
            if (gr[a] > gr[b]) {
                swap(a, b);
            }
            e_map[{gr[a], gr[b]}].push_back({a, b});
        }
    }
    used.assign(n, false);
    int goods = 0;
    int cur_comp = 0;
    forn (i, k) {
        for (int v: gr_list[i]) {
            if (col[v] == -1) {
                find_comps(v, 0, cur_comp);
                cur_comp += 2;
            }
        }
        for (int v: gr_list[i]) {
            comp[v] += col[v];
        }
        goods += !bad[i];
    }
    g.resize(cur_comp);
    col.assign(cur_comp, -1);
    int ans = goods * (goods - 1) / 2;
    for (auto& e_pair: e_map) {
        auto& e = e_pair.second;
        int gr_a = e_pair.first.first;
        int gr_b = e_pair.first.second;
        if (bad[gr_a] || bad[gr_b]) {
            continue;
        }
        for (auto& ab: e) {
            int a = comp[ab.first];
            int b = comp[ab.second];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        BAD = false;
        for (auto& ab: e) {
            int a = comp[ab.first];
            int b = comp[ab.second];
            if (col[a] == -1) {
                dfs(a, 0);
            }
        }
        for (auto& ab: e) {
            int a = comp[ab.first];
            int b = comp[ab.second];
            col[a] = col[b] = -1;
            g[a].clear();
            g[b].clear();
            a ^= 1;
            b ^= 1;
            col[a] = col[b] = -1;
            g[a].clear();
            g[b].clear();
        }
        //cerr << gr_a + 1 << " " << gr_b + 1 << " " << BAD << endl;
        ans -= BAD;
    }
    cout << ans << endl;
}