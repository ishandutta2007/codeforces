#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef int64_t ll;

vector<vector<ll>> g;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    g.resize(n);
    for (ll i = 0; i < m; ++i) {
        ll v, u;
        cin >> v >> u;
        g[v - 1].emplace_back(u - 1);
        g[u - 1].emplace_back(v - 1);
    }
    vector<pair<ll, ll>> id(n);
    for (ll i = 0; i < n; ++i) {
        cin >> id[i].first;
        id[i].second = i;
    }
    sort(id.begin(), id.end());
    vector<ll> color(n);
    for (auto i : id) {
        set<ll> q;
        ll v = i.second;
        ll c = i.first;
        for (ll u : g[v]) {
            if (color[u]) {
                q.insert(color[u]);
            }
        }
        if (q.count(c)) {
            cout << -1 << endl;
            return 0;
        }
        if (q.size() < c - 1) {
            cout << -1 << endl;
            return 0;
        }
        color[v] = c;
    }
    for (ll i = 0; i < n; ++i) {
        cout << id[i].second + 1 << " ";
    }
    cout << endl;
    return 0;
}