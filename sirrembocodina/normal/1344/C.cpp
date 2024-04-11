
#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define sqr(x) (x) * (x)

using namespace std;

const int mod = 998244353;

vector<vector<int>> g, rg;
vector<bool> used;
vector<int> ts;

void dfs(int v) {
    used[v] = true;
    for (int to: g[v]) {
        if (!used[to]) {
            dfs(to);
        }
    }
    ts.push_back(v);
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    g.resize(n);
    rg.resize(n);
    used.resize(n);
    forn (i, m) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
        rg[y].push_back(x);
    }
    forn (i, n) {
        if (!used[i]) {
            dfs(i);
        }
    }
    string ans = "";
    forn (i, n) {
        ans.push_back('_');
    }
    vector<int> w(n);
    forn (i, n) {
        w[ts[i]] = i;
    }
    vector<int> dp1(n), dp2(n);
    forn (i, n) {
        int v = ts[i];
        dp1[i] = v;
        for (int to: g[v]) {
            int j = w[to];
            if (j > i) {
                cout << -1 << endl;
                return 0;
            }
            dp1[i] = min(dp1[i], dp1[j]);
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        int v = ts[i];
        dp2[i] = v;
        for (int to: rg[v]) {
            int j = w[to];
            dp2[i] = min(dp2[i], dp2[j]);
        }
    }
    int cnt = 0;
    forn (i, n) {
        int v = ts[i];
        if (dp1[i] < v || dp2[i] < v) {
            ans[v] = 'E';
        } else {
            ans[v] = 'A';
            ++cnt;
        }
    }
    cout << cnt << endl;
    cout << ans << endl;
}