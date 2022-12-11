#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef int64_t ll;

vector<vector<ll>> tree;
vector<ll> height;
vector<ll> sz;

void dfs(ll v, ll p) {
    sz[v] = 1;
    height[v] = height[p] + 1;
    for (ll u : tree[v]) {
        if (u == p) {
            continue;
        }
        dfs(u, v);
        sz[v] += sz[u];
    }
}

int main() {
    ll n, k;
    cin >> n >> k;
    k = n - k;
    height.resize(n);
    tree.resize(n);
    sz.resize(n);
    for (ll i = 1; i < n; ++i) {
        ll v, u;
        cin >> v >> u;
        --v;
        --u;
        tree[v].emplace_back(u);
        tree[u].emplace_back(v);
    }
    dfs(0, 0);
    vector<ll> a;
    for (ll i = 0; i < n; ++i) {
        a.emplace_back(sz[i] - height[i]);
    }
    ll res = 0;
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    for (ll i = 0; i < k; ++i) {
        res += a[i];
    }
    cout << res << endl;

    return 0;
}