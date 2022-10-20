#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

template <class T, class Op = multiplies<T>>
constexpr T power(T a, long long n, Op op = Op(), T e = {1}) {
  assert(n >= 0);
  while (n) {
    if (n & 1) e = op(e, a);
    if (n >>= 1) a = op(a, a);
  }
  return e;
}

template <unsigned M> struct modular {
  using m = modular;
  static constexpr unsigned mod = M;
  unsigned v;
  modular(long long x = 0) : v((x %= mod) < 0 ? x + mod : x) {}
  m operator-() const { return m() -= *this; }
  m& operator+=(m b) { if ((int)(v += b.v - mod) < 0) v += mod; return *this; }
  m& operator-=(m b) { if ((int)(v -= b.v) < 0) v += mod; return *this; }
  m& operator*=(m b) { v = (uint64_t)v * b.v % mod; return *this; }
  m& operator/=(m b) { return *this *= power(b, mod - 2); }
  friend m operator+(m a, m b) { return a += b; }
  friend m operator-(m a, m b) { return a -= b; }
  friend m operator*(m a, m b) { return a *= b; }
  friend m operator/(m a, m b) { return a /= b; }
  friend bool operator==(m a, m b) { return a.v == b.v; }
};

using mint = modular<power(10, 9) + 7>;

template <class T> constexpr T inf = numeric_limits<T>::max() / 2.1;

auto chmax = [](auto&& a, auto b) { return a < b ? a = b, 1 : 0; };

struct edge {
  int from, to, w;
};

struct line {
  long long a, b;
  long long operator()(int x) const {
    return a * x + b;
  }
};
bool need(const line& l, const line& m, const line& r) {
  return m.b * (r.a - l.a) > l.b * (r.a - m.a) + r.b * (m.a - l.a);
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m, q;
  cin >> n >> m >> q;
  vector<edge> es(m);
  vector<vector<int>> g(n);
  for (int id = 0; id < m; ++id) {
    auto&& [u, v, w] = es[id];
    cin >> u >> v >> w;
    --u, --v;
    g[u].push_back(id);
    g[v].push_back(id);
  }
  vector dp(n, vector(n, -inf<int>));
  dp[0][0] = 0;
  for (int i = 1; i < n; ++i) {
    for (int id = 0; id < m; ++id) {
      chmax(dp[i][es[id].to], dp[i - 1][es[id].from] + es[id].w);
      chmax(dp[i][es[id].from], dp[i - 1][es[id].to] + es[id].w);
    }
  }
  vector<pair<long long, long long>> ab;
  for (int v = 0; v < n; ++v) {
    int max_w = -1;
    for (int id : g[v]) {
      chmax(max_w, es[id].w);
    }
    int max_b = -1;
    for (int i = 0; i < n; ++i) {
      if (dp[i][v] < 0) continue;
      chmax(max_b, dp[i][v] + max_w * (n - i));
    }
    ab.emplace_back(max_w, max_b);
  }
  sort(begin(ab), end(ab));
  vector<line> ch;
  for (auto [a, b] : ab) {
    line cur{a, b};
    while (size(ch) >= 2 and not need(ch[size(ch) - 2], ch.back(), cur)) {
      ch.pop_back();
    }
    if (not empty(ch) and ch[0].b <= b) {
      ch.clear();
    }
    ch.push_back(cur);
  }
  mint res;
  for (int i = 1; i < n; ++i) {
    if (i > q) break;
    res += *max_element(begin(dp[i]), end(dp[i]));
  }
  q -= n;
  for (int t = 0, l = 0; t < (int)size(ch); ++t) {
    if (l > q) break;
    int ok = l, ng = inf<int>;
    while (ng - ok > 1) {
      int mid = (ok + ng) / 2;
      (t == (int)size(ch) - 1 or ch[t](mid) >= ch[t + 1](mid) ? ok : ng) = mid;
    }
    int r = min(q, ok);
    res += mint(ch[t](l) + ch[t](r)) * (r - l + 1) / 2;
    l = ng;
  }
  cout << res.v << '\n';
}