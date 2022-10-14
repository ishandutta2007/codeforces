// #pragma GCC optimize("unroll-loops")

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
#include <queue>
#include <bitset>

#define pb push_back
// #define int short
#define int long long
#define pii pair<int, int>
#define unmap unordered_map
#define unset unordered_set
#define tupint tuple<int, int, int>
#define dbl long double
#define str string
using namespace std;
const int M = 998244353;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        a--;
        b--;
        vector<int> C(n), D(n);
        vector<vector<int>> graph(n);
        for (int i =0; i < m; i++) {
            int v, u;
            cin >> v >> u;
            v--; u--;
            graph[v].pb(u); graph[u].pb(v);
        }
        int c1 = 0;
        vector<bool> used1(n, false);
        used1[a] = true;
        for (int v = 0; v < n; v++) {
            if (!used1[v]) {
                c1++;
                C[v] = c1;
                deque<int> q = {v};
                while (!q.empty()) {
                    int v2 = q.front(); q.pop_front();
                    for (auto u : graph[v2]) {
                        if (!used1[u]) {
                            used1[u] = true;
                            C[u] = c1;
                            q.pb(u);
                        }
                    }
                }
            }
        }
        int c2 = 0;
        vector<bool> used2(n, false);
        used2[b] = true;
        for (int v = 0; v < n; v++) {
            if (!used2[v]) {
                c2++;
                D[v] = c2;
                deque<int> q = {v};
                while (!q.empty()) {
                    int v2 = q.front(); q.pop_front();
                    for (auto u : graph[v2]) {
                        if (!used2[u]) {
                            used2[u] = true;
                            D[u] = c2;
                            q.pb(u);
                        }
                    }
                }
            }
        }
        int L1 = 0, L2 = 0, L3 = 0;
        map<pii, int> k1;
        for (int i = 0; i < n; i++) {
            if (i != a && i != b) {
                k1[{C[i], D[i]}]++;
            }
        }
        for (auto p : k1) {
            L1 += p.second * (p.second - 1) / 2;
        }
        vector<int> rc(n);
        vector<int> rd(n);
        for (int i = 0; i < n; i++) {
            if (i != a && i != b) {
                rc[C[i]]++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (i != a && i != b) {
                rd[D[i]]++;
            }
        }
        for (auto g : rc) {
            L2 += g * (g - 1) / 2;
        }
        for (auto g : rd) {
            L3 += g * (g - 1) / 2;
        }
        cout << (n - 2) * (n - 3) / 2 - L2 - L3 + L1 << '\n';
    }
}