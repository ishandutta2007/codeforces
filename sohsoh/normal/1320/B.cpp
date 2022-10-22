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

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

vector<ll> adj[MAXN];
set<ll> par[MAXN];
ll cnt[MAXN] = {0}, p[MAXN], dist[MAXN];

ll k, n, m;

void BFS(ll v) {
    fill(dist, dist + MAXN, INF);
    fill(cnt, cnt + MAXN, 0);
    queue<ll> q;
    q.push(v);
    dist[v] = 0;
    cnt[v] = 1;

    while (!q.empty()) {
        v = q.front();
        q.pop();
        for (ll u : adj[v]) {
            if (dist[u] == dist[v] + 1) {
                par[u].insert(v);
                cnt[u]++;
            }
            if (dist[u] == INF) {
                dist[u] = dist[v] + 1;
                par[u].insert(v);
                cnt[u]++;
                q.push(u);
            }
        }
    }
}

int main() {
    fast_io;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        ll v, u;
        cin >> v >> u;
        adj[u].push_back(v);
    }

    cin >> k;
    for (int i = 1; i <= k; i++) cin >> p[i];
    BFS(p[k]);

    pll res;
    res.first = 0; res.second = 0;
    for (int i = 1; i <= k; i++) {
        ll v = p[i];
        ll u = p[i + 1];
        if (dist[v] != k - i && par[v].find(u) == par[v].end()) res.first++;
        if (dist[v] != k - i && !(cnt[v] == 1 && *par[v].begin() == u)) res.second++;
        if (dist[v] == k - i && !(cnt[v] == 1)) res.second++;
    }

    cout << res.first << sep << res.second << endl;
    return 0;
}