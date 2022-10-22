#pragma GCC optimize("O3")

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

using namespace std;

typedef int64_t ll;
typedef uint64_t ull;
typedef long double ld;

const ll MOD = 998244353;
const ld EPS = 1e-11;
const ld INFLD = 1e20;
const ll INFL = 4e18;
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

vector<int> root;
vector<int> rsiz;

int GetRoot(int u) {
    if (u == root[u]) {
        return u;
    }
    root[u] = GetRoot(root[u]);
    return root[u];
}

bool Fuse(int u, int v) {
    u = GetRoot(u);
    v = GetRoot(v);
    if (u != v) {
        root[u] = v;
        rsiz[v] += rsiz[u];
        return true;
    }
    return false;
}

void Solve() {
    int n, q;
    cin >> n >> q;
    root.resize(n);
    for (int i = 0; i < n; ++i) {
        root[i] = i;
    }
    rsiz.assign(n, 1);

    int asks = 1;
    for (int i = 0; i < q; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        if (!Fuse(u, v)) {
            ++asks;
        }

        set<int> roots;
        vector<int> root_sizes;
        for (int i = 0; i < n; ++i) {
            int cr = GetRoot(i);
            if (roots.count(cr) == 0) {
                roots.insert(cr);
                root_sizes.push_back(rsiz[cr]);
            }
        }
        sort(root_sizes.begin(), root_sizes.end());

        int ans = 0;
        for (int i = 0; i < min((int)root_sizes.size(), asks); ++i) {
            ans += root_sizes[root_sizes.size() - 1 - i];
        }

        cout << ans - 1 << "\n";
    }
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