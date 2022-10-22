
#include<bits/stdc++.h>

#ifndef __COUNTER__
#define __COUNTER__ __LINE__
#endif

#define REP_SELECTER(a, b, c, d, e, ...) e
#define REP1_0(b, c) REP1_1(b, c)
#define REP1_1(b, c) for (ll REP_COUNTER_ ## c = 0; REP_COUNTER_ ## c < (ll)(b); ++ REP_COUNTER_ ## c)
#define REP1(b) REP1_0(b, __COUNTER__)
#define REP2(i, b) for (ll i = 0; i < (ll)(b); ++i)
#define REP3(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define REP4(i, a, b, c) for (ll i = (ll)(a); i < (ll)(b); i += (ll)(c))
#define rep(...) REP_SELECTER(__VA_ARGS__, REP4, REP3, REP2, REP1) (__VA_ARGS__)
#define RREP2(i, a) for (ll i = (ll)(a) - 1; i >= 0; --i)
#define RREP3(i, a, b) for (ll i = (ll)(a) - 1; i >= (ll)(b); --i)
#define RREP4(i, a, b, c) for (ll i = (ll)(a) - 1; i >= (ll)(b); i -= (ll)(c))
#define rrep(...) REP_SELECTER(__VA_ARGS__, RREP4, RREP3, RREP2) (__VA_ARGS__)
#define REPS2(i, b) for (ll i = 1; i <= (ll)(b); ++i)
#define REPS3(i, a, b) for (ll i = (ll)(a) + 1; i <= (ll)(b); ++i)
#define REPS4(i, a, b, c) for (ll i = (ll)(a) + 1; i <= (ll)(b); i += (ll)(c))
#define reps(...) REP_SELECTER(__VA_ARGS__, REPS4, REPS3, REPS2) (__VA_ARGS__)
#define RREPS2(i, a) for (ll i = (ll)(a); i > 0; --i)
#define RREPS3(i, a, b) for (ll i = (ll)(a); i > (ll)(b); --i)
#define RREPS4(i, a, b, c) for (ll i = (ll)(a); i > (ll)(b); i -= (ll)(c))
#define rreps(...) REP_SELECTER(__VA_ARGS__, RREPS4, RREPS3, RREPS2) (__VA_ARGS__)

#define all(v) (v).begin(), (v).end()

#if __cplusplus >= 201402L
#define CONSTEXPR constexpr
#else
#define CONSTEXPR
#endif

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using PLL = std::pair<ll, ll>;
template<class T> using prique = std::priority_queue<T, std::vector<T>, std::greater<T>>;

template<class T> class infinity {
  public:
    static constexpr T value = std::numeric_limits<T>::max() / 2;
    static constexpr T mvalue = std::numeric_limits<T>::min() / 2;
    static constexpr T max = std::numeric_limits<T>::max();
    static constexpr T min = std::numeric_limits<T>::min();
};

#if __cplusplus <= 201402L
template<class T> constexpr T infinity<T>::value;
template<class T> constexpr T infinity<T>::mvalue;
template<class T> constexpr T infinity<T>::max;
template<class T> constexpr T infinity<T>::min;
#endif

#if __cplusplus >= 201402L
template<class T> constexpr T INF = infinity<T>::value;
#endif

constexpr ll inf = infinity<ll>::value;
constexpr ld EPS = 1e-8;
constexpr ld PI = 3.1415926535897932384626;

template<class T, class U> std::ostream& operator<<(std::ostream& ost, const std::pair<T, U>& p) {
    return ost << p.first << ' ' << p.second;
}
template<class T, class U> std::istream& operator>>(std::istream& ist, std::pair<T, U>& p) {
    return ist >> p.first >> p.second;
}

template<class Container,
        typename std::enable_if<!std::is_same<Container, std::string>::value>::type* = nullptr>
auto operator<<(std::ostream& ost, const Container& cont)
        -> decltype(cont.begin(), cont.end(), ost)
{
    for (auto itr = cont.begin(); itr != cont.end(); ++itr) {
        if (itr != cont.begin()) ost << ' ';
        ost << *itr;
    }
    return ost;
}
template<class Container,
        typename std::enable_if<!std::is_same<Container, std::string>::value>::type* = nullptr>
auto operator>>(std::istream& ist, Container& cont)
        -> decltype(cont.begin(), cont.end(), ist)
{
    for (auto itr = cont.begin(); itr != cont.end(); ++itr) ist >> *itr;
    return ist;
}

template<class T, class U> inline constexpr bool chmin(T &a, const U &b) noexcept {
    return a > b ? a = b, true : false;
}
template<class T, class U> inline constexpr bool chmax(T &a, const U &b) noexcept {
    return a < b ? a = b, true : false;
}

inline CONSTEXPR ll gcd(ll a, ll b) noexcept {
    while (b) {
        const ll c = a;
        a = b;
        b = c % b;
    }
    return a;
}
inline CONSTEXPR ll lcm(ll a, ll b) noexcept {
    return a / gcd(a, b) * b;
}

inline CONSTEXPR bool is_prime(ll N) noexcept {
    if (N <= 1) return false;
    for (ll i = 2; i * i <= N; ++i) {
        if (N % i == 0) return false;
    }
    return true;
}
inline std::vector<ll> prime_factor(ll N) noexcept {
    std::vector<ll> res;
    for (ll i = 2; i * i <= N; ++i) {
        while (N % i == 0) {
            res.push_back(i);
            N /= i;
        }
    }
    if (N != 1) res.push_back(N);
    return res;
}

inline CONSTEXPR ll my_pow(ll a, ll b) noexcept {
    ll res = 1;
    while (b) {
        if (b & 1) res *= a;
        b >>= 1;
        a *= a;
    }
    return res;
}
inline CONSTEXPR ll mod_pow(ll a, ll b, ll mod) noexcept {
    a %= mod;
    ll res = 1;
    while (b) {
        if (b & 1) (res *= a) %= mod;
        b >>= 1;
        (a *= a) %= mod;
    }
    return res;
}

PLL extGCD(ll a, ll b) noexcept {
    if (b == 0) return PLL{1, 0};
    PLL p = extGCD(b, a % b);
    std::swap(p.first, p.second);
    p.second -= p.first * (a / b);
    if (p.first < 0) {
        p.first += b;
        p.second -= a;
    }
    return p;
}
ll mod_inv(ll a, ll mod) noexcept {
    const PLL p = extGCD(a, mod);
    assert(p.first * a + p.second * mod == 1);
    return p.first;
}
PLL ChineseRemainder(ll b1, ll m1, ll b2, ll m2) noexcept {
    const PLL p = extGCD(m1, m2);
    const ll g = p.first * m1 + p.second * m2;
    const ll l = m1 / g * m2;
    if ((b2 - b1) % g != 0) return PLL{-1, -1};
    const ll x = (b2 - b1) / g * p.first % (m2 / g);
    return {(x * m1 + b1 + l) % l, l};
}
PLL ChineseRemainders(const std::vector<ll>& b, const std::vector<ll>& m) noexcept {
    PLL res{0, 1};
    rep (i, b.size()) {
        res = ChineseRemainder(res.first, res.second, b[i], m[i]);
        if (res.first == -1) return res;
    }
    return res;
}

template<class F> class RecLambda {
  private:
    F f;
  public:
    explicit constexpr RecLambda(F&& f_) : f(std::forward<F>(f_)) {}
    template<class... Args> constexpr auto operator()(Args&&... args) const
            -> decltype(f(*this, std::forward<Args>(args)...)) {
        return f(*this, std::forward<Args>(args)...);
    }
};

template<class F> inline constexpr RecLambda<F> rec_lambda(F&& f) {
    return RecLambda<F>(std::forward<F>(f));
}

template<class T, class Arg> constexpr std::vector<T> make_vec(int n, Arg&& arg) {
    return std::vector<T>(n, arg);
}
template<class T, class... Args> constexpr auto make_vec(int n, Args&&... args)
        -> std::vector<decltype(make_vec<T>(args...))> {
    return std::vector<decltype(make_vec<T>(args...))>
               (n, make_vec<T>(std::forward<Args>(args)...));
}

inline CONSTEXPR int popcnt(ull x) {
#if __cplusplus >= 202002L
    return std::popcount(x);
#endif
    x = (x & 0x5555555555555555) + ((x >> 1 ) & 0x5555555555555555);
    x = (x & 0x3333333333333333) + ((x >> 2 ) & 0x3333333333333333);
    x = (x & 0x0f0f0f0f0f0f0f0f) + ((x >> 4 ) & 0x0f0f0f0f0f0f0f0f);
    x = (x & 0x00ff00ff00ff00ff) + ((x >> 8 ) & 0x00ff00ff00ff00ff);
    x = (x & 0x0000ffff0000ffff) + ((x >> 16) & 0x0000ffff0000ffff);
    return (x & 0x00000000ffffffff) + ((x >> 32) & 0x00000000ffffffff);
}

template<class T> class presser : public std::vector<T> {
  private:
    using Base = std::vector<T>;
  public:
    using Base::Base;
    presser(const std::vector<T>& vec) : Base(vec) {}
    void push(const std::vector<T>& vec) {
        int n = this->size();
        this->resize(n + vec.size());
        std::copy(all(vec), this->begin() + n);
    }
    int build() {
        std::sort(this->begin(), this->end());
        this->erase(std::unique(this->begin(), this->end()), this->end());
        return this->size();
    }
    int get_index(const T& val) const {
        return static_cast<int>(std::lower_bound(this->begin(), this->end(), val) - this->begin());
    }
    std::vector<int> pressed(const std::vector<T>& vec) const {
        std::vector<int> res(vec.size());
        rep (i, vec.size()) res[i] = this->get_index(vec[i]);
        return res;
    }
    void press(std::vector<T>& vec) const {
        static_assert(std::is_integral<T>::value, "cannot convert from int type");
        rep (i, vec.size()) vec[i] = this->get_index(vec[i]);
    }
};


class ModIntBase {};
class StaticModIntBase : ModIntBase {};
class DynamicModIntBase : ModIntBase {};

template<class T> using is_ModInt = std::is_base_of<ModIntBase, T>;
template<class T> using is_StaticModInt = std::is_base_of<StaticModIntBase, T>;
template<class T> using is_DynamicModInt = std::is_base_of<DynamicModIntBase, T>;

template<ll mod> class StaticModInt : StaticModIntBase {
  protected:
    ll val;
    static constexpr ll inv1000000007[] = {-1, 1, 500000004, 333333336, 250000002,
            400000003, 166666668, 142857144, 125000001, 111111112, 700000005};
    static constexpr ll inv998244353 [] = {-1, 1, 499122177, 332748118, 748683265,
            598946612, 166374059, 855638017, 873463809, 443664157, 299473306};
  public:
    StaticModInt() : StaticModInt(0) {}
    template<class T, typename std::enable_if<std::is_integral<T>::value>::type* = nullptr> StaticModInt(T v) : val(v) {
        val %= mod;
        if (val < 0) val += mod;
    }
    ll get() const { return val; }
    static ll get_mod() { return mod; }
    static StaticModInt raw(ll v) {
        StaticModInt res;
        res.val = v;
        return res;
    }
    StaticModInt inv() const {
#if __cplusplus >= 201703L
        if constexpr (mod == 1000000007) {
            if (val <= 10) return inv1000000007[val];
        }
        else if constexpr (mod == 998244353) {
            if (val <= 10) return inv998244353[val];
        }
#else
        if (mod == 1000000007) {
            if (val <= 10) return inv1000000007[val];
        }
        else if (mod == 998244353) {
            if (val <= 10) return inv998244353[val];
        }
#endif
        return mod_inv(val, mod);
    }
    StaticModInt& operator++() {
        ++val;
        if (val == mod) val = 0;
        return *this;
    }
    StaticModInt operator++(int) {
        StaticModInt res = *this;
        ++ *this;
        return res;
    }
    StaticModInt& operator--() {
        if (val == 0) val = mod;
        --val;
        return *this;
    }
    StaticModInt operator--(int) {
        StaticModInt res = *this;
        -- *this;
        return res;
    }
    StaticModInt& operator+=(const StaticModInt& other) {
        val += other.val;
        if (val >= mod) val -= mod;
        return *this;
    }
    StaticModInt& operator-=(const StaticModInt& other) {
        val -= other.val;
        if (val < 0) val += mod;
        return *this;
    }
    StaticModInt& operator*=(const StaticModInt& other) {
        (val *= other.val) %= mod;
        return *this;
    }
    StaticModInt& operator/=(const StaticModInt& other) {
        (val *= other.inv().get()) %= mod;
        return *this;
    }
    friend StaticModInt operator+(const StaticModInt& lhs, const StaticModInt& rhs) {
        return StaticModInt(lhs) += rhs;
    }
    friend StaticModInt operator-(const StaticModInt& lhs, const StaticModInt& rhs) {
        return StaticModInt(lhs) -= rhs;
    }
    friend StaticModInt operator*(const StaticModInt& lhs, const StaticModInt& rhs) {
        return StaticModInt(lhs) *= rhs;
    }
    friend StaticModInt operator/(const StaticModInt& lhs, const StaticModInt& rhs) {
        return StaticModInt(lhs) /= rhs;
    }
    StaticModInt operator+() const {
        return StaticModInt(*this);
    }
    StaticModInt operator-() const {
        return StaticModInt(0) - *this;
    }
    StaticModInt pow(ll a) const {
        StaticModInt v = *this, res = 1;
        while (a) {
            if (a & 1) res *= v;
            a >>= 1;
            v *= v;
        }
        return res;
    }
    friend std::ostream& operator<<(std::ostream& ost, const StaticModInt& sm) {
        return ost << sm.val;
    }
    friend std::istream& operator>>(std::istream& ist, StaticModInt& sm) {
        return ist >> sm.val;
    }
};

#if __cplusplus < 201703L
template<ll mod> constexpr ll StaticModInt<mod>::inv1000000007[];
template<ll mod> constexpr ll StaticModInt<mod>::inv998244353 [];
#endif

using modint1000000007 = StaticModInt<1000000007>;
using modint998244353  = StaticModInt<998244353>;

template<int id> class DynamicModInt : DynamicModIntBase {
  protected:
    ll val;
    static ll mod;
  public:
    DynamicModInt() : DynamicModInt(0) {}
    template<class T, typename std::enable_if<std::is_integral<T>::value>::type* = nullptr> DynamicModInt(T v) : val(v) {
        val %= mod;
        if (val < 0) val += mod;
    }
    ll get() const { return val; }
    static ll get_mod() { return mod; }
    static void set_mod(ll v) { mod = v; }
    static DynamicModInt raw(ll v) {
        DynamicModInt res;
        res.val = v;
        return res;
    }
    DynamicModInt inv() const { return mod_inv(val, mod); }
    DynamicModInt& operator++() {
        ++val;
        if (val == mod) val = 0;
        return *this;
    }
    DynamicModInt operator++(int) {
        DynamicModInt res = *this;
        ++ *this;
        return res;
    }
    DynamicModInt& operator--() {
        if (val == 0) val = mod;
        --val;
        return *this;
    }
    DynamicModInt operator--(int) {
        DynamicModInt res = *this;
        -- *this;
        return res;
    }
    DynamicModInt& operator+=(const DynamicModInt& other) {
        val += other.val;
        if (val >= mod) val -= mod;
        return *this;
    }
    DynamicModInt& operator-=(const DynamicModInt& other) {
        val -= other.val;
        if (val < 0) val += mod;
        return *this;
    }
    DynamicModInt& operator*=(const DynamicModInt& other) {
        (val *= other.val) %= mod;
        return *this;
    }
    DynamicModInt& operator/=(const DynamicModInt& other) {
        (val *= other.inv().get()) %= mod;
        return *this;
    }
    friend DynamicModInt operator+(const DynamicModInt& lhs, const DynamicModInt& rhs) {
        return DynamicModInt(lhs) += rhs;
    }
    friend DynamicModInt operator-(const DynamicModInt& lhs, const DynamicModInt& rhs) {
        return DynamicModInt(lhs) -= rhs;
    }
    friend DynamicModInt operator*(const DynamicModInt& lhs, const DynamicModInt& rhs) {
        return DynamicModInt(lhs) *= rhs;
    }
    friend DynamicModInt operator/(const DynamicModInt& lhs, const DynamicModInt& rhs) {
        return DynamicModInt(lhs) /= rhs;
    }
    DynamicModInt operator+() const {
        return DynamicModInt(*this);
    }
    DynamicModInt operator-() const {
        return DynamicModInt(0) - *this;
    }
    DynamicModInt pow(ll a) const {
        DynamicModInt v = *this, res = 1;
        while (a) {
            if (a & 1) res *= v;
            a >>= 1;
            v *= v;
        }
        return res;
    }
    friend std::ostream& operator<<(std::ostream& ost, const DynamicModInt& sm) {
        return ost << sm.val;
    }
    friend std::istream& operator>>(std::istream& ist, DynamicModInt& sm) {
        return ist >> sm.val;
    }
};

template<int id> ll DynamicModInt<id>::mod = 1000000007;

using modint = DynamicModInt<-1>;

/**
 * @brief ModInt
 * @docs docs/ModInt.md
 */


template<class T> class IntCombinatorics {
  protected:
    static std::vector<T> factorial;
  public:
    static void init(ll n) {
        factorial.reserve(n + 1);
        while ((ll)factorial.size() <= n) factorial.push_back(factorial.back() * factorial.size());
    }
    static T fact(ll x) {
        init(x);
        return factorial[x];
    }
    static T perm(ll n, ll r) {
        if (r < 0 || r > n) return T(0);
        init(n);
        return factorial[n] / factorial[n - r];
    }
    static T comb(ll n, ll r) {
        if (r < 0 || r > n) return T(0);
        init(n);
        return factorial[n] / factorial[n - r] / factorial[r];
    }
    static T homo(ll n, ll r) {
        return comb(n + r - 1, r);
    }
};

template<class T> std::vector<T> IntCombinatorics<T>::factorial = std::vector<T>(1, 1);

template<class T> class Combinatorics {
  protected:
    static std::vector<T> factorial;
    static std::vector<T> factinv;
  public:
    static void init(ll n) {
        int b = factorial.size();
        if (n < b) return;
        factorial.reserve(n + 1);
        while ((ll)factorial.size() <= n) factorial.push_back(factorial.back() * factorial.size());
        factinv.resize(n + 1);
        factinv[n] = T(1) / factorial[n];
        rreps (i, n, b) factinv[i - 1] = factinv[i] * i;
    }
    static T fact(ll x) {
        init(x);
        return factorial[x];
    }
    static T finv(ll x) {
        init(x);
        return factinv[x];
    }
    static T perm(ll n, ll r) {
        if (r < 0 || r > n) return 0;
        init(n);
        return factorial[n] * factinv[n - r];
    }
    static T comb(ll n, ll r) {
        if (r < 0 || r > n) return 0;
        init(n);
        return factorial[n] * factinv[n - r] * factinv[r];
    }
    static T homo(ll n, ll r) {
        return comb(n + r - 1, r);
    }
};

template<class T> std::vector<T> Combinatorics<T>::factorial = std::vector<T>(1, 1);
template<class T> std::vector<T> Combinatorics<T>::factinv = std::vector<T>(1, 1);

/**
 * @brief Combinatorics
 * @docs docs/Combinatorics.md
 */

using namespace std;

using mint = modint998244353;
using comb = Combinatorics<mint>;

bool is_match(const string& a, const string& b) {
    rep (i, 2) {
        if (a[i] != '?' && a[i] != b[i]) return false;
    }
    return true;
}

int main() {
    int n; cin >> n;
    int wl = 0, bl = 0, wr = 0, br = 0;
    int t = n;
    bool flga = true, flgb = true;
    rep (n) {
        string s; cin >> s;
        if (s[0] == 'W') wl++;
        if (s[0] == 'B') bl++;
        if (s[1] == 'W') wr++;
        if (s[1] == 'B') br++;
        if (s[0] == s[1] && s[0] != '?') t = -1;
        if (s[0] != '?' || s[1] != '?') t--;
        flga = flga && is_match(s, "WB");
        flgb = flgb && is_match(s, "BW");
    }
    mint ans = 0;
    rep (i, n + 1) {
        if (wl > i || bl > (n - i) || br > i || wr > (n - i)) continue;
        ans += comb::comb(n - wl - bl, i - wl) * comb::comb(n - wr - br, i - br);
    }
    if (t >= 0) ans -= mint(2).pow(t);
    if (flga) ans++;
    if (flgb) ans++;
    cout << ans << endl;
}