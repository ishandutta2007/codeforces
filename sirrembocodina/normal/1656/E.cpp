#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

struct my_hash {
    inline size_t operator()(const pair<int, int>& a) const {
        return a.first * 31 + a.second;
    }
};

vector<vector<int>> g;
vector<int> ans;

void dfs(int v, int p, int cur = 0) {
    int sons = 0;
    int nxt_cur = cur ? -cur : -1;
    for (int to: g[v]) {
        if (to == p) {
            continue;
        }
        dfs(to, v, nxt_cur);
        sons++;
    }
    ans[v] = cur - nxt_cur * sons;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        g.clear();
        g.resize(n);
        ans.clear();
        ans.resize(n);
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        dfs(0, -1);
        for (int i = 0; i < n; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}