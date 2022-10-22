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

const ll MAXN = 6e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

vector<ll> adj[MAXN];
ll A[MAXN] = {0}, ind[MAXN];
bool vis[MAXN] = {false};
ll n, m;

bool cmp(ll i, ll j) {
    return A[i] < A[j];
}

void kill() {
        cout << -1 << endl;
        exit(0);
}

void DFS(ll v) {
    vis[v] = true;
    ll c = A[v];
    bool b = false;

    ll i = 1;
    for (ll u : adj[v]) {
        if (A[u] == i) i++;
        if (vis[u]) continue;
        DFS(u);
    }

    if (i != c) kill();
}

int main() {
    fast_io;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) cin >> A[i];
    for (int i = 1; i <= n; i++) ind[i] = i;

    for (int i = 1; i <= n; i++) {
        sort(all(adj[i]), cmp);
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        DFS(i);
    }

    sort(ind + 1, ind + n + 1, cmp);
    for (int i = 1; i <= n; i++) cout << ind[i] << sep;
    cout << endl;
    return 0;
}