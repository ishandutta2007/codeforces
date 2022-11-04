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

struct SparseTable {
  SparseTable(const vector<int>& v) {
    table.emplace_back(v);
    for (int i = 0; (1 << (i + 1)) <= len(v); ++i) {
      table.emplace_back(len(v) - (1 << (i + 1)) + 1);
      for (int j = 0; j < len(table.back()); ++j) {
        table.back()[j] = max(table[i][j], table[i][j + (1 << i)]);
      }
    }

    lg.resize(len(v) + 1, -1);
    for (int i = 1; i <= len(v); ++i) {
      lg[i] = lg[i >> 1] + 1;
    }
  }

  int query(int l, int r) const {
    int lvl = lg[r - l];
    return max(table[lvl][l], table[lvl][r - (1 << lvl)]);
  }

  vector<vector<int>> table;
  vector<int> lg;
};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  cin >> a;
  
  SparseTable t(a);

  int q;
  cin >> q;
  while (q --> 0) {
    int x1, y1, x2, y2, k;
    cin >> x1 >> y1 >> x2 >> y2 >> k;
    --x1, --y1, --x2, --y2;
    if (y1 > y2) {
      swap(x1, x2);
      swap(y1, y2);
    }

    if ((x1 - x2) % k != 0 || (y1 - y2) % k != 0) {
      cout << "NO\n";
      continue;
    }
    if (y1 == y2) {
      cout << "YES\n";
      continue;
    }
    int mx = t.query(y1, y2);
    int maxx = x1 + (n - 1 - x1) / k * k;
    if (maxx >= mx) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}