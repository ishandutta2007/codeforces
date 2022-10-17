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

// segment_tree {{{
template<typename T, typename F> struct segment_tree {
    int SZ;
    T id; F tt;
    vector<T> table;

    segment_tree() {}
    segment_tree(int _SZ, T _id, F _tt) : SZ(_SZ), id(_id), tt(_tt) {
        table.resize(2 * SZ, id);
    }
    template<typename L> void set_leaves(L create) {
        F0R (i, SZ) table[SZ + i] = create(i);
        FORd (i, 1, SZ) table[i] = tt(table[2 * i], table[2 * i + 1]);
    }

    // Replaces the element at index i with v
    void replace(int i, T v) {
        table[i += SZ] = v;
        for (i /= 2; i > 0; i /= 2) {
            table[i] = tt(table[2 * i], table[2 * i + 1]);
        }
    }

    // Accumulates the elements at indices in [i, j)
    T operator()(int i, int j) const {
        T left = id, right = id;
        for (i += SZ, j += SZ; i < j; i /= 2, j /= 2) {
            if (i&1) left = tt(left, table[i++]);
            if (j&1) right = tt(table[--j], right);
        }
        return tt(left, right);
    }
    const T& operator[](int i) const { return table[SZ + i]; }
};

template<typename T, typename F> struct full_segment_tree : segment_tree<T, F> {
    // Internal size is rounded up so that all layers are full
    full_segment_tree() {}
    full_segment_tree(int _SZ, T _id, F _tt) :
        segment_tree<T, F>(1 << (32 - __builtin_clz(_SZ - 1)), _id, _tt) {}

    /*
     * Returns the first i in [0, S] such that comp(this(0, i))
     * evaluates to true. Returns -1 if no such i exists.
     * Requires that comp(this(0, i)) is non-decreasing in i.
     */
    template<typename C> int lower_bound(C comp) const {
        if (!comp(this->table[1])) return -1;
        if (comp(T{})) return 0;

        int loc = 1;
        for (T cur{}; loc < this->SZ; ) {
            T mid = this->tt(cur, this->table[2 * loc]);
            if (comp(mid)) {
                loc = 2 * loc;
            } else {
                cur = mid;
                loc = 2 * loc + 1;
            }
        }
        return loc - this->SZ + 1;
    }
};
// }}}

int main() {
    setIO();

    int N, K, D; re(N, K, D); vi a(N); re(a);

    auto match = [&](int a, int b) {
        if (D == 0) return a == b;
        a %= D; if (a < 0) a += D;
        b %= D; if (b < 0) b += D;
        return a == b;
    };

    pair<int, pii> ans = {0, {-1, 1}};
    auto rec = [&](int i, int j) { ckmax(ans, {j-i, {-(i+1), j}}); };

    vi R(N), L(N);
    auto solve = [&](auto& self, int i, int j) -> void {
        if (j - i <= 1) { rec(i, j); return; }
        int k = (i + j) / 2;
        self(self, i, k), self(self, k, j);

        // min and max occur on the right {{{
        {
            int l = k, lo = INT_MAX, hi = INT_MIN;
            FOR (r, k, min(j, R[k])) {
                ckmin(lo, a[r]); ckmax(hi, a[r]); ckmax(l, L[r]);
                while (l >= max(i, L[r]+1) && lo <= a[l] && a[l] <= hi) l--;
                if (hi - lo + 1 <= r - l + K) rec(l+1, r+1);
            }
        } // }}}
        // min and max occur on the left {{{
        {
            int r = k, lo = INT_MAX, hi = INT_MIN;
            FORd (l, max(i, L[k-1]+1), k) {
                ckmin(lo, a[l]); ckmax(hi, a[l]); ckmin(r, R[l]);
                while (r < min(j, R[l]) && lo <= a[r] && a[r] <= hi) r++;
                if (hi - lo + 1 <= r - l + K) rec(l, r);
            }
        } // }}}

        // min/max separate sides
        vi mins(j - k), maxes(j - k);
        mins[0] = a[k]; FOR (m, 1, sz(mins)) mins[m] = min(mins[m-1], a[k+m]);
        maxes[0] = a[k]; FOR (m, 1, sz(maxes)) maxes[m] = max(maxes[m-1], a[k+m]);

        struct qr{ int l, rl, rh, e; };
        vector<qr> minq, maxq;
        int lo = INT_MAX, hi = INT_MIN;
        FORd (l, i, k) {
            ckmin(lo, a[l]); ckmax(hi, a[l]);
            // hi - lo + 1 <= r - l + 1 + K ---> hi - r <= lo - l + K
            minq.pb({ l, lb(all(maxes), hi) - maxes.begin() + k,
                         min(R[l], int(ub(all(mins), lo, greater<int>()) - mins.begin()) + k), lo - l + K });
            // hi - lo + 1 <= r - l + 1 + K ---> -r - lo <= -l - hi + K
            maxq.pb({ l, lb(all(mins), lo, greater<int>()) - mins.begin() + k,
                         min(R[l], int(ub(all(maxes), hi) - maxes.begin()) + k), -l - hi + K });
        }

        {
            vpii rmin(j - k);
            FOR (r, k, j) rmin[r-k] = { r, -r - mins[r-k] }; sort_by(rmin, a.s < b.s);
            segment_tree st(j - k, -1, [](int a, int b){ return max(a, b); });
            sort_by(maxq, a.e < b.e);
            int ri = 0; trav (q, maxq) {
                while (ri < sz(rmin) && rmin[ri].s <= q.e) st.replace(rmin[ri].f - k, rmin[ri].f), ri++;
                if (int r = st(q.rl - k, q.rh - k); r != -1) rec(q.l, r + 1);
            }
        }
        {
            vpii rmax(j - k);
            FOR (r, k, j) rmax[r-k] = { r, -r + maxes[r-k] }; sort_by(rmax, a.s < b.s);
            segment_tree st(j - k, -1, [](int a, int b){ return max(a, b); });
            sort_by(minq, a.e < b.e);
            int ri = 0; trav (q, minq) {
                while (ri < sz(rmax) && rmax[ri].s <= q.e) st.replace(rmax[ri].f - k, rmax[ri].f), ri++;
                if (int r = st(q.rl - k, q.rh - k); r != -1) rec(q.l, r + 1);
            }
        }
    };

    for (int i = 0, j = 0; i < N; i = j) {
        while (j < N && match(a[i], a[j])) j++;
        if (D == 0) rec(i, j);
        else {
            FOR (k, i, j) {
                if (a[k] % D != 0 && a[k] < 0) a[k] = a[k] / D - 1;
                else a[k] /= D;
            }
            set<int> elts;
            FOR (k, i, j) {
                for (R[k] = k > i ? R[k-1] : k; R[k] < j && !elts.count(a[R[k]]); R[k]++)
                    elts.insert(a[R[k]]);
                elts.erase(a[k]);
            }
            FORd (k, i, j) {
                for (L[k] = k+1<j ? L[k+1] : k; L[k] >= i && !elts.count(a[L[k]]); L[k]--)
                    elts.insert(a[L[k]]);
                elts.erase(a[k]);
            }
            solve(solve, i, j);
        }
    }

    ps(-ans.s.f, ans.s.s);

    return 0;
}