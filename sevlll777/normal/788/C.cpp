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
    int n, k;
    cin >> n >> k;
    vector<int> A(k);
    for (int i = 0; i < k; i++) cin >> A[i];
    for (int i = 0; i < k; i++) A[i] -= n;
    bool neg = false, pos = false;
    set<int> kek;
    for (auto x : A) {
        if (x == 0) {
            cout << "1\n";
            exit(0);
        }
        kek.insert(x);
        neg |= (x < 0);
        pos |= (x > 0);
    }
    vector <vector<int>> g(4 * n + 1);
    for (int i = 0; i <= 4 * n; i++) {
        for (auto x : kek) {
            if (i + x >= 0 && i + x <= 4 * n) {
                g[i].pb(i + x);
            }
        }
    }
    deque<int> q = {2 * n};
    bitset<2000009> used;
    vector<int> dist(4 * n + 1);
    while (!q.empty()) {
        int v = q.front();
        if (v == n + n && dist[v]) {
            cout << dist[v] << '\n';
            exit(0);
        }
        q.pop_front();
        for (auto u : g[v]) {
            if (!used[u]) {
                used[u] = true;
                dist[u] = 1 + dist[v];
                q.pb(u);
            }
        }
    }
    if (!pos || !neg) {
        cout << "-1\n";
        exit(0);
    }

}