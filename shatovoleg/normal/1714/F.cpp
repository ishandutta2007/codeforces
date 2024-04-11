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
mt19937 rnd((uint32_t)chrono::high_resolution_clock::now().time_since_epoch().count());
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

void solve() {
    int n, d12, d23, d31;
    cin >> n >> d12 >> d23 >> d31;
    if ((d12 ^ d23 ^ d31) & 1) {
        cout << "NO\n";
        return;
    }
    const int sm = (d12 + d23 + d31) >> 1;
    const int d1 = sm - d23, d2 = sm - d31, d3 = sm - d12;
    if (d1 < 0 || d2 < 0 || d3 < 0) {
        cout << "NO\n";
        return;
    }
    if (d1 + d2 + d3 + 1 > n) {
        cout << "NO\n";
        return;
    }

    vector<pii> ans;
    int c = 4;
    int unused = 5;

    auto build_path = [&ans, &unused](int from, int to, int length) {
        for (int i = 0; i + 1 < length; ++i) {
            ans.emplace_back(from, unused);
            from = unused++;
        }
        if (length != 0) {
            ans.emplace_back(from, to);
        }
    };

    build_path(c, 1, d1);
    build_path(c, 2, d2);
    build_path(c, 3, d3);

    int replace_c_with = -1;
    if (d1 == 0) {
        replace_c_with = 1;
    } else if (d2 == 0) {
        replace_c_with = 2;
    } else if (d3 == 0) {
        replace_c_with = 3;
    }

    if (replace_c_with != -1) {
        for (auto& [u, v] : ans) {
            if (u == c) {
                u = replace_c_with;
            } else if (v == c) {
                v = replace_c_with;
            }
            if (u > c) {
                --u;
            }
            if (v > c) {
                --v;
            }
        }
        --unused;
        c = replace_c_with;
    }
    while (unused <= n) {
        ans.emplace_back(c, unused++);
    }
    cout << "YES\n";
    for (auto [u, v] : ans) {
        cout << u << " " << v << '\n';
    }
}