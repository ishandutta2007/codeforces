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

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

vector<ll> adj[MAXN], adj2[MAXN];
ll n, m;
ll dist[MAXN];
ll status[MAXN];
bool col[MAXN], vis2[MAXN] = {false};

ll to_num(ll i, ll j) {
    return m * i + j;
}

pll from_num(ll x) { return {x / m, x % m}; }

void clearify() {
    for (int i = 0; i <= n * m; i++) {
        adj[i].clear();
        adj2[i].clear();
        dist[i] = INF;
        vis2[i] = false;
    }
}

pll DFS(ll v, ll lev = 0) {
    vis2[v] = true;
    for (ll u : adj[v]) {
        if (vis2[u]) return {u, lev + 1};
        pll ans = DFS(u, lev + 1);
        if (ans.X == v) return {v, ans.Y - lev};
        return ans;
    }

    return {-1, -1}; //just for fun :)
}

void BFS(ll v, ll len) {
    queue<ll> q;
    q.push(v);
    dist[v] = 0;
    status[0] = col[v] + 1;
    while (!q.empty()) {
        ll v = q.front();
        q.pop();
        for (ll u : adj2[v]) {
            if (dist[u] != INF) continue;
            dist[u] = (dist[v] + 1) % len;
            status[dist[u]] = max(status[dist[u]], 1ll + col[u]);
            q.push(u);
        }
    }
}

ll solve() {
    cin >> n >> m;
    ll ans1 = 0, ans2 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            col[to_num(i, j)] = (c == '0');
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            ll u = to_num(i, j);
            ll v = u;
            if (c == 'U') v = u - m;
            if (c == 'D') v = u + m;
            if (c == 'L') v = u - 1;
            if (c == 'R') v = u + 1;
            adj[u].push_back(v);
            adj2[v].push_back(u);
        }
    }

    for (int i = 0; i < n * m; i++) {
        if (dist[i] == INF) {
            vis2[i] = true;
            pll ans = DFS(i);
            BFS(ans.X, ans.Y);
//            debug(i)
//            debug(ans.X)
//            debug(ans.Y)
            for (int j = 0; j <= ans.Y; j++) {
                if (status[j] == 2) ans2++;
                else if (status[j]) ans1++;
                status[j] = 0;
            }
        }
    }

    cout << ans1 + ans2 << sep << ans2 << endl;

    clearify();
    return 0;
}

int main() {
    fast_io;
    fill(dist, dist + MAXN, INF);
    ll t;
    cin >> t;
    while (t--) solve();
}