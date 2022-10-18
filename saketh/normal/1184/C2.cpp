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

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define trav(x, ...) for (auto& __VA_ARGS__ : x)

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
using vpll = vector<pll>;
using vpdd = vector<pdd>;

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
    template<class T> void prContain(const T& x) {
        pr("{");
        bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0;
        pr("}");
    }
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

namespace __io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
}
using namespace __io;
// }}}

template<typename T, typename U, bool PROP = true> struct segment_tree_lazy {
    int S;
    vector<T> table;
    vb has; vector<U> ops;

    segment_tree_lazy(int _S) : S(_S) {
        table.resize(2 * S), has.resize(S), ops.resize(S);
    }

    segment_tree_lazy(auto begin, auto end) : segment_tree_lazy(distance(begin, end)) {
        copy(begin, end, table.begin() + S);
        for (int i = S - 1; i > 0; i--)
            table[i] = table[2 * i] + table[2 * i + 1];
    }

    void apply(int i, const U &op) {
        table[i] = op(table[i]);
        if (i < S) has[i] = true, ops[i] = op(ops[i]);
    }

    void rebuild(int i) {
        for (i /= 2; i; i /= 2)
            table[i] = ops[i](table[2 * i] + table[2 * i + 1]);
    }

    void propagate(int i) {
        for (int j = 31 - __builtin_clz(i); j > 0; j--) {
            if (int k = i >> j; has[k]) {
                apply(2 * k, ops[k]);
                apply(2 * k + 1, ops[k]);
                has[k] = false, ops[k] = U{};
            }
        }
    }

    void replace(int i, T v) {
        if (PROP) propagate(i + S);
        table[i + S] = v;
        rebuild(i + S);
    }

    void apply(int i, int j, U op) {
        i += S, j += S;
        if (PROP) propagate(i), propagate(j - 1);
        for (int l = i, r = j; l < r; l /= 2, r /= 2) {
            if (l&1) apply(l++, op);
            if (r&1) apply(--r, op);
        }
        rebuild(i), rebuild(j - 1);
    }

    T operator()(int i, int j) {
        i += S, j += S;
        if (PROP) propagate(i), propagate(j - 1);
        T left{}, right{};
        for (; i < j; i /= 2, j /= 2) {
            if (i&1) left = left + table[i++];
            if (j&1) right = table[--j] + right;
        }
        return left + right;
    }
    T operator()(int i) { return *this(i, i+1); }
};

struct node {
    int v;
    node(int _v = 0) : v(_v) {}
    node operator+(const node& o) const {
        return node(max(v, o.v));
    }
};
struct upd {
    int v;
    upd(int _v = 0) : v(_v) {}
    upd operator()(const upd& o) const {
        return upd(v + o.v);
    }
    node operator()(const node& o) const {
        return node(v + o.v);
    }
};

int main() {
    setIO();

    int N, R; re(N, R); vpii pts(N); re(pts);
    trav (pts, [x, y]) {
        x += 1e6, y += 1e6;
        tie(x, y) = mp(x+y, x-y);
    }
    sort(all(pts));

    segment_tree_lazy<node, upd> st(6e6 + 5);
    int ans = 0, j = 0;
    F0R (i, N) {
        st.apply(pts[i].s, pts[i].s + 2 * R + 1, upd(1));
        while (j < i && pts[j].f < pts[i].f - 2 * R) {
            st.apply(pts[j].s, pts[j].s + 2 * R + 1, upd(-1));
            j++;
        }
        ckmax(ans, st(0, st.S).v);
    }
    ps(ans);

    return 0;
}