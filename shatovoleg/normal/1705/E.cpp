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

struct Block {
  array<int, 2> first;
  int ln;
  int paint; // -1 - not paint, 0 - paint zeros, 1 - paint ones
} const Neutral{{-1, -1}, 0, -1}, Zero{{0, -1}, 1, -1};

Block Merge(Block l, Block r) {
  auto [lf, lln, lp] = l;
  auto [rf, rln, rp] = r;

  array<int, 2> first;
  for (int i = 0; i < 2; ++i) {
    if (lf[i] != -1) {
      first[i] = lf[i];
    } else if (rf[i] != -1) {
      first[i] = rf[i] + lln;
    } else {
      first[i] = -1;
    }
  }

  int ln = lln + rln;

  assert(lp == -1 && rp == -1);

  return Block{first, ln, -1};
}

struct SegTree {
  SegTree(int sz) : n(sz) {
    while (n & (n - 1)) {
      n += (n & -n);
    }

    tree.resize(2 * n - 1, Zero);

    for (int i = n - 2; i > -1; --i) {
      recalc(i);
    }
  }

  void recalc(int idx) {
    tree[idx] = Merge(tree[2 * idx + 1], tree[2 * idx + 2]);
  }

  void push(int idx, int l, int r) {
    auto& [first, _, p] = tree[idx];
    if (p == -1) {
      return;
    }
    first = {-1, -1};
    first[p] = 0;
    if (r - l != 1) {
      tree[2 * idx + 1].paint = p;
      tree[2 * idx + 2].paint = p;
    }
    p = -1;
  }

  void paint(int v, int tl, int tr, int l, int r, int clr) {
    push(v, tl, tr);
    if (tl >= r || tr <= l) {
      return;
    }
    if (tl >= l && tr <= r) {
      tree[v].paint = clr;
      push(v, tl, tr);
      return;
    }
    int mid = (tl + tr) >> 1;
    paint(2 * v + 1, tl, mid, l, r, clr);
    paint(2 * v + 2, mid, tr, l, r, clr);
    recalc(v);
  }

  void Paint(int l, int r, int clr) {
    paint(0, 0, n, l, r, clr);
  }

  int GetLastOne() {
    assert(tree[0].first[1] != -1);
    int idx = 0, l = 0, r = n;
    push(idx, l, r);
    while (r - l > 1) {
      int mid = (l + r) >> 1;
      int lchild = 2 * idx + 1, rchild = 2 * idx + 2;
      push(lchild, l, mid);
      push(rchild, mid, r);
      if (tree[rchild].first[1] != -1) {
        l = mid;
        idx = rchild;
      } else {
        r = mid;
        idx = lchild;
      }
    }
    return l;
  }

  Block query(int v, int tl, int tr, int l, int r) {
    if (l >= tr || r <= tl) {
      return Neutral;
    }
    push(v, tl, tr);
    if (tl >= l && tr <= r) {
      return tree[v];
    }
    int mid = (tl + tr) >> 1;
    return Merge(query(2 * v + 1, tl, mid, l, r),
                 query(2 * v + 2, mid, tr, l, r));
  }

  Block query(int l, int r) {
    return query(0, 0, n, l, r);
  }

  void Add(int pos) {  // Add 1 << pos
    auto blk = query(pos, n);
    int fz = blk.first[0];
    assert(fz != -1);
    Paint(pos + fz, pos + fz + 1, 1);
    if (fz != 0) {
      Paint(pos, pos + fz, 0);
    }
  }

  void Sub(int pos) {  // Sub 1 << pos
    auto blk = query(pos, n);
    int fo = blk.first[1];
    assert(fo != -1);
    Paint(pos + fo, pos + fo + 1, 0);
    if (fo != 0) {
      Paint(pos, pos + fo, 1);
    }
  }

  int n;
  vector<Block> tree;
};

void run() {
  constexpr int maxa = int(2e5 + 100);

  int n, q;
  cin >> n >> q;
  SegTree t(maxa);

  vector<int> a(n);
  cin >> a;
  for (auto x : a) {
    t.Add(x);
  }

  for (int i = 0; i < q; ++i) {
    int pos, newval;
    cin >> pos >> newval;
    --pos;
    t.Sub(a[pos]);
    t.Add(a[pos] = newval);
    cout << t.GetLastOne() << '\n';
  }
}