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

using point = array<int, 2>;

ll dist(point a, point b) {
  int res = 0;
  for (int i = 0; i < 2; ++i) {
    res += abs(a[i] - b[i]);
  }
  return res;
}

struct Node {
  array<point, 2> start{}, finish{};
  array<array<ll, 2>, 2> dist{};

  Node(array<point, 2> start, array<point, 2> finish) : start(start), finish(finish) {
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        auto s = start[i];
        s[i]++;
        dist[i][j] = ::dist(s, finish[j]) + 1;
      }
    }
  }

  Node() {
    for (auto& line : dist) {
      for (auto& x : line) {
        x = INF;
      }
    }
  }
};

Node Merge(const Node& a, const Node& b) {
  Node result;
  result.start = a.start;
  result.finish = b.finish;
  for (int sa = 0; sa < 2; ++sa) {
    for (int fb = 0; fb < 2; ++fb) {
      for (int fa = 0; fa < 2; ++fa) {
        for (int sb = 0; sb < 2; ++sb) {
          cmin(result.dist[sa][fb], a.dist[sa][fa] + b.dist[sb][fb] + dist(a.finish[fa], b.start[sb]));
        }
      }
    }
  }
  return result;
}

struct SegTree {
  SegTree(int sz) : n(sz) {
    while (n & (n - 1)) ++n;

    tree.resize(2 * n - 1);
  }

  void update(int idx, const Node& value) {
    idx += n - 1;
    tree[idx] = value;

    while (idx > 0) {
      idx = (idx - 1) >> 1;
      tree[idx] = Merge(tree[2 * idx + 1], tree[2 * idx + 2]);
    }
  }

  Node query(int v, int tl, int tr, int l, int r) {
    assert(l < tr && r > tl);
    if (tl >= l && tr <= r) {
      return tree[v];
    }
    int mid = (tl + tr) >> 1;
    if (mid >= r) {
      return query(2 * v + 1, tl, mid, l, r);
    }
    if (mid <= l) {
      return query(2 * v + 2, mid, tr, l, r);
    }
    return Merge(query(2 * v + 1, tl, mid, l, r), query(2 * v + 2, mid, tr, l, r));
  }

  Node query(int l, int r) {
    return query(0, 0, n, l, r);
  }

  vector<Node> tree;
  int n;
};

void run() {
  int n;
  cin >> n;
  vector<array<point, 2>> doors(n - 1);
  for (auto& p : doors) {
    for (auto& door : p) {
      for (auto& x : door) {
        cin >> x;
        --x;
      }
    }
  }
  SegTree t(n - 1);
  for (int i = 0; i + 1 < n; ++i) {
    auto nxt_door = doors[i];
    for (int j = 0; j < 2; ++j) {
      nxt_door[j][j]++;
    }
    t.update(i, {doors[i], nxt_door});
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    array<point, 2> query;
    for (auto& p : query) {
      for (auto& x : p) {
        cin >> x;
        --x;
      }
    }
    auto [start, finish] = query;
    int ls = max(start[0], start[1]), lf = max(finish[0], finish[1]);
    if (ls == lf) {
      cout << dist(start, finish) << '\n';
      continue;
    }
    if (ls > lf) {
      swap(start, finish);
      swap(ls, lf);
    }
    auto node = t.query(ls, lf);
    ll ans = INF;
    for (int s = 0; s < 2; ++s) {
      for (int f = 0; f < 2; ++f) {
        cmin(ans, dist(start, node.start[s]) + node.dist[s][f] + dist(node.finish[f], finish));
      }
    }
    cout << ans << '\n';
  }
}