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
    template<typename T> typename vector<T>::const_iterator find(const vector<T>& v, const T& x) {
        auto it = lower_bound(all(v), x); return it != v.end() && *it == x ? it : v.end();
    }
    template<typename T> size_t index(const vector<T>& v, const T& x) {
        auto it = find(v, x); assert(it != v.end() && *it == x); return it - v.begin();
    }

    template<typename T1, typename T2> typename vector<pair<T1, T2>>::iterator lower_bound(
            const vector<pair<T1, T2>>& v, const T1& x) {
        return lower_bound(all(v), x, [](pair<T1, T2> a, pair<T1, T2> b) { return a.f < b.f; });
    }
    template<typename T1, typename T2> typename vector<pair<T1, T2>>::iterator upper_bound(
            const vector<pair<T1, T2>>& v, const T1& x) {
        return upper_bound(all(v), x, [](pair<T1, T2> a, pair<T1, T2> b) { return a.f < b.f; });
    }
}
using namespace __algorithm;

struct __monostate {
    friend istream& operator>>(istream& is, const __attribute__((unused))__monostate& ms) { return is; }
    friend ostream& operator<<(ostream& os, const __attribute__((unused))__monostate& ms) { return os; }
} ms;

namespace __io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        cout << setprecision(15);
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
    segment_tree_lazy(int SZ_, T tid_, U uid_, TT tt_, UU uu_, UT ut_)
            : tid(tid_), uid(uid_), tt(tt_), uu(uu_), ut(ut_) {
        init(SZ_);
    }
    void init(int SZ_) {
        SZ = SZ_;
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

const int s0 = 0, s1 = 1, s01 = 2, s10 = 3;

struct node {
    int W = 0;
    array<int, 4> L = {0,0,0,0};
    array<int, 4> R = {0,0,0,0};
    array<int, 2> I = {0,0};

    node() {}

    node(char dir) {
        W = 1;
        if (dir == '<') {
            L = {0,1,1,1};
            R = {0,1,1,1};
        } else {
            L = {1,0,1,1};
            R = {1,0,1,1};
        }
        I = {1,1};
    }

    node(int W_, array<int, 4> L_, array<int, 4> R_, array<int, 2> I_) : W(W_), L(L_), R(R_), I(I_) {}
};

auto nn = [](node a, node b) {
    node res {
        a.W + b.W,
        { a.L[s0] + (a.L[s0] == a.W ? b.L[s0] : 0),
          a.L[s1] + (a.L[s1] == a.W ? b.L[s1] : 0),
          max(a.L[s01] + (a.L[s01] == a.W ? b.L[s1] : 0), a.L[s0] + (a.L[s0] == a.W ? b.L[s01] : 0)),
          max(a.L[s10] + (a.L[s10] == a.W ? b.L[s0] : 0), a.L[s1] + (a.L[s1] == a.W ? b.L[s10] : 0)),
        },
        {
            b.R[s0] + (b.R[s0] == b.W ? a.R[s0] : 0),
            b.R[s1] + (b.R[s1] == b.W ? a.R[s1] : 0),
            max(b.R[s01] + (b.R[s01] == b.W ? a.R[s0] : 0), b.R[s1] + (b.R[s1] == b.W ? a.R[s01] : 0)),
            max(b.R[s10] + (b.R[s10] == b.W ? a.R[s1] : 0), b.R[s0] + (b.R[s0] == b.W ? a.R[s10] : 0)),
        },
        {
            max({ a.I[0], b.I[0], a.R[s01] + b.L[s1], a.R[s0] + b.L[s01] }),
            max({ a.I[1], b.I[1], a.R[s10] + b.L[s0], a.R[s1] + b.L[s10] }),
        }
    };

    ckmax(res.I[0], max({ res.L[s01], res.R[s01] }));
    ckmax(res.I[1], max({ res.L[s10], res.R[s10] }));

    return res;
};

using update = bool;

auto uu = [](update a, update b) { return a ^ b; };

auto un = [](update u, node n) {
    node r = n;
    if (u) {
        swap(r.I[0], r.I[1]);
        for (int i = 0; i < 4; i += 2) {
            swap(r.L[i], r.L[i+1]);
            swap(r.R[i], r.R[i+1]);
        }
    }
    return r;
};



int main() {
    setIO();

    int N, Q; re(N, Q);

    segment_tree_lazy st(N, node{}, false, nn, uu, un);

    string init; re(init);
    st.set_leaves([&](int i) {
        return node{init[i]};
    });

    F0R (q, Q) {
        int l, r; re(l, r); --l;
        st(l, r, true);
        auto n = st(l, r);
        ps(n.I[0]);
    }

    return 0;
}