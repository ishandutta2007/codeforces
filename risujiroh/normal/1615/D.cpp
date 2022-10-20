#define NDEBUG

#include <bits/stdc++.h>
#include <x86intrin.h>

#define DUMP(...) void(0)

using namespace std;

using uint = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

template <class F> struct fix : F {
  fix(F f) : F(move(f)) {}
  template <class... Args> decltype(auto) operator()(Args&&... args) const {
    return F::operator()(ref(*this), forward<Args>(args)...);
  }
};

template <class T> auto sz(T&& x) {
  auto ret = size(forward<T>(x));
  return make_signed_t<decltype(ret)>(ret);
}

template <class T> T div_floor(T x, T y) { return x / y - ((x ^ y) < 0 && x % y); }
template <class T> T div_ceil(T x, T y) { return x / y + (0 <= (x ^ y) && x % y); }

template <class T, class U = T> bool chmin(T& x, U&& y) { return y < x ? x = forward<U>(y), true : false; }
template <class T, class U = T> bool chmax(T& x, U&& y) { return x < y ? x = forward<U>(y), true : false; }

template <class T> const auto inf_v = numeric_limits<T>::max() / 2;
const auto inf = inf_v<int>;

auto mt = mt19937_64(_rdtsc());
template <class T> T rand(T x, T y) {
  if constexpr (is_integral_v<T>) return uniform_int_distribution(x, y)(mt);
  if constexpr (is_floating_point_v<T>) return uniform_real_distribution(x, y)(mt);
}

auto rep = views::iota;
auto rev = views::reverse;

void solve(int);

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  for (auto i : rep(0, t)) solve(i);
}

template <class T, class Op, class Inv> struct weighted_dsu {
  const Op op;
  const T e;
  const Inv inv;
  vector<int> p, sz;
  vector<T> d;
  weighted_dsu(int n, Op _op, T _e, Inv _inv) : op(_op), e(_e), inv(_inv), p(n, -1), sz(n, 1), d(n, e) {}
  pair<int, T> root(int v) const {
    T a = e;
    while (p[v] != -1) a = op(a, d[v]), v = p[v];
    return {v, a};
  }
  void unite(int u, int v, T w) {
    T du, dv;
    tie(u, du) = root(u), tie(v, dv) = root(v);
    assert(u != v);
    if (sz[u] < sz[v]) swap(u, v), swap(du, dv), w = inv(w);
    p[v] = u;
    sz[u] += sz[v];
    d[v] = op(op(du, w), inv(dv));
  }
  T diff(int u, int v) const {
    T du, dv;
    tie(u, du) = root(u), tie(v, dv) = root(v);
    assert(u == v);
    return op(dv, inv(du));
  }
  bool same(int u, int v) const { return root(u).first == root(v).first; }
  int size(int v) const { return sz[root(v).first]; }
};
template <class T, class Op, class Inv> auto make_weighted_dsu(int n, Op op, T e, Inv inv) {
  return weighted_dsu<T, Op, Inv>(n, op, e, inv);
}

void solve(int) {
  int n, m;
  cin >> n >> m;
  auto x = vector<int>(n - 1);
  auto y = vector<int>(n - 1);
  auto v = vector<int>(n - 1);
  for (auto e : rep(0, n - 1)) {
    cin >> x[e] >> y[e] >> v[e];
    --x[e], --y[e];
  }
  auto a = vector<int>(m);
  auto b = vector<int>(m);
  auto p = vector<int>(m);
  for (auto i : rep(0, m)) {
    cin >> a[i] >> b[i] >> p[i];
    --a[i], --b[i];
  }
  auto d = make_weighted_dsu(n, bit_xor(), 0, [](int x) { return x; });
  for (auto e : rep(0, n - 1)) {
    if (v[e] == -1) {
      continue;
    }
    d.unite(x[e], y[e], v[e]);
  }
  for (auto i : rep(0, m)) {
    if (d.same(a[i], b[i])) {
      if (__builtin_parity(d.diff(a[i], b[i])) != p[i]) {
        cout << "NO\n";
        return;
      }
    } else {
      d.unite(a[i], b[i], p[i]);
    }
  }
  cout << "YES\n";
  for (auto e : rep(0, n - 1)) {
    if (!d.same(x[e], y[e])) {
      d.unite(x[e], y[e], 0);
    }
    cout << x[e] + 1 << ' ' << y[e] + 1 << ' ' << d.diff(x[e], y[e]) << '\n';
  }
}