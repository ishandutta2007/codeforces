/*
    Soheil Mohammadkhani
    i'm sad :(
    aghayi ke dari in code ro mikhooi, in kod copyie :|
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

set<ll> adj[27];
bool vis[27] = {false};

string res = "";
void DFS(ll v, ll par) {
    res.push_back(v + 'a');
    for (ll u : adj[v]) if (u != par) DFS(u, v);
}

ll solve() {
    string s;
    cin >> s;
    res = "";
    fill(vis, vis + 27, false);
    for (int i = 0; i < 27; i++) adj[i].clear(); // preset
    char p = s[0];
    for (char c : s) {
        if (c == p) continue;
        adj[c - 'a'].insert(p - 'a');
        adj[p - 'a'].insert(c - 'a');

        p = c;
    }

    ll root = -1;
    ll no_one = 0;
    for (int i = 0; i < 27; i++) {
        if (SZ(adj[i]) > 2) return cout << "NO" << endl, 0;
        if (SZ(adj[i]) == 1) root = i, no_one++;
    }

    if (root == -1 && SZ(s) > 1) return cout << "NO" << endl, 0;
    if (SZ(s) > 1) DFS(root, -1);
    cout << "YES" << endl;
    for (int i = 0; i < 26; i++) {
        if (SZ(adj[i]) == 0) {
            res.push_back(char(i + 'a'));
        }
    }

    cout << res << endl;

    return 0;
}

int main() {
    fast_io;

    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}