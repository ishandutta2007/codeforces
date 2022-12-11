#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef int64_t ll;

void dfs1(vector<vector<ll>>& g, vector<bool>& used, vector<ll>& topsort, ll v) {
    used[v] = true;
    for (ll i = 0; i < g[v].size(); ++i) {
        if (!used[g[v][i]]) {
            dfs1(g, used, topsort, g[v][i]);
        }
    }
    topsort.push_back(v);
}

void dfs2(vector<vector<ll>>& g, vector<ll>& component, ll v, ll k) {
    component[v] = k;
    for (ll i = 0; i  < g[v].size(); ++i) {
        if (component[g[v][i]] == 0) {
            dfs2(g, component, g[v][i], k);
        }
    }
}

int main() {
    ll n, m, h;
    cin >> n >> m >> h;
    vector<ll> color(n);
    vector<vector<ll>> g(n);
    vector<vector<ll>> gr(n);
    for (ll i = 0; i < n; ++i) {
        cin >> color[i];
    }
    vector<pair<ll, ll>> edge;
    for (ll i = 0; i < m; ++i) {
        ll v, u;
        cin >> v >> u;
        --v;
        --u;
        if ((color[v] + 1) % h == color[u]) {
            g[v].push_back(u);
            gr[u].push_back(v);
            edge.push_back(make_pair(v, u));
        }
        if ((color[u] + 1) % h == color[v]) {
            g[u].push_back(v);
            gr[v].push_back(u);
            edge.push_back(make_pair(u, v));
        }
    }
    vector<ll> topsort;
    vector<bool> used(n);
    for (ll i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs1(g, used, topsort, i);
        }
    }
    vector<ll> component(n);
    ll k = 1;
    for (ll i = n - 1; i >= 0; --i) {
        if (component[topsort[i]] == 0) {
            dfs2(gr, component, topsort[i], k);
            ++k;
        }
    }
    vector<ll> cnt(k + 1);
    vector<bool> isStok(k + 1, true);
    for (ll i = 0; i < n; ++i) {
        ++cnt[component[i]];
    }
    for (ll i = 0; i < edge.size(); ++i) {
        if (component[edge[i].first] != component[edge[i].second]) {
            isStok[component[edge[i].first]] = false;
        }
    }
    ll mn = 1e9;
    for (ll i = 1; i < k; ++i) {
        if (isStok[i] && cnt[i] < mn) {
            mn = cnt[i];
        }
    }
    for (ll i = 1; i < k; ++i) {
        if (isStok[i] && cnt[i] == mn) {
            cout << mn << endl;
            for (int j = 0; j < n; ++j) {
                if (component[j] == i) {
                    cout << j + 1 << " ";
                }
            }
            return 0;
        }
    }
    return 0;
}