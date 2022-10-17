#include <bits/stdc++.h>
using namespace std;

// template {{{
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#define f first
#define s second
#define resz resize

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)

#define sort_by(x, y) sort(all(x), [&](const auto& a, const auto& b) { return y; })

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;

using vpii = vector<pii>;
using vvpii = vector<vpii>;
using vpll = vector<pll>;
using vvpll = vector<vpll>;
using vpdd = vector<pdd>;
using vvpdd = vector<vpdd>;

template<typename T> void ckmin(T& a, const T& b) { a = min(a, b); }
template<typename T> void ckmax(T& a, const T& b) { a = max(a, b); }

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

namespace __input {
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);

    template<class T> void re(T& x) { cin >> x; }
    void re(double& x) { string t; re(t); x = stod(t); }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) {
        re(first); re(rest...);
    }

    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
}
using namespace __input;

namespace __output {
    template<class T1, class T2> void pr(const pair<T1,T2>& x);
    template<class T, size_t SZ> void pr(const array<T,SZ>& x);
    template<class T> void pr(const vector<T>& x);
    template<class T> void pr(const set<T>& x);
    template<class T1, class T2> void pr(const map<T1,T2>& x);

    template<class T> void pr(const T& x) { cout << x; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) {
        pr(first); pr(rest...);
    }

    template<class T1, class T2> void pr(const pair<T1,T2>& x) {
        pr("{",x.f,", ",x.s,"}");
    }
    template<class T, bool pretty = true> void prContain(const T& x) {
        if (pretty) pr("{");
        bool fst = 1; for (const auto& a: x) pr(!fst?pretty?", ":" ":"",a), fst = 0;
        if (pretty) pr("}");
    }
    template<class T> void pc(const T& x) { prContain<T, false>(x); pr("\n"); }
    template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
    template<class T> void pr(const vector<T>& x) { prContain(x); }
    template<class T> void pr(const set<T>& x) { prContain(x); }
    template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }

    void ps() { pr("\n"); }
    template<class Arg> void ps(const Arg& first) {
        pr(first); ps();
    }
    template<class Arg, class... Args> void ps(const Arg& first, const Args&... rest) {
        pr(first," "); ps(rest...);
    }
}
using namespace __output;

#define TRACE(x) x
#define __pn(x) pr(#x, " = ")
#define pd(...) __pn((__VA_ARGS__)), ps(__VA_ARGS__), cout << flush

namespace __algorithm {
    template<typename T> void dedup(vector<T>& v) {
        sort(all(v)); v.erase(unique(all(v)), v.end());
    }
    template<typename T> typename vector<T>::iterator find(vector<T>& v, const T& x) {
        auto it = lower_bound(all(v), x); return it != v.end() && *it == x ? it : v.end();
    }
    template<typename T> size_t index(vector<T>& v, const T& x) {
        auto it = find(v, x); assert(it != v.end() && *it == x); return it - v.begin();
    }

    template<typename C, typename T> vector<T> prefixes(const C& v, T zero) {
        vector<T> res(sz(v) + 1, zero); F0R (i, sz(v)) res[i+1] = res[i] + v[i]; return res;
    }
    template<typename C, typename T> vector<T> suffixes(const C& v, T zero) {
        vector<T> res(sz(v) + 1, zero); F0Rd (i, sz(v)) res[i] = v[i] + res[i+1]; return res;
    }
}
using namespace __algorithm;

struct monostate {
    friend istream& operator>>(istream& is, const __attribute__((unused))monostate& ms) { return is; }
    friend ostream& operator<<(ostream& os, const __attribute__((unused))monostate& ms) { return os; }
} ms;

template<typename W=monostate> struct wedge {
    int u, v, i; W w;
    wedge<W>(int _u=-1, int _v=-1, int _i=-1) : u(_u), v(_v), i(_i) {}
    int operator[](int loc) const { return u ^ v ^ loc; }
    friend void re(wedge& e) { re(e.u, e.v, e.w); --e.u, --e.v; }
    friend void pr(const wedge& e) { pr(e.u, "<-", e.w, "->", e.v); }
};

namespace __io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.precision(15);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
}
using namespace __io;
// }}}

template<typename T, typename I> struct persistent_segment_tree {
    using F = function<T(const T&, const T&)>;

    size_t SZ;
    F combine;
    vector<vector<pair<I, T>>> table;

    T get(int i) const { return sz(table[i]) ? table[i].back().s : T{}; }
    T get(int i, I w) const {
        static auto cmp = [](const pair<I, T>& a, const pair<I, T>& b) { return a.f < b.f; };
        auto it = ub(all(table[i]), mp(w, T{}), cmp);
        return it != table[i].begin() ? prev(it)->s : T{};
    }

    persistent_segment_tree<T, I>(size_t _SZ, F combine) : SZ(_SZ), combine(combine) {
        table.resize(2 * SZ);
        //FORd (i, SZ, sz(table)) table[i].reserve(1);
        //FORd (i, 1, SZ) table[i].reserve(table[2*i].capacity() + table[2*i+1].capacity());
    }

    void replace(int i, T v, I w) {
        table[i += SZ].eb(w, v);
        for (i /= 2; i; i /= 2)
            table[i].eb(w, combine(get(2 * i), get(2 * i + 1)));
    }

    T operator[](int i) const { return get(SZ + i); }

    T operator()(int i, int j, I w) const {
        T left{}, right{};
        for (i += SZ, j += SZ; i < j; i /= 2, j /= 2) {
            if (i&1) left = combine(left, get(i++, w));
            if (j&1) right = combine(get(--j, w), right);
        }
        return combine(left, right);
    }
};

int main() {
    setIO();

    int N, R; re(N, R); --R; vi a(N); re(a);

    vvi adj(N);
    F0R (i, N-1) {
        int u, v; re(u, v); --u, --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vi depth(N), st(N), en(N); int T = 0;
    auto dfs = [&](auto& self, int loc, int par, int dep) -> void {
        depth[loc] = dep;
        st[loc] = T++;
        trav (nbr, adj[loc]) if (nbr != par) {
            self(self, nbr, loc, dep+1);
        }
        en[loc] = T;
    };
    dfs(dfs, R, R, 0);

    vi nodes(N); F0R (i, N) nodes[i] = i;
    sort_by(nodes, depth[a] < depth[b]);

    struct mint { int v = INT_MAX; };
    persistent_segment_tree<mint, int> ds(N, [](const mint& a, const mint& b){ return a.v < b.v ? a : b; });
    F0R (i, N) { ds.replace(st[nodes[i]], mint{a[nodes[i]]}, depth[nodes[i]]); }

    int Q; re(Q); ll last = 0;
    F0R (qi, Q) {
        int p, q; re(p, q);
        p = (p + last) % N;
        q = (q + last) % N;
        ps(last = ds(st[p], en[p], depth[p] + q).v);
    }

    return 0;
}