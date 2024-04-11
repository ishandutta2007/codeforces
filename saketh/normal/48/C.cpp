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
        ios_base::sync_with_stdio(0); cin.tie(0);
        cout << fixed << setprecision(15);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
}
using namespace __io;
// }}}

// frac {{{
struct frac {
    ll n, d;
    frac(ll _n, ll _d = 1) : n(_n), d(_d) {
        assert(n != 0 || d != 0);
        if (d < 0) { n *= -1; d *= -1; }
        ll g = __gcd(abs(n), d);
        n /= g;
        d /= g;
    }
    explicit operator double() const { return double(n)/d; }
    friend ostream& operator << (ostream& o, const frac& f) {
        return o << f.n << "/" << f.d;
    }

    friend bool operator < (const frac& a, const frac& b) {
        return a.n * b.d < b.n * a.d;
    }
    friend bool operator <= (const frac& a, const frac& b) {
        return a.n * b.d <= b.n * a.d;
    }
    friend bool operator == (const frac& a, const frac& b) {
        return a.n * b.d == b.n * a.d;
    }
    friend bool operator != (const frac& a, const frac& b) {
        return a.n * b.d != b.n * a.d;
    }
    friend bool operator >= (const frac& a, const frac& b) {
        return a.n * b.d >= b.n * a.d;
    }
    friend bool operator > (const frac& a, const frac& b) {
        return a.n * b.d > b.n * a.d;
    }

    friend frac min(const frac a, const frac b) { return a <= b ? a : b; }
    friend frac max(const frac a, const frac b) { return a >= b ? a : b; }

    frac& operator += (const frac& b) { return *this = frac(n*b.d+b.n*d, d*b.d); }
    frac& operator -= (const frac& b) { return *this = frac(n*b.d-b.n*d, d*b.d); }
    frac& operator *= (const frac& b) { return *this = frac(n*b.n, d*b.d); }
    frac& operator /= (const frac& b) { return *this = frac(n*b.d, d*b.n); }
    friend frac operator + (const frac& a, const frac& b) { return frac(a) += b; }
    friend frac operator - (const frac& a, const frac& b) { return frac(a) -= b; }
    friend frac operator * (const frac& a, const frac& b) { return frac(a) *= b; }
    friend frac operator / (const frac& a, const frac& b) { return frac(a) /= b; }

    ll floor() { assert(d > 0); return n / d - ((n < 0) && (n % d)); }
    ll ceil() { assert(d > 0); return n / d + ((n > 0) && (n % d)); }

    // canonical continued fraction
    vll to_cont() const {
        if (d == 0) return { LLONG_MAX };
        vll cont;
        for (ll n = this->n, d = this->d; ; swap(n, d)) {
            ll f = (n >= 0 ? n : n - d + 1) / d;
            cont.push_back(f);
            n -= f * d;
            if (n == 0) break;
        }
        return cont;
    }

    static frac from_cont(const vll& cont) {
        ll n = 1, d = 0;
        for (int i = int(cont.size()) - 1; i >= 0; i--) {
            swap(n, d);
            n += d * cont[i];
        }
        return { n, d };
    }

    // "best" fraction in (x, y): minimizes both n and d
    friend frac best_in(const frac x, const frac y) {
        assert(x < y);

        vll x1 = x.to_cont(), y1 = y.to_cont();
        vll x2 = x1; x2.back()--; x2.push_back(1);
        vll y2 = y1; y2.back()--; y2.push_back(1);

        auto z = [](const vll& a, const vll& b) {
            vll c;
            for (int i = 0; ; i++) {
                ll ai = i < a.size() ? a[i] : LLONG_MAX;
                ll bi = i < b.size() ? b[i] : LLONG_MAX;
                if (ai != bi) {
                    c.push_back(min(ai, bi) + 1);
                    return from_cont(c);
                }
                c.push_back(ai);
            }
        };

        frac ans = { 1, 0 };
        for (const frac f : {z(x1, y1), z(x1, y2), z(x2, y1), z(x2, y2)}) {
            if (x < f && f < y && (ans.d == 0 || f.d < ans.d))
                ans = f;
        }
        return ans;
    }
};
// }}}

int main() {
    setIO();

    int N; re(N); vi stops(N); re(stops);

    frac lo = {10}, hi = {int(1e9)};

    F0R (i, N) {
        ckmax(lo, stops[i] * frac{10, i+1});
        ckmin(hi, (stops[i] + 1) * frac{10, i+1});
    }

    int nlo = ((N + 1) * lo / 10).floor();
    int nhi = ((N + 1) * hi / 10).ceil();

    if (nhi - nlo > 1) ps("not unique");
    else ps("unique"), ps(nlo);

    // did you check N=1? did you mix up N,M?
    return 0;
}