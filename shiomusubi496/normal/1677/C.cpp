#line 2 "library/other/template.hpp"

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

#define each_for(...) for (auto&& __VA_ARGS__)
#define each_const(...) for (const auto& __VA_ARGS__)

#define all(v) std::begin(v), std::end(v)
#define rall(v) std::rbegin(v), std::rend(v)

#if __cplusplus >= 201402L
#define CONSTEXPR constexpr
#else
#define CONSTEXPR
#endif

#ifdef __cpp_if_constexpr
#define IF_CONSTEXPR constexpr
#else
#define IF_CONSTEXPR
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

inline PLL extGCD(ll a, ll b) noexcept {
    const ll n = a, m = b;
    ll x = 1, y = 0, u = 0, v = 1;
    ll t;
    while (b) {
        t = a / b;
        std::swap(a -= t * b, b);
        std::swap(x -= t * u, u);
        std::swap(y -= t * v, v);
    }
    if (x < 0) {
        x += m;
        y -= n;
    }
    return {x, y};
}
inline ll mod_inv(ll a, ll mod) noexcept {
    ll b = mod;
    ll x = 1, u = 0;
    ll t;
    while (b) {
        t = a / b;
        std::swap(a -= t * b, b);
        std::swap(x -= t * u, u);
    }
    if (x < 0) x += mod;
    assert(a == 1);
    return x;
}
inline PLL ChineseRemainder(ll b1, ll m1, ll b2, ll m2) noexcept {
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

template<class Head, class... Tail> struct multi_dim_vector {
    using type = std::vector<typename multi_dim_vector<Tail...>::type>;
};
template<class T> struct multi_dim_vector<T> {
    using type = T;
};

template<class T, class Arg> constexpr std::vector<T> make_vec(int n, Arg&& arg) {
    return std::vector<T>(n, std::forward<Arg>(arg));
}
template<class T, class... Args>
constexpr typename multi_dim_vector<Args..., T>::type make_vec(int n, Args&&... args) {
    return typename multi_dim_vector<Args..., T>::type (n, make_vec<T>(std::forward<Args>(args)...));
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

template<class T, class Comp = std::less<T>> class presser {
  protected:
    std::vector<T> dat;
    Comp cmp;
    bool sorted = false;
  public:
    presser() : presser(Comp()) {}
    presser(const Comp& cmp) : cmp(cmp) {}
    presser(const std::vector<T>& vec, const Comp& cmp = Comp()) : dat(vec), cmp(cmp) {}
    presser(std::vector<T>&& vec, const Comp& cmp = Comp()) : dat(std::move(vec)), cmp(cmp) {}
    presser(std::initializer_list<T> il, const Comp& cmp = Comp()) : dat(il.begin(), il.end()), cmp(cmp) {}
    void reserve(int n) {
        assert(!sorted);
        dat.reserve(n);
    }
    void push_back(const T& v) {
        assert(!sorted);
        dat.push_back(v);
    }
    void push_back(T&& v) {
        assert(!sorted);
        dat.push_back(std::move(v));
    }
    void push(const std::vector<T>& vec) {
        assert(!sorted);
        const int n = dat.size();
        dat.resize(n + vec.size());
        rep (i, vec.size()) dat[n + i] = vec[i];
    }
    int build() {
        assert(!sorted); sorted = true;
        std::sort(all(dat), cmp);
        dat.erase(std::unique(all(dat), [&](const T& a, const T& b) -> bool {
            return !cmp(a, b) && !cmp(b, a);
        }), dat.end());
        return dat.size();
    }
    const T& operator[](int k) const& {
        assert(sorted);
        assert(0 <= k && k < (int)dat.size());
        return dat[k];
    }
    T operator[](int k) && {
        assert(sorted);
        assert(0 <= k && k < (int)dat.size());
        return std::move(dat[k]);
    }
    int get_index(const T& val) const {
        assert(sorted);
        return static_cast<int>(std::lower_bound(all(dat), val, cmp) - dat.begin());
    }
    std::vector<int> pressed(const std::vector<T>& vec) const {
        assert(sorted);
        std::vector<int> res(vec.size());
        rep (i, vec.size()) res[i] = get_index(vec[i]);
        return res;
    }
    void press(std::vector<T>& vec) const {
        static_assert(std::is_integral<T>::value, "template argument must be convertible from int type");
        assert(sorted);
        each_for (i : vec) i = get_index(i);
    }
    int size() const {
        assert(sorted);
        return dat.size();
    }
    const std::vector<T>& data() const& { return dat; }
    std::vector<T> data() && { return std::move(dat); }
};
#line 2 "main.cpp"

using namespace std;

void solve();

int main() {
    int t; scanf("%d", &t);
    rep (t) solve();
}

void solve() {
    int n; scanf("%d", &n);
    vector<int> s;
    {
        vector<ll> a(n), b(n);
        rep (i, n) scanf("%lld", &a[i]), --a[i];
        rep (i, n) scanf("%lld", &b[i]), --b[i];
        vector<ll> ra(n);
        rep (i, n) ra[a[i]] = i;
        vector<bool> used(n, false);
        rep (i, n) {
            if (used[i]) continue;
            int cnt = 0;
            for (int j = i; !used[j]; j = ra[b[j]]) {
                ++cnt;
                used[j] = true;
            }
            s.push_back(cnt);
        }
    }
    int sm = 0;
    rep (i, s.size()) sm += s[i] / 2;
    ll ans = 0;
    rep (i, sm) ans -= i;
    rep (i, sm) ans += n - i - 1;
    printf("%lld\n", ans * 2);
}