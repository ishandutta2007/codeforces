#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> g;
vector<vector<int>> rg;
vector<vector<int>> a;
vector<int> topsort;
vector<int> color;
vector<int> used;
vector<int> cnt;

void dfs_topsort(int v) {
    used[v] = 1;
    for (int u : g[v]) {
        if (used[u] == 1) {
            continue;
        }
        dfs_topsort(u);
    }
    topsort.emplace_back(v);
}

void dfs(int v, int c) {
    color[v] = c;
    a[c].emplace_back(v);
    for (int u : rg[v]) {
        if (color[u] != -1) {
            continue;
        }
        dfs(u, c);
    }
}

int main() {
    cin >> n >> m;
    g.resize(n);
    rg.resize(n);
    used.resize(n);
    color.resize(n, -1);
    for (int i = 0; i < m; ++i) {
        int v, u;
        cin >> v >> u;
        g[v - 1].emplace_back(u - 1);
        rg[u - 1].emplace_back(v - 1);
    }
    for (int i = 0; i < n; ++i) {
        if (used[i] == 0) {
            dfs_topsort(i);
        }
    }
    reverse(topsort.begin(), topsort.end());
    int c = -1;
    for (int i : topsort) {
        if (color[i] == -1) {
            ++c;
            a.emplace_back();
            cnt.emplace_back();
            dfs(i, c);
        }
    }
    for (int v = 0; v < n; ++v) {
        for (int u : g[v]) {
            if (color[u] == color[v]) {
                continue;
            }
            ++cnt[color[u]];
        }
    }
    vector<int> need;
    for (int i = 0; i < cnt.size(); ++i) {
        if (cnt[i] == 0) {
            need.emplace_back(i);
        }
    }
    int result = a[need[0]].back();
    vector<vector<int>> b = a;
    while (need.size() > 1) {
        while (a[need.back()].size()) {
            cout << "? " << result + 1 << " " << a[need.back()].back() + 1 << endl;
            int ans;
            cin >> ans;
            if (ans == 0) {
                result = a[need.back()].back();
                swap(need[0], need.back());
                a[need.back()].pop_back();
            }
            if (ans == 1) {
                a[need.back()].pop_back();
            }
        }
        int kek = need.back();
        need.pop_back();
        for (int v : b[kek]) {
            for (int u : g[v]) {
                if (color[u] == color[v]) {
                    continue;
                }
                --cnt[color[u]];
                if (cnt[color[u]] == 0) {
                    need.emplace_back(color[u]);
                }
            }
        }
    }
    cout << "! " << result + 1 << endl;
    return 0;
}