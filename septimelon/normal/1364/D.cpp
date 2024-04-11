#include <bits/stdc++.h>

using namespace std;

int n, m, k;
vector<vector<int>> r;

vector<int> pathb;
vector<int> path;
vector<bool> vis;
vector<int> viss;

void godfs(int v) {
    if (vis[v]) {
        return;
    }
    pathb.push_back(v);
    vis[v] = true;
    for (int i = 0; i < r[v].size(); ++i) {
        godfs(r[v][i]);
    }
}

bool findfs(int v, int from) {
    path.push_back(v);
    if (viss[v] == 1) {
        return true;
    } else if (viss[v] == -1) {
        path.pop_back();
        return false;
    }
    viss[v] = 1;
    for (int i = 0; i < r[v].size(); ++i) {
        if (r[v][i] == from) {
            continue;
        }
        if (i + 1 < r[v].size() && r[v][i + 1] != from && viss[r[v][i + 1]] == 1) {
            continue;
        }
        if (i + 2 < r[v].size() && r[v][i + 2] != from && viss[r[v][i + 2]] == 1) {
            ++i;
            continue;
        }
        if (findfs(r[v][i], v)) {
            return true;
        }
    }
    viss[v] = -1;
    path.pop_back();
    return false;
}

void tredfs(int v, int col) {
    if (vis[v]) {
        return;
    }
    vis[v] = true;
    viss[v] = col;
    for (int i = 0; i < r[v].size(); ++i) {
        tredfs(r[v][i], 1 - col);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m >> k;
    r.assign(n, vector<int>());
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        r[u].push_back(v);
        r[v].push_back(u);
    }
    
    vis.assign(n, false);
    godfs(0);
    vector<int> revpath(n);
    for (int i = 0; i < n; ++i) {
        revpath[pathb[i]] = i;
    }
    vector<vector<int>> r2(n, vector<int>());
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < r[i].size(); ++j) {
            r[i][j] = revpath[r[i][j]];
        }
        sort(r[i].begin(), r[i].end());
    }
    r2 = r;
    r.clear();
    for (int i = 0; i < n; ++i) {
        r.push_back(r2[pathb[i]]);
    }
    path.clear();
    
    viss.assign(n, 0);
    int begi = 0;
    int vsum = 0;
    if (findfs(0, -1)) {
        while (path[begi] <= path.back()) {
            ++begi;
        }
        /*for (int i = 0; i < path.size(); ++i) {
            cout << pathb[path[i]] + 1 << " ";
        } cout << endl;*/
        if (path.size() - begi <= k) {
            cout << "2\n";
            cout << path.size() - begi << "\n";
            for (int i = begi; i < path.size(); ++i) {
                cout << pathb[path[i]] + 1 << " ";
            }
        } else {
            cout << "1\n";
            for (int i = 0; i < (k + 1) / 2; ++i) {
                cout << pathb[path[begi + i * 2]] + 1 << " ";
            }
        }
        return 0;
    }
    
    vis.assign(n, false);
    viss.assign(n, 0);
    tredfs(0, 0);
    for (int i = 0; i < n; ++i) {
        vsum += viss[i];
    }
    path.clear();
    if (vsum >= (k + 1) / 2) {
        for (int i = 0; i < n; ++i) {
            if (viss[i] == 1) {
                path.push_back(i);
            }
        }
    } else {
        for (int i = 0; i < n; ++i) {
            if (viss[i] == 0) {
                path.push_back(i);
            }
        }
    }
    cout << "1\n";
    for (int i = 0; i < (k + 1) / 2; ++i) {
        cout << pathb[path[i]] + 1 << " ";
    }
    
    return 0;
}