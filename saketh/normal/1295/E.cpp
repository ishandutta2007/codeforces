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
    template<class T> void pr(const deque<T>& x);
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
    template<class T> void pr(const deque<T>& x) { prContain(x); }
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

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
struct monostate {
    friend istream& operator>>(istream& is, const monostate& ms) { return is; }
    friend ostream& operator<<(ostream& os, const monostate& ms) { return os; }
    friend monostate operator+(const monostate& a, const monostate& b) { return a; }
} ms;
#pragma GCC diagnostic pop

namespace __io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        cout << fixed << setprecision(15);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
}
using namespace __io;
// }}}

// segment_tree_lazy {{{
template<typename T, typename U, typename TT, typename UU, typename UT>
struct segment_tree_lazy {
    int SZ;
    T tid; U uid; TT tt; UU uu; UT ut;
    vector<T> table;
    vb has; vector<U> ops;

    segment_tree_lazy() {}
    segment_tree_lazy(int _SZ, T _tid, U _uid, TT _tt, UU _uu, UT _ut)
            : tid(_tid), uid(_uid), tt(_tt), uu(_uu), ut(_ut) {
        init(_SZ);
    }
    void init(int _SZ) {
        SZ = _SZ;
        table.resize(2 * SZ, tid), has.resize(SZ), ops.resize(SZ, uid);
    }
    template<typename L> void set_leaves(L create) {
        F0R (i, SZ) table[SZ + i] = create(i);
        FORd (i, 1, SZ) table[i] = tt(table[2 * i], table[2 * i + 1]);
    }

    void _apply(int i, const U &op) {
        table[i] = ut(op, table[i]);
        if (i < SZ) has[i] = true, ops[i] = uu(op, ops[i]);
    }
    void _rebuild(int i) {
        for (i /= 2; i; i /= 2)
            table[i] = ut(ops[i], tt(table[2 * i], table[2 * i + 1]));
    }
    void _propagate(int i) {
        for (int j = 31 - __builtin_clz(i); j > 0; j--) {
            int k = i >> j;
            if (has[k]) {
                _apply(2 * k, ops[k]);
                _apply(2 * k + 1, ops[k]);
                has[k] = false, ops[k] = uid;
            }
        }
    }

    // Replaces the element at index i with v
    void replace(int i, T v) {
        i += SZ;
        _propagate(i);
        table[i] = v;
        _rebuild(i);
    }

    // Applies op to the elements at indices in [i, j)
    void operator()(int i, int j, U op) {
        i += SZ, j += SZ;
        _propagate(i), _propagate(j - 1);
        for (int l = i, r = j; l < r; l /= 2, r /= 2) {
            if (l&1) _apply(l++, op);
            if (r&1) _apply(--r, op);
        }
        _rebuild(i), _rebuild(j - 1);
    }

    // Returns the element at index i
    const T& operator[](int i) {
        i += SZ;
        _propagate(i);
        return table[i];
    }

    // Accumulates the elements at indices in [i, j)
    T operator()(int i, int j) {
        i += SZ, j += SZ;
        _propagate(i), _propagate(j - 1);
        T left = tid, right = tid;
        for (; i < j; i /= 2, j /= 2) {
            if (i&1) left = tt(left, table[i++]);
            if (j&1) right = tt(table[--j], right);
        }
        return tt(left, right);
    }
};
// }}}

int main() {
    setIO();

    int N; re(N); vi p(N), a(N); re(p, a); trav (e, p) --e;

    const ll INF = LLONG_MAX / 4;

    using nv_t = ll;
    struct n { nv_t lo; /*int ix;*/ };
    using u = nv_t;
    auto nn = [](n a, n b) { return n{ min(a.lo, b.lo) }; /*, a.lo <= b.lo ? a.ix : b.ix };*/ };
    auto uu = plus<nv_t>();
    auto un = [](u U, n N) { N.lo += U; return N; };

    segment_tree_lazy st(N + 1, n{INF}, 0ll, nn, uu, un);

    vll costs(N); F0R (i, N) costs[p[i]] = a[i];
    vll cost_pref = prefixes(costs, 0ll, plus<ll>());

    // initially "left" is empty and "right" is full
    st.set_leaves([&](int cutoff){
        // everything smaller than cutoff on the right moves
        return n{cost_pref[cutoff]};
    });

    ll ans = INF;
    F0R (i, N - 1) {
        // move ith element from "right" to "left"
        int val = p[i];
        // cutoffs greater than val no longer penalized
        st(val+1, st.SZ, -costs[val]);
        // cutoffs leq than val now penalized
        st(0, val+1, +costs[val]);

        ckmin(ans, st(0, st.SZ).lo);
    }

    ps(ans);

    // did you check N=1? did you mix up N,M?
    // check your "infinity" and "null" values against the bounds
    return 0;
}