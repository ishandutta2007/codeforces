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
const int M = 998244353;
const int L = 18;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g((L + 2) * n + L);
    vector<pair<int, int>> orig, origt;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        orig.pb({a, b});
        origt.pb({b, a});
        g[a].pb({b, 1});
    }
    int w = 1;
    for (int level = 1; level <= L; level++) {
        if (level % 2) {
            for (auto p : origt) {
                g[p.first + (level - 1) * n].pb({p.second + level * n, w + 1});
            }
            for (auto p : origt) {
                g[level * n + p.first].pb({level * n + p.second, 1});
            }
        } else {
            for (auto p : orig) {
                g[p.first + (level - 1) * n].pb({p.second + level * n, w + 1});
            }
            for (auto p : orig) {
                g[level * n + p.first].pb({level * n + p.second, 1});
            }
        }
        w *= 2;
    }
    vector<int> dist((L + 2) * n + L, 1e9);
    dist[1] = 0;
    priority_queue<pair<int, int>> q;
    q.push({0, 1});
    while (!q.empty()) {
        pair<int, int> u = q.top();
        q.pop();
        if (u.first > dist[u.second]) continue;
        for (int i = 0; i < (int) g[u.second].size(); i++) {
            int v = g[u.second][i].first, len = g[u.second][i].second;
            if (dist[v] > dist[u.second] + len) {
                dist[v] = dist[u.second] + len;
                q.push({-dist[v], v});
            }
        }
    }
    int ans = 1e9;
    for (int level = 0; level <= L; level++) {
        if (dist[level * n + n] != 1e9) {
            ans = min(ans, dist[level * n + n]);
        }
    }
    if (ans != 1e9) {
        cout << ans << '\n';
        exit(0);
    }
    vector<vector<pair<int, pair<int, int>>>> gg(2 * n + 3);
    for (auto p : orig) {
        gg[p.first].pb({p.second, {0, 1}});
        gg[p.second + n].pb({p.first + n, {0, 1}});
    }
    for (int u = 1; u <= n; u++) {
        gg[u].pb({n + u, {1, 0}});
        gg[u + n].pb({u, {1, 0}});
    }
    vector<pair<int, int>> dist2((L + 2) * n + L, {1e9, 1e9});
    dist2[1] = {0, 0};
    priority_queue<pair<pair<int, int>, int>> q2;
    q2.push({{0, 0}, 1});
    while (!q2.empty()) {
        pair<pair<int, int>, int> u = q2.top();
        q2.pop();
        if (u.first > dist2[u.second]) continue;
        for (int i = 0; i < (int) gg[u.second].size(); i++) {
            int v = gg[u.second][i].first;
            pair<int, int> len = gg[u.second][i].second;
            pair<int, int> keku = {dist2[u.second].first + len.first, dist2[u.second].second + len.second};
            if (dist2[v] > keku) {
                dist2[v] = keku;
                q2.push({{-dist2[v].first, -dist2[v].second}, v});
            }
        }
    }
    pair<int, int> lal = min(dist2[2 * n], dist2[n]);
    long long sas = 1;
    for (int i = 0; i < lal.first; i++) {
        sas *= 2;
        sas %= M;
    }
    assert(lal.first != 0);
    sas += (M - 1);
    sas %= M;
    sas += lal.second;
    sas %= M;
    cout << sas << '\n';

}