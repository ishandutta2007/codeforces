/*
    Soheil Mohammadkhani
    I will change this text here when i've got "Expert" :)
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define debug2(x)                   cerr << #x << ": " <<  x <<  " ";
#define debug_p(x)                  cerr << #x << ": " <<  x.X <<  " " << x.Y << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define FOR(n)                      for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define kill(x)                     return cout << x << endl, 0;

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 5000 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, q, col[MAXN][MAXN] = {0}, par[MAXN];
vector<ll> adj[MAXN];
vector<pll> tmp;
vector<pair<pll, ll>> tmp2;

void DFS(ll v, ll tar, ll w) {
    if (v == tar) {
        while (par[v] != 0) {
            col[par[v]][v] = max(col[par[v]][v], w);
            col[v][par[v]] = max(col[v][par[v]], w);
            v = par[v];
        }

        return;
    }

    for (ll u : adj[v]) {
        if (u != par[v]) {
            par[u] = v;
            DFS(u, tar, w);
        }
    }
}

bool DFS2(ll v, ll tar, ll w) {
    if (v == tar) {
        while (par[v] != 0) {
            if (col[v][par[v]] == w) return true;
            v = par[v];
        }

        return false;
    }

    bool ans = false;
    for (ll u : adj[v]) {
        if (u != par[v]) {
            par[u] = v;
            ans = ans || DFS2(u, tar, w);
        }
    }

    return ans;
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        tmp.push_back({u, v});
    }

    cin >> q;
    while (q--) {
        ll u, v, w;
        cin >> u >> v >> w;
        tmp2.push_back({{v, u}, w});
        fill(par, par + MAXN, 0);
        DFS(u, v, w);
    }

    for (pair<pll, ll> p : tmp2) {
        par[p.X.X] = 0;
        fill(par, par + MAXN, 0);
        if (!DFS2(p.X.X, p.X.Y, p.Y)) return cout << -1 << endl, 0;
    }

    for (pll e : tmp) {
        ll ans = max(col[e.X][e.Y], 1ll);
        cout << ans << sep;
    }

    cout << endl;
}