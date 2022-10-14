#include <iostream>
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
#include <chrono>
#include <random>
#include <bitset>

#define pb push_back
// #define int long long
#define ld long double
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--; t--;
    vector<vector<int>> g(n);
    set<pair<int, int>> ed;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].pb(b);
        g[b].pb(a);
        ed.insert({min(a, b), max(a, b)});
    }
    vector<int> dists(n, 1e9), distt(n, 1e9);
    dists[s] = 0;
    distt[t] = 0;
    vector<bool> used(n, false);
    used[s] = true;
    deque<int> q = {s};
    while (!q.empty()) {
        int v = q.front();
        q.pop_front();
        for (auto u : g[v]) {
            if (!used[u]) {
                q.pb(u);
                used[u] = true;
                dists[u] = 1 + dists[v];
            }
        }
    }
    fill(used.begin(), used.end(), false);
    q = {t};
    used[t] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop_front();
        for (auto u : g[v]) {
            if (!used[u]) {
                q.pb(u);
                used[u] = true;
                distt[u] = 1 + distt[v];
            }
        }
    }
    int ans = 0;
    int d = distt[s];
    for (int v1 = 0; v1 < n; v1++) {
        for (int v2 = v1 + 1; v2 < n; v2++) {
            if (dists[v1] + 1 + distt[v2] >= d && distt[v1] + 1 + dists[v2] >= d) {
                if (ed.find({v1, v2}) == ed.end()) ans++;
            }
        }
    }
    cout << ans << '\n';
}