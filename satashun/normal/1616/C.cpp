//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;

template <class T>
V<T> make_vec(size_t a) {
    return V<T>(a);
}

template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return V<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
#define per(i, b) per2(i, 0, b)
#define per2(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define ALL(c) (c).begin(), (c).end()
#define SZ(x) ((int)(x).size())

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }

template <class T, class U>
void chmin(T& t, const U& u) {
    if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
    if (t < u) t = u;
}

template <class T>
void mkuni(vector<T>& v) {
    sort(ALL(v));
    v.erase(unique(ALL(v)), end(v));
}

template <class T>
vector<int> sort_by(const vector<T>& v) {
    vector<int> res(v.size());
    iota(res.begin(), res.end(), 0);
    sort(res.begin(), res.end(), [&](int i, int j) { return v[i] < v[j]; });
    return res;
}

template <class T, class U>
istream& operator>>(istream& is, pair<T, U>& p) {
    is >> p.first >> p.second;
    return is;
}

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

template <class T>
istream& operator>>(istream& is, vector<T>& v) {
    for (auto& x : v) {
        is >> x;
    }
    return is;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "{";
    rep(i, v.size()) {
        if (i) os << ",";
        os << v[i];
    }
    os << "}";
    return os;
}

#ifdef LOCAL
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << H;
    debug_out(T...);
}
#define debug(...) \
    cerr << __LINE__ << " [" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif

template <class T>
void scan(vector<T>& v, T offset = T(0)) {
    for (auto& x : v) {
        cin >> x;
        x += offset;
    }
}

template <class T>
void print(T x, int suc = 1) {
    cout << x;
    if (suc == 1)
        cout << "\n";
    else if (suc == 2)
        cout << " ";
}

template <class T>
void print(const vector<T>& v, int suc = 1) {
    for (int i = 0; i < v.size(); ++i)
        print(v[i], i == int(v.size()) - 1 ? suc : 2);
}

struct prepare_io {
    prepare_io() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
    }
} prep_io;

template <class T>
T gcd(T a, T b) {
    return b ? gcd(b, a % b) : a;
}

// a / b
template <class T>
struct Fraction {
    T a, b;
    Fraction(T _a = 0) : a(_a), b(1) {}
    Fraction(T _a, T _b) {
        T g = gcd(abs(_a), abs(_b));
        a = _a / g;
        b = _b / g;
    }

    using F = Fraction;

    F operator-() const {
        F f;
        f.a = -a;
        f.b = b;
        return f;
    }

    F operator+(const F& r) const { return {r.b * a + b * r.a, b * r.b}; }
    F operator-(const F& r) const { return *this + (-r); }
    F operator*(const F& r) const { return {a * r.a, b * r.b}; }
    F operator/(const F& r) const { return {a * r.b, b * r.a}; }
    F& operator+=(const F& r) { return *this = *this + r; }
    F& operator-=(const F& r) { return *this = *this - r; }
    F& operator*=(const F& r) { return *this = *this * r; }
    F& operator/=(const F& r) { return *this = *this / r; }
    bool operator<(const F& r) const { return a * r.b < b * r.a; }
    bool operator>(const F& r) const { return r < *this; }
    bool operator<=(const F& r) const { return !(r < *this); }
    bool operator>=(const F& r) const { return !(*this < r); }
    bool operator==(const F& r) const { return !(*this < r) && !(r < *this); }
    bool operator!=(const F& r) const { return !(*this == r); }
    friend ostream& operator<<(ostream& os, const F& v) {
        return os << v.a << '/' << v.b;
    }
};

using F = Fraction<ll>;

const int B = 2e5;
int cnt[B * 2];

void slv() {
    int n;
    cin >> n;
    V<int> a(n);
    cin >> a;

    int mx = 1;

    V<pii> cand;

    rep(i, n) {
        rep(j, i) { cand.eb(a[i] - a[j], i - j); }
    }

    for (auto f : cand) {
        V<int> vec;

        rep(i, n) {
            int v = f.se * a[i] - i * f.fi + B;
            cnt[v]++;
            vec.pb(v);
        }

        for (int v : vec) {
            chmax(mx, cnt[v]);
            cnt[v] = 0;
        }
        /*
        map<F, int> T;
        rep(i, n) T[F(a[i], 1) - f * i]++;
        for (auto p : T) chmax(mx, p.se);*/
    }
    print(n - mx);
}

int main() {
    int cases = 0;
    cin >> cases;
    rep(i, cases) slv();

    return 0;
}