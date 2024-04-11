#define LOCAL
#include <bits/stdc++.h>
using namespace std;
#pragma region Macros
typedef long long ll;
typedef __int128_t i128;
typedef unsigned int uint;
typedef unsigned long long ull;
#define ALL(x) (x).begin(), (x).end()

template <typename T> istream& operator>>(istream& is, vector<T>& v) {
    for (T& x : v) is >> x;
    return is;
}
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
    for (int i = 0; i < (int)v.size(); i++) {
        os << v[i] << (i + 1 == (int)v.size() ? "" : " ");
    }
    return os;
}
template <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}
template <typename T, typename U, typename V> ostream& operator<<(ostream& os, const tuple<T, U, V>& t) {
    os << '(' << get<0>(t) << ',' << get<1>(t) << ',' << get<2>(t) << ')';
    return os;
}
template <typename T, typename U, typename V, typename W> ostream& operator<<(ostream& os, const tuple<T, U, V, W>& t) {
    os << '(' << get<0>(t) << ',' << get<1>(t) << ',' << get<2>(t) << ',' << get<3>(t) << ')';
    return os;
}
template <typename T, typename U> ostream& operator<<(ostream& os, const map<T, U>& m) {
    os << '{';
    for (auto itr = m.begin(); itr != m.end();) {
        os << '(' << itr->first << ',' << itr->second << ')';
        if (++itr != m.end()) os << ',';
    }
    os << '}';
    return os;
}
template <typename T, typename U> ostream& operator<<(ostream& os, const unordered_map<T, U>& m) {
    os << '{';
    for (auto itr = m.begin(); itr != m.end();) {
        os << '(' << itr->first << ',' << itr->second << ')';
        if (++itr != m.end()) os << ',';
    }
    os << '}';
    return os;
}
template <typename T> ostream& operator<<(ostream& os, const set<T>& s) {
    os << '{';
    for (auto itr = s.begin(); itr != s.end();) {
        os << *itr;
        if (++itr != s.end()) os << ',';
    }
    os << '}';
    return os;
}
template <typename T> ostream& operator<<(ostream& os, const multiset<T>& s) {
    os << '{';
    for (auto itr = s.begin(); itr != s.end();) {
        os << *itr;
        if (++itr != s.end()) os << ',';
    }
    os << '}';
    return os;
}
template <typename T> ostream& operator<<(ostream& os, const unordered_set<T>& s) {
    os << '{';
    for (auto itr = s.begin(); itr != s.end();) {
        os << *itr;
        if (++itr != s.end()) os << ',';
    }
    os << '}';
    return os;
}
template <typename T> ostream& operator<<(ostream& os, const deque<T>& v) {
    for (int i = 0; i < (int)v.size(); i++) {
        os << v[i] << (i + 1 == (int)v.size() ? "" : " ");
    }
    return os;
}

void debug_out() { cerr << '\n'; }
template <class Head, class... Tail> void debug_out(Head&& head, Tail&&... tail) {
    cerr << head;
    if (sizeof...(Tail) > 0) cerr << ", ";
    debug_out(move(tail)...);
}
#ifdef LOCAL
#define debug(...)                                                                   \
    cerr << " ";                                                                     \
    cerr << #__VA_ARGS__ << " :[" << __LINE__ << ":" << __FUNCTION__ << "]" << '\n'; \
    cerr << " ";                                                                     \
    debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

template <typename T> T gcd(T x, T y) { return y != 0 ? gcd(y, x % y) : x; }
template <typename T> T lcm(T x, T y) { return x / gcd(x, y) * y; }

template <class T1, class T2> inline bool chmin(T1& a, T2 b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T1, class T2> inline bool chmax(T1& a, T2 b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
#pragma endregion

/**
 * @brief modint
 * @docs docs/modulo/modint.md
 */
template <uint32_t mod> class modint {
    using i64 = int64_t;
    using u32 = uint32_t;
    using u64 = uint64_t;

public:
    u32 v;
    constexpr modint(const i64 x = 0) noexcept : v(x < 0 ? mod - 1 - (-(x + 1) % mod) : x % mod) {}
    constexpr u32& value() noexcept { return v; }
    constexpr const u32& value() const noexcept { return v; }
    constexpr modint operator+(const modint& rhs) const noexcept { return modint(*this) += rhs; }
    constexpr modint operator-(const modint& rhs) const noexcept { return modint(*this) -= rhs; }
    constexpr modint operator*(const modint& rhs) const noexcept { return modint(*this) *= rhs; }
    constexpr modint operator/(const modint& rhs) const noexcept { return modint(*this) /= rhs; }
    constexpr modint& operator+=(const modint& rhs) noexcept {
        v += rhs.v;
        if (v >= mod) v -= mod;
        return *this;
    }
    constexpr modint& operator-=(const modint& rhs) noexcept {
        if (v < rhs.v) v += mod;
        v -= rhs.v;
        return *this;
    }
    constexpr modint& operator*=(const modint& rhs) noexcept {
        v = (u64)v * rhs.v % mod;
        return *this;
    }
    constexpr modint& operator/=(const modint& rhs) noexcept { return *this *= rhs.pow(mod - 2); }
    constexpr modint pow(u64 exp) const noexcept {
        modint self(*this), res(1);
        while (exp > 0) {
            if (exp & 1) res *= self;
            self *= self;
            exp >>= 1;
        }
        return res;
    }
    constexpr modint& operator++() noexcept {
        if (++v == mod) v = 0;
        return *this;
    }
    constexpr modint& operator--() noexcept {
        if (v == 0) v = mod;
        return --v, *this;
    }
    constexpr modint operator++(int) noexcept {
        modint t = *this;
        return ++*this, t;
    }
    constexpr modint operator--(int) noexcept {
        modint t = *this;
        return --*this, t;
    }
    constexpr modint operator-() const noexcept { return modint(mod - v); }
    template <class T> friend constexpr modint operator+(T x, modint y) noexcept { return modint(x) + y; }
    template <class T> friend constexpr modint operator-(T x, modint y) noexcept { return modint(x) - y; }
    template <class T> friend constexpr modint operator*(T x, modint y) noexcept { return modint(x) * y; }
    template <class T> friend constexpr modint operator/(T x, modint y) noexcept { return modint(x) / y; }
    constexpr bool operator==(const modint& rhs) const noexcept { return v == rhs.v; }
    constexpr bool operator!=(const modint& rhs) const noexcept { return v != rhs.v; }
    constexpr bool operator!() const noexcept { return !v; }
    friend istream& operator>>(istream& s, modint& rhs) noexcept {
        i64 v;
        rhs = modint{(s >> v, v)};
        return s;
    }
    friend ostream& operator<<(ostream& s, const modint& rhs) noexcept { return s << rhs.v; }
};

/**
 * @brief Matrix
 * @docs docs/linearalgebra/Matrix.md
 */
template <class T> struct Matrix {
    vector<vector<T>> A;
    Matrix(size_t n, size_t m) : A(n, vector<T>(m, 0)) {}
    Matrix(size_t n) : A(n, vector<T>(n, 0)) {}
    size_t height() const { return A.size(); }
    size_t width() const { return A[0].size(); }
    inline const vector<T>& operator[](int i) const { return A[i]; }
    inline vector<T>& operator[](int i) { return A[i]; }
    static Matrix I(size_t n) {
        Matrix res(n);
        for (int i = 0; i < n; i++) res[i][i] = 1;
        return res;
    }
    Matrix operator+(const Matrix& B) const { return Matrix(*this) += B; }
    Matrix operator-(const Matrix& B) const { return Matrix(*this) -= B; }
    Matrix operator*(const Matrix& B) const { return Matrix(*this) *= B; }
    Matrix operator^(const long long k) const { return Matrix(*this) ^= k; }
    Matrix& operator+=(const Matrix& B) {
        size_t n = height(), m = width();
        assert(n == B.height() && m == B.width());
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                (*this)[i][j] += B[i][j];
            }
        }
        return *this;
    }
    Matrix& operator-=(const Matrix& B) {
        size_t n = height(), m = width();
        assert(n == B.height() && m == B.width());
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                (*this)[i][j] -= B[i][j];
            }
        }
        return *this;
    }
    Matrix& operator*=(const Matrix& B) {
        size_t n = height(), m = B.width(), l = width();
        assert(l == B.height());
        vector<vector<T>> C(n, vector<T>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < l; k++) {
                    C[i][j] += (*this)[i][k] * B[k][j];
                }
            }
        }
        A.swap(C);
        return *this;
    }
    Matrix& operator^=(long long k) {
        Matrix res = Matrix::I(height());
        while (k > 0) {
            if (k & 1) res *= *this;
            *this *= *this;
            k >>= 1LL;
        }
        A.swap(res.A);
        return *this;
    }
    T determinant() {
        Matrix B(*this);
        T res = 1;
        for (int i = 0; i < width(); i++) {
            int pivot = -1;
            for (int j = i; j < height(); j++) {
                if (B[j][i] != 0) {
                    pivot = j;
                }
            }
            if (pivot < 0) return 0;
            if (pivot != i) {
                res *= -1;
                swap(B[i], B[pivot]);
            }
            res *= B[i][i];
            T v = T(1) / B[i][i];
            for (int j = 0; j < width(); j++) B[i][j] *= v;
            for (int j = i + 1; j < height(); j++) {
                T w = B[j][i];
                for (int k = 0; k < width(); k++) {
                    B[j][k] -= B[i][k] * w;
                }
            }
        }
        return res;
    }
};

/**
 * @brief combination
 * @docs docs/combinatorics/combination.md
 */
template <class M> struct Combination {
    vector<M> _fac, _inv, _finv;
    Combination(int n) : _fac(n + 1), _inv(n + 1), _finv(n + 1) {
        _fac[0] = _finv[n] = _inv[0] = 1;
        for (int i = 1; i <= n; i++) _fac[i] = _fac[i - 1] * i;
        _finv[n] /= _fac[n];
        for (int i = n - 1; i >= 0; i--) _finv[i] = _finv[i + 1] * (i + 1);
        for (int i = 1; i <= n; i++) _inv[i] = _finv[i] * _fac[i - 1];
    }
    M fac(int k) const { return _fac[k]; }
    M finv(int k) const { return _finv[k]; }
    M inv(int k) const { return _inv[k]; }
    M P(int n, int r) const {
        if (n < 0 || r < 0 || n < r) return 0;
        return _fac[n] * _finv[n - r];
    }
    M C(int n, int r) const {
        if (n < 0 || r < 0 || n < r) return 0;
        return _fac[n] * _finv[r] * _finv[n - r];
    }
};

const int INF = 1e9;
const long long IINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const char dir[4] = {'D', 'R', 'U', 'L'};
const long long MOD = 1000000007;
// const long long MOD = 998244353;

const int MAX_K = 42;
using mint = modint<MOD>;
using M = Matrix<mint>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    Combination<mint> COM(MAX_K);
    vector<mint> power(MAX_K + 1, 1);
    for (int i = 0; i < MAX_K; i++) power[i + 1] = power[i] * 2;
    ll n;
    int k;
    cin >> n >> k;

    M m(2 * k + 3);
    for (int i = 0; i <= k; i++) m[i][i + k + 1] = 1;
    for (int i = k + 1; i < 2 * (k + 1); i++) {
        for (int j = 0; j < 2 * (k + 1); j++) {
            if (j <= k)
                m[i][j] = (i - k - 1 < j ? 0 : COM.C(i - k - 1, j) * power[i - k - 1 - j]);
            else
                m[i][j] = COM.C(i - k - 1, j - k - 1);
        }
    }
    m[2 * k + 2][2 * k + 1] = m[2 * k + 2][2 * k + 2] = 1;
    // for (int i = 0; i < m.height(); i++) {
    //     for (int j = 0; j < m.width(); j++) {
    //         cerr << m[i][j] << (j + 1 == m.width() ? '\n' : ' ');
    //     }
    // }

    m ^= n;
    mint ans = m[2 * k + 2][0];
    for (int j = k + 1; j < 2 * (k + 1); j++) ans += m[2 * (k + 1)][j];

    // for (int i = 0; i < m.height(); i++) {
    //     for (int j = 0; j < m.width(); j++) {
    //         cerr << m[i][j] << (j + 1 == m.width() ? '\n' : ' ');
    //     }
    // }

    cout << ans << '\n';
    return 0;
}