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

void solve() {
    int n;
    cin >> n;

    const int r = rnd() % (1 << n);

    auto ask = [r](int i, int j) {
        if (i == -1) {
            return 2;
        }
        if (j == -1) {
            return 1;
        }
        cout << "? " << (r ^ i) + 1 << " " << (r ^ j) + 1 << endl;
        int ret;
        cin >> ret;
        return ret;
    };

    auto answer = [r](int i) {
        cout << "! " << (r ^ i) + 1 << endl;
    };

    auto solve = YPredicate([&](auto& solve, int l, int n) -> int {
        const int r = l + (1 << n);
        if (n == 0) {
            return l;
        }
        if (n & 1) {
            int ans[] = {-1, solve(l, n - 1), solve(l + (1 << (n - 1)), n - 1)};
            return ans[ask(ans[1], ans[2])];
        }

        int ln = (1 << (n - 2));
        int arr[] = {solve(l, n - 2), solve(l + ln, n - 2),
                     solve(l + 2 * ln, n - 2), solve(r - ln, n - 2)};

        int defeated[4]{};

        for (int i = 0; i < 2; ++i) {
            if (!defeated[i] && !defeated[i + 2]) {
                int r = ask(arr[i], arr[i + 2]);
                if (r == 0) {
                    defeated[i] = defeated[i + 2] = 1;
                } else if (r == 1) {
                    defeated[i ^ 1] = defeated[i + 2] = 1;
                } else if (r == 2) {
                    defeated[(i + 2) ^ 1] = defeated[i] = 1;
                }
            }
        }

        int winner = -1;

        for (int i = 0; i < 4; ++i) {
            if (defeated[i]) continue;
            if (int r = ask(winner, arr[i]); r == 2) {
                winner = arr[i];
            } else if (r == 0) {
                winner = -1;
            }
        }

        return winner;
    });

    answer(solve(0, n));
}