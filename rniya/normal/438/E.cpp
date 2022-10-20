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
 * @brief Number Theoretic Transform
 * @docs docs/convolution/NumberTheoreticTransform.md
 */
template <int mod> struct NumberTheoreticTransform {
    using Mint = modint<mod>;
    vector<Mint> roots;
    vector<int> rev;
    int base, max_base;
    Mint root;
    NumberTheoreticTransform() : base(1), rev{0, 1}, roots{Mint(0), Mint(1)} {
        int tmp = mod - 1;
        for (max_base = 0; tmp % 2 == 0; max_base++) tmp >>= 1;
        root = 2;
        while (root.pow((mod - 1) >> 1) == 1) root++;
        root = root.pow((mod - 1) >> max_base);
    }
    void ensure_base(int nbase) {
        if (nbase <= base) return;
        rev.resize(1 << nbase);
        for (int i = 0; i < (1 << nbase); i++) {
            rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (nbase - 1));
        }
        roots.resize(1 << nbase);
        for (; base < nbase; base++) {
            Mint z = root.pow(1 << (max_base - 1 - base));
            for (int i = 1 << (base - 1); i < (1 << base); i++) {
                roots[i << 1] = roots[i];
                roots[i << 1 | 1] = roots[i] * z;
            }
        }
    }
    void ntt(vector<Mint>& a) {
        const int n = a.size();
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
                    Mint z = a[i + j + k] * roots[j + k];
                    a[i + j + k] = a[i + j] - z;
                    a[i + j] = a[i + j] + z;
                }
            }
        }
    }
    vector<Mint> multiply(vector<Mint> a, vector<Mint> b) {
        int need = a.size() + b.size() - 1;
        int nbase = 1;
        while ((1 << nbase) < need) nbase++;
        ensure_base(nbase);
        int sz = 1 << nbase;
        a.resize(sz, Mint(0));
        b.resize(sz, Mint(0));
        ntt(a);
        ntt(b);
        Mint inv_sz = 1 / Mint(sz);
        for (int i = 0; i < sz; i++) a[i] *= b[i] * inv_sz;
        reverse(a.begin() + 1, a.end());
        ntt(a);
        a.resize(need);
        return a;
    }
    vector<int> multiply(vector<int> a, vector<int> b) {
        vector<Mint> A(a.size()), B(b.size());
        for (int i = 0; i < a.size(); i++) A[i] = Mint(a[i]);
        for (int i = 0; i < b.size(); i++) B[i] = Mint(b[i]);
        vector<Mint> C = multiply(A, B);
        vector<int> res(C.size());
        for (int i = 0; i < C.size(); i++) res[i] = C[i].v;
        return res;
    }
};

/**
 * @brief Formal Power Series
 * @docs docs/polynomial/FormalPowerSeries.md
 */
template <typename M> struct FormalPowerSeries : vector<M> {
    using vector<M>::vector;
    using Poly = FormalPowerSeries;
    using MUL = function<Poly(Poly, Poly)>;
    static MUL& get_mul() {
        static MUL mul = nullptr;
        return mul;
    }
    static void set_mul(MUL f) { get_mul() = f; }
    void shrink() {
        while (this->size() && this->back() == M(0)) this->pop_back();
    }
    Poly pre(int deg) const { return Poly(this->begin(), this->begin() + min((int)this->size(), deg)); }
    Poly operator+(const M& v) const { return Poly(*this) += v; }
    Poly operator+(const Poly& p) const { return Poly(*this) += p; }
    Poly operator-(const M& v) const { return Poly(*this) -= v; }
    Poly operator-(const Poly& p) const { return Poly(*this) -= p; }
    Poly operator*(const M& v) const { return Poly(*this) *= v; }
    Poly operator*(const Poly& p) const { return Poly(*this) *= p; }
    Poly operator/(const Poly& p) const { return Poly(*this) /= p; }
    Poly operator%(const Poly& p) const { return Poly(*this) %= p; }
    Poly& operator+=(const M& v) {
        if (this->empty()) this->resize(1);
        (*this)[0] += v;
        return *this;
    }
    Poly& operator+=(const Poly& p) {
        if (p.size() > this->size()) this->resize(p.size());
        for (int i = 0; i < (int)p.size(); i++) (*this)[i] += p[i];
        return *this;
    }
    Poly& operator-=(const M& v) {
        if (this->empty()) this->resize(1);
        (*this)[0] -= v;
        return *this;
    }
    Poly& operator-=(const Poly& p) {
        if (p.size() > this->size()) this->resize(p.size());
        for (int i = 0; i < (int)p.size(); i++) (*this)[i] -= p[i];
        return *this;
    }
    Poly& operator*=(const M& v) {
        for (int i = 0; i < (int)this->size(); i++) (*this)[i] *= v;
        return *this;
    }
    Poly& operator*=(const Poly& p) {
        if (this->empty() || p.empty()) {
            this->clear();
            return *this;
        }
        assert(get_mul() != nullptr);
        return *this = get_mul()(*this, p);
    }
    Poly& operator/=(const Poly& p) {
        if (this->size() < p.size()) {
            this->clear();
            return *this;
        }
        int n = this->size() - p.size() - 1;
        return *this = (rev().pre(n) * p.rev().inv(n)).pre(n).rev(n);
    }
    Poly& operator%=(const Poly& p) { return *this -= *this / p * p; }
    Poly operator<<(const int deg) {
        Poly res(*this);
        res.insert(res.begin(), deg, M(0));
        return res;
    }
    Poly operator>>(const int deg) {
        if (this->size() <= deg) return {};
        Poly res(*this);
        res.erase(res.begin(), res.begin() + deg);
        return res;
    }
    Poly operator-() const {
        Poly res(this->size());
        for (int i = 0; i < (int)this->size(); i++) res[i] = -(*this)[i];
        return res;
    }
    Poly rev(int deg = -1) const {
        Poly res(*this);
        if (~deg) res.resize(deg, M(0));
        reverse(res.begin(), res.end());
        return res;
    }
    Poly diff() const {
        Poly res(max(0, (int)this->size() - 1));
        for (int i = 1; i < (int)this->size(); i++) res[i - 1] = (*this)[i] * M(i);
        return res;
    }
    Poly integral() const {
        Poly res(this->size() + 1);
        res[0] = M(0);
        for (int i = 0; i < (int)this->size(); i++) res[i + 1] = (*this)[i] / M(i + 1);
        return res;
    }
    Poly inv(int deg = -1) const {
        assert((*this)[0] != M(0));
        if (deg < 0) deg = this->size();
        Poly res({M(1) / (*this)[0]});
        for (int i = 1; i < deg; i <<= 1) {
            res = (res + res - res * res * pre(i << 1)).pre(i << 1);
        }
        return res.pre(deg);
    }
    Poly log(int deg = -1) const {
        assert((*this)[0] == M(1));
        if (deg < 0) deg = this->size();
        return (this->diff() * this->inv(deg)).pre(deg - 1).integral();
    }
    Poly sqrt(int deg = -1) const {
        assert((*this)[0] == M(1));
        if (deg == -1) deg = this->size();
        Poly res({M(1)});
        M inv2 = M(1) / M(2);
        for (int i = 1; i < deg; i <<= 1) {
            res = (res + pre(i << 1) * res.inv(i << 1)) * inv2;
        }
        return res.pre(deg);
    }
    Poly exp(int deg = -1) {
        assert((*this)[0] == M(0));
        if (deg < 0) deg = this->size();
        Poly res({M(1)});
        for (int i = 1; i < deg; i <<= 1) {
            res = (res * (pre(i << 1) + M(1) - res.log(i << 1))).pre(i << 1);
        }
        return res.pre(deg);
    }
    Poly pow(long long k, int deg = -1) const {
        if (deg < 0) deg = this->size();
        for (int i = 0; i < (int)this->size(); i++) {
            if ((*this)[i] == M(0)) continue;
            if (k * i > deg) return Poly(deg, M(0));
            M inv = M(1) / (*this)[i];
            Poly res = (((*this * inv) >> i).log() * k).exp() * (*this)[i].pow(k);
            res = (res << (i * k)).pre(deg);
            if ((int)res.size() < deg) res.resize(deg, M(0));
            return res;
        }
        return *this;
    }
    Poly pow_mod(long long k, const Poly& mod) const {
        Poly x(*this), res = {M(1)};
        while (k > 0) {
            if (k & 1) res = res * x % mod;
            x = x * x % mod;
            k >>= 1;
        }
        return res;
    }
    Poly linear_mul(const M& a, const M& b) {
        Poly res(this->size() + 1);
        for (int i = 0; i < this->size() + 1; i++) {
            res[i] = (i - 1 >= 0 ? (*this)[i - 1] * a : M(0)) + (i < (int)this->size() ? (*this)[i] * b : M(0));
        }
        return res;
    }
    Poly linear_div(const M& a, const M& b) {
        Poly res(this->size() - 1);
        M inv_b = M(1) / b;
        for (int i = 0; i + 1 < (int)this->size(); i++) {
            res[i] = ((*this)[i] - (i - 1 >= 0 ? res[i - 1] * a : M(0))) * inv_b;
        }
        return res;
    }
    Poly sparse_mul(const M& c, const M& d) {
        Poly res(*this);
        res.resize(this->size() + d, M(0));
        for (int i = 0; i < (int)this->size(); i++) {
            res[i + d] += (*this)[i] * c;
        }
        return res;
    }
    Poly sparse_div(const M& c, const M& d) {
        Poly res(*this);
        for (int i = 0; i < res.size() - d; i++) {
            res[i + d] -= res[i] * c;
        }
        return res;
    }
    M operator()(const M& x) const {
        M res = 0, power = 1;
        for (int i = 0; i < (int)this->size(); i++, power *= x) {
            res += (*this)[i] * power;
        }
        return res;
    }
};

const int INF = 1e9;
const long long IINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const char dir[4] = {'D', 'R', 'U', 'L'};
// const long long MOD = 1000000007;
const long long MOD = 998244353;

using mint = modint<MOD>;
using FPS = FormalPowerSeries<mint>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    NumberTheoreticTransform<MOD> NTT;
    auto mul = [&](const FPS::Poly& a, const FPS::Poly& b) {
        auto res = NTT.multiply(a, b);
        return FPS::Poly(res.begin(), res.end());
    };
    FPS::set_mul(mul);

    int n, m;
    cin >> n >> m;
    FPS C(m + 1, 0);
    for (; n--;) {
        int c;
        cin >> c;
        if (c <= m) C[c]++;
    }

    FPS one(1, 1);
    FPS ans = ((one - C * 4).sqrt() + one).inv() * 2;
    for (int i = 1; i <= m; i++) cout << ans[i] << '\n';
    return 0;
}