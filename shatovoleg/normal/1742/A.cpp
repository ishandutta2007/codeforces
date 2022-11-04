#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;

#define all(v) v.begin(), v.end()
#define len(v) ((int)(v).size())
#define pb push_back
#define kek pop_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mp make_pair


template<class T, class Tuple>
struct TupleHasType;

template<class T, class... Ts>
struct TupleHasType<T, const std::tuple<Ts...>>
    : std::disjunction<std::is_same<T, Ts>...> {};

struct NegativeInfType;

struct PositiveInfType {
    static constexpr std::tuple infinities{
      static_cast<int>(1e9) + 666,
      // static_cast<int>(1 << 30),
      static_cast<ll>(1e18) + 666,
      static_cast<double>(1e40l),
      static_cast<float>(1e25),
    };

    template<class T, class = std::enable_if_t<TupleHasType<T, decltype(infinities)>::value>>
    operator T() const {
      return std::get<T>(infinities);
    }

    NegativeInfType operator-() const;
} const INF;

struct NegativeInfType {
    template<class T, class = decltype(T(INF))>
    operator T() const {
        return -(T)INF;
    }
};

NegativeInfType PositiveInfType::operator-() const {
    return {};
}

template<class T>
bool operator==(T val, const PositiveInfType& inf) {
    return val == T(inf);
}

template<class T>
bool operator==(T val, const NegativeInfType& neg_inf) {
    return val == T(neg_inf);
}

const ll INFll = INF;

mt19937 rnd((uint32_t)chrono::high_resolution_clock::now()
                      .time_since_epoch().count());

// mt19937 rnd(666);

template<class t1, class t2>
inline bool cmin(t1& a, const t2& b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class... Types, class tuple>
inline bool cmin(std::tuple<Types&...>&& a, const tuple& b) {
    return cmin(a, b);
}

template<class t1, class t2>
inline bool cmax(t1& a, const t2& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class... Types, class tuple>
inline bool cmax(std::tuple<Types&...>&& a, const tuple& b) {
    return cmax(a, b);
}

inline int bpow(ll a, ll b, int mod) {
    a %= mod;
    int res = 1;
    for (; b; b >>= 1) {
        if (b & 1) {
            res = int(1ll * res * a % mod);
        }
        a *= a;
        a %= mod;
    }
    return res;
}

template<class T1, class T2>
istream& operator>>(istream& in, pair<T1, T2>& p);

template<class T, size_t N>
istream& operator>>(istream& in, array<T, N>& v);

template<class T>
istream& operator>>(istream& in, vector<T>& v);

template<class T>
istream& operator>>(istream& in, vector<T>& v) {
    for (auto& x : v) {
        in >> x;
    }
    return in;
}

template<class T, size_t N>
istream& operator>>(istream& in, array<T, N>& v) {
    for (auto& x : v) {
        in >> x;
    }
    return in;
}

template<class T1, class T2>
istream& operator>>(istream& in, pair<T1, T2>& p) {
    return in >> p.first >> p.second;
}

template<class TLambda>
struct YCombinator {
    YCombinator(TLambda&& l) : l_(std::forward<TLambda>(l)) {}

    template<class... TArgs>
    auto operator()(TArgs&&... args) {
        return l_(*this, std::forward<TArgs>(args)...);
    }

 private:
    TLambda l_;
};

template<class ItBegin, class ItEnd>
struct Range {
    Range(const Range&) = delete;
    Range& operator=(const Range&) = delete;

    Range(Range&&) = default;
    Range& operator=(Range&&) = default;

    Range(ItBegin begin, ItEnd end) : begin_(begin), end_(end) {
    }

    auto begin() const {
        return begin_;
    }

    auto end() const {
        return end_;
    }

 private:
    ItBegin begin_;
    ItEnd end_;
};

template<class Container, class Projection>
struct OwningRange {
 private:
    using Underlying = Range<
      decltype(std::declval<Projection>()(std::begin(std::declval<Container&>()))),
      decltype(std::declval<Projection>()(std::end(  std::declval<Container&>())))>;
 public:
    OwningRange(Container&& container, Projection&& proj)
      : container_(std::move(container)),
        range_(proj(std::begin(container_)), proj(std::end(container_))) {
    }

    auto begin() const {
        return range_.begin();
    }

    auto end() const {
        return range_.end();
    }

 private:
    Container container_;
    Underlying range_;
};

template<class ItType>
class EnumerationIterator {
 public:
    EnumerationIterator(ItType iter) : iter_(move(iter)) {
    }

    EnumerationIterator& operator++() {
        ++iter_;
        ++index_;
        return *this;
    }

    bool operator==(const EnumerationIterator& other) const noexcept {
        return iter_ == other.iter_;
    }

    bool operator!=(const EnumerationIterator& other) const noexcept {
        return !(*this == other);
    }

    template<size_t I>
    auto& get() & {
        if constexpr (I == 0) {
            return index_;
        } else {
            return *iter_;
        }
    }

    template<size_t I>
    auto get() && {
        if constexpr (I == 0) {
            return index_;
        } else {
            return *iter_;
        }
    }

    auto& operator*() & {
        return *this;
    }

    auto operator*() && {
        return *this;
    }

 private:
    size_t index_{0};
    ItType iter_;
};

template<class T>
struct std::tuple_size<EnumerationIterator<T>> : std::integral_constant<size_t, 2> {
};

template<class T, size_t I>
struct std::tuple_element<I, EnumerationIterator<T>> :
    std::tuple_element<I, std::tuple<const size_t, std::remove_reference_t<decltype(*std::declval<T>())>>> {};


[[maybe_unused]] class Enumerator {
 public:
    template<class Container>
    auto operator()(Container&& container) const {
        if constexpr (std::is_lvalue_reference_v<Container&&>) {
            auto begin = EnumerationIterator(std::begin(container));
            auto end   = EnumerationIterator(std::end(container));
            return Range(begin, end);
        } else {
            return OwningRange(std::move(container), [](auto it) {
                return EnumerationIterator(it);
            });
        }
    }
} const Enumerate;

template<class Container>
auto operator|(Container&& container, const Enumerator& enumerate) {
    return enumerate(std::forward<Container>(container));
}

void run();

// #define TASK "rooms"

signed main() {
#if defined(TASK) && !defined(LOCAL)
    freopen(TASK ".in", "r", stdin);
    freopen(TASK ".out", "w", stdout);
#endif
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
}

void solve();

void run() {
    int n;
    cin >> n;
    while (n --> 0) {
        solve();
    }
}

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b + c || b == a + c || c == b + a) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}