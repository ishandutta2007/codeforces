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
    FILE* setIn(string s) { return freopen(s.c_str(),"r",stdin); }
    FILE* setOut(string s) { return freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        cout << setprecision(15);
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
    segment_tree(int SZ_, T id_, F tt_) : SZ(SZ_), id(id_), tt(tt_) {
        table.resize(2 * SZ, id);
    }
    template<typename L> void set_leaves(L create) {
        for (int i = 0; i < SZ; i++) table[SZ + i] = create(i);
        for (int i = SZ - 1; i; i--) table[i] = tt(table[2 * i], table[2 * i + 1]);
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
// }}}

int solve(int L, int R, vi vals) {
    if (L + sz(vals) >= R) {
        ps(-1);
        exit(0);
    }

    vals.insert(vals.begin(), L);
    vals.pb(R);

    vi order(sz(vals));
    iota(all(order), 0);
    sort_by(order, (vals[a] - a) != (vals[b] - b) ? (vals[a] - a) < (vals[b] - b) : a < b);

    vi index(sz(vals));
    F0R (i, sz(vals)) index[order[i]] = i;

    auto smaller = [](int a, int b) { return min(a, b); };
    segment_tree<int, decltype(smaller)> st(sz(vals), INT_MAX, smaller);

    st.replace(index.back(), 0 + sz(vals) - 1);
    F0Rd (i, sz(vals) - 1) {
        int succ = st(index[i] + 1, sz(vals));

        if (i == 0) {
            assert(succ != INT_MAX);
            return succ - i - 1;
        }

        if (succ == INT_MAX) continue;

        st.replace(index[i], succ - i - 1 + i);
    }

    return 0;
}

int main() {
    setIO();

    int N, K; re(N, K);
    vi a(N); re(a);
    vi b(K); re(b); trav (inx, b) --inx;

    int ans = 0;

    if (b.empty()) {
        ans += solve(INT_MIN, INT_MAX, a);
    } else {
        ans += solve(INT_MIN, a[b[0]], {a.begin(), a.begin() + b[0]});
        F0R (i, sz(b) - 1) {
            ans += solve(a[b[i]], a[b[i + 1]], {a.begin() + b[i] + 1, a.begin() + b[i + 1]});
        }
        ans += solve(a[b[sz(b) - 1]], INT_MAX, {a.begin() + b[sz(b) - 1] + 1, a.end()});
    }

    ps(ans);

    return 0;
}