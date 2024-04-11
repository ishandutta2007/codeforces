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

// modnum {{{
using v_t = int;
using vv_t = ll;
template<v_t MOD> struct modnum {
    v_t v;
    modnum() : v(0) {}
    modnum(vv_t _v) : v(_v % MOD) { if (v < 0) v += MOD; }
    explicit operator v_t() const { return v; }
    friend istream& operator >> (istream& i, modnum& n) { vv_t w; i >> w; n = modnum(w); return i; }
    friend ostream& operator << (ostream& o, const modnum& n) { return o << n.v; }

    friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
    friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
#if !defined(_WIN32) || defined(_WIN64)
        return x % m;
#endif
        // Neal's optimized mod for 32-bit machines.
        // x must be less than 2^32 * m for this to work, so that x / m fits in a 32-bit integer.
        unsigned x_high = x >> 32, x_low = (unsigned) x;
        unsigned quot, rem;
        asm("divl %4\n"
                : "=a" (quot), "=d" (rem)
                : "d" (x_high), "a" (x_low), "r" (m));
        return rem;
    }

    modnum& operator += (const modnum& o) { v += o.v; if (v >= MOD) v -= MOD; return *this; }
    modnum& operator -= (const modnum& o) { v -= o.v; if (v < 0) v += MOD; return *this; }
    modnum& operator *= (const modnum& o) { v = fast_mod(vv_t(v) * o.v); return *this; }
    modnum operator - () { modnum res; if (v) res.v = MOD - v; return res; }
    friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
    friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
    friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }

    modnum pow(vv_t e) const {
        if (e < 0) return 1 / this->pow(-e);
        if (e == 0) return 1;
        if (e & 1) return *this * this->pow(e-1);
        return (*this * *this).pow(e/2);
    }

    modnum inv() const {
        v_t g = MOD, x = 0, y = 1;
        for (v_t r = v; r != 0; ) {
            v_t q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        }

        assert(g == 1);
        assert(y == MOD || y == -MOD);
        return x < 0 ? x + MOD : x;
    }
    modnum& operator /= (const modnum& o) { return (*this) *= o.inv(); }
    friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= modnum(b); }

    static constexpr v_t totient() {
        v_t tot = MOD, tmp = MOD;
        for (v_t p = 2; p * p <= tmp; p++) if (tmp % p == 0) {
            tot = tot / p * (p - 1);
            while (tmp % p == 0) tmp /= p;
        }
        if (tmp > 1) tot = tot / tmp * (tmp - 1);
        return tot;
    }

    static v_t primitive_root() {
        if (MOD == 1) return 0;
        if (MOD == 2) return 1;

        v_t tot = totient(), tmp = tot;
        vi tot_pr;
        for (v_t p = 2; p * p <= tmp; p++) if (tot % p == 0) {
            tot_pr.push_back(p);
            while (tmp % p == 0) tmp /= p;
        }
        if (tmp > 1) tot_pr.push_back(tmp);

        for (v_t r = 2; r < MOD; r++) if (__gcd(r, MOD) == 1) {
            bool root = true;
            for (v_t p : tot_pr) root &= modnum(r).pow(tot / p) != 1;
            if (root) return r;
        }
        assert(false);
    }

    static modnum generator() { static modnum g = primitive_root(); return g; }
    static v_t discrete_log(modnum v) {
        static const v_t M = ceil(sqrt(MOD));
        static unordered_map<v_t, v_t> table;
        if (table.empty()) {
            modnum e = 1;
            for (v_t i = 0; i < M; i++) { table[e.v] = i; e *= generator(); }
        }
        static modnum f = generator().pow(totient() - M);

        for (v_t i = 0; i < M; i++) {
            if (table.count(v.v)) return table[v.v] + i * M;
            v *= f;
        }
        assert(false);
    }

    static modnum unity_root(int deg) {
        assert(totient() % deg == 0);
        return generator().pow(totient() / deg);
    }

    static modnum unity_root(int deg, int pow) {
        static vector<modnum> table{ 0, 1 };
        while (sz(table) <= deg) {
            modnum w = unity_root(sz(table));
            for (int i = sz(table)/2, s = sz(table); i < s; i++) {
                table.push_back(table[i]);
                table.push_back(table[i] * w);
            }
        }
        return table[deg + (pow < 0 ? deg + pow : pow)];
    }

    static modnum fact(int n) {
        static vector<modnum> fact = { 1 };
        for (assert(n >= 0); fact.size() <= n; )
            fact.push_back(fact.back() * fact.size());
        return fact[n];
    }

    static modnum finv(int n) {
        static vector<modnum> finv = { 1 };
        for (assert(n >= 0); finv.size() <= n; )
            finv.push_back(finv.back() / finv.size());
        return finv[n];
    }

    static modnum ncr(int n, int r) {
        assert(n >= 0);
        if (r < 0 || n < r) return 0;
        return fact(n) * finv(r) * finv(n - r);
    }
};
// }}}
using mn = modnum<int(10007)>;
using vmn = vector<mn>;

// point {{{
template<typename T> struct point {
    T x, y;
    point() : x(0), y(0) {}
    point(T _x, T _y) : x(_x), y(_y) {}
    friend istream& operator >> (istream& i, point& p) { return i >> p.x >> p.y; }
    friend ostream& operator << (ostream& o, const point& p) {
        return o << "(" << p.x << ", " << p.y << ")";
    }

    T norm() const { return x * x + y * y; }
    double len() const { return sqrt(norm()); }
    double ang() const { return atan2(y, x); }
    point<T> conj() const { return { x, -y }; }

    point& operator += (const point& o) { x += o.x; y += o.y; return *this; }
    point& operator -= (const point& o) { x -= o.x; y -= o.y; return *this; }
    point& operator *= (const T& c) { x *= c; y *= c; return *this; }
    point& operator /= (const T& c) { x /= c; y /= c; return *this; }
    friend point operator + (const point& a, const point& b) { return point(a) += b; }
    friend point operator - (const point& a, const point& b) { return point(a) -= b; }
    friend point operator * (const point& a, const T& c) { return point(a) *= c; }
    friend point operator * (const T& c, const point& a) { return point(a) *= c; }
    friend point operator / (const point& a, const T& c) { return point(a) /= c; }

    bool operator == (const point& o) const { return x == o.x && y == o.y; }
    bool operator != (const point& o) const { return x != o.x || y != o.y; }
    bool operator < (const point& o) const { return (x != o.x) ? x < o.x : y < o.y; }
    bool operator > (const point& o) const { return (x != o.x) ? x > o.x : y > o.y; }
    bool operator <= (const point& o) const { return !(*this > o); }

    friend T dot(const point& a, const point& b) { return a.x * b.x + a.y * b.y; }
    friend T cross(const point& a, const point& b) { return a.x * b.y - a.y * b.x; }
    friend T cross(const point& p, const point& a, const point& b) { return cross(a - p, b - p); }

    friend point<T> operator * (const point& a, const point& b) {
        return { a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x };
    }
    friend point<T> operator / (const point& a, const point& b) {
        return a * b.conj() / b.norm();
    }

    point dir() const { return point(*this) / len(); }
    point rotate(const double& ang) const { return *this * point(cos(ang), sin(ang)); }

    T dist(const point& a) const { return (a - *this).len(); }
    T dist(const point& a, const point& b) {
        return abs(cross(*this, a, b)) / a.dist(b);
    }
    point reflect(const point& a, const point& b) const {
        return a + ((*this - a) / (b - a)).conj() * (b - a);
    }
    point foot(const point& a, const point& b) const {
        return (*this + this->reflect(a, b)) / 2;
    }
    friend point extension(const point& a, const point& b, const point& c, const point& d) {
        T x = cross(a, b, c), y = cross(a, b, d);
        return (d * x - c * y) / (x - y);
    }

    friend vector<point> seg_intersect(point a, point b, point c, point d) {
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);

        T a1 = cross(a, b, c), a2 = cross(a, b, d);
        if (a1 > a2) swap(a1, a2);
        if (!(a1 <= 0 && a2 >= 0)) return {};

        if (a1 == 0 && a2 == 0) {
            if (cross(a, c, d) != 0) return {};
            point<T> x1 = max(a, c), x2 = min(b, d);
            if (x1 > x2) return {};
            if (x1 == x2) return { x1 };
            return { x1, x2 };
        }

        point<T> z = extension(a, b, c, d);
        if (a <= z && z <= b) return { z };
        return {};
    }

    using polygon = vector<point<T>>;
    friend ostream& operator << (ostream& o, const polygon& poly) {
        o << "{";
        for (auto pt : poly) o << " " << pt;
        return o << " }";
    }

    string classify(const polygon& p) const {
        bool ans = 0;
        for (int i = 0; i < p.size(); i++) {
            point<T> a = p[i], b = p[(i + 1) % p.size()];
            if (cross(a, b, *this) == 0 && min(a, b) <= *this && *this <= max(a, b))
                return "on";
            if (a.y > b.y) swap(a, b);
            if (a.y <= y && y < b.y && cross(*this, a, b) > 0) ans ^= 1;
        }
        return ans ? "in" : "out";
    }

    friend polygon convex_hull(const vector<point>& pts) {
        point pivot = *min_element(all(pts));
        auto sorted = pts;
        sort(all(sorted), [&pivot](const point& p, const point& q) {
            T cp = cross(pivot, p, q);
            if (cp != 0) return cp > 0;
            return pivot.dist(p) < pivot.dist(q);
        });

        int j = 0;
        polygon res(pts.size());
        for (const point& p : sorted) {
            while (j > 1 && cross(res[j - 2], res[j - 1], p) <= 0)
                j--;
            res[j++] = p;
        }
        res.erase(res.begin() + j, res.end());
        return res;
    }

    // twice the signed area
    friend T area(const polygon& p) {
        T a = 0;
        for (int i = 0; i < sz(p); i++)
            a += cross(p[i], p[i+1 < sz(p) ? i+1 : 0]);
        return a;
    }
};
// }}}
// fft {{{
template<typename T, bool INV> static void fft(vector<T>& a, int N) {
    assert(__builtin_popcount(N) == 1);
    for (int i = 1, j = 0, k; i < N; i++) {
        for (k = N >> 1; (j ^= k) < k; k >>= 1);
        if (i < j) swap(a[i], a[j]);
    }

    for (int l = 1; l < N; l <<= 1) {
        for (int i = 0; i < N; i += 2 * l) {
            for (int j = 0; j < l; j++) {
                T w = T::unity_root(2 * l, INV ? -j : j);
                T u = a[i + j];
                T v = a[i + j + l] * w;
                a[i + j] = u + v;
                a[i + j + l] = u - v;
            }
        }
    }
    if (INV) {
        T ninv = T{N}.inv();
        for (int i = 0; i < N; i++) a[i] = a[i] * ninv;
    }
}
// }}}
// complex_fft {{{
namespace complex_fft {
    using dbl = double;
    struct cnum : point<dbl> {
        cnum(point<dbl> p) : point<dbl>(p) {}
        cnum(dbl _x = 0, dbl _y = 0) : point<dbl>(_x, _y) {}
        cnum inv() const { dbl n = norm(); return cnum(x / n, -y / n); }

        static cnum unity_root(int deg, int pow) {
            static vector<cnum> table{ 0, 1 };
            while (sz(table) <= deg) {
                dbl t = 2 * acos(-1) / sz(table);
                cnum w{ cos(t), sin(t) };
                for (int i = sz(table)/2, s = sz(table); i < s; i++) {
                    table.push_back(table[i]);
                    table.push_back(table[i] * w);
                }
            }
            return table[deg + (pow < 0 ? deg + pow : pow)];
        }
    };
    static vector<cnum> fa, fb;

    vector<cnum> operator*(const vector<cnum>& a, const vector<cnum>& b) {
        if (a.empty() || b.empty()) return {};
        int s = sz(a) + sz(b) - 1;
        int N = 1 << (s > 1 ? 32 - __builtin_clz(s - 1) : 0);
        if (N > sz(fa)) fa.resize(N), fb.resize(N);

        copy(all(a), fa.begin());
        fill(fa.begin() + sz(a), fa.begin() + N, 0);
        copy(all(b), fb.begin());
        fill(fb.begin() + sz(b), fb.begin() + N, 0);

        fft<cnum, false>(fa, N);
        fft<cnum, false>(fb, N);
        for (int i = 0; i < N; i++) fa[i] = fa[i] * fb[i];
        fft<cnum, true>(fa, N);
        return { fa.begin(), fa.begin() + s };
    }

    template<int MOD>
    vector<modnum<MOD>> operator*(const vector<modnum<MOD>>& a, const vector<modnum<MOD>>& b) {
        if (a.empty() || b.empty()) return {};
        int s = sz(a) + sz(b) - 1;
        if (true || min(sz(a), sz(b)) < 150) {
            const vv_t VV_BOUND = numeric_limits<vv_t>::max() - vv_t(MOD) * MOD;
            vector<vv_t> res(s);
            for (int i = 0; i < sz(a); i++) for (int j = 0; j < sz(b); j++) {
                if ((res[i + j] += vv_t(a[i].v) * b[j].v) > VV_BOUND) res[i + j] %= MOD;
            }
            return {res.begin(), res.end()};
        }

        int N = 1 << (s > 1 ? 32 - __builtin_clz(s - 1) : 0);
        if (N > sz(fa)) fa.resize(N), fb.resize(N);

        for (int i = 0; i < sz(a); i++)
            fa[i] = cnum(a[i].v & ((1 << 15) - 1), a[i].v >> 15);
        fill(fa.begin() + sz(a), fa.begin() + N, 0);
        fft<cnum, false>(fa, N);

        if (a != b) {
            for (int i = 0; i < sz(b); i++)
                fb[i] = cnum(b[i].v & ((1 << 15) - 1), b[i].v >> 15);
            fill(fb.begin() + sz(b), fb.begin() + N, 0);
            fft<cnum, false>(fb, N);
        } else {
            copy(fa.begin(), fa.begin() + N, fb.begin());
        }

        for (int i = 0; i <= N / 2; i++) {
            int j = (N - i) & (N - 1);
            cnum g0 = (fb[i] + fb[j].conj()) / (2 * N);
            cnum g1 = (fb[i] - fb[j].conj()) / (2 * N);
            g1 = { g1.y, -g1.x };
            if (j != i) {
                swap(fa[j], fa[i]);
                fb[j] = fa[j] * g1;
                fa[j] = fa[j] * g0;
            }
            fb[i] = fa[i] * g1.conj();
            fa[i] = fa[i] * g0.conj();
        }
        fft<cnum, false>(fa, N), fft<cnum, false>(fb, N);

        vector<modnum<MOD>> c(s);
        for (int i = 0; i < s; i++)
            c[i] =  ll(fa[i].x + 0.5)
                 + (ll(fa[i].y + 0.5) % MOD << 15)
                 + (ll(fb[i].x + 0.5) % MOD << 15)
                 + (ll(fb[i].y + 0.5) % MOD << 30);
        return c;
    }
    template<int MOD>
    vector<modnum<MOD>> conv(const vector<modnum<MOD>>& a, const vector<modnum<MOD>>& b) {
        return a * b;
    }
}
// }}}
using namespace complex_fft;

// vector_operators {{{
namespace vector_operators {
    template<typename T> vector<T>& operator*=(vector<T>& l, const T& r) {
        for (T& e : l) e *= r; return l;
    }
    template<typename T> vector<T>& operator/=(vector<T>& l, const T& r) {
        for (T& e : l) e /= r; return l;
    }
    template<typename T> vector<T> operator*(vector<T> l, const T& r) { return l *= r; }
    template<typename T> vector<T> operator*(const T& l, vector<T> r) { return r *= l; }
    template<typename T> vector<T> operator/(vector<T> l, const T& r) { return l /= r; }

    template<typename T> vector<T>& operator+=(vector<T>& l, vector<T>& r) {
        l.resz(max(sz(l), sz(r))); for (int i = 0; i < sz(r); i++) l[i] += r[i]; return l;
    }
    template<typename T> vector<T>& operator-=(vector<T>& l, const vector<T>& r) {
        l.resz(max(sz(l), sz(r))); for (int i = 0; i < sz(r); i++) l[i] -= r[i]; return l;
    }
    template<typename T> vector<T> operator+(vector<T> l, const vector<T>& r) { return l += r; }
    template<typename T> vector<T> operator-(vector<T> l, const vector<T>& r) { return l -= r; }

    template<typename T> vector<T> conv(const vector<T>& l, const vector<T>& r) {
        if (l.empty() || r.empty()) return {};
        vector<T> p(sz(l) + sz(r) - 1);
        for (int i = 0; i < sz(l); i++) for (int j = 0; j < sz(r); j++) p[i+j] += l[i] * r[j];
        return p;
    }
    template<typename T> vector<T> operator*(const vector<T>& l, const vector<T>& r) {
        return complex_fft::conv(l, r);
    }

    template<typename T> vector<T> dot(const vector<T>& a, const vector<T>& b) {
        vector<T> p(min(sz(a), sz(b))); for (int i = 0; i < sz(p); i++) p[i] = a[i] * b[i]; return p;
    }

    template<typename T> vector<T>& operator<<=(vector<T>& v, int x) {
        v.insert(v.begin(), x, 0); return v;
    }
    template<typename T> vector<T> operator<<(vector<T> v, int x) { return v <<= x; }

    template<typename T> void rem_lead(vector<T>& v) { while (sz(v) && v.back() == 0) v.pop_back(); }
    template<typename T> vector<T> without_lead(vector<T> v) { rem_lead(v); return v; }

    template<typename T> vector<T> reversed(vector<T> v) {
        reverse(all(v)); rem_lead(v); return v;
    }
    template<typename T> vector<T> reversed(const vector<T>& v, int S) {
        assert(S >= sz(v)); vector<T> res(S); copy(all(v), res.rbegin()); return res;
    }

    template<typename T> pair<vector<T>, vector<T>> long_division(vector<T> a, vector<T> b) {
        rem_lead(a), rem_lead(b), assert(!b.empty());
        T B = T{1} / b.back(); for (T& e : b) e *= B;
        vector<T> q(max(sz(a) - sz(b) + 1, 0));
        for (; sz(a) >= sz(b); rem_lead(a)) {
            q[sz(a) - sz(b)] = a.back();
            a -= a.back() * (b << (sz(a) - sz(b)));
        }
        for (T& e : q) e *= B;
        return {q, a}; // quotient, remainder
    }

    template<typename T> vector<T> mod_xk(const vector<T>& v, int k) {
        vector<T> r{v.begin(), v.begin() + min(sz(v), k)}; rem_lead(r); return r;
    }
    // 1/v % x^k
    template<typename T> vector<T> inv(const vector<T>& v, int k) {
        assert(!v.empty());
        if (k == 0) return {};
        if (k == 1) return { T{1}/v[0] };
        vector<T> v0 = inv(v, (k + 1)/2);
        return mod_xk(v0 * (vector<T>{2} - v0 * mod_xk(v, k)), k);
    }
    // Fast quotient and remainder by multiplying with inverse if you have an FFT
    template<typename T> vector<T> quo(vector<T> a, vector<T> b) {
        if (sz(a) < sz(b)) return {0};
        rem_lead(a), rem_lead(b), assert(!b.empty());
        int s = sz(a) + 1 - sz(b);
        return reversed(mod_xk(reversed(a) * inv(reversed(b), s), s), s);
    }
    template<typename T> vector<T> rem(const vector<T>& a, const vector<T>& b) {
        return without_lead(sz(a) < sz(b) ? a : (a - quo(a, b) * b));
    }

    template<typename T> vector<T>& operator/=(vector<T>& a, const vector<T>& b) {
        return a = min(sz(a), sz(b)) < 150 ? long_division(a, b).first  : quo(a, b);
    }
    template<typename T> vector<T>& operator%=(vector<T>& a, const vector<T>& b) {
        return a = min(sz(a), sz(b)) < 150 ? long_division(a, b).second : rem(a, b);
    }
    template<typename T> vector<T> operator/(vector<T> a, const vector<T>& b) { return a /= b; }
    template<typename T> vector<T> operator%(vector<T> a, const vector<T>& b) { return a %= b; }

    template<typename T> vector<T> mod_pow(const vector<T>& v, ll e, const vector<T>& m) {
        if (!e) return {1};
        vector<T> res = mod_pow(v, e/2, m); res = res * res % m;
        return e&1 ? res * v % m : res;
    }

    // evaluate polynomial v at x0
    template<typename T> T operator|(const vector<T>& v, const T& x0) {
        T res = 0; for (int i = sz(v) - 1; i >= 0; --i) res = res * x0 + v[i]; return res;
    }
}
using namespace vector_operators;
// }}}

template<typename T> struct LFSR {
    vector<T> seq;    // original sequence
    vector<T> fib;    // seq[i] = sum_j fib[j] * seq[i-1-j] (i >= sz(fib))
    vector<T> galois; // 0 = sum_j galois[j] * seq[i+j] (i <= sz(seq) - sz(galois))

    LFSR(vector<T> _seq) : seq(_seq) {
        vector<T> C = {1}, B = {1}; T b = 1;
        for (int i = 0, m = 1; i < sz(seq); i++, m++) {
            T d = 0; for (int j = 0; j < sz(C); j++) d += C[j] * seq[i - j];
            if (d == 0) continue;
            vector<T> _B = C; C.resz(max(sz(C), m+sz(B)));
            T dbi = d/b; for (int j = 0; j < sz(B); j++) C[m+j] -= dbi * B[j];
            if (sz(_B) < m+sz(B)) { B = _B; b = d; m = 0; }
        }
        galois = reversed(C);
        fib = move(C); fib.erase(fib.begin()); fib *= T{-1};
    }

    T operator[](ll n) const {
        vector<T> r = dot(seq, mod_pow({0,1}, n, galois));
        return accumulate(all(r), T{0});
    }
};

const int MAXN = 205;
const int MAXK = 1205;
mn dp[3][MAXN][MAXN];

int main() {
    setIO();

    string s; int K; re(s, K);

    int x = 0;
    vmn ans(MAXK);
    dp[0][0][sz(s)] = 1;

    F0R (k, MAXK) {
        int y = x+1 < 3 ? x+1 : 0;
        int z = y+1 < 3 ? y+1 : 0;

        F0R (i, sz(s)+1) FOR (j, i, sz(s)+1) if (mn v = dp[x][i][j]; v.v) {
            v.v = mn::fast_mod(v.v, 10007);
            if (i == j) ans[k].v += v.v;
            if (k&1) continue; // can't extend odd anymore
            if (i == j) {
                dp[y][i][j].v += 26 * v.v;
                dp[z][i][j].v += 26 * v.v;
            } else if (j - i == 1) {
                dp[y][i+1][j].v += v.v;
                dp[z][i+1][j].v += v.v;
                dp[z][i][j].v += 25 * v.v;
            } else if (s[i] == s[j-1]) {
                dp[z][i+1][j-1].v += v.v;
                dp[z][i][j].v += 25 * v.v;
            } else {
                dp[z][i+1][j].v += v.v;
                dp[z][i][j-1].v += v.v;
                dp[z][i][j].v += 24 * v.v;
            }
        }

        memset(dp[x], 0, sizeof(dp[x]));
        x = y;
    }

    trav (e, ans) e.v = mn::fast_mod(e.v, 10007);

    ps(LFSR(ans)[sz(s) + K]);

    return 0;
}