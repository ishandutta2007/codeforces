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
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 99824353; // 1e9 + 9;

vector<ll> adj[MAXN];

int main() {
    ll n, m;
    cin >> n >> m;
    if (n < 7) return cout << m << endl, 0;
    for (int i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll ans = 0;
    for (int i = 1; i <= 6; i++) {
        for (int u = 1; u < 8; u++) {
            for (int v = u + 1; v < 8; v++) {
                set<ll> st;
                for (ll e : adj[v]) st.insert(e);
                for (ll e : adj[u]) st.insert(e);
                ans = max(ans, m + ll(st.size()) - ll(adj[v].size()) - ll(adj[u].size()));
            }
        }
    }

    cout << ans << endl;
    return 0;
}