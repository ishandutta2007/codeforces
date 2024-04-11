#include <bits/stdc++.h>
using namespace std;

string to_string(string s) { return '"' + s + '"'; }
string to_string(bool b) { return b ? "true" : "false"; }
template <size_t N> string to_string(bitset<N> bs) {
  string res;
  for (size_t i = 0; i < N; ++i) res += '0' + bs[i];
  return res;
}
string to_string(vector<bool> v) {
  string res = "{";
  for (bool e : v) res += to_string(e) + ", ";
  return res += "}";
}
template <class T, class U> string to_string(pair<T, U> p);
template <class C> string to_string(C c) {
  string res = "{";
  for (auto e : c) res += to_string(e) + ", ";
  return res += "}";
}
template <class T, class U> string to_string(pair<T, U> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
void debug() { cerr << '\n'; }
template <class Head, class... Tail> void debug(Head head, Tail... tail) {
  cerr << '\t' << to_string(head), debug(tail...);
}
#ifdef LOCAL
#define DEBUG(...) cerr << "[" << #__VA_ARGS__ << "]:", debug(__VA_ARGS__)
#else
#define DEBUG(...)
#endif

template <class T> struct fenwick_mul {
  const int n;
  vector<T> t;
  fenwick_mul(int _n = -1) : n(_n), t(n + 1, 1) {}
  void mul(int i, T a) { for (++i; i <= n; i += i & -i) t[i] *= a; }
  T prod(int i) const {
    T s = 1;
    for (; i; i -= i & -i) s *= t[i];
    return s;
  }
};

template <class T> struct fenwick2d_mul {
  vector<pair<int, int>> p;
  vector<int> xs;
  vector<vector<int>> ys;
  int n;
  vector<fenwick_mul<T>> ft;
  void add_point(int x, int y) { p.emplace_back(x, y), xs.push_back(x); }
  void build() {
    sort(begin(xs), end(xs));
    xs.erase(unique(begin(xs), end(xs)), end(xs));
    n = xs.size();
    ys.resize(n + 1);
    for (auto e : p) {
      int x = zip(e.first);
      for (++x; x <= n; x += x & -x) ys[x].push_back(e.second);
    }
    for (auto&& v : ys) {
      sort(begin(v), end(v));
      v.erase(unique(begin(v), end(v)), end(v));
      ft.emplace_back(v.size());
    }
  }
  int zip(int x) const {
    return lower_bound(begin(xs), end(xs), x) - begin(xs);
  }
  int zip(int x, int y) const {
    return lower_bound(begin(ys[x]), end(ys[x]), y) - begin(ys[x]);
  }
  void mul(int x, int y, T a) {
    x = zip(x);
    for (++x; x <= n; x += x & -x) ft[x].mul(zip(x, y), a);
  }
  T prod(int x, int y) const {
    x = zip(x);
    T s = 1;
    for (; x; x -= x & -x) s *= ft[x].prod(zip(x, y));
    return s;
  }
};

template <class T> struct fenwick {
  const int n;
  vector<T> t;
  fenwick(int _n = -1) : n(_n), t(n + 1) {}
  void add(int i, T a) { for (++i; i <= n; i += i & -i) t[i] += a; }
  T sum(int i) const {
    T s = 0;
    for (; i; i -= i & -i) s += t[i];
    return s;
  }
};

template <class T> struct fenwick2d {
  vector<pair<int, int>> p;
  vector<int> xs;
  vector<vector<int>> ys;
  int n;
  vector<fenwick<T>> ft;
  void add_point(int x, int y) { p.emplace_back(x, y), xs.push_back(x); }
  void build() {
    sort(begin(xs), end(xs));
    xs.erase(unique(begin(xs), end(xs)), end(xs));
    n = xs.size();
    ys.resize(n + 1);
    for (auto e : p) {
      int x = zip(e.first);
      for (++x; x <= n; x += x & -x) ys[x].push_back(e.second);
    }
    for (auto&& v : ys) {
      sort(begin(v), end(v));
      v.erase(unique(begin(v), end(v)), end(v));
      ft.emplace_back(v.size());
    }
  }
  int zip(int x) const {
    return lower_bound(begin(xs), end(xs), x) - begin(xs);
  }
  int zip(int x, int y) const {
    return lower_bound(begin(ys[x]), end(ys[x]), y) - begin(ys[x]);
  }
  void add(int x, int y, T a) {
    x = zip(x);
    for (++x; x <= n; x += x & -x) ft[x].add(zip(x, y), a);
  }
  T sum(int x, int y) const {
    x = zip(x);
    T s = 0;
    for (; x; x -= x & -x) s += ft[x].sum(zip(x, y));
    return s;
  }
};

template <class T, class Op = multiplies<T>>
T power(T a, long long n, Op op = multiplies<T>(), T e = {1}) {
  assert(n >= 0);
  while (n) {
    if (n & 1) e = op(e, a);
    if (n >>= 1) a = op(a, a);
  }
  return e;
}

template <unsigned M> struct modular {
  using m = modular;
  unsigned v;
  modular(long long x = 0) : v((x %= M) < 0 ? x + M : x) {}
  m operator-() const { return m() -= *this; }
  m& operator+=(m b) { if ((v += b.v) >= M) v -= M; return *this; }
  m& operator-=(m b) { if (v < b.v) v += M; v -= b.v; return *this; }
  m& operator*=(m b) {
    auto x = (uint64_t)v * b.v;
    unsigned xu = x >> 32, xl = x, d;
    asm("divl %4; \n\t" : "=a" (d), "=d" (v) : "d" (xu), "a" (xl), "r" (M));
    return *this;
  }
  m& operator/=(m b) { return *this *= power(b, M - 2); }
  friend m operator+(m a, m b) { return a += b; }
  friend m operator-(m a, m b) { return a -= b; }
  friend m operator*(m a, m b) { return a *= b; }
  friend m operator/(m a, m b) { return a /= b; }
  friend bool operator==(m a, m b) { return a.v == b.v; }
  friend string to_string(m a) { return to_string(a.v); }
};

constexpr long long mod = 1e9 + 7;
using mint = modular<mod>;

struct point {
  int x, y;
  mint w;
  friend string to_string(point p) {
    return "(" + to_string(p.x) + ", " + to_string(p.y) + ", " + to_string(p.w) + ")";
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  struct edge {
    int u, v, c;
    mint x;
  };
  vector<edge> es;
  vector<vector<int>> g(n);
  for (int id = 0; id < n - 1; ++id) {
    int u, v, c;
    mint x;
    cin >> u >> v >> x.v >> c;
    --u, --v;
    es.push_back({u, v, c, x});
    g[u].push_back(id);
    g[v].push_back(id);
  }
  auto other = [&](int id, int v) {
    return es[id].u ^ es[id].v ^ v;
  };
  vector<bool> ex(n, true);
  vector<int> sz(n), par(n);
  auto centroids = [&](int r, int cur_n) {
    vector<int> res;
    auto dfs = [&](auto&& self, int v, int p) -> void {
      sz[v] = 1, par[v] = p;
      bool ok = true;
      for (int id : g[v]) {
        int u = other(id, v);
        if (ex[u] and u != p) {
          self(self, u, v);
          sz[v] += sz[u];
          ok &= 2 * sz[u] <= cur_n;
        }
      }
      if (ok and 2 * sz[v] >= cur_n) {
        res.push_back(v);
      }
    };
    dfs(dfs, r, -1);
    return res;
  };
  auto f = [](vector<point> ps) {
    mint res = 1;
    // for (int j = 0; j < (int)ps.size(); ++j) {
    //   for (int i = 0; i < j; ++i) {
    //     if (ps[i].x + ps[j].x <= 0 and ps[i].y + ps[j].y <= 0) {
    //       res *= ps[i].w * ps[j].w;
    //     }
    //   }
    // }
    // DEBUG(ps, res);
    fenwick2d_mul<mint> ftm;
    fenwick2d<int> ft;
    for (auto&& p : ps) {
      ftm.add_point(p.x, p.y);
      ft.add_point(p.x, p.y);
    }
    ftm.build(), ft.build();
    for (auto&& p : ps) {
      res *= ftm.prod(-p.x + 1, -p.y + 1) * power(p.w, ft.sum(-p.x + 1, -p.y + 1));
      ftm.mul(p.x, p.y, p.w);
      ft.add(p.x, p.y, 1);
    }
    return res;
  };
  vector<point> ps;
  mint res = 1;
  auto dfs = [&](auto&& self, int v, int p, array<int, 2> cnt, mint w) -> void {
    if (cnt[0] <= 2 * cnt[1] and cnt[1] <= 2 * cnt[0]) {
      res *= w;
    }
    ps.push_back({cnt[0] - 2 * cnt[1], cnt[1] - 2 * cnt[0], w});
    for (int id : g[v]) {
      int u = other(id, v);
      if (ex[u] and u != p) {
        self(self, u, v, {cnt[0] + (es[id].c == 0), cnt[1] + (es[id].c == 1)}, w * es[id].x);
      }
    }
  };
  auto rec = [&](auto&& self, int c, int cur_n) -> void {
    c = centroids(c, cur_n)[0];
    ex[c] = false;
    ps.clear();
    for (int id : g[c]) {
      int v = other(id, c);
      if (ex[v]) {
        int prv = ps.size();
        dfs(dfs, v, c, {es[id].c == 0, es[id].c == 1}, es[id].x);
        res /= f({begin(ps) + prv, end(ps)});
      }
    }
    res *= f(ps);
    for (int id : g[c]) {
      int v = other(id, c);
      if (ex[v]) {
        self(self, v, par[v] == c ? sz[v] : cur_n - sz[c]);
      }
    }
    ex[c] = true;
  };
  rec(rec, 0, n);
  cout << res.v << '\n';
}