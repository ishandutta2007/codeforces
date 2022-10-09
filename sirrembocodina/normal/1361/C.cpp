
#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define sqr(x) (x) * (x)

using namespace std;

void solve(vector<vector<pair<int, pair<int, int>>>>& g, vector<bool>& del, vector<int> &st, vector<int>& ans, int v) {
    for (int i = st[v]; i < g[v].size(); i++) {
        auto e = g[v][i];
        int ind = e.second.first / 2;
        if (del[ind]) {
            continue;
        }
        del[ind] = true;
        st[v] = i + 1;
        int to = e.first;
        solve(g, del, st, ans, to);
        ans.push_back(e.second.second);
        ans.push_back(e.second.first);
        if (st[v] > i + 1) {
            return;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<pair<int, int>> e(n);
    forn (i, n) {
        cin >> e[i].first >> e[i].second;
    }
    int max_k = 0;
    vector<int> ANS(2 * n);
    forn (i, 2 * n) {
        ANS[i] = i;
    }
    for (int k = 1; k <= 20; k++) {
        vector<vector<pair<int, pair<int, int>>>> g(1 << k);
        vector<int> st(1 << k);
        vector<bool> del(n);
        forn (i, n) {
            int x = e[i].first & ((1 << k) - 1);
            int y = e[i].second & ((1 << k) - 1);
            g[x].push_back({y, {2 * i, 2 * i + 1}});
            g[y].push_back({x, {2 * i + 1, 2 * i}});
            //cerr << x << " " << y << endl;
        }
        bool bad = false;
        forn (i, 1 << k) {
            if (g[i].size() % 2) {
                bad = true;
                break;
            }
        }
        if (bad) {
            break;
        }
        vector<int> ans;
        forn (i, 1 << k) {
            if (g[i].size()) {
                solve(g, del, st, ans, i);
                break;
            }
        }
        if (ans.size() < 2 * n) {
            break;
        }
        max_k = k;
        ANS = ans;
    }
    cout << max_k << endl;
    forn (i, 2 * n) {
        cout << ANS[i] + 1 << " ";
    }
    cout << endl;
}