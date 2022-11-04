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
  int n = 1;
  // cin >> n;
  while (n --> 0) {
    solve();
  }
}

constexpr int root = 15'311'432;
const int base_of_order_of_root = 23;
const int order_of_root = 1 << base_of_order_of_root;
constexpr int mod = 998'244'353;

constexpr int K = 19;
constexpr int N = 1 << K;

int mul(int a, int b) {
  return int(1ll * a * b % mod);
}

int rev(int val) {
  if (val == 1) {
    return val;
  }
  return mod - mul(mod / val, rev(mod % val));
}


int roots[N];
int bit_rev[N];

void init() {
  for (int i = 0; i < N; ++i) {
    bit_rev[i] = (bit_rev[i >> 1] >> 1) | ((i & 1) << (K - 1));
  }
  for (int b = 0; (1 << b) < N; ++b) {
    int k = (1 << b);
    // cmpl tmp = polar<ld>(1, M_PI / k);
    int tmp = bpow(root, (order_of_root >> 1) >> b, mod);

    roots[k] = 1;
    for (int i = 1; i < k; ++i) {
      roots[k + i] = roots[(k + i) >> 1];
      if (i & 1) roots[k + i] = mul(roots[k + i], tmp);
    }
  }
}

void fft(array<int, N>& a) {
  for (int i = 0; i < N; ++i) {
    if (bit_rev[i] < i) swap(a[bit_rev[i]], a[i]);
  }
  for (int step = 1; step < N; step <<= 1) {
    for (int i = 0; i < N; i += (step << 1)) {
      for (int j = 0; j < step; ++j) {
        int tmp = mul(a[i + j + step], roots[step + j]);

        a[i + j + step] = a[i + j] - tmp;
        if (a[i + j + step] < 0) {
          a[i + j + step] += mod;
        }

        a[i + j] += tmp;
        if (a[i + j] >= mod) {
          a[i + j] -= mod;
        }
      }
    }
  }
}

void rfft(array<int, N>& a) {
  fft(a);
  int invn = rev(N);
  for (auto& x : a) {
    x = mul(x, invn);
  }
  reverse(1 + all(a));
}

void solve() {
  init();

  int n, k, f;
  cin >> n >> k >> f;
  if (2 * k < f) {
    cout << 0 << endl;
    return;
  }
  array<int, N> dp{};
  fill(dp.begin(), dp.begin() + k + 1, 1);
  for (int i = 0; i < n - 1; ++i) {
    // array<int, N> ndp{};
    // for (int i = 0; i < N; ++i) {
    //   for (int j = 0; j + i < N; ++j) {
    //     ndp[i + j] += mul(dp[i], dp[j]);
    //     if (ndp[i + j] >= mod) {
    //       ndp[i + j] -= mod;
    //     }
    //   }
    // }
    // dp = ndp;

    fft(dp);
    for (auto& x : dp) {
      x = mul(x, x);
    }
    rfft(dp);

    for (int j = N - 2; j > -1; --j) {
      if ((dp[j] += dp[j + 1]) >= mod) {
        dp[j] -= mod;
      }
    }
    for (int j = 0; j < k; ++j) {
      int real_value = dp[j] - dp[j + 1];
      if (real_value < 0) {
        real_value += mod;
      }
      dp[j] += mul(real_value, k - j);
      if (dp[j] >= mod) {
        dp[j] -= mod;
      }
    }
    fill(k + 1 + all(dp), 0);

  }

  int ans = 0;
  for (int i = 0; i <= f; ++i) {
    ans += mul(dp[i], dp[f - i]);
    if (ans >= mod) {
      ans -= mod;
    }
  }

  cout << ans << endl;
}