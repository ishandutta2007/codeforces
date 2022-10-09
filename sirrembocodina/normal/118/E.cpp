#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

vector<vector<int>> g;
vector<bool> used;
vector<int> up;
vector<int> in;
int cnt = 0;
vector<pair<int, int>> ans;

void dfs(int v, int p) {
    used[v] = true;
    in[v] = cnt++;
    up[v] = in[v];
    for (int to: g[v]) {
        if (to == p) {
            continue;
        }
        if (used[to]) {
            if (in[to] < in[v]) {
                up[v] = min(up[v], in[to]);
                ans.push_back({v, to});
            }
            continue;
        }
        ans.push_back({v, to});
        dfs(to, v);
        if (up[to] == in[to]) {
            cout << 0 << endl;
            exit(0);
        }
        up[v] = min(up[v], up[to]);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    g.resize(n);
    forn (i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    used.resize(n);
    up.resize(n);
    in.resize(n);
    dfs(0, -1);
    forn (i, ans.size()) {
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
    }
}