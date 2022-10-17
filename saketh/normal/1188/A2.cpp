#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

#define FOR(i, a, b)    for (int i = (a); i < (b); i++)
#define F0R(i, a)       for (int i = 0; i < (a); i++)
#define FORd(i, a, b)   for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i, a)      for (int i = (a)-1; i >= 0; i--)
#define trav(a, x)      for (auto& a : x)

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;

template<typename T> void ckmin(T& a, const T& b) { a = min(a, b); }
template<typename T> void ckmax(T& a, const T& b) { a = max(a, b); }

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

namespace __input {
    template<typename T1, typename T2> istream& operator >>(istream& i, pair<T1, T2>& p) {
        i >> p.first >> p.second; return i;
    }
    template<typename T, size_t N> istream& operator >>(istream& i, array<T, N>& v) {
        for (auto& e : v) { i >> e; } return i;
    }
    template<typename T> istream& operator >>(istream& i, vector<T>& v) {
        for (auto& e : v) { i >> e; } return i;
    }
}
using namespace __input;

namespace __output {
    template<typename T1, typename T2> ostream& operator<<(ostream& o, const pair<T1, T2>& t) {
        return o << "(" << t.first << ", " << t.second << ")";
    }
    template<typename T, size_t N> ostream& operator<<(ostream& o, const array<T, N>& a) {
        o << "["; for (int i = 0; i < N; i++) { if (i) o << ", "; o << a[i]; } return o << "]";
    }
    template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
        o << "["; for (int i = 0; i < sz(v); i++) { if (i) o << ", "; o << v[i]; } return o << "]";
    }
}
using namespace __output;

struct edge { int u, v; ll x; };
vector<edge> ops;

int go(vvi& adj, auto& edges, int loc, int inc, int root, ll wt) {
    if (loc != root && sz(adj[loc]) == 1) {
        ops.pb({ loc, root, wt });
        return loc;
    }

    vi leaves;
    ll sum = 0;

    trav (ei, adj[loc]) if (ei != inc) {
        auto e = edges[ei];
        int nbr = e.u + e.v - loc;
        sum += e.x;
        leaves.pb(go(adj, edges, nbr, ei, root, e.x));
    }

    if (loc != root && sum != wt) {
        ll add = wt - sum;
        ops.pb({ leaves[0], root, add / 2 });
        ops.pb({ leaves[1], root, add / 2 });
        ops.pb({ leaves[0], leaves[1], -add / 2 });
    }
    return leaves.front();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;
    vector<edge> edges(N - 1);

    vvi adj(N);
    F0R (ei, N - 1) {
        auto& e = edges[ei];
        cin >> e.u >> e.v >> e.x;
        adj[--e.u].pb(ei);
        adj[--e.v].pb(ei);
    }

    trav (v, adj) if (sz(v) == 2) { cout << "NO\n"; return 0; }

    int leaf = 0;
    while (sz(adj[leaf]) != 1) leaf++;

    go(adj, edges, leaf, -1, leaf, -1);

    cout << "YES\n" << sz(ops) << "\n";
    for (auto& [u, v, x] : ops) {
        cout << u + 1 << " " << v + 1 << " " << x << "\n";
    }

    return 0;
}