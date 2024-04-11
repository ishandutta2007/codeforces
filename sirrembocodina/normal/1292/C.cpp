#include <iostream>
#include <map>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fs first
#define sc second
#define pb push_back
#define int int64_t

vector<int> g[3010];
int p[3010][3010];
int d[3010][3010];
int sz[3010][3010];
vector<pair<int, int> > o[3010];
vector<bool> used;

void dfs(int v, int i, int l) {
    sz[i][v] = 1;
    if (i < v) {
        o[l].push_back(make_pair(i, v));
    }
    used[v] = true;
    for (auto &to: g[v]) {
        if (used[to]) {
            continue;
        }
        p[i][to] = v;
        dfs(to, i, l + 1);
        sz[i][v] += sz[i][to];
    }
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    forn (i, n) {
        used.assign(n, false);
        dfs(i, i, 0);
        p[i][i] = -1;
    }
    int ans = 0;
    for (int l = 3009; l > 0; --l) {
        for (auto& x: o[l]) {
            int a = x.first, b = x.second;
            for (auto &to: g[a]) {
                if (to == p[b][a]) {
                    continue;
                }
                d[a][b] = max(d[a][b], d[to][b]);
            }
            for (auto &to: g[b]) {
                if (to == p[a][b]) {
                    continue;
                }
                d[a][b] = max(d[a][b], d[a][to]);
            }
            d[a][b] += sz[a][b] * sz[b][a];
            d[b][a] = d[a][b];
            ans = max(ans, d[a][b]);
        }
    }
    cout << ans << endl;
}