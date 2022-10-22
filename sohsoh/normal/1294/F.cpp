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
#define SZ(x)                       ll(x.size())
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define debug2(x)                   cerr << #x << ": " <<  x <<  " ";
#define debug_p(x)                  cerr << #x << ": " <<  x.X <<  " " << x.Y << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define FOR(n)                      for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define kill(x)                     return cout << x << endl, 0;

ll poww(ll a, ll b, ll md) {
    if (b == -1) return poww(a, md - 2, md);
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n;
vector<ll> adj[MAXN];
ll par[MAXN];
ll dist[MAXN] = {0};

void DFS(ll v, ll p = 0) {
    par[v] = p;
    for (ll u : adj[v]) if (u != p) DFS(u, v);
}

pll DFS2(ll v, ll p = 0, ll d = 0) {
    pll x = {d, v};
    for (ll u : adj[v]) if (u != p) x = max(DFS2(u, v, d + 1), x);
    return x;
}

int main() {
//    fast_io;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    fill(dist, dist + MAXN, INF);

    pll ab = {-1, -1};
    ab.X = DFS2(1).Y;
    ab.Y = DFS2(ab.X).Y;

    DFS(ab.X);
    dist[ab.X] = 0;
    ll l = 0;
    ll x = ab.Y;

    queue<ll> path;
    path.push(ab.X);
    while (x != ab.X) {
        l++;
        path.push(x);
        dist[x] = 0;
        x = par[x];
    }

    while (!path.empty()) {
        ll v = path.front();
        path.pop();
        dist[v] = 0;
        queue<ll> q;
        q.push(v);

        while (!q.empty()) {
            v = q.front();
            q.pop();

            for (ll u : adj[v]) {
                if (dist[u] == INF) {
                    dist[u] = dist[v] + 1;
                    q.push(u);
                }
            }
        }
    }

    ll bf = 0;
    ll bfi = 1;
    while (ab.X == bfi || ab.Y == bfi) bfi++;
    for (int i = 1; i <= n; i++) {
        if (i == ab.X || i == ab.Y) continue;
        if (dist[i] != INF) {
            if (dist[i] > bf) {
                bf = dist[i];
                bfi = i;
            }
        }
    }

    cout << l + bf << endl;
    cout << ab.X << " " << ab.Y << sep << bfi << endl;
    return 0;
}