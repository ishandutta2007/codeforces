#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <random>
#include <queue>
#include <bitset>

// #define int long long
#define ll long long
#define dbl long double
#define pb push_back
#define str string
using namespace std;
const int M = 998244353;
const int MAXN = 100009;
const int LOG = 21;
vector<pair<int, ll>> gr[MAXN];
int cnt[MAXN];
int imp[50];
vector<ll> imp_dists[50];
vector<bool> used(MAXN, false);
int binup[MAXN][LOG];
int depth[MAXN];
ll wdepth[MAXN];
int cc = 0;

int lca(int a, int b) {
    if (depth[a] > depth[b]) swap(a, b);
    int da = depth[a], db = depth[b];
    for (int lg = LOG - 1; lg >= 0; lg--) {
        if (db - (1 << lg) >= da) {
            db -= (1 << lg);
            b = binup[b][lg];
        }
    }
    if (a == b) return a;
    for (int lg = LOG - 1; lg >= 0; lg--) {
        if (binup[a][lg] != binup[b][lg]) {
            a = binup[a][lg];
            b = binup[b][lg];
        }
    }
    return binup[a][0];
}

void dfs(int v) {
    for (auto u : gr[v]) {
        if (!used[u.first]) {
            cnt[v]++; cnt[u.first]++;
            binup[u.first][0] = v;
            for (int lg = 1; lg < LOG; lg++) {
                binup[u.first][lg] = binup[binup[u.first][lg - 1]][lg - 1];
            }
            depth[u.first] = 1 + depth[v];
            wdepth[u.first] = u.second + wdepth[v];
            used[u.first] = true;
            dfs(u.first);
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        ll d;
        cin >> a >> b >> d;
        a--;
        b--;
        gr[a].pb({b, d});
        gr[b].pb({a, d});
    }

    used[0] = true;
    for (int lg = 0; lg < LOG; lg++) binup[0][lg] = 0;
    depth[0] = 0;
    wdepth[0] = 0;
    dfs(0);

    for (int v = 0; v < n; v++) {
        if (cnt[v] != gr[v].size()) {
            imp[cc++] = v;
        }
    }

    for (int x = 0; x < cc; x++) {
        int v = imp[x];
        vector<ll> dists(n, 1e18);
        dists[v] = 0;
        priority_queue<pair<ll, int>> qu;
        qu.push({0, v});
        while (!qu.empty()) {
            pair<int, int> u = qu.top();
            qu.pop();
            if (u.first > dists[u.second]) continue;
            for (auto v2 : gr[u.second]) {
                ll len = v2.second;
                if (dists[v2.first] > dists[u.second] + len) {
                    dists[v2.first] = dists[u.second] + len;
                    qu.push({dists[v2.first], v2.first});
                }
            }
        }
        imp_dists[x] = dists;
    }

    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        ll ans = wdepth[a] + wdepth[b] - 2 * wdepth[lca(a, b)];
        for (int i = 0; i < cc; i++) {
            ans = min(ans, imp_dists[i][a] + imp_dists[i][b]);
        }
        cout << ans << '\n';
    }


}