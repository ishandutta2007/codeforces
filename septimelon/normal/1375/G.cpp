#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 1000000009;

int mex(const vector<int>& c) {
    for (int i = 0; i < c.size(); ++i) {
        if (c[i] == 0) {
            return i;
        }
    }
}

void dfs(int v, int col, const vector<vector<int>>& r, vector<bool>& vis, vector<int>& c) {
    if (vis[v]) {
        return;
    }
    vis[v] = true;
    ++c[col];
    for (int i = 0; i < r[v].size(); ++i) {
        dfs(r[v][i], 1 - col, r, vis, c);
    }
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> r(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        r[u].push_back(v);
        r[v].push_back(u);
    }
    
    vector<bool> vis(n, false);
    vector<int> c(2, 0);
    dfs(0, 0, r, vis, c);
    
    cout << min(c[0], c[1]) - 1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t = 1;
    //cin >> t;
    for (int qq = 0; qq < t; ++qq) {
       solve();
    }
   
    return 0;
}