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
const int M = 1000000007;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, a, b, da, db;
        cin >> n >> a >> b >> da >> db;
        vector<vector<int>> g(n);
        a--;
        b--;
        for (int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            g[x].pb(y);
            g[y].pb(x);
        }
        vector<int> dis(n), dis2(n);
        vector<bool> used(n, false);
        deque<int> q = {a};
        used[a] = true;
        while (!q.empty()) {
            int x = q.front();
            q.pop_front();
            for (auto y : g[x]) {
                if (!used[y]) {
                    q.pb(y);
                    used[y] = true;
                    dis[y] = 1 + dis[x];
                }
            }
        }
        int mx = 0, vv = 0;
        for (int v = 0; v < n; v++) {
            if (dis[v] > mx) {
                mx = dis[v];
                vv = v;
            }
        }
        int diameter = 1;
        fill(used.begin(), used.end(), false);
        used[vv] = true;
        q = {vv};
        while (!q.empty()) {
            int x = q.front();
            q.pop_front();
            for (auto y : g[x]) {
                if (!used[y]) {
                    q.pb(y);
                    used[y] = true;
                    dis2[y] = 1 + dis2[x];
                    diameter = max(diameter, dis2[y]);
                }
            }
        }
        if (db <= 2 * da || dis[b] <= da || diameter <= 2 * da) {
            cout << "Alice\n";
        } else {
            cout << "Bob\n";
        }
    }
}