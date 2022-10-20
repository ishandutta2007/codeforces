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
 * @brief Square Matrix
 * @docs docs/linearalgebra/SquareMatrix.md
 */
template <class T, size_t N> struct SquareMatrix {
    array<array<T, N>, N> A;
    SquareMatrix() = default;
    size_t size() { return N; }
    inline const array<T, N>& operator[](int i) const { return A[i]; }
    inline array<T, N>& operator[](int i) { return A[i]; }
    static SquareMatrix add_identity() { return SquareMatrix(); }
    static SquareMatrix mul_identity() {
        SquareMatrix res;
        for (size_t i = 0; i < N; i++) res[i][i] = 1;
        return res;
    }
    SquareMatrix operator+(const SquareMatrix& B) const { return SquareMatrix(*this) += B; }
    SquareMatrix operator-(const SquareMatrix& B) const { return SquareMatrix(*this) -= B; }
    SquareMatrix operator*(const SquareMatrix& B) const { return SquareMatrix(*this) *= B; }
    SquareMatrix operator^(const long long& k) const { return SquareMatrix(*this) ^= k; }
    SquareMatrix& operator+=(const SquareMatrix& B) {
        for (size_t i = 0; i < N; i++) {
            for (size_t j = 0; j < N; j++) {
                (*this)[i][j] += B[i][j];
            }
        }
        return *this;
    }
    SquareMatrix& operator-=(const SquareMatrix& B) {
        for (size_t i = 0; i < N; i++) {
            for (size_t j = 0; j < N; j++) {
                (*this)[i][j] -= B[i][j];
            }
        }
        return *this;
    }
    SquareMatrix& operator*=(const SquareMatrix& B) {
        array<array<T, N>, N> C;
        for (size_t i = 0; i < N; i++) {
            for (size_t j = 0; j < N; j++) {
                for (size_t k = 0; k < N; k++) {
                    C[i][j] += (*this)[i][k] * B[k][j];
                }
            }
        }
        A.swap(C);
        return *this;
    }
    SquareMatrix& operator^=(long long k) {
        SquareMatrix res = SquareMatrix::mul_identity();
        while (k > 0) {
            if (k & 1) res *= *this;
            *this *= *this;
            k >>= 1LL;
        }
        A.swap(res.A);
        return *this;
    }
};

const int INF = 1e9;
const long long IINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const char dir[4] = {'D', 'R', 'U', 'L'};
const long long MOD = 1000000007;
// const long long MOD = 998244353;

const int MAX = 7;
using mint = modint<MOD>;
using SM = SquareMatrix<mint, 1 << MAX>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<int> w(MAX + 1);
    for (int i = 1; i <= MAX; i++) cin >> w[i];

    vector<vector<SM>> A(MAX + 1, vector<SM>(MAX + 1));
    for (int i = 0; i <= MAX; i++) {
        for (int j = 1; j <= MAX; j++) {
            for (int mask = 0; mask < (1 << MAX); mask++) {
                if (mask & ((((1 << (MAX + 1)) - 1) >> i) << i)) continue;
                int nmask = mask;
                for (int k = i; k < j; k++) nmask |= 1 << k;
                A[i][j][mask][nmask] = 1;
            }
        }
    }

    vector<SM> B(MAX + 1);
    for (int i = 1; i <= MAX; i++) {
        for (int mask1 = 0; mask1 < (1 << i); mask1++) {
            for (int mask2 = 0; mask2 < (1 << i); mask2++) {
                for (int mask = 0; mask < (1 << (i + 1)); mask++) {
                    if (!(mask & 1)) continue;
                    if (!(mask >> i & 1)) continue;

                    int add = 1;
                    for (int j = 0; j < i; j++) {
                        if (!(mask1 >> j & 1)) continue;
                        if (!(mask2 >> j & 1)) continue;
                        if (!(mask >> j & 1)) continue;
                        if (!(mask >> (j + 1) & 1)) continue;
                        add = 0;
                    }
                    B[i][mask1][mask2] += add;
                }
            }
        }
    }

    SM prod = SM::mul_identity();
    int pre = 0;
    for (int i = 1; i <= MAX; i++) {
        if (!w[i]) continue;
        prod *= A[pre][i];
        prod *= B[i] ^ w[i];
        pre = i;
    }

    mint ans = prod[0][(1 << pre) - 1];
    cout << ans << '\n';
    return 0;
}