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
      return get<T>(infinities);
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
inline bool cmin(t1 &a, const t2 &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class t1, class t2>
inline bool cmax(t1 &a, const t2 &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
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
    YPredicate(TLambda&& l) : l_(l) {}

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

template<class ItBegin, class ItEnd, class Container>
struct OwningRange : Range<ItBegin, ItEnd> {
    OwningRange(Container&& container, ItBegin begin, ItEnd end)
      : Range<ItBegin, ItEnd>(begin, end), container_(std::move(container)) {
    }

private:
    Container container_;
};

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

void solve();

constexpr int mod = 998'244'353;

vector<vector<ll>> stirling;

void init(int n) {
    stirling.resize(n);
    for (int i = 0; i < n; ++i) {
        stirling[i].resize(i + 1);
        for (int k = 0; k <= i; ++k) {
            if (i == k) {
                stirling[i][k] = 1;
            } else if (i == 0 || k == 0) {
                stirling[i][k] = 0;
            } else {
                stirling[i][k] = k * stirling[i - 1][k] + stirling[i - 1][k - 1];
                stirling[i][k] %= mod;
            }
        }
    }
}

void run() {
    init(2005);

    int t;
    cin >> t;
    while (t --> 0) {
        solve();
    }
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    const int odd = (m + 1) / 2;
    ll val = bpow(m, n, mod);
    const int rm = bpow(m, mod - 2, mod);

    ll ans = 0;
    for (int i = 0; i <= k; ++i) {
        ans += val * stirling[k][i];
        (val *= (n - i)) %= mod;
        (val *= rm) %= mod;
        (val *= odd) %= mod;
        ans %= mod;
    }
    cout << ans << endl;
}