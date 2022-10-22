#define _CRT_SECURE_NO_WARNINGS

#pragma GCC optimize("O3")

#include <algorithm>
#include <bitset>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include <cassert>
#include <assert.h>

using namespace std;

typedef int64_t ll;
typedef uint64_t ull;
typedef long double ld;

const ll MOD = 998244353;
const ld EPS = 1e-9;
const ld INFLD = 1e20;
const ll INFL = 1e17;
const int INF = 2e9 + 7;
const ld PI = acos(-1);
const ld E = exp(1);

//mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnd(643896);

double ReadDouble() {
    string s;
    cin >> s;
    return stol(s);
}

int n;
vector<ll> h;
vector<vector<int>> r;

vector<ll> maxd, smax, sump;

void DFS(int u, int root) {
    for (int v : r[u]) {
        if (v == root) {
            continue;
        }
        DFS(v, u);
        sump[u] += sump[v];
        if (maxd[v] > maxd[u]) {
            smax[u] = maxd[u];
            maxd[u] = maxd[v];
        }
        else if (maxd[v] > smax[u]) {
            smax[u] = maxd[v];
        }
    }
    if (h[u] > maxd[u]) {
        sump[u] += h[u] - maxd[u];
        maxd[u] = h[u];
    }
    if (u == root) {
        sump[u] += h[u] - smax[u];
        smax[u] = h[u];
    }
}

void Solve() {
    cin >> n;
    h.resize(n);
    ll maxh(0);
    int root{ 0 };
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
        if (h[i] > maxh) {
            maxh = h[i];
            root = i;
        }
    }
    r.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        r[u].push_back(v);
        r[v].push_back(u);
    }

    maxd.assign(n, 0);
    smax.assign(n, 0);
    sump.assign(n, 0);

    DFS(root, root);

    cout << sump[root] << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif // LOCAL

    int t = 1;
    //cin >> t;
    for (int q = 0; q < t; ++q) {
        Solve();
    }

    return 0;
}