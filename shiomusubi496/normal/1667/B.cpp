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
        dat.reserve(dat.size() + vec.size());
        std::copy(all(vec), std::back_inserter(dat));
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
#line 2 "library/data-struct/segment/SegmentTree.hpp"

#line 2 "library/other/bitop.hpp"

#line 4 "library/other/bitop.hpp"

namespace bitop {

#define KTH_BIT(b, k) (((b) >> (k)) & 1)
#define POW2(k) (1ull << (k))

    inline ull next_combination(int n, ull x) {
        if (n == 0) return 1;
        ull a = x & -x;
        ull b = x + a;
        return (x & ~b) / a >> 1 | b;
    }

#define rep_comb(i, n, k) for (ull i = (1ull << (k)) - 1; i < (1ull << (n)); i = bitop::next_combination((n), i))

    inline CONSTEXPR int msb(ull x) {
        int res = x ? 0 : -1;
        if (x & 0xFFFFFFFF00000000) x &= 0xFFFFFFFF00000000, res += 32;
        if (x & 0xFFFF0000FFFF0000) x &= 0xFFFF0000FFFF0000, res += 16;
        if (x & 0xFF00FF00FF00FF00) x &= 0xFF00FF00FF00FF00, res +=  8;
        if (x & 0xF0F0F0F0F0F0F0F0) x &= 0xF0F0F0F0F0F0F0F0, res +=  4;
        if (x & 0xCCCCCCCCCCCCCCCC) x &= 0xCCCCCCCCCCCCCCCC, res +=  2;
        return res + ((x & 0xAAAAAAAAAAAAAAAA) ? 1 : 0);
    }

    inline CONSTEXPR int ceil_log2(ull x) {
        return x ? msb(x - 1) + 1 : 0;
    }
}
#line 2 "library/other/monoid.hpp"

#line 4 "library/other/monoid.hpp"

namespace Monoid {

template<class T> struct Sum {
    using value_type = T;
    static constexpr T op(const T& a, const T& b) { return a + b; }
    static constexpr T id() { return T{0}; }
    static constexpr T inv(const T& a, const T& b) { return a - b; }
    static constexpr T get_inv(const T& a) { return -a; }
};

template<class T, T max_value = infinity<T>::max> struct Min {
    using value_type = T;
    static constexpr T op(const T& a, const T& b) { return a > b ? b : a; }
    static constexpr T id() { return max_value; }
};

template<class T, T min_value = infinity<T>::min> struct Max {
    using value_type = T;
    static constexpr T op(const T& a, const T& b) { return a < b ? b : a;}
    static constexpr T id() { return min_value; }
};

template<class T> struct Assign {
    using value_type = T;
    static constexpr T op(const T&, const T& b) { return b; }
};


template<class T, T max_value = infinity<T>::max> struct AssignMin {
    using M = Min<T, max_value>;
    using E = Assign<T>;
    static constexpr T op(const T& a, const T&) { return a; }
    static constexpr T mul(const T& a, int) { return a; }
    static constexpr T mul_op(const T& a, int, const T&) { return a; }
};

template<class T, T min_value = infinity<T>::min> struct AssignMax {
    using M = Max<T, min_value>;
    using E = Assign<T>;
    static constexpr T op(const T& a, const T&) { return a; }
    static constexpr T mul(const T& a, int) { return a; }
    static constexpr T mul_op(const T& a, int, const T&) { return a; }
};

template<class T> struct AssignSum {
    using M = Sum<T>;
    using E = Assign<T>;
    static constexpr T op(const T& a, const T&) { return a; }
    static constexpr T mul(const T& a, int b) { return a * b; }
    static constexpr T mul_op(const T& a, int b, const T&) { return a * b; }
};

template<class T, T max_value = infinity<T>::max> struct AddMin {
    using M = Min<T, max_value>;
    using E = Sum<T>;
    static constexpr T op(const T& a, const T& b) { return b + a; }
    static constexpr T mul(const T& a, int) { return a; }
    static constexpr T mul_op(const T& a, int, const T& c) { return c + a; }
};

template<class T, T min_value = infinity<T>::min> struct AddMax {
    using M = Max<T, min_value>;
    using E = Sum<T>;
    static constexpr T op(const T& a, const T& b) { return b + a; }
    static constexpr T mul(const T& a, int) { return a; }
    static constexpr T mul_op(const T& a, int, const T& c) { return c + a; }
};

template<class T> struct AddSum {
    using M = Sum<T>;
    using E = Sum<T>;
    static constexpr T op(const T& a, const T& b) { return b + a; }
    static constexpr T mul(const T& a, int b) { return a * b; }
    static constexpr T mul_op(const T& a, int b, const T& c) { return c + a * b; }
};

template<class T, T max_value = infinity<T>::max> struct ChminMin {
    using M = Min<T, max_value>;
    using E = Min<T>;
    static constexpr T op(const T& a, const T& b) { return std::min(b, a); }
    static constexpr T mul(const T& a, int) { return a; }
    static constexpr T mul_op(const T& a, int, const T& c) { return std::min(c, a); }
};

template<class T, T min_value = infinity<T>::min> struct ChminMax {
    using M = Max<T, min_value>;
    using E = Min<T>;
    static constexpr T op(const T& a, const T& b) { return std::min(b, a); }
    static constexpr T mul(const T& a, int) { return a; }
    static constexpr T mul_op(const T& a, int, const T& c) { return std::min(c, a); }
};

template<class T, T max_value = infinity<T>::max> struct ChmaxMin {
    using M = Min<T, max_value>;
    using E = Max<T>;
    static constexpr T op(const T& a, const T& b) { return std::max(b, a); }
    static constexpr T mul(const T& a, int) { return a; }
    static constexpr T mul_op(const T& a, int, const T& c) { return std::max(c, a); }
};

template<class T, T min_value = infinity<T>::min> struct ChmaxMax {
    using M = Max<T, min_value>;
    using E = Max<T>;
    static constexpr T op(const T& a, const T& b) { return std::max(b, a); }
    static constexpr T mul(const T& a, int) { return a; }
    static constexpr T mul_op(const T& a, int, const T& c) { return std::max(c, a); }
};


template<class M> struct ReverseMonoid {
    using value_type = typename M::value_type;
    static value_type op(const value_type& a, const value_type& b) {
        return M::op(b, a);
    }
    static value_type id() { return M::id(); }
    static value_type get_inv(const value_type& a) { return M::get_inv(a); }
};

template<class M_> struct AttachEffector {
    using M = M_;
    using E = M_;
    using T = typename M_::value_type;
    static T op(const T& a, const T& b) { return M_::op(b, a); }
};

template<class E_> struct AttachMonoid {
    using M = E_;
    using E = E_;
    using T = typename E_::value_type;
    static T op(const T& a, const T& b) { return E_::op(b, a); }
};


template<class M, class = void> class has_id : public std::false_type {};
template<class M> class has_id<M, decltype((void)M::id)> : public std::true_type {};

template<class M, class = void> class has_inv : public std::false_type {};
template<class M> class has_inv<M, decltype((void)M::inv)> : public std::true_type {};

template<class M, class = void> class has_get_inv : public std::false_type {};
template<class M> class has_get_inv<M, decltype((void)M::get_inv)> : public std::true_type {};


template<class A, class = void> class has_mul : public std::false_type {};
template<class A> class has_mul<A, decltype((void)A::mul)> : public std::true_type {};

template<class A, class = void> class has_mul_op : public std::false_type {};
template<class A> class has_mul_op<A, decltype((void)A::mul_op)> : public std::true_type {};


template<class T, class = void> class is_semigroup : public std::false_type {};;
template<class T> class is_semigroup<T, decltype(std::declval<typename T::value_type>(), (void)T::op)> : public std::true_type {};

template<class T, class = void> class is_monoid : public std::false_type {};;
template<class T> class is_monoid<T, decltype(std::declval<typename T::value_type>(), (void)T::op, (void)T::id)> : public std::true_type {};

template<class T, class = void> class is_group : public std::false_type {};;
template<class T> class is_group<T, decltype(std::declval<typename T::value_type>(), (void)T::op, (void)T::id, (void)T::get_inv)> : public std::true_type {};

template<class T, class = void> class is_action : public std::true_type {};
template<class T> class is_action<T, decltype(std::declval<typename T::M>(), std::declval<typename T::E>(), (void)T::op)> : public std::false_type {};

} // namespace Monoid
#line 6 "library/data-struct/segment/SegmentTree.hpp"

template<class M> class SegmentTree {
  protected:
    using T = typename M::value_type;
    int n, ori;
    std::vector<T> data;
  public:
    SegmentTree() : SegmentTree(0) {}
    SegmentTree(int n) : SegmentTree(std::vector<T>(n, M::id())) {}
    SegmentTree(const std::vector<T>& v) { init(v); }
    void init(const std::vector<T>& v) {
        ori = v.size();
        n = 1 << bitop::ceil_log2(ori);
        data.assign(n << 1, M::id());
        rep (i, ori) data[n + i] = v[i];
        rrep (i, n, 1) data[i] = M::op(data[i << 1], data[i << 1 ^ 1]);
    }
    template<class Upd> void update(int k, const Upd& upd) {
        assert(0 <= k && k < ori);
        k += n;
        data[k] = upd(data[k]);
        while (k >>= 1) data[k] = M::op(data[k << 1], data[k << 1 ^ 1]);
    }
    void set(int k, T x) {
        update(k, [&](T) -> T { return x; });
    }
    void apply(int k, T x) {
        update(k, [&](T a) -> T { return M::op(a, x); });
    }
    T prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= ori);
        l += n; r += n;
        T lsm = M::id(), rsm = M::id();
        while (l < r) {
            if (l & 1) lsm = M::op(lsm, data[l++]);
            if (r & 1) rsm = M::op(data[--r], rsm);
            l >>= 1; r >>= 1;
        }
        return M::op(lsm, rsm);
    }
    T all_prod() const { return data[1]; }
    T get(int k) const { return data[k + n]; }
    template<class Cond> int max_right(int l, const Cond& cond) const {
        assert(0 <= l && l <= ori);
        assert(cond(M::id()));
        if (l == ori) return ori;
        l += n;
        T sm = M::id();
        do {
            while ((l & 1) == 0) l >>= 1;
            if (!cond(M::op(sm, data[l]))) {
                while (l < n) {
                    l <<= 1;
                    if (cond(M::op(sm, data[l]))) sm = M::op(sm, data[l++]);
                }
                return l - n;
            }
            sm = M::op(sm, data[l++]);
        } while ((l & -l) != l);
        return ori;
    }
    template<class Cond> int min_left(int r, const Cond& cond) const {
        assert(0 <= r && r <= ori);
        assert(cond(M::id()));
        if (r == 0) return 0;
        r += n;
        T sm = M::id();
        do {
            --r;
            while ((r & 1) && r > 1) r >>= 1;
            if (!cond(M::op(data[r], sm))) {
                while (r < n) {
                    r = r << 1 ^ 1;
                    if (cond(M::op(data[r], sm))) sm = M::op(data[r--], sm);
                }
                return r + 1 - n;
            }
            sm = M::op(data[r], sm);
        } while ((r & -r) != r);
        return 0;
    }
};

// verified with test/aoj/DSL/DSL_2_A-RMQ.test.cpp
template<class T, T max_value = infinity<T>::max> using RangeMinimumQuery = SegmentTree<Monoid::Min<T, max_value>>;

template<class T, T min_value = infinity<T>::min> using RangeMaximumQuery = SegmentTree<Monoid::Max<T, min_value>>;

// verified with test/aoj/DSL/DSL_2_B-RSQ.test.cpp
template<class T> using RangeSumQuery = SegmentTree<Monoid::Sum<T>>;

/**
 * @brief SegmentTree()
 * @docs docs/SegmentTree.md
 */
#line 3 "main.cpp"

using namespace std;

void solve();

int main() {
    int t; scanf("%d", &t);
    rep (t) solve();
}

void solve() {
    int n; scanf("%d", &n);
    vector<ll> a(n);
    rep (i, n) scanf("%lld", &a[i]);
    vector<ll> b(n + 1);
    rep (i, n) b[i + 1] = b[i] + a[i];
    presser<ll> ps(b); ps.build();
    ps.press(b);
    RangeMaximumQuery<ll, -inf> seg(ps.size()), seg2(ps.size()), seg3(ps.size());
    seg.apply(ps.get_index(0), 0);
    seg2.apply(ps.get_index(0), 0);
    seg3.apply(ps.get_index(0), 0);
    reps (i, n) {
        ll mx = -inf;
        chmax(mx, seg.prod(0, b[i]) + i);
        chmax(mx, seg2.prod(b[i] + 1, ps.size()) - i);
        chmax(mx, seg3.get(b[i]));
        seg.apply(b[i], mx - i);
        seg2.apply(b[i], mx + i);
        seg3.apply(b[i], mx);
        if (i == n) {
            printf("%lld\n", mx);
        }
    }
}