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

template <int i, typename T> void print_tuple(ostream&, const T&) {}
template <int i, typename T, typename H, class... Args> void print_tuple(ostream& os, const T& t) {
    if (i) os << ',';
    os << get<i>(t);
    print_tuple<i + 1, T, Args...>(os, t);
}
template <typename... Args> ostream& operator<<(ostream& os, const tuple<Args...>& t) {
    os << '{';
    print_tuple<0, tuple<Args...>, Args...>(os, t);
    return os << '}';
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

int topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }
int topbit(long long t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }
int botbit(signed a) { return a == 0 ? 32 : __builtin_ctz(a); }
int botbit(long long a) { return a == 0 ? 64 : __builtin_ctzll(a); }
int popcount(signed t) { return __builtin_popcount(t); }
int popcount(long long t) { return __builtin_popcountll(t); }
bool ispow2(int i) { return i && (i & -i) == i; }

template <class T> T ceil(T x, T y) {
    assert(y >= 1);
    return (x > 0 ? (x + y - 1) / y : x / y);
}
template <class T> T floor(T x, T y) {
    assert(y >= 1);
    return (x > 0 ? x / y : (x - y + 1) / y);
}

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

#include <cassert>
#include <cstdint>
#include <iostream>

template <uint64_t Modulus> class modint {
    using i64 = int64_t;
    using u32 = uint32_t;
    using u64 = uint64_t;

    static_assert(Modulus < static_cast<uint32_t>(1) << 31, "Modulus must be less than 2**31");
    static constexpr u32 mod = Modulus;
    u32 v;

public:
    constexpr modint(const i64 x = 0) noexcept : v(x < 0 ? mod - 1 - (-(x + 1) % mod) : x % mod) {}
    constexpr u32& val() noexcept { return v; }
    constexpr const u32& val() const noexcept { return v; }
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
    constexpr modint& operator/=(const modint& rhs) noexcept { return *this *= rhs.inv(); }
    constexpr modint pow(long long n) const noexcept {
        assert(0 <= n);
        modint self(*this), res(1);
        while (n > 0) {
            if (n & 1) res *= self;
            self *= self;
            n >>= 1;
        }
        return res;
    }
    constexpr modint inv() const noexcept {
        assert(*this != 0);
        return pow(mod - 2);
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
    friend std::istream& operator>>(std::istream& s, modint& rhs) noexcept {
        i64 v;
        rhs = modint{(s >> v, v)};
        return s;
    }
    friend std::ostream& operator<<(std::ostream& s, const modint& rhs) noexcept { return s << rhs.v; }
};

/**
 * @brief modint
 * @docs docs/modulo/modint.md
 */

/**
 * @brief Fast Fourier Transform
 * @docs docs/convolution/FastFourierTransform.md
 */
namespace FastFourierTransform {
struct Complex {
    double x, y;
    Complex() : x(0), y(0) {}
    Complex(double x, double y) : x(x), y(y) {}
    inline Complex operator+(const Complex& c) const { return Complex(x + c.x, y + c.y); }
    inline Complex operator-(const Complex& c) const { return Complex(x - c.x, y - c.y); }
    inline Complex operator*(const Complex& c) const { return Complex(x * c.x - y * c.y, x * c.y + y * c.x); }
    inline Complex conj() const { return Complex(x, -y); }
};
const double PI = acosl(-1);
vector<Complex> roots = {{0, 0}, {1, 0}};
vector<int> rev = {0, 1};
int base = 1;
void ensure_base(int nbase) {
    if (nbase <= base) return;
    rev.resize(1 << nbase);
    for (int i = 0; i < (1 << nbase); i++) {
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (nbase - 1));
    }
    roots.resize(1 << nbase);
    for (; base < nbase; base++) {
        double angle = PI * 2.0 / (1 << (base + 1));
        for (int i = 1 << (base - 1); i < (1 << base); i++) {
            roots[i << 1] = roots[i];
            double angle_i = angle * ((i << 1 | 1) - (1 << base));
            roots[i << 1 | 1] = Complex(cos(angle_i), sin(angle_i));
        }
    }
}
void fft(vector<Complex>& a, int n) {
    int zeros = __builtin_ctz(n);
    ensure_base(zeros);
    int shift = base - zeros;
    for (int i = 0; i < n; i++) {
        if (i < (rev[i] >> shift)) {
            swap(a[i], a[rev[i] >> shift]);
        }
    }
    for (int k = 1; k < n; k <<= 1) {
        for (int i = 0; i < n; i += (k << 1)) {
            for (int j = 0; j < k; j++) {
                Complex z = a[i + j + k] * roots[j + k];
                a[i + j + k] = a[i + j] - z;
                a[i + j] = a[i + j] + z;
            }
        }
    }
}
vector<long long> multiply(const vector<int>& a, const vector<int>& b) {
    int need = a.size() + b.size() - 1;
    int nbase = 1;
    while ((1 << nbase) < need) nbase++;
    ensure_base(nbase);
    int sz = 1 << nbase;
    vector<Complex> C(sz);
    for (int i = 0; i < sz; i++) {
        int x = (i < a.size() ? a[i] : 0);
        int y = (i < b.size() ? b[i] : 0);
        C[i] = Complex(x, y);
    }
    fft(C, sz);
    Complex r(0, -0.25 / (sz >> 1)), s(0, 1), t(0.5, 0);
    for (int i = 0; i <= (sz >> 1); i++) {
        int j = (sz - i) & (sz - 1);
        Complex z = (C[j] * C[j] - (C[i] * C[i]).conj()) * r;
        C[j] = (C[i] * C[i] - (C[j] * C[j]).conj()) * r;
        C[i] = z;
    }
    for (int i = 0; i < (sz >> 1); i++) {
        Complex C0 = (C[i] + C[i + (sz >> 1)]) * t;
        Complex C1 = (C[i] - C[i + (sz >> 1)]) * t * roots[(sz >> 1) + i];
        C[i] = C0 + C1 * s;
    }
    fft(C, sz >> 1);
    vector<long long> res(need);
    for (int i = 0; i < need; i++) {
        res[i] = llround(i & 1 ? C[i >> 1].y : C[i >> 1].x);
    }
    return res;
}
}  // namespace FastFourierTransform

const int INF = 1e9;
const long long IINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const char dir[4] = {'D', 'R', 'U', 'L'};
const long long MOD = 1000000007;
// const long long MOD = 998244353;

using mint = modint<MOD>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int& x : a) cin >> x, x %= k;

    vector<int> sum(n + 1, 0), sum_rev(n + 1, 0);
    for (int i = 0; i < n; i++) sum[i + 1] = (sum[i] + a[i]) % k;
    for (int i = n - 1; i >= 0; i--) sum_rev[i] = (sum_rev[i + 1] + a[i]) % k;
    int cycle = sum.back();
    mint ans = 0;

    {
        // 1  ()
        vector<int> cnt(k, 0);
        for (int i = 1; i < n; i++) {
            ans += cnt[sum[i]];
            cnt[sum[i]]++;
        }
    }

    {
        // 
        vector<int> left(k), right(k);
        for (int i = 0; i < n; i++) left[sum[i]]++;
        for (int i = 1; i <= n; i++) right[sum_rev[i]]++;
        auto result = FastFourierTransform::multiply(left, right);
        for (size_t i = k; i < result.size(); i++) result[i % k] += result[i];
        for (int i = 0, j = 0; i <= m - 2; i++, (j += k - cycle) %= k) {  // 
            ans += result[j] - (i == 0);
        }
    }

    {
        // m - 1  + 
        vector<int> cnt(k, 0);
        int rest = ll(cycle) * (m - 1) % k;
        for (int i = 1; i <= n; i++) cnt[sum_rev[i]]++;
        for (int i = 0; i < n; i++) {
            ans += cnt[(2 * k - rest - sum[i]) % k];
            cnt[sum_rev[i + 1]]--;
        }
        if (m == 1) ans--;
    }

    ans *= m;
    if (ll(cycle) * m % k == 0) ans++;
    cout << ans << '\n';
    return 0;
}