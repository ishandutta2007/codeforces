// Bipolar disorder is very cool

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef int64_t ll;

vector<vector<ll>> tree;
vector<ll> result;
vector<ll> color;
vector<ll> down;

void dfs_down(ll v, ll p) {
    down[v] = color[v];
    for (ll u : tree[v]) {
        if (u == p) {
            continue;
        }
        dfs_down(u, v);
        down[v] = max(down[v], down[v] + down[u]);
    }
}

void dfs(ll v, ll p) {
    result[v] = down[v];
    if (p != v) {
        if (down[v] < 0) {
            result[v] = max(result[v], result[v] + result[p]);
        } else {
            result[v] = max(result[v], result[p]);
        }
    }
    for (ll u : tree[v]) {
        if (u == p) {
            continue;
        }
        dfs(u, v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    tree.resize(n);
    result.resize(n);
    color.resize(n);
    down.resize(n);
    for (ll& i : color) {
        cin >> i;
        if (i == 0) {
            i = -1;
        }
    }
    for (ll i = 1; i < n; ++i) {
        ll v, u;
        cin >> v >> u;
        tree[v - 1].emplace_back(u - 1);
        tree[u - 1].emplace_back(v - 1);
    }
    dfs_down(0, 0);
    dfs(0, 0);

    for (ll i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}