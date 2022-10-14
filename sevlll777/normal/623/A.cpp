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
#define int long long
#define ld long double
using namespace std;
const int M = 1000000007;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<set<int>> g(n);
    for (int v = 0; v < n; v++) {
        for (int u = 0; u < n; u++) {
            if (v != u) {
                g[v].insert(u);
            }
        }
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].erase(b);
        g[b].erase(a);
    }
    bitset<5050> used;
    string ans = "";
    vector<int> color(n, -1);
    bool f = true;
    for (int v = 0; v < n; v++) {
        if (!used[v] && !g[v].empty()) {
            color[v] = 0;
            deque<int> q = {v};
            used[v] = true;
            while (!q.empty()) {
                int u = q.front();
                q.pop_front();
                for (auto vv : g[u]) {
                    if (!used[vv]) {
                        used[vv] = true;
                        color[vv] = 1 - color[u];
                        q.pb(vv);
                    } else if (color[u] == color[vv]) {
                        f = false;
                    }
                }
            }
        }
    }
    if (!f) {
        cout << "No\n";
    } else {
        int ca = 0, cc = 0;
        for (auto x : color) {
            ca += (x == 0);
            cc += (x == 1);
        }
        if (n * (n - 1) / 2 == m + ca * cc) {
            cout << "Yes\n";
            for (auto x : color) {
                if (x == 0) {
                    cout << 'a';
                } else if (x == 1) {
                    cout << 'c';
                } else {
                    cout << 'b';
                }
            }
            cout << '\n';
        } else {
            cout << "No\n";
        }
    }
}