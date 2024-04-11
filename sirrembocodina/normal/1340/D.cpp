
#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define sqr(x) (x) * (x)

using namespace std;

const int mod = 998244353;

vector<vector<int> > g;
vector<bool> used;
int mx = 0;
vector<pair<int, int> > ans;

void dfs(int v, int cur) {
    int in_cur = cur;
    ans.push_back({v, cur});
    used[v] = true;
    vector<int> sons;
    for (int to: g[v]) {
        if (!used[to]) {
            sons.push_back(to);
        }
    }
    forn (i, sons.size()) {
        int to = sons[i];
        if (cur == mx) {
            cur = in_cur - 1 - sons.size() + i;
            ans.push_back({v, cur});
        }
        dfs(to, cur + 1);
        cur++;
        ans.push_back({v, cur});
    }
    if (cur != in_cur - 1 && v != 0) {
        ans.push_back({v, in_cur - 1});
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    g.resize(n);
    forn (i, n - 1) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    forn (i, n) {
        mx = max(mx, (int)(g[i].size()));
    }
    used.resize(n);
    dfs(0, 0);
    cout << ans.size() << endl;
    forn (i, ans.size()) {
        cout << ans[i].first + 1 << " " << ans[i].second << endl;
    }
}