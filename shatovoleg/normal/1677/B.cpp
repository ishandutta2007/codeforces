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


struct InfType {
    static constexpr int int_inf = static_cast<int>(1e9 + 666);
    static constexpr ll ll_inf = (ll)3e18 + 666;

    operator int() const {
        return int_inf;
    }

    operator long long() const {
        return ll_inf;
    }
} const INF;

template<class T>
bool operator==(T val, const InfType& inf) {
    return val == T(inf);
}

const ll INFll = INF;
mt19937 rnd((uint32_t)chrono::high_resolution_clock::now().time_since_epoch().count());

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
//  int n;
//  cin >> n;
//  vector<int> a(n);
//  cin >> a;
//  vector<int> left(n, 0), right(n, 0);
//  for (int i = 0; i < n; ++i) {
//    for (int j = 0; j < i; ++j) {
//      if (a[j] < a[i]) {
//        ++left[i];
//      }
//      if (a[j] > a[i]) {
//        ++right[j];
//      }
//    }
//  }
//  ll ans = 0;
//  for (int i = 0; i < n; ++i) {
//    for (int j = 0; j < i; ++j) {
//      ans += left[i] * right[j];
//    }
//  }
//  cout << ans << endl;
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  vector<vector<char>> fld(n, vector<char>(m, 0));
  reverse(all(s));
  for (int i = 0; i < len(s); ++i) {
    fld[i / m][i % m] = (s[i] - '0');
  }
  vector<int> ans(n * m);
  for (int i = 0; i < m; ++i) {
    for (int j = n - 1; j > -1; --j) {
      if (fld[j][i] == 1) {
        ans[(n - j - 1) * m + (m - i - 1)]++;
        break;
      }
    }
  }
  reverse(all(s));
  for (int i = 0; i < n; ++i) {
    ++ans[i * m];
  }
  vector<int> sub(m, 0);
  int curans = 0;
  int last1 = -m;
  for (int i = 0; i < n * m; ++i) {
    if (s[i] == '1') {
      last1 = i;
    }
    if (i - last1 >= m) {
      ++sub[i % m];
    }
    curans += ans[i];
    cout << curans - sub[i % m] << " ";
  }
  cout << endl;
}