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
};

namespace FFT {
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
        if (INV) for (T& t : a) t = t * T(N).inv();
    }

    static vector<cnum> fa, fb;

    vector<cnum> operator*(const vector<cnum>& a, const vector<cnum>& b) {
        if (a.empty() || b.empty()) return {};
        int s = sz(a) + sz(b) - 1;
        int N = 1 << (s > 1 ? 32 - __builtin_clz(s - 1) : 0);
        if (N > sz(fa)) fa.resize(N), fb.resize(N);

        copy(all(a), fa.begin()), copy(all(b), fb.begin());
        fill(fa.begin() + sz(a), fa.begin() + N, 0);
        fill(fb.begin() + sz(b), fb.begin() + N, 0);

        fft<cnum, false>(fa, N), fft<cnum, false>(fb, N);
        for (int i = 0; i < N; i++) fa[i] = fa[i] * fb[i];
        fft<cnum, true>(fa, N);
        return { fa.begin(), fa.begin() + s };
    }
}
using namespace FFT;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    const string lett = "ATGC";

    int S, T, K; string s, t; re(S, T, K, s, t);

    vector<vector<cnum>> app(4, vector<cnum>(S));
    F0R (j, 4) {
        const char c = lett[j];

        int ct = 0;
        F0R (i, K) ct += s[i] == c;

        F0R (i, S) {
            if (i + K < S) ct += s[i + K] == c;
            if (i - K - 1 >= 0) ct -= s[i - K - 1] == c;
            app[j][i] = ct > 0 ? 1. : 0.;
        }
    }

    vector<vector<cnum>> need(4, vector<cnum>(T));
    F0R (i, T) need[lett.find(t[i])][T - 1 - i] = 1.;

    vector<vector<cnum>> prod(4);
    F0R (i, 4) prod[i] = app[i] * need[i];

    int ans = 0;
    F0R (i, S - T + 1) {
        int match = 0;
        F0R (j, 4)
            match += round(prod[j][i + T - 1].x);
        ans += match == T;
    }
    ps(ans);

    return 0;
}