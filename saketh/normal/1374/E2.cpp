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
using ld = long double;
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

template<typename T> using max_heap = priority_queue<T>;
template<typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

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

namespace __numeric {
    template<typename T>
    typename enable_if<is_integral<T>::value, T>::type floor(T n, T d) {
        assert(d != 0);
        if (d < 0) tie(n, d) = mp(-n, -d);
        return n / d - ((n < 0) && (n % d));
    }
    template<typename T>
    typename enable_if<is_integral<T>::value, T>::type ceil(T n, T d) {
        assert(d != 0);
        if (d < 0) tie(n, d) = mp(-n, -d);
        return n / d + ((n > 0) && (n % d));
    }
};
using namespace __numeric;

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

// binary_indexed_tree {{{
template<typename T> struct binary_indexed_tree {
    int S;
    vector<T> table;

    binary_indexed_tree<T>(int _S = 0) : S(_S) {
        table.resize(S+1);
    }

    // Adds v to the element at index i
    void add(int i, T v) {
        for (i++; i <= S; i += i&-i)
            table[i] = table[i] + v;
    }

    // Replaces the element at index i with v
    void replace(int i, T v) {
        add(i, v - sum(i, i+1));
    }

    // Returns the sum of the elements at indices in [0, i)
    T sum(int i) const {
        T res{};
        for (; i; i -= i&-i)
            res = res + table[i];
        return res;
    }

    // Returns the sum of the elements at indices in [l, r)
    T sum(int l, int r) const {
        return l > r ? T{} : sum(r) - sum(l);
    }

    /*
     * Returns the first i in [0, S] such that comp(sum(i)) is true.
     * Returns -1 if no such i exists.
     * Requires that comp(sum(i)) is non-decreasing in i.
     * The empty prefix is considered to have sum equal to T().
     */
    int lower_bound(const auto& comp) const {
        T cur = T{};
        if (comp(cur)) return 0;

        int inx = 0;
        for (int i = 31 - __builtin_clz(S); i >= 0; i--) {
            int nxt = inx + (1 << i);
            if (nxt <= S && !comp(cur + table[nxt])) {
                inx = nxt;
                cur = cur + table[nxt];
            }
        }

        return inx < S ? inx + 1 : -1;
    }
};
// }}}

int main() {
    setIO();

    int N, M, K; re(N, M, K);

    vvpii have(4);
    F0R (i, N) {
        int t, a, b; re(t, a, b);
        have[2 * a + b].eb(t, i);
    }
    F0R (t, 4) sort(all(have[t]));

    const int MAXT = 1e4 + 1;
    binary_indexed_tree<int> ct(MAXT), sum(MAXT);

    int cand = 0;
    F0R (t, 4) trav (e, have[t]) cand += e.f;

    auto put = [&](int v, bool neg) {
        ct.add(v, neg ? -1 : 1);
        sum.add(v, neg ? -v : v);
        if (neg) cand += v;
        else cand -= v;
    };
    F0R (t, 3) trav (e, have[t]) put(e.f, false);

    pii ans{INT_MAX, -1};
    F0Rd (take_both, N + 1) {
        if (take_both < sz(have[3]))
            put(have[3][take_both].f, false);

        int need_single = K - take_both;
        if (need_single < 0)
            continue;
        if (need_single > min(sz(have[1]), sz(have[2])))
            break;

        if (need_single) {
            put(have[1][need_single - 1].f, true);
            put(have[2][need_single - 1].f, true);
        }

        int remain = M - take_both - 2 * need_single;
        if (take_both > sz(have[3]) || remain < 0) continue;

        int inx = ct.lower_bound([&](int s) { return s >= remain; });
        if (inx == -1) continue;

        int total = cand + sum.sum(inx) - (ct.sum(inx) - remain) * (inx - 1);
        ckmin(ans, mp(total, take_both));
    }

    if (ans.s == -1) {
        ps(-1);
        return 0;
    }

    int take_both = ans.s;
    int need_single = K - take_both;

    array<int, 4> qty = { 0, need_single, need_single, take_both };

    vi took;
    vpii rest;
    F0R (t, 4) F0R (i, sz(have[t])) {
        if (i < qty[t]) took.pb(have[t][i].s + 1);
        else rest.eb(have[t][i]);
    }

    int remain = M - take_both - 2 * need_single;
    sort(all(rest));
    F0R (i, remain) took.pb(rest[i].s + 1);

    ps(ans.f);
    pc(took);


    // did you check N=1? did you mix up N,M?
    // check your "infinity" and "null" values against the bounds
    return 0;
}