// Megumin top

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

typedef int64_t ll;

inline void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

ll n;
vector<vector<ll>> g;
vector<ll> s;
vector<ll> a;

void dfs(ll v, ll p, ll add) {
    if (s[v] == -1) {
        ll mn = -1;
        for (auto u : g[v]) {
            if (u == p) {
                continue;
            }
            if (mn == -1 || s[mn] > s[u]) {
                mn = u;
            }
        }
        if (mn == -1) {
            s[v] = add;
        }
        else {
            s[v] = s[mn];
        }
    }
    a[v] = s[v] - add;
    for (auto u : g[v]) {
        if (u == p) {
            continue;
        }
        dfs(u, v, s[v]);
    }
}

inline void solve() {
    cin >> n;
    g.resize(n);
    s.resize(n);
    a.resize(n);
    for (ll i = 1; i < n; ++i) {
        ll p;
        cin >> p;
        g[p - 1].emplace_back(i);
        g[i].emplace_back(p - 1);
    }
    for (ll i = 0; i < n; ++i) {
        cin >> s[i];
    }
    dfs(0, 0, 0);
    ll result = 0;          
    for (auto i : a) {
        if (i < 0) {
            cout << -1 << endl;
            return;
        }
        result += i;
    }
    cout << result << endl;
}

int main() {
    start();
    solve();
    return 0;
}