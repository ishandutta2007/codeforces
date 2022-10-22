/*
    Soheil Mohammadkhani
    shitty problem :)
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
#define bug(x)                      cerr << #x << ": " <<  x <<  " ";
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define FOR(n)                      for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    if (b == -1) return poww(a, md - 2, md);
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

bool shitty_graph = false;
vector<ll> adj[MAXN];
ll n, ans;

ll find_roots() {
    for (int i = 1; i <= n; i++) if (SZ(adj[i]) == 1) return i;
}

ll DFS(ll v, ll ps = 0, ll p = -1) {
    if (SZ(adj[v]) == 1 && ps != 0) {
        if (ps % 2 != 0) shitty_graph = true;
        return ps;
    }

    ll num_leaf = 0;
    for (ll u : adj[v]) {
        if (SZ(adj[u]) == 1) num_leaf++;
        if (u != p) DFS(u, ps + 1, v);
    }

    if (num_leaf > 1) ans -= num_leaf - 1;
}

int main() {
    fast_io;
    cin >> n;
    ans = n - 1;

    for (int i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(find_roots());

    if (shitty_graph) cout << 3 << sep;
    else cout << 1 << sep;

    cout << ans << endl;
    return 0;
}