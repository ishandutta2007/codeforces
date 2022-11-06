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
      // static_cast<int>(1e9) + 666,
      static_cast<int>(1 << 30),
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

void run() {
    int t = 1;
    // cin >> t;
    while (t --> 0) {
        solve();
    }
}

using Seg = array<ll, 4>;

Seg Merge(const Seg& left, const Seg& right) {
    auto [lmp, lms, lsm, lans] = left;
    auto [rmp, rms, rsm, rans] = right;

    ll max_pref = max(lmp, lsm + rmp);
    ll max_suff = max(rms, rsm + lms);
    ll ans = max(lms + rmp, max(lans, rans));
    ll sum = lsm + rsm;

    return {max_pref, max_suff, sum, ans};
}

void solve() {
    int n;
    cin >> n;

    vector<ll> v(1 << n);
    cin >> v;

    auto Build = YPredicate([]<class It>(auto& Build, It begin, It end, int n) -> vector<Seg> {
        if (n == 0) {
            ll opt = max(0ll, *begin);
            return {{opt, opt, *begin, opt}};
        }
        auto left = Build(begin, begin + (1 << (n - 1)), n - 1);
        auto right = Build(begin + (1 << (n - 1)), end, n - 1);

        vector<Seg> ans;
        ans.reserve(1 << n);
        for (int i = 0; i < (1 << (n - 1)); ++i) {
            ans.emplace_back(Merge(left[i], right[i]));
        }
        for (int i = 0; i < (1 << (n - 1)); ++i) {
            ans.emplace_back(Merge(right[i], left[i]));
        }
        return ans;
    });

    auto Ans = Build(all(v), n);
    int cur = 0;
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int k;
        cin >> k;
        cur ^= (1 << k);

        cout << Ans[cur].back() << '\n';
    }
}