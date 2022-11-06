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

void run() {
    int t;
    cin >> t;
    while (t --> 0) {
        solve();
    }
}

void SuffMax(vector<int>& v) {
    v.push_back(-INF);
    for (int i = len(v) - 2; i > -1; --i) {
        cmax(v[i], v[i + 1]);
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> first_row(n);
    vector<int> second_row(n);

    cin >> first_row >> second_row;
    first_row[0] = -1;

    vector<int> fr1 = first_row, fr2 = first_row;
    vector<int> sr1 = second_row, sr2 = second_row;

    for (int i = 0; i < n; ++i) {
        fr1[i] -= i;
        fr2[i] += i;

        sr1[i] += i;
        sr2[i] -= i;
    }
    SuffMax(fr1); SuffMax(fr2); SuffMax(sr1); SuffMax(sr2);

    int cur_mx = 0;
    int ans = INF;
    ans <<= 1;

    for (int i = 0; i <= n; ++i) {
        int cur_ans = cur_mx;
        if (i & 1) {
            cmax(cur_ans, sr2[i] - i + 1);
            cmax(cur_ans, fr2[i] - i - 2 * n + 2);
        } else {
            cmax(cur_ans, fr1[i] - i + 1);
            cmax(cur_ans, sr1[i] - i - 2 * n + 2);
        }
        cmin(ans, cur_ans);
        if (i != n) {
            int curt = 2 * i;
            if (i & 1) {
                cmax(cur_mx, second_row[i] - curt + 1);
                cmax(cur_mx, first_row[i] - curt);
            } else {
                cmax(cur_mx, first_row[i] - curt + 1);
                cmax(cur_mx, second_row[i] - curt);
            }
        }
    }
    cout << ans + 2 * n - 1 << endl;
}