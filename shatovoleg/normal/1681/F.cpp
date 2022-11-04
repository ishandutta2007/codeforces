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

struct DSU {
  DSU() = default;

  DSU(int n) : l(n), s(n, 1) {
    iota(all(l), 0);
  }

  int GetRoot(int v) {
    while (l[v] != v) {
      v = l[v];
    }
    return v;
  }

  void Union(int u, int v) {
    u = GetRoot(u); v = GetRoot(v);
    assert(u != v);
    if (s[u] > s[v]) {
      swap(u, v);
    }
    actions.pb({&l[u], l[u]});
    l[u] = v;
    actions.pb({&s[v], s[v]});
    s[v] += s[u];
  }

  int GetSize(int v) {
    return s[GetRoot(v)];
  }

  void Undo() {
    for (int i = 0; i < 2; ++i) {
      auto [addr, value] = actions.back();
      actions.kek();
      *addr = value;
    }
  }

  void Undo(int n) {
    for (int i = 0; i < n; ++i) {
      Undo();
    }
  }

  vector<int> l, s;
  vector<pair<int*, int>> actions;
};

vector<vector<pii>> edges;
DSU d;

ll solve(int l, int r) {
  if (r - l == 1) {
    ll ans = 0;
    for (auto [u, v] : edges[l]) {
      ans += 1ll * d.GetSize(u) * d.GetSize(v);
    }
    return ans;
  }
  int mid = (r + l) >> 1;
  int cnt = 0;
  for (int i = l; i < mid; ++i) {
    for (auto [u, v] : edges[i]) {
      d.Union(u, v);
      ++cnt;
    }
  }
  ll ans = solve(mid, r);
  d.Undo(cnt);
  cnt = 0;
  for (int i = mid; i < r; ++i) {
    for (auto [u, v] : edges[i]) {
      d.Union(u, v);
      ++cnt;
    }
  }
  ans += solve(l, mid);
  d.Undo(cnt);
  return ans;
}

void run() {
  int n;
  cin >> n;
  d = DSU(n);
  vector<array<int, 3>> edges(n - 1);
  vector<int> crd;
  for (auto& [u, v, c] : edges) {
    cin >> u >> v >> c;
    --u, --v;
    crd.push_back(c);
  }
  sort(all(crd));
  crd.resize(unique(all(crd)) - crd.begin());
  for (auto& [u, v, c] : edges) {
    c = (int)(lower_bound(all(crd), c) - crd.begin());
  }
  ::edges.resize(len(crd));
  for (auto [u, v, c] : edges) {
    ::edges[c].push_back({u, v});
  }

  cout << solve(0, len(crd)) << endl;
}