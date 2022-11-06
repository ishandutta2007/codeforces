#include<bits/stdc++.h>
using namespace std;

vector <vector <pair<int, int>>> g;
vector <int> col;
bool ok;
vector <int> black, white;

void add_edge (int x, int y, int z) {
    g[x].emplace_back(y, z);
    g[y].emplace_back(x, z);
}

void dfs (int v) {
    if (col[v]) black.push_back(v); else white.push_back(v);
    for (auto edge : g[v]) {
        int u = edge.first;
        int x = edge.second;
        if (col[u] == -1) {
            col[u] = col[v] ^ x;
            dfs(u);
        } else {
            if ((col[v] ^ col[u]) != x) {
                ok = 0;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <vector <int>> a(2, vector<int>(n));
        vector <vector <pair <int, int>>> ind(n);
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> a[i][j];
                a[i][j]--;
                ind[a[i][j]].emplace_back(i, j);
            }
        }
        g.assign(n, {});
        col.assign(n, -1);
        ok = 1;
        for (int i = 0; i < n; ++i) {
            if (ind[i].size() != 2) {
                ok = 0;
                break;
            }
            if (ind[i][0].first == ind[i][1].first) add_edge(ind[i][0].second, ind[i][1].second, 1); else add_edge(ind[i][0].second, ind[i][1].second, 0);
        }
        vector <int> ans;
        for (int i = 0; i < n; ++i) {
            if (col[i] == -1) {
                col[i] = 0;
                black = white = {};
                dfs(i);
                if (white.size() < black.size()) swap(black, white);
                for (auto v : black) {
                    ans.push_back(v);
                }
            }
        }
        if (ok) {
            cout << ans.size() << endl;
            for (auto v : ans) cout << v + 1 << " ";
            cout << endl;
        } else cout << -1 << endl;
    }
    return 0;
}