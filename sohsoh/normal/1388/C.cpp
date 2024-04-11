/*
    Soheil Mohammadkhani
    OK, im back :)
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

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

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

pld f(ll s, ll n) {
    ll x = s + n;
    ld a = x / ld(2);
    return {a, s - a};
}

vector<ll> adj[MAXN];
ll P[MAXN], S[MAXN] = {0}, H[MAXN], n = 0, m = 0;

ll sdfs(ll v, ll p = -1) {
    ll s = P[v];
    for (ll u : adj[v]) if (u != p) s += sdfs(u, v);
    S[v] = s;
    return S[v];
}

bool ok = true;

pll dfs(ll v, ll p = 0) {
    pld ans = f(S[v], H[v]);
    pll tans = {ans.X, ans.Y};
    if (ll(ans.X) != ans.X || ll(ans.Y) != ans.Y || ans.X < 0 || ans.Y < 0) ok = false;
    for (ll u : adj[v]) {
        if (u != p) {
            pll p = dfs(u, v);
            tans.X -= p.X;
            tans.Y -= p.Y;
        }
    }

    if (tans.X < 0 || tans.X + tans.Y != P[v]) ok = false;
    return ans;
}

ll solve() {
    for (int i = 0; i < n + 10; i++) {
        adj[i].clear();
        P[i] = 0;
        S[i] = 0;
    }
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> P[i];
    for (int i = 1; i <= n; i++) cin >> H[i];
    for (int i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    sdfs(1);
    ok = true;
    dfs(1);
    if (ok) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}