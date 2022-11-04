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
// mt19937 rnd((uint32_t)chrono::high_resolution_clock::now().time_since_epoch().count());
mt19937 rnd(666);

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
  int n;
  cin >> n;
  while (n --> 0) {
    solve();
  }
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<ll> a(n), b(n);
  cin >> a >> b;
  partial_sum(all(a), a.begin()); a.insert(a.begin(), 0);
  partial_sum(all(b), b.begin()); b.insert(b.begin(), 0);
  vector<pii> segs(m);
  vector<vector<int>> ends(n + 1);
  for (auto& [l, r] : segs) {
    cin >> l >> r;
    --l;
  }
  for (int i = 0; i < m; ++i) {
    ends[segs[i].first].pb(i);
    ends[segs[i].second].pb(i);
  }

  vector<int> badness(m, 2);
  for (int i = 0; i <= n; ++i) {
    if (a[i] == b[i]) {
      for (auto x : ends[i]) {
        --badness[x];
      }
    }
  }

  vector<int> next(n + 2);
  iota(all(next), 0);
  auto GetRoot = YPredicate([&next](auto& GetRoot, int v) -> int {
    if (next[v] == v) {
      return next[v];
    }
    return next[v] = GetRoot(next[v]);
  });
  for (int i = 0; i <= n; ++i) {
    if (a[i] == b[i]) {
      ++next[i];
    }
  }

  vector<int> q;
  for (int i = 0; i < m; ++i) {
    if (badness[i] == 0) {
      q.push_back(i);
    }
  }
  while (len(q)) {
    {
      auto idx = rnd() % q.size();
      swap(q[idx], q.back());
    }
    auto v = q.back();
    q.pop_back();
    auto [l, r] = segs[v];
    assert(a[l] == b[l] && a[r] == b[r]);
    l = GetRoot(l);
    while (l < r) {
      ++next[l];
      a[l] = b[l];
      for (auto x : ends[l]) {
        if (--badness[x] == 0) {
          q.push_back(x);
        }
      }
      l = GetRoot(l);
    }
  }
  if (a == b) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}