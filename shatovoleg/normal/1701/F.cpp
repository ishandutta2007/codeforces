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

void solve();

void run() {
  int t = 1;
  while (t --> 0) {
    solve();
  }
}

ll c2(int n) {
  return 1ll * n * (n - 1) >> 1;
}

#define Get(v, prop) ((v) ? (v)->prop : 0)

struct Node {
  int key;
  int val;
  ll sub_sum;
  int sz;
  int add = 0;
  Node *l = nullptr, *r = nullptr;

  Node(int key, int val) : key(key), val(val) {
    recalc();
  }

  void recalc() {
    sub_sum = Get(l, sub_sum) + Get(r, sub_sum) + val;
    sz = Get(l, sz) + Get(r, sz) + 1;
  }

  void push() {
    if (l) {
      l->add += add;
    }
    if (r) {
      r->add += add;
    }
    val += add;
    sub_sum += add * sz;
    add = 0;
  }

  ~Node() {
    if (l) {
      delete l;
    }
    if (r) {
      delete r;
    }
  }
};

Node* Merge(Node* l, Node* r) {
  if (!l) {
    if (r) {
      r->push();
    }
    return r;
  }
  if (!r) {
    l->push();
    return l;
  }
  if (rnd() % (Get(l, sz) + Get(r, sz)) < Get(l, sz)) {
    l->push();
    l->r = Merge(l->r, r);
    if (l->l) {
      l->l->push();
    }
    l->recalc();
    return l;
  } else {
    r->push();
    r->l = Merge(l, r->l);
    if (r->r) {
      r->r->push();
    }
    r->recalc();
    return r;
  }
}

pair<Node*, Node*> Split(Node* t, int key) {
  if (!t) {
    return {nullptr, nullptr};
  }
  t->push();
  if (key <= t->key) {
    auto [l, r] = Split(t->l, key);
    t->l = r;
    if (t->r) {
      t->r->push();
    }
    t->recalc();
    return {l, t};
  } else {
    auto [l, r] = Split(t->r, key);
    t->r = l;
    if (t->l) {
      t->l->push();
    }
    t->recalc();
    return {t, r};
  }
}

void Insert(Node*& t, Node* v) {
  if (rnd() % (Get(t, sz) + 1) == 0) {
    auto [l, r] = Split(t, v->key);
    t = Merge(l, Merge(v, r));
    return;
  }
  t->push();
  if (v->key > t->key) {
    Insert(t->r, v);
  } else {
    Insert(t->l, v);
  }
  t->recalc();
}

void Erase(Node*& t, int key) {
  if (!t) {
    return;
  }
  if (key > t->key) {
    Erase(t->r, key);
  } else if (key < t->key) {
    Erase(t->l, key);
  } else {
    Node* cp = t;
    t = Merge(t->l, t->r);
    cp->l = cp->r = nullptr;
    delete cp;
    return;
  }
  t->recalc();
}

bool Exists(Node* t, int key) {
  if (!t) {
    return false;
  }
  if (key > t->key) {
    return Exists(t->r, key);
  }
  if (key < t->key) {
    return Exists(t->l, key);
  }
  return true;
}

void solve() {
  int q, d;
  cin >> q >> d;

  Node* root = nullptr;
  ll cnt = 0;

  auto add = [&cnt, &root, d](int x) {
    auto [l, tmp] = Split(root, x - d);
    auto [mid, r] = Split(tmp, x);
    if (mid) {
      cnt += mid->sub_sum;
      mid->add += 1;
      mid->push();
    }

    auto [rseg, rest] = Split(r, x + d + 1);
    int sz = Get(rseg, sz);
    cnt += c2(sz);

    Node* nw = new Node(x, sz);

    root = Merge(Merge(Merge(l, mid), nw), Merge(rseg, rest));
  };

  auto remove = [&cnt, &root, d](int x) {
    auto [lrest, tmp1] = Split(root, x - d);
    auto [mid, tmp2] = Split(tmp1, x);
    auto [node, rrest] = Split(tmp2, x + 1);
    assert(node);
    if (mid) {
      mid->add -= 1;
      mid->push();
      cnt -= mid->sub_sum;
    }
    cnt -= c2(node->val);

    delete node;

    root = Merge(Merge(lrest, mid), rrest);
  };

  for (int i = 0; i < q; ++i) {
    int v;
    cin >> v;
    if (Exists(root, v)) {
      remove(v);
    } else {
      add(v);
    }
    cout << cnt << '\n';
  }
  delete root;
}