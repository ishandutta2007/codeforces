/*
    Soheil Mohammadkhani
    I will change this text here when i've got "Candidate Master":)
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 2e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

vector<ll> adj[MAXN], topo;
ll vis[MAXN] = {0}, vis2[MAXN] = {0}, n, m, topo_ord[MAXN];
vector<pll> edges;

bool is_acyc(ll v) {
    vis2[v] = 1;
    for (ll u : adj[v]) if (vis2[u] != 2 && (vis2[u] == 1 || (!is_acyc(u)))) return false;
    vis2[v] = 2;
    topo.push_back(v);
    return true;
}

ll solve() {
    for (int i = 0; i < n + 10; i++) adj[i].clear();
    edges.clear();
    fill(vis, vis + n + 10, 0);
    fill(vis2, vis2 + n + 10, 0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        ll t, u, v;
        cin >> t >> u >> v;
        if (t) adj[u].push_back(v);
        else edges.push_back({u, v});
    }

    for (int i = 1; i <= n; i++) if (vis2[i] == 0 && !is_acyc(i)) return cout << "NO" << endl, 0;
    cout << "YES" << endl;
    reverse(all(topo));
    for (int i = 0; i < n; i++) topo_ord[topo[i]] = i;
    for (pll e : edges) {
        if (topo_ord[e.X] > topo_ord[e.Y]) swap(e.X, e.Y);
        cout << e.X << sep << e.Y << endl;
    }

    for (int i = 1; i <= n; i++) for (ll u : adj[i]) cout << i << sep << u << endl;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}