#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e18 + 7;
const ll MAXN = 1e6 + 7;
const double EPS = 1e-8;

vector <vector <pair <ll, ll> > > gr;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    ll n, m;
    cin >> n >> m;
    gr.resize(n);
    for (ll i = 0; i < m; i++) {
        ll v, u, w;
        cin >> v >> u >> w;
        v--, u--;
        gr[v].push_back({u, w});
        gr[u].push_back({v, w});
    }
    vector <pair <ll, ll> > a(n);
    set <pair <ll, ll> > q;
    vector <ll> dist(n);
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        dist[i] = x;
        q.insert({x, i});
    }
    while (!q.empty()) {
        auto v = q.begin()->second;
        q.erase(q.begin());
        for (auto e : gr[v]) {
            ll u = e.first, w = e.second;
            if (dist[u] > dist[v] + 2 * w) {
                q.erase({dist[u], u});
                dist[u] = dist[v] + 2 * w;
                q.insert({dist[u], u});
            }
        }
    }
    for (ll x : dist) {
        cout << x << " ";
    }
}