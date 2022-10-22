#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <cassert>
#include <assert.h>

//#pragma GCC optimize("O3")

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll MOD = 1000000007;
const ld EPS = 1e-11;
const ll INFL = 1e18;
const ll INF = 1e9 + 7;
const ld PI = acos(-1);

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

int getr(int u, vector<int>& root) {
    //cout << u << " - ";
    vector<int> path;
    while (root[u] != u) {
        path.push_back(u);
        u = root[u];
    }
    for (int i = 0; i < path.size(); ++i) {
        root[path[i]] = u;
    }
    //cout << u << "\n";
    return u;
}

bool unite(int u, int v, vector<int>& root) {
    //cout << u << "; " << v << "\n";
    u = getr(u, root);
    v = getr(v, root);
    root[u] = v;
    return u != v;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, pair<int, int>>> r;
    int mind = INF;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u;
        --v;
        mind = min(mind, abs(w - k));
        r.push_back({ w, {u, v} });
    }
    sort(r.begin(), r.end());

    int maxw = 0;
    vector<int> root(n);
    for (int i = 0; i < n; ++i) {
        root[i] = i;
    }

    ll ans = 0;
    for (int i = 0; i < m; ++i) {
        if (unite(r[i].second.first, r[i].second.second, root)) {
            maxw = r[i].first;
            if (maxw > k) {
                ans += (ll)maxw - (ll)k;
            }
        }
        //cout << ans << "\n";
    }

    if (ans == 0) {
        cout << mind << "\n";
    }
    else {
        cout << ans << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    
    for (int q = 0; q < t; ++q) {
        solve();
    }

    return 0;
}