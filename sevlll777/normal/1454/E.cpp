#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define ld long double
using namespace std;
const int M = 1000000007;
const int N = 200009;
vector<vector<int>> g;
bitset<N> used;
vector<int> par;
int cec = -1;
int sz;

void dfs(int v) {
    sz++;
    used[v] = true;
    for (auto u : g[v]) {
        if (!used[u]) {
            par[u] = v;
            dfs(u);
        } else if (par[v] != u) {
            if (cec == -1) {
                cec = v;
                par[u] = v;
            }
        }
    }
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        used.reset();
        sz = 0;
        cec = -1;
        int n;
        cin >> n;
        g.assign(n, {});
        par.assign(n, 0);
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            g[a].pb(b);
            g[b].pb(a);
        }
        dfs(0);
        used.reset();
        vector<int> mec = {cec};
        int c2 = cec;
        used[cec] = true;
        cec = par[cec];
        while (cec != c2) {
            used[cec] = true;
            mec.pb(cec);
            cec = par[cec];
        }
        vector<int> T;
        int ans = 0, st = 0, st2 = 0;
        sz = 0;
        for (auto x : mec) {
            dfs(x);
            st += sz;
            st2 += sz * sz;
            ans += sz * (sz - 1) / 2;
            sz = 0;
        }
        ans += (st * st - st2);
        cout << ans << '\n';

    }


}