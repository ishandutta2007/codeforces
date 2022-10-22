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

const ll MAXN = 5e5 + 10;
const ll INF = 8e16;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll par[MAXN] = {0}, ans = 0, n, c[MAXN], p[MAXN] = {0};
vector<ll> adj[MAXN];

pll DFS(ll v, ll pr) {
    pll tmp = {0, 0};
    if (p[v] == 1) tmp.X++;
    else if (p[v] == -1) tmp.Y++;
    for (ll u : adj[v]) {
        if (u != pr) {
            par[u] = min(par[v], c[u]);
            pll res = DFS(u, v);
            tmp.X += res.X;
            tmp.Y += res.Y;
        }
    }

    ll x = min(tmp.X, tmp.Y);
    ans += 2 * x * par[v];
    tmp.X -= x;
    tmp.Y -= x;
    return tmp;
}

int main() {
    fast_io;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        ll x, y;
        cin >> x >> y;
        p[i] = x - y;
    }

    for (int i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    par[1] = c[1];
    pll res = DFS(1, 0);
    if (res.X > 0 || res.Y > 0) return cout << "-1" << endl, 0;
    cout << ans << endl;
    return 0;
}