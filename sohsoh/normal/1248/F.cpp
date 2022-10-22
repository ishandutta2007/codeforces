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

ll n = 0, m;
vector<ll> adj[MAXN], rev_adj[MAXN];
set<ll> ans;

void DFS1(ll v) {
    ans.insert(v);
    for (ll u : adj[v]) if (ans.find(u) == ans.end()) DFS1(u);
}


void DFS2(ll v) {
    ans.insert(v);
    for (ll u : rev_adj[v]) if (ans.find(u) == ans.end()) DFS2(u);
}

ll solve() {
    for (int i = 0; i <= n + 2; i++) {
        adj[i].clear();
        rev_adj[i].clear();
    }
    ans.clear();

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        rev_adj[v].push_back(u);
    }

    DFS1(1);
    if (ans.size() < n) {
        cout << "YES" << endl;
        cout << ans.size() << sep << n - ans.size() << endl;
        for (ll e : ans) cout << e << sep; cout << endl;
        for (int i = 1; i <= n; i++) if (ans.find(i) == ans.end()) cout << i << sep; cout << endl;
        return 0;
    }

    ans.clear();
    DFS2(1);
    if (ans.size() < n) {
        cout << "YES" << endl;
        cout << n - ans.size() << sep << ans.size() << endl;
        for (int i = 1; i <= n; i++) if (ans.find(i) == ans.end()) cout << i << sep; cout << endl;
        for (ll e : ans) cout << e << sep; cout << endl;
        return 0;
    }

    return cout << "NO" << endl, 0;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}