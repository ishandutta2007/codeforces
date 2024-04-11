// #define _GLIBCXX_DEBUG

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

#define int long long
#define dbl long double
#define pb push_back
#define str string
using namespace std;
const int M = 998244353;
int dist[5010][5010];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<pair<int, int>> huh;
    for (int v = 1; v <= n; v++) {
        int cnt = 0;
        g[v].pb(v);
        vector<bool> used(n + 1, false);
        used[v] = true;
        deque<int> q = {v};
        while (!q.empty()) {
            int u = q.front();
            q.pop_front();
            for (auto uu : g[u]) {
                if (!used[uu]) {
                    used[uu] = true;
                    q.pb(uu);
                    dist[v][uu] = 1 + dist[v][u];
                    cnt += dist[v][uu];
                }
            }
        }
        huh.pb({cnt, v});
    }
    sort(huh.begin(), huh.end());
    int a = huh[1].second;
    int b = huh[2].second;
    int c = huh[0].second;
    cout << a << ' ' << b << ' ' << c << endl;
    for (int i = 0; i < n - 1; i++) {
        int php;
        cin >> php;
        pair<int, int> aa = {10000000, 1}, bb = {1000000, 1}, cc = {1000000, 1};
        for (auto w : g[a]) {
            int cz = 0;
            for (auto pp : g[php]) cz += dist[w][pp];
            aa = min(aa, {cz, w});
        }
        for (auto w : g[b]) {
            int cz = 0;
            for (auto pp : g[php]) cz += dist[w][pp];
            bb = min(bb, {cz, w});
        }
        for (auto w : g[c]) {
            int cz = 0;
            for (auto pp : g[php]) cz += dist[w][pp];
            cc = min(cc, {cz, w});
        }
        int la = a, lb = b, lc = c;
        a = aa.second;
        b = bb.second;
        c = cc.second;
        while (a == b || a == c || b == c) {
            a = g[la][rand() % (g[la].size())];
            c = g[lc][rand() % (g[lc].size())];
        }
        cout << a << ' ' << b << ' ' << c << endl;
        if (php == a || php == b || php == c) {
            return 0;
        }
    }


}