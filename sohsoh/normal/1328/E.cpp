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

vector<int> adj[MAXN];
ll tin[MAXN], tout[MAXN];

int par[MAXN];

ll t = 0;
void DFS(int v = 1, int p = -1) {
    if (v == 1) par[v] = 1;
    else par[v] = p;
    t++;
    tin[v] = t;

    for (int u : adj[v]) {
        if (u != p) DFS(u, v);
    }

    tout[v] = t;
}

bool tin_comp(int a, int b) {
    return tin[a] < tin[b];
}

int solve() {
    ll n;
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i] = par[a[i]];
    }
    sort(a, a + n, tin_comp);
    for (int i = 0; i < n - 1; i++) {
        if (tout[a[i]] < tout[a[i + 1]]) {
            return cout << "NO" << endl, 0;
        }
    }

    return cout << "YES" << endl, 0;
}

int main() {
    fast_io;

    ll n, m;
    cin >> n >> m;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS();

    while (m--) solve();
    return 0;
}