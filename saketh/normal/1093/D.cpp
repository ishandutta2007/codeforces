#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<int MOD> struct modnum {
    int v;
    modnum() : v(0) {}
    modnum(ll _v) : v(_v % MOD) { if (v < 0) v += MOD; }
    explicit operator int() const { return v; }
    friend ostream& operator << (ostream& o, const modnum& n) { return o << n.v; }
    friend istream& operator << (istream& i, modnum& n) { ll v; i >> v; n = modnum(v); return i; }

    friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
    friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

    modnum& operator += (const modnum& o) { v += o.v; if (v >= MOD) v -= MOD; return *this; }
    modnum& operator -= (const modnum& o) { v -= o.v; if (v < 0) v += MOD; return *this; }
    modnum& operator *= (const modnum& o) { v = int(ll(v) * ll(o.v) % MOD); return *this; }
    modnum operator - () { modnum res; if (v) res.v = MOD - v; return res; }
    friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
    friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
    friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }

    modnum pow(int e) const {
        if (e == 0) return 1;
        if (e & 1) return *this * this->pow(e-1);
        return (*this * *this).pow(e/2);
    }

    /* requires prime MOD */
    modnum& operator /= (const modnum& o) { return (*this) *= o.pow(MOD - 2); }
    friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= modnum(b); }
};
using mn = modnum<998244353>;

void assign(vvi& adj, vi& color, int& c0, int& c1, int loc, int col) {
    color[loc] = col;
    if (col) c1++;
    else c0++;

    for (int nbr : adj[loc]) if (color[nbr] == -1) {
        assign(adj, color, c0, c1, nbr, !col);
    }
}

void solve() {
    int N, M;
    cin >> N >> M;

    vvi adj(N);
    for (int e = 0; e < M; e++) {
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    vi color(N, -1);
    vector<pair<int, int>> comps;
    for (int i = 0; i < N; i++) {
        if (color[i] != -1) continue;
        int c0 = 0, c1 = 0;
        assign(adj, color, c0, c1, i, 0);
        comps.emplace_back(c0, c1);
    }

    for (int u = 0; u < N; u++) {
        for (int v : adj[u]) {
            if (color[u] == color[v]) {
                cout << 0 << "\n";
                return;
            }
        }
    }

    mn ans = 1;
    for (auto [c0, c1] : comps) {
        mn cc = mn(2).pow(c0) * mn(1).pow(c1)
              + mn(1).pow(c0) * mn(2).pow(c1);
        ans *= cc;
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}