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

template<typename T> struct line {
    T a, b; int regions;
    bool q;
    mutable T l;
    T eval(T x) const { return a * x + b; }

    bool operator < (const line& o) const {
        return (q || o.q) ? l < o.l : a < o.a;
    }

    static constexpr T inf = numeric_limits<T>::has_infinity ?
        numeric_limits<T>::infinity() : numeric_limits<T>::max();

    template<typename _T = T> static
    typename enable_if<is_integral<_T>::value, _T>::type div(const _T a, const _T b) {
        return a / b - ((a ^ b) < 0 && (a % b));
    }
    template<typename _T = T> static
    typename enable_if<!is_integral<_T>::value, _T>::type div(const _T a, const _T b) {
        return a / b;
    }

    T boundary(const line<T>& o) const {
        if (a == o.a) return b > o.b ? inf : -inf;
        return div(o.b - b, a - o.a);
    }
};

/*
 * insert_line(a, b): inserts the line f(x) = a * x + b
 *                    the value of a must be non-decreasing across calls
 *
 * maximum(x0): returns the maximum value at x0 among all inserted lines
 *              the value of x0 must be non-decreasing across calls
 */
template<typename T> struct line_container_monotonic : deque<line<T>> {
    // amortized O(1)
    void insert_line(T a, T b, int regions) {
        line<T> ins = { a, b, regions, false, line<T>::inf };
        if (!this->empty()) {
            auto bk = this->rbegin();
            if (bk->a == a && bk->b >= b) return;
            bk->l = bk->boundary(ins);
            while (this->size() >= 2 && next(bk)->l >= bk->l) {
                this->pop_back(), bk++;
                bk->l = bk->boundary(ins);
            }
        }
        this->push_back(ins);
    }

    // amortized O(1)
    pair<T, int> maximum(T x0) {
        assert(!this->empty());
        while (this->front().l < x0) this->pop_front();
        return { this->front().eval(x0), this->front().regions };
    }
};

int main() {
    setIO();

    int N, K; re(N, K); vi t(N); re(t);

    vll pref = prefixes(t, 0ll, plus<ll>());

    vd invs(sz(pref));
    F0R (i, N) invs[i+1] = invs[i] + 1. / t[i];

    vd sums(sz(pref));
    F0R (i, N) sums[i+1] = sums[i] + pref[i+1] / double(t[i]);

    auto solve = [&](double lam) {
        line_container_monotonic<double> dp;
        dp.insert_line(0, 0, 0);

        FOR (i, 1, N + 1) {
            auto [v, r] = dp.maximum(invs[i]);
            double a = -pref[i];
            double b = -sums[i] + pref[i] * invs[i] + -v + sums[i] + lam;
            dp.insert_line(-a, -b, r+1);
        }

        auto [v, r] = dp.maximum(invs.back());
        return mp(sums.back() - v + lam, r+1);
    };

    if (K >= N) { ps(N); return 0; }

    double lo = 0., hi = 1e21;
    F0R (i, 100) {
        double mi = (lo + hi) / 2;
        if (solve(mi).s > K) lo = mi;
        else hi = mi;
    }

    auto [v, r] = solve(lo);
    ps(v - K * lo);

    // did you check N=1? did you mix up N,M?
    return 0;
}