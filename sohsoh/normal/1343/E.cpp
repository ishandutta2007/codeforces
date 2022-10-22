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

const ll MAXN = 2e5 + 10;
const ll LOG = 22;
const ll INF = 8e17;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, m, a, b, c, P[MAXN], d1[MAXN], d2[MAXN], d3[MAXN], pref[MAXN];
vector<ll> adj[MAXN];

void prep() {
    fill(pref, pref + n + 2, 0);
    fill(d1, d1 + n + 2, INF);
    fill(d2, d2 + n + 2, INF);
    fill(d3, d3 + n + 2, INF);
    for (int i = 0; i <= n; i++) adj[i].clear();
}

void BFS(ll v, ll* dist) {
    queue<ll> q;
    dist[v] = 0;
    q.push(v);
    while (!q.empty()) {
        v = q.front();
        q.pop();
        for (ll u : adj[v]) {
            if (dist[u] == INF) {
                q.push(u);
                dist[u] = dist[v] + 1;
            }
        }
    }
}

ll solve() {
    cin >> n >> m >> a >> b >> c;
    prep();
    for (int i = 0; i < m; i++) cin >> P[i];
    sort(P, P + m);
    for (int i = 0; i < m; i++) pref[i + 1] = pref[i] + P[i];

    for (int i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    BFS(a, d1);
    BFS(b, d2);
    BFS(c, d3);

    ll ans = INF;
    for (int v = 1; v <= n; v++) {
        if (d1[v] + d2[v] + d3[v] > m) continue;
        ll t_ans = pref[d1[v] + d2[v] + d3[v]] + pref[d2[v]];
        if (t_ans == 1) debug(v)
        ans = min(t_ans, ans);
    }

    cout << ans << endl;
    return 0;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}