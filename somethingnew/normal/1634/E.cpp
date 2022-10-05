#include <iostream>
#include "cmath"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "map"
#include "queue"
#include "array"
#include "numeric"
#include "iomanip"

using namespace std;
#define all(x) x.begin(), x.end()
#define int long long
vector<string> ans;
map<array<int, 3>, int> cnt;
bool isex(int a, int b, int j) {
    if (a > b) {
        swap(a, b);
    }
    return cnt[{a, b, j}];
}
void eras(int a, int b, int j, int t) {
    if (a > b) {
        swap(a, b);
    }
    ans[a][j] = 'L';
    if (t == 1)
        ans[a][j] = 'R';
    cnt[{a, b, j}]--;
}
vector<vector<pair<int, int>>> g;
map<int, int> mpnums;
int t = 1;
bool dfs(int v, int start = -1, int q = 0) {
    if (v == start)
        return 1;
    while (!g[v].empty() and !isex(v, g[v].back().first, g[v].back().second))
        g[v].pop_back();
    if (g[v].empty())
        return 0;
    eras(v, g[v].back().first, g[v].back().second, q);
    if (start == -1)
        dfs(g[v].back().first, v, 1 - q);
    else
        dfs(g[v].back().first, start, 1 - q);
    return 1;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    cin >> m;
    ans.assign(m, {});
    vector<map<int, int>> elems(m);
    g.assign(m, {});
    for (int i = 0; i < m; ++i) {
        int n;
        cin >> n;
        ans[i].assign(n, '?');
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            if (mpnums[x] == 0) {
                mpnums[x] = t++;
                g.push_back({});
            }
            int v = mpnums[x] - 1 + m;
            cnt[{i, v, j}]++;
            g[v].push_back({i, j});
            g[i].push_back({v, j});
        }
    }
    for (int i = 0; i < g.size(); ++i) {
        if (g[i].size() % 2 == 1) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < m; ++i) {
        while (dfs(i));
    }
    for (int i = 0; i < m; ++i) {
        cout << ans[i] << '\n';
    }
}