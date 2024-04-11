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
    template<typename C, typename T, typename OP> vector<T> prefixes(const C& v, T id, OP op) {
        vector<T> r(sz(v)+1, id); F0R (i, sz(v)) r[i+1] = op(r[i], v[i]); return r;
    }
    template<typename C, typename T, typename OP> vector<T> suffixes(const C& v, T id, OP op) {
        vector<T> r(sz(v)+1, id); F0Rd (i, sz(v)) r[i] = op(v[i], r[i+1]); return r;
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

/*
 * Accepts a sequence of operations inserting and deleting
 * elements of type T in a data structure of type D, and
 * a function "eval" on type D computing a result of type V.
 *
 * Computes and returns the results obtained when applying
 * the given operations sequentially.
 *
 * Requires D to expose a function to undo the most recently
 * performed insertions. Does not require D to support deletion
 * of arbitrary elements. Breaks amortized complexity.
 */
template<typename D, typename T, typename V>
vector<V> query_tree(D& ds, const vector<pair<bool, T>>& ops,
        const auto& apply, const auto& eval) {
    vi match(sz(ops), sz(ops));
    map<T, int> inserted;
    for (int op = 0; op < sz(ops); op++) {
        const auto &[ins, t] = ops[op];
        if (ins) inserted[t] = op;
        else {
            auto it = inserted.find(t);
            match[op] = it->second;
            match[it->second] = op;
            inserted.erase(it);
        }
    }

    vector<V> results(sz(ops) + 1);
    results[0] = eval(ds);

    auto dfs = [&](auto& self, int l, int r) -> void {
        if (r - l == 1) {
            if (match[l] > l) apply(ds, ops[l].second);
            results[r] = eval(ds);
            if (match[l] > l) ds.rewind(ds.opcount() - 1);
            return;
        }

        const int mid = (l + r) / 2;
        const int before = ds.opcount();

        if (l < mid) {
            for (int i = mid; i < r; i++)
                if (match[i] < l) apply(ds, ops[i].second);
            self(self, l, mid);
            ds.rewind(before);
        }

        if (mid < r) {
            for (int i = l; i < mid; i++)
                if (match[i] >= r) apply(ds, ops[i].second);
            self(self, mid, r);
            ds.rewind(before);
        }
    };
    dfs(dfs, 0, sz(ops));

    return results;
}

/// uf {{{
struct persistent_union_find {
    struct node {
        int par, rank, flip;
        node(int id = 0) : par(id), rank(0), flip(0) {}
        void operator +=(const node& o) {
            if (rank == o.rank) rank++;
        }
    };

    int N, ops;
    vector<node> dsu;
    vector<tuple<int, node, int, int>> history;

    persistent_union_find(int _N) : N(_N), ops(0) {
        for (int i = 0; i < N; i++)
            dsu.push_back(node(i));
    }

    int opcount() const { return ops; }
    int components() const { return N - sz(history); }

    pii rep(int i) const {
        int d = 0;
        while (i != dsu[i].par) {
            d ^= dsu[i].flip;
            i = dsu[i].par;
        }
        return {i, d};
    }

    int bad = 0;
    bool unio(int a, int b) {
        ops++;
        pii ar = rep(a), br = rep(b);
        if(ar.f == br.f) {
            if (ar.s == br.s) {
                bad++;
                history.emplace_back(ops, -1, -1, -1);
            }
            return false;
        }

        a = ar.f, b = br.f;
        if (dsu[a].rank < dsu[b].rank)
            swap(a, b);

        history.emplace_back(ops, dsu[a], a, b);
        dsu[a] += dsu[b];
        dsu[b].par = a;
        dsu[b].flip = ar.s == br.s;

        return true;
    }

    void rewind(int _ops) {
        for (ops = _ops; !history.empty(); history.pop_back()) {
            const auto &[op, av, a, b] = history.back();
            if (op <= ops) break;
            if (a == -1) { bad--; }
            else {
                dsu[a] = av;
                dsu[b].par = b;
            }
        }
    }
};
// }}}

int main() {
    setIO();

    int N, Q; re(N, Q);

    vpii ops(Q); re(ops);
    trav(e, ops) {
        e.f--, e.s--;
        if (e.f > e.s) swap(e.f, e.s);
    }

    vector<pair<bool, pii>> bops(Q);
    set<pii> active;
    F0R (i, Q) {
        auto it = active.find(ops[i]);
        if (it == active.end()) {
            bops[i] = {true, ops[i]};
            active.insert(ops[i]);
        } else {
            bops[i] = {false, ops[i]};
            active.erase(it);
        }
    }

    auto apply = [](persistent_union_find& uf, pii e){ uf.unio(e.f, e.s); };
    auto eval = [](persistent_union_find& uf){ return uf.bad == 0; };

    persistent_union_find uf(N);
    vb ans = query_tree<persistent_union_find, pii, bool>(uf, bops, apply, eval);
    F0R (i, Q) { ps(ans[i+1] ? "YES" : "NO"); }

    return 0;
}