#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define FORR(i, n) for(ll i = (ll)n - 1LL; i >= 0LL; i--)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) begin(x), end(x)
using namespace std;
using ll = long long;
constexpr ll Mod = 998244353;
constexpr ll mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;
const double PI = acos(-1);
template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) {
    return a < b && (a = b, true);
}
template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) {
    return a > b && (a = b, true);
}
/*-------------------------------------------*/

int n;
vector<vector<int>> G;
vector<ll> p, h;

vector<ll> m;

bool dfs(int v, int par) {
    for(auto &&u : G[v])
        if(u != par) {
            if(!dfs(u, v)) return false;
            p[v] += p[u];
            m[v] += m[u];
        }
    if(abs(p[v] - m[v]) % 2 != abs(h[v]) % 2) return false;
    if(m[v] - p[v] > h[v]) return false;

    ll x = (m[v] - p[v] - h[v]) / 2;
    p[v] += x;
    m[v] -= x;
    return p[v] >= 0 && m[v] >= 0;
}

void solve() {
    cin >> n;
    int aaaa;
    cin >> aaaa;
    G.assign(n, vector<int>());
    p.resize(n);
    h.resize(n);
    m.assign(n, 0);
    rep(i, n) cin >> p[i];
    rep(i, n) cin >> h[i];
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    cout << (dfs(0, -1) ? "YES" : "NO") << "\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}