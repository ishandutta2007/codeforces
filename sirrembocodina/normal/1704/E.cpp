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

int mod = 998244353;

vector<bool> used;
vector<vector<int>> g;
vector<vector<int>> rg;
vector<int> top;

void dfs(int v) {
    used[v] = true;
    for (int to: g[v]) {
        if (!used[to]) {
            dfs(to);
        }
    }
    top.push_back(v);
}

void add(int& a, bool& a_of, int b, bool b_of) {
    a += b;
    if (a >= mod) {
        a -= mod;
        a_of = true;
    }
    if (b_of) {
        a_of = true;
    }
}

int t[1000][1000];
bool t_of[1000][1000];

int32_t main() {
    srand(time(nullptr));
    ios_base::sync_with_stdio(0);
    int T = 1;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        g.clear();
        g.resize(n);
        rg.clear();
        rg.resize(n);
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            g[a].push_back(b);
            rg[b].push_back(a);
        }
        used.assign(n, false);
        top.clear();
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                dfs(i);
            }
        }
        reverse(top.begin(), top.end());
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                t[i][j] = 0;
                t_of[i][j] = false;
            }
            t[i][0] = a[i];
        }
        for (int v: top) {
            for (int fr: rg[v]) {
                for (int i = 0; i < n - 1; i++) {
                    add(t[v][i + 1], t_of[v][i + 1], t[fr][i], t_of[fr][i]);
                }
            }
        }
        int last = -1;
        for (int i = 0; i < n; i++) {
            if (g[i].empty()) {
                last = i;
                break;
            }
        }
        int ans = 0;
        bool ans_of = false;
        for (int i = 0; i < n; i++) {
            if (!t_of[last][i] && t[last][i] == 0) {
                continue;
            }
            if (!ans_of && ans < i) {
                ans = i;
            }
            add(ans, ans_of, t[last][i], t_of[last][i]);
        }
        cout << ans << '\n';
    }
}