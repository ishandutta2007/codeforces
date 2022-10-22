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

ll n, m, col[MAXN];
vector<ll> adj[MAXN];

void DFS(ll v) {
    for (ll u : adj[v]) {
        if (col[u] == col[v]) {
            cout << "-1" << endl, 0;
            exit(0);
        }

        if (col[u] == INF) {
            col[u] = !col[v];
            DFS(u);
        }
    }
}

int main() {
    fill(col, col + MAXN, INF);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (col[i] == INF) {
            col[i] = 0;
            DFS(i);
        }
    }

    vector<ll> st1, st2;
    for (int i = 1; i <= n; i++) {
        if (col[i]) st1.push_back(i);
        else st2.push_back(i);
    }

    cout << st1.size() << endl;
    for (ll e : st1) cout << e << sep;
    cout << endl;
    cout << st2.size() << endl;
    for (ll e : st2) cout << e << sep;
    cout << endl;
}