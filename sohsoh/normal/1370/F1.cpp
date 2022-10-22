/*
    Soheil Mohammadkhani
    Rade-B from now :)
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

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n;
vector<ll> adj[MAXN], dist[MAXN], vv;

void DFS(ll v, ll par = 0, ll x = 0) {
    dist[x].push_back(v);
    for (ll u : adj[v]) if (u != par) DFS(u, v, x + 1);
}

pll Q(vector<ll> v) {
    if (v.size() == 0) return {INF, INF};
    cout << '?' << sep;
    cout << v.size() << sep;
    for (ll u : v) cout << u << sep;
    cout << endl;
    cout.flush();
    ll x, y;
    cin >> x >> y;
    return {x, y};
}

void DFS2(ll v, ll d, ll par = 0, ll x = 0) {
    if (x == d) vv.push_back(v);
    for (ll u : adj[v]) if (u != par) DFS2(u, d, v, x + 1);
}

ll solve() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll u, ud, l = INF, ba = -1, r = INF;
    vector<ll> q;
    for (int i = 0; i < n; i++) q.push_back(i + 1);
    pll ans = Q(q);
    u = ans.X;
    ud = ans.Y;
    q.clear();

    DFS(u);
    ll L = 0, R = 0;
    while (!dist[R + 1].empty()) R++;
    pll tmp;
    while (L < R) {
        ll mid = ceil((L + R) / ld(2));
        tmp = Q(dist[mid]);
        if (tmp.Y > ud) R = mid - 1;
        else {
            L = mid;
            if (mid > ba) {
                l = tmp.X;
                ba = mid;
            }
        }
    }

    vv.clear();
    DFS2(l, ud);
    r = Q(vv).X;

    cout << '!' << sep <<  l << sep << r << endl;
    cout.flush();

    string stat;
    cin >> stat;
    for (int i = 0; i < n + 10; i++) adj[i].clear();
    for (int i = 0; i < n + 10; i++) dist[i].clear();
    return 0;
}

int main() {
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}