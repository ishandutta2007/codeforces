#include <algorithm>
#include <bitset>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
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

//#pragma comment(linker, "/STACK:134217728")

//#pragma GCC optimize("O3")

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef bitset<2000> bset;

const ll MOD = 998244353;
const ld EPS = 1e-11;
const ld INFLD = 1e20;
const ld INFLDSQ = 1e40;
const ll INFL = 2e18;
const int INF = 2e9 + 7;
const ld PI = acos(-1);
const ld E = exp(1);

//mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnd(123876);

class DSU {
public:
    vector<int> root;

    DSU(int n) : root(n) {
        for (int i = 0; i < n; ++i) {
            root[i] = i;
        }
    }

    int GetRoot(int u) {
        vector<int> path;
        while (root[u] != u) {
            path.push_back(u);
            u = root[u];
        }
        for (int v : path) {
            root[v] = u;
        }
        return u;
    }

    bool Fuse(int u, int v) {
        u = GetRoot(u);
        v = GetRoot(v);
        root[u] = v;
        return (u != v);
    }
};

bool GetPath(int cu, int from, int fin, const vector<vector<int>>& r, vector<int>& path) {
    path.push_back(cu);
    if (cu == fin) {
        return true;
    }
    for (int v : r[cu]) {
        if (v != from) {
            if (GetPath(v, cu, fin, r, path)) {
                return true;
            }
        }
    }
    path.pop_back();
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> r(n);
    DSU dsu(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        if (dsu.Fuse(u, v)) {
            r[u].push_back(v);
            r[v].push_back(u);
        }
    }

    vector<vector<int>> paths;
    int q;
    cin >> q;
    int vis_odd{ 0 };
    vector<bool> vis(n, false);
    for (int qq = 0; qq < q; ++qq) {
        int a[2];
        cin >> a[0] >> a[1];
        for (int i = 0; i < 2; ++i) {
            --a[i];
            if (vis[a[i]]) {
                --vis_odd;
                vis[a[i]] = false;
            }
            else {
                ++vis_odd;
                vis[a[i]] = true;
            }
        }
        paths.emplace_back();
        GetPath(a[0], -1, a[1], r, paths.back());
    }

    if (vis_odd > 0) {
        cout << "NO\n" << vis_odd / 2 << endl;
    }
    else {
        cout << "YES\n";
        for (auto path : paths) {
            cout << path.size() << "\n";
            for (int u : path) {
                cout << u + 1 << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}