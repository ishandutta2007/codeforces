/*
    Soheil Mohammadkhani
    IDK :)
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
#define SZ(x)                       ll(x.size());
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define bug(x)                      cerr << #x << ": " <<  x <<  " ";
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define FOR(n)                      for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    if (b == -1) return poww(a, md - 2, md);
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, q;
ll H[MAXN], par[LOG][MAXN];
vector<ll> adj[MAXN];

ll DFS(ll v, ll p) {
    H[v] = H[p] + 1;
    par[0][v] = p;
    for (ll u : adj[v]) if (u != p) DFS(u, v);
}

ll getPar(ll v, ll h) {
    for (ll i = 0; i < LOG; i++) if (h & (1ll << i)) v = par[i][v];
    return v;
}

ll LCA(ll v, ll u) {
    if (H[v] > H[u]) swap(u, v);
    u = getPar(u, H[u] - H[v]);
    if (u == v) return v;
    for (ll i = LOG - 1; i >= 0; i--) {
        if (par[i][v] != par[i][u]) {
            v = par[i][v];
            u = par[i][u];
        }
    }
    return par[0][v];
}

ll dist(ll u, ll v) {
    return H[u] + H[v] - 2 * H[LCA(u, v)];
}

ll solve() {
    ll x, y, a, b, k;
    cin >> x >> y >> a >> b >> k;
    queue<ll> q;
    q.push(dist(a, b));
    q.push(dist(a, x) + dist(b, y) + 1);
    q.push(dist(a, y) + dist(b, x) + 1);

    while (!q.empty()) {
        if (q.front() % 2 == k % 2 && q.front() <= k) return cout << "YES" << endl, 0;
        q.pop();
    }

    return cout << "NO" << endl, 0;
}

int main() {
    fast_io; H[0] = -1;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(1, 0);

    //PREPROCCESS
    for (ll i = 1; i < LOG; i++) {
        for (ll j = 0; j <= n; j++) par[i][j] = par[i - 1][par[i - 1][j]];
    }

    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}