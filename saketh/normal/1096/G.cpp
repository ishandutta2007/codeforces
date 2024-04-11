#include <bits/stdc++.h>
using namespace std;

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

#define FOR(i, a, b)    for (int i = (a); i < (b); i++)
#define F0R(i, a)       for (int i = 0; i < (a); i++)
#define FORd(i, a, b)   for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i, a)      for (int i = (a)-1; i >= 0; i--)
#define trav(a, x)      for (auto& a : x)

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;

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

template<int MOD> struct modnum {
    int v;
    modnum() : v(0) {}
    modnum(ll _v) : v(_v % MOD) { if (v < 0) v += MOD; }
    explicit operator int() const { return v; }
    friend istream& operator >> (istream& i, modnum& n) { ll w; i >> w; n = modnum(w); return i; }
    friend ostream& operator << (ostream& o, const modnum& n) { return o << n.v; }

    friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
    friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

    modnum& operator += (const modnum& o) { v += o.v; if (v >= MOD) v -= MOD; return *this; }
    modnum& operator -= (const modnum& o) { v -= o.v; if (v < 0) v += MOD; return *this; }
    modnum& operator *= (const modnum& o) { v = int(ll(v) * ll(o.v) % MOD); return *this; }
    modnum operator - () { modnum res; if (v) res.v = MOD - v; return res; }
    friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
    friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
    friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }

    modnum pow(ll e) const {
        if (e < 0) return 1 / this->pow(-e);
        if (e == 0) return 1;
        if (e & 1) return *this * this->pow(e-1);
        return (*this * *this).pow(e/2);
    }

    modnum inv() const {
        int g = MOD, x = 0, y = 1;
        for (int r = v; r != 0; ) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        }

        assert(g == 1);
        assert(y == MOD || y == -MOD);
        return x < 0 ? x + MOD : x;
    }
    modnum& operator /= (const modnum& o) { return (*this) *= o.inv(); }
    friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= modnum(b); }

    static int totient() {
        int tot = MOD, tmp = MOD;
        for (int p = 2; p * p <= tmp; p++) if (tmp % p == 0) {
            tot = tot / p * (p - 1);
            while (tmp % p == 0) tmp /= p;
        }
        if (tmp > 1) tot = tot / tmp * (tmp - 1);
        return tot;
    }

    static int primitive_root() {
        if (MOD == 1) return 0;
        if (MOD == 2) return 1;

        int tot = totient(), tmp = tot;
        vi tot_pr;
        for (int p = 2; p * p <= tmp; p++) if (tot % p == 0) {
            tot_pr.push_back(p);
            while (tmp % p == 0) tmp /= p;
        }
        if (tmp > 1) tot_pr.push_back(tmp);

        for (int r = 2; r < MOD; r++) if (__gcd(r, MOD) == 1) {
            bool root = true;
            for (int p : tot_pr) root &= modnum(r).pow(tot / p) != 1;
            if (root) return r;
        }
        assert(false);
    }

    static modnum generator() { static modnum g = primitive_root(); return g; }
    static int discrete_log(modnum v) {
        static const int M = ceil(sqrt(MOD));
        static unordered_map<int, int> table;
        if (table.empty()) {
            modnum e = 1;
            for (int i = 0; i < M; i++) { table[e.v] = i; e *= generator(); }
        }
        static modnum f = generator().pow(totient() - M);

        for (int i = 0; i < M; i++) {
            if (table.count(v.v)) return table[v.v] + i * M;
            v *= f;
        }
        assert(false);
    }

    static modnum unity_root(int deg) {
        assert(totient() % deg == 0);
        return generator().pow(totient() / deg);
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
        if (r < 0 || n < r) return 0;
        return fact(n) * finv(r) * finv(n - r);
    }
};
using mn = modnum<int(998244353)>;
using vmn = vector<mn>;
using vvmn = vector<vmn>;

template<typename T> struct point {
    T x, y;
    point() : x(0), y(0) {}
    point(T _x, T _y = 0) : x(_x), y(_y) {}
    friend istream& operator >> (istream& i, point& p) { return i >> p.x >> p.y; }
    friend ostream& operator << (ostream& o, const point& p) {
        return o << "(" << p.x << ", " << p.y << ")";
    }
    static point cis(double t) { return point{ cos(t), sin(t) }; }

    T norm() const { return x * x + y * y; }
    double len() const { return sqrt(norm()); }
    double ang() const { return atan2(y, x); }
    point<T> conj() const { return { x, -y }; }
    point<T> inv() const { return conj() / norm(); }

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

    point& operator *= (const point& b) {
        return *this = { x * b.x - y * b.y, x * b.y + y * b.x };
    }
    point& operator /= (const point& b) {
        return *this *= b.conj() / b.norm();
    }
    friend point operator * (const point& a, const point& b) { return point(a) *= b; }
    friend point operator / (const point& a, const point& b) { return point(a) /= b; }

    point dir() const { return point(*this) / len(); }
    point rotate(const double& ang) const { return *this * point(cos(ang), sin(ang)); }
    static point unity_root(int deg) { return cis(2 * acos(-1) / deg); }

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
};

namespace FFT {
    template<typename T> static T unity_root(int deg, int pow) {
        static vector<T> table{ T(0), T(1) };
        while (sz(table) <= deg) {
            T w = T::unity_root(sz(table));
            for (int i = sz(table)/2, s = sz(table); i < s; i++) {
                table.push_back(table[i]);
                table.push_back(table[i] * w);
            }
        }
        return table[deg + (pow < 0 ? deg + pow : pow)];
    }

    template<typename T, bool INV> static void fft(vector<T>& a, int N) {
        assert(__builtin_popcount(N) == 1);

        for (int i = 1, j = 0, k; i < N; i++) {
            for (k = N >> 1; (j ^= k) < k; k >>= 1);
            if (i < j) swap(a[i], a[j]);
        }

        for (int l = 1; l < N; l <<= 1) {
            for (int i = 0; i < N; i += 2 * l) {
                for (int j = 0; j < l; j++) {
                    T w = unity_root<T>(2 * l, INV ? -j : j);
                    T u = a[i + j];
                    T v = a[i + j + l] * w;
                    a[i + j] = u + v;
                    a[i + j + l] = u - v;
                }
            }
        }
        if (INV){ T iN = T(N).inv(); for (T& t : a) t /= iN; };
    }

    template<typename T> vector<T> convolution(const vector<T>& a, const vector<T>& b) {
        if (a.empty() || b.empty()) return {};
        int s = sz(a) + sz(b) - 1;
        int N = 1 << (s > 1 ? 32 - __builtin_clz(s - 1) : 0);

        static vector<T> fa, fb;
        if (N > sz(fa)) fa.resize(N), fb.resize(N);

        copy(all(a), fa.begin()), copy(all(b), fb.begin());
        fill(fa.begin() + sz(a), fa.begin() + N, 0);
        fill(fb.begin() + sz(b), fb.begin() + N, 0);

        fft<T, false>(fa, N), fft<T, false>(fb, N);
        for (int i = 0; i < N; i++) fa[i] = fa[i] * fb[i];
        fft<T, true>(fa, N);
        return { fa.begin(), fa.begin() + s };
    }

    using cnum = point<double>;
    vector<cnum> operator*(const vector<cnum>& a, const vector<cnum>& b) {
        return convolution<cnum>(a, b);
    }

    template<int MOD> vector<modnum<MOD>> operator*(
            const vector<modnum<MOD>>& a, const vector<modnum<MOD>>& b) {
        if (a.empty() || b.empty()) return {};
        int s = sz(a) + sz(b) - 1;
        int N = 1 << (s > 1 ? 32 - __builtin_clz(s - 1) : 0);
        //if (modnum<MOD>::totient() % N == 0) return convolution<modnum<MOD>>(a, b);

        static vector<cnum> fa, fb;
        if (N > sz(fa)) fa.resize(N), fb.resize(N);

        for (int i = 0; i < sz(a); i++) fa[i] = cnum(a[i].v & ((1 << 15) - 1), a[i].v >> 15);
        fill(fa.begin() + sz(a), fa.begin() + N, 0);
        for (int i = 0; i < sz(b); i++) fb[i] = cnum(b[i].v & ((1 << 15) - 1), b[i].v >> 15);
        fill(fb.begin() + sz(b), fb.begin() + N, 0);

        fft<cnum, false>(fa, N), fft<cnum, false>(fb, N);
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
}
using namespace FFT;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K; re(N, K);
    vi d(K); re(d);

    vmn dp(10);
    trav (v, d) dp[v] = 1;

    vmn DP = { 1 };
    for (int tmp = N/2; tmp; tmp >>= 1) {
        if (tmp&1) DP = DP * dp;
        dp = dp * dp;
    }

    dp = DP;
    reverse(all(DP));

    vmn res = dp * DP;
    ps(res[sz(dp) - 1].v);

    return 0;
}