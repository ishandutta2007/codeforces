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
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    vector<int> color(n);
    deque<int> q = {0};
    vector<bool> used(n, false);
    used[0] = true;
    while (!q.empty()) {
        int l = q.back();
        q.pop_back();
        for (auto uu : g[l]) {
            if (!used[uu]) {
                used[uu] = true;
                q.pb(uu);
                color[uu] = 1 - color[l];
            }
        }
    }
    int b = 0, w = 0;
    for (int v = 0; v < n; v++) {
        if (color[v]) {
            b++;
        } else {
            w++;
        }
    }
    cout << -1 + min(b, w) << '\n';
}