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

bool ok = true;
vector<int> used;
vector<vector<int>> g;

void dfs(int v) {
    used[v]++;
    for (int to: g[v]) {
        if (used[to] == 1) {
            ok = false;
        }
        if (!used[to]) {
            dfs(to);
        }
    }
    used[v]++;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<pair<int, int>> cnt(n);
        for (int i = 0; i < n; i++) {
            cnt[i].second = i;
        }
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
            cnt[a[i]].first++;
        }
        sort(cnt.rbegin(), cnt.rend());
        vector<int> b(n);
        g.clear();
        g.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            b[i]--;
            if (a[i] != cnt[0].second && b[i] != cnt[0].second) {
                g[a[i]].push_back(b[i]);
            }
        }
        ok = true;
        used.assign(n, 0);
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                dfs(i);
            }
        }
        cout << (ok ? "AC\n" : "WA\n");
    }
}