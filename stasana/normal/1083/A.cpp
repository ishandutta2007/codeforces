// Megumin top

#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

typedef int64_t ll;
typedef long double ld;

ll n;
vector<vector<pair<ll, ll>>> tree;
vector<ll> arr;

ll result = 0;

ll dfs(ll v, ll p = -1) {
    ll mx1 = arr[v];
    ll mx2 = arr[v];
    for (auto u : tree[v]) {
        if (u.first == p) {
            continue;
        }
        ll newValue = dfs(u.first, v) + arr[v] - u.second;
        if (mx1 < newValue) {
            mx2 = mx1;
            mx1 = newValue;
        }
        else if (mx2 < newValue) {
            mx2 = newValue;
        }
    }
    result = max(result, mx1 + mx2 - arr[v]);
    return mx1;
}

int main() {
    cin >> n;
    tree.resize(n);
    arr.resize(n);
    for (ll i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for (ll i = 0; i < n - 1; ++i) {
        ll v, u, w;
        cin >> v >> u >> w;
        --v;
        --u;
        tree[u].emplace_back(v, w);
        tree[v].emplace_back(u, w);
    }
    
    dfs(0);

    cout << result << endl;

    return 0;
}