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


struct NegativeInfType;

struct PositiveInfType {
    static constexpr std::tuple infinities{
      static_cast<int>(1e9) + 666,
      // static_cast<int>(1 << 30),
      static_cast<ll>(1e18) + 666,
      static_cast<double>(1e40l),
      static_cast<float>(1e25),
    };

    template<class T>
    operator T() const {
      return std::get<T>(infinities);
    }

    NegativeInfType operator-() const;
} const INF;

struct NegativeInfType {
    template<class T>
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

template<class TLambda>
struct YPredicate {
    YPredicate(TLambda&& l) : l_(std::forward<TLambda>(l)) {}

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

// #define TASK "taskname"

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

array<array<array<char, 3>, 3>, 3> reachable(char fld[3][3][3], int x, int y, int z) {
    array<array<array<char, 3>, 3>, 3> result{};
    result[x][y][z] = 1;
    for (int i = x; i < 3; ++i) {
        for (int j = y; j < 3; ++j) {
            for (int k = z; k < 3; ++k) {
                if (fld[i][j][k] == '0') {
                    result[i][j][k] = 0;
                }
                if (!result[i][j][k]) {
                    continue;
                }
                if (i + 1 < 3) {
                    result[i + 1][j][k] = 1;
                }
                if (j + 1 < 3) {
                    result[i][j + 1][k] = 1;
                }
                if (k + 1 < 3) {
                    result[i][j][k + 1] = 1;
                }
            }
        }
    }
    return result;
}

bool check_center(char fld[3][3][3]) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                if (i + j + k == 3) continue;
                if (fld[i][j][k] != '1') continue;
                auto r1 = reachable(fld, i, j, k);
                fld[1][1][1] = '0';
                auto r2 = reachable(fld, i, j, k);
                fld[1][1][1] = '1';
                r1[1][1][1] = 0;
                if (r1 != r2) {
                    return true;
                }
            }
        }
    }
    return false;
}

void run() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<string>> proc(n, vector<string>(m));
    cin >> proc;

    proc.insert(proc.begin(), vector<string>(m, string(k, '0')));
    proc.pb(vector<string>(m, string(k, '0')));
    n += 2;
    for (int i = 0; i < n; ++i) {
        proc[i].insert(proc[i].begin(), string(k, '0'));
        proc[i].pb(string(k, '0'));
        for (int j = 0; j < m + 2; ++j) {
            proc[i][j].insert(proc[i][j].begin(), '0');
            proc[i][j].pb('0');
        }
    }
    m += 2;
    k += 2;

    int ans = 0;
    for (int i = 1; i + 1 < n; ++i) {
        for (int j = 1; j + 1 < m; ++j) {
            for (int l = 1; l + 1 < k; ++l) {
                if (proc[i][j][l] == '0') continue;
                char fld[3][3][3]{};
                for (int a = 0; a < 3; ++a) {
                    for (int b = 0; b < 3; ++b) {
                        for (int c = 0; c < 3; ++c) {
                            fld[a][b][c] = proc[i + a - 1][j + b - 1][l + c - 1];
                        }
                    }
                }
                ans += check_center(fld);
            }
        }
    }

    cout << ans << endl;
}