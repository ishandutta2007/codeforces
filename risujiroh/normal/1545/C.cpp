#include <bits/stdc++.h>

template <class T, class Int> T power(T a, Int n, T e = 1) {
  __glibcxx_assert(n >= 0);
  if (n == 0) return e;
  for (; ~n & 1; n >>= 1) a *= a;
  T res = a;
  while (n >>= 1) {
    a *= a;
    if (n & 1) res *= a;
  }
  return res;
}

template <class T> class NumberBase {
 public:
  T& operator++() { return self() += T(1); }
  T& operator--() { return self() -= T(1); }
  T operator++(int) { return std::exchange(self(), ++self()); }
  T operator--(int) { return std::exchange(self(), --self()); }
  T operator+() const { return self(); }
  T operator-() const { return T{} - self(); }
  bool operator!() const { return self() == T{}; }
  explicit operator bool() const { return !!self(); }
  friend T operator+(const T& a, const T& b) { return T(a) += b; }
  friend T operator-(const T& a, const T& b) { return T(a) -= b; }
  friend T operator*(const T& a, const T& b) { return T(a) *= b; }
  friend T operator/(const T& a, const T& b) { return T(a) /= b; }
  friend bool operator>(const T& a, const T& b) { return b < a; }
  friend bool operator<=(const T& a, const T& b) { return !(a > b); }
  friend bool operator>=(const T& a, const T& b) { return !(a < b); }
  friend bool operator!=(const T& a, const T& b) { return !(a == b); }

 private:
  T& self() { return *static_cast<T*>(this); }
  const T& self() const { return *static_cast<const T*>(this); }
};

template <auto P> struct FpStaticPolicy {
  using U = std::make_unsigned_t<decltype(P)>;
  using D = std::conditional_t<std::is_same_v<U, uint32_t>, uint64_t, __uint128_t>;
  static_assert(2 <= P && P <= U(-1) / 4);
  static constexpr U p = P;
  static constexpr U inv_p = [] {
    U res = p;
    for (int _ = 5; _--;) res *= 2 - p * res;
    return p == 2 ? U(-1) / 2 + 1 : res;
  }();
  static constexpr U r2 = p == 2 ? 1 : -D(p) % p;
};
template <class T, int Id> struct FpDynamicPolicy {
  using U = std::make_unsigned_t<T>;
  using D = std::conditional_t<std::is_same_v<U, uint32_t>, uint64_t, __uint128_t>;
  static inline U p, inv_p, r2;
};
template <class Policy = FpStaticPolicy<998244353>> class Fp : public NumberBase<Fp<Policy>> {
  using U = typename Policy::U;
  using D = typename Policy::D;
  static_assert(std::is_same_v<U, uint32_t> || std::is_same_v<U, uint64_t>);

 public:
  using T = std::make_signed_t<U>;
  static inline std::vector<Fp> fact, ifact, inv;
  static constexpr T mod() { return Policy::p; }
  static void mod(T mod) {
    __glibcxx_assert(2 <= mod && mod <= T(U(-1) / 4));
    fact.clear(), ifact.clear(), inv.clear();
    Policy::p = mod, Policy::inv_p = Policy::p, Policy::r2 = -D(Policy::p) % Policy::p;
    for (int _ = 5; _--;) Policy::inv_p *= 2 - Policy::p * Policy::inv_p;
    if (Policy::p == 2) Policy::inv_p = U(-1) / 2 + 1, Policy::r2 = 1;
  }
  static void reserve(T n) {
    __glibcxx_assert(0 <= n && n < mod());
    fact.resize(n + 1), ifact.resize(n + 1), inv.resize(n + 1);
    fact[0] = 1;
    for (T i = 1; i <= n; ++i) fact[i] = i * fact[i - 1];
    ifact[n] = power(fact[n], Policy::p - 2);
    for (T i = n; i; --i) ifact[i - 1] = ifact[i] * i, inv[i] = fact[i - 1] * ifact[i];
  }
  static Fp binom(T n, T k) {
    if (n >= 0) return 0 <= k && k <= n ? fact[n] * ifact[k] * ifact[n - k] : 0;
    if (k >= 0) return k & 1 ? -binom(k + ~n, k) : binom(k + ~n, k);
    return (n ^ k) & 1 ? -binom(~k, ~n) : binom(~k, ~n);
  }
  Fp() : v(0) {}
  template <class Int, std::enable_if_t<std::is_integral_v<Int> && std::is_signed_v<Int>>* = nullptr> Fp(Int x) {
    v = -mod() <= x && x < mod() ? x : x % mod();
    v = reduce(D(v + Policy::p) * Policy::r2);
  }
  template <class Int, std::enable_if_t<std::is_integral_v<Int> && std::is_unsigned_v<Int>>* = nullptr> Fp(Int x) {
    v = x < 2 * Policy::p ? x : x % Policy::p;
    v = reduce(D(v) * Policy::r2);
  }
  T val() const {
    T res = reduce(v) - Policy::p;
    return res < 0 ? res + Policy::p : res;
  }
  Fp& operator+=(const Fp& o) {
    v = T(v += o.v - 2 * Policy::p) < 0 ? v + 2 * Policy::p : v;
    return *this;
  }
  Fp& operator-=(const Fp& o) {
    v = T(v -= o.v) < 0 ? v + 2 * Policy::p : v;
    return *this;
  }
  Fp& operator*=(const Fp& o) {
    v = reduce(D(v) * o.v);
    return *this;
  }
  Fp& operator/=(const Fp& o) {
    __glibcxx_assert(o);
    if (o.val() < T(std::size(inv))) return *this *= inv[o.val()];
    if ((-o).val() < T(std::size(inv))) return *this *= -inv[(-o).val()];
    return *this *= power(o, Policy::p - 2);
  }
  friend bool operator==(const Fp& a, const Fp& b) {
    return a.v == b.v || a.v + Policy::p == b.v || a.v == b.v + Policy::p;
  }
  friend std::ostream& operator<<(std::ostream& os, const Fp& a) { return os << a.val(); }

 private:
  static U reduce(D x) { return (x + D(U(x) * -Policy::inv_p) * Policy::p) >> std::numeric_limits<U>::digits; }
  U v;
};

// https://github.com/kth-competitive-programming/kactl
namespace kactl {

using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll mod = 1000000007;  // faster if const

ll modpow(ll b, ll e) {
  ll ans = 1;
  for (; e; b = b * b % mod, e /= 2)
    if (e & 1) ans = ans * b % mod;
  return ans;
}

int matInv(vector<vector<ll>>& A) {
  int n = sz(A);
  vi col(n);
  vector<vector<ll>> tmp(n, vector<ll>(n));
  rep(i, 0, n) tmp[i][i] = 1, col[i] = i;

  rep(i, 0, n) {
    int r = i, c = i;
    rep(j, i, n) rep(k, i, n) if (A[j][k]) {
      r = j;
      c = k;
      goto found;
    }
    return i;
  found:
    A[i].swap(A[r]);
    tmp[i].swap(tmp[r]);
    rep(j, 0, n) swap(A[j][i], A[j][c]), swap(tmp[j][i], tmp[j][c]);
    swap(col[i], col[c]);
    ll v = modpow(A[i][i], mod - 2);
    rep(j, i + 1, n) {
      ll f = A[j][i] * v % mod;
      A[j][i] = 0;
      rep(k, i + 1, n) A[j][k] = (A[j][k] - f * A[i][k]) % mod;
      rep(k, 0, n) tmp[j][k] = (tmp[j][k] - f * tmp[i][k]) % mod;
    }
    rep(j, i + 1, n) A[i][j] = A[i][j] * v % mod;
    rep(j, 0, n) tmp[i][j] = tmp[i][j] * v % mod;
    A[i][i] = 1;
  }

  for (int i = n - 1; i > 0; --i) rep(j, 0, i) {
      ll v = A[j][i];
      rep(k, 0, n) tmp[j][k] = (tmp[j][k] - v * tmp[i][k]) % mod;
    }

  rep(i, 0, n) rep(j, 0, n) A[col[i]][col[j]] = tmp[i][j] % mod + (tmp[i][j] < 0 ? mod : 0);
  return n;
}

vector<pii> generalMatching(int N, vector<pii>& ed) {
  vector<vector<ll>> mat(N, vector<ll>(N)), A;
  for (pii pa : ed) {
    int a = pa.first, b = pa.second, r = rand() % mod;
    mat[a][b] = r, mat[b][a] = (mod - r) % mod;
  }

  int r = matInv(A = mat), M = 2 * N - r, fi, fj;
  assert(r % 2 == 0);

  if (M != N) do {
      mat.resize(M, vector<ll>(M));
      rep(i, 0, N) {
        mat[i].resize(M);
        rep(j, N, M) {
          int r = rand() % mod;
          mat[i][j] = r, mat[j][i] = (mod - r) % mod;
        }
      }
    } while (matInv(A = mat) != M);

  vi has(M, 1);
  vector<pii> ret;
  rep(it, 0, M / 2) {
    rep(i, 0, M) if (has[i]) rep(j, i + 1, M) if (A[i][j] && mat[i][j]) {
      fi = i;
      fj = j;
      goto done;
    }
    assert(0);
  done:
    if (fj < N) ret.emplace_back(fi, fj);
    has[fi] = has[fj] = 0;
    rep(sw, 0, 2) {
      ll a = modpow(A[fi][fj], mod - 2);
      rep(i, 0, M) if (has[i] && A[i][fj]) {
        ll b = A[i][fj] * a % mod;
        rep(j, 0, M) A[i][j] = (A[i][j] - A[fi][j] * b) % mod;
      }
      swap(fi, fj);
    }
  }
  return ret;
}

#undef sz
#undef all
#undef rep

}  // namespace kactl

#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>

namespace atcoder {
namespace internal {

template <class E> struct csr {
  std::vector<int> start;
  std::vector<E> elist;
  explicit csr(int n, const std::vector<std::pair<int, E>>& edges) : start(n + 1), elist(edges.size()) {
    for (auto e : edges) {
      start[e.first + 1]++;
    }
    for (int i = 1; i <= n; i++) {
      start[i] += start[i - 1];
    }
    auto counter = start;
    for (auto e : edges) {
      elist[counter[e.first]++] = e.second;
    }
  }
};

}  // namespace internal

}  // namespace atcoder

namespace atcoder {
namespace internal {

struct scc_graph {
 public:
  explicit scc_graph(int n) : _n(n) {}

  int num_vertices() { return _n; }

  void add_edge(int from, int to) { edges.push_back({from, {to}}); }

  std::pair<int, std::vector<int>> scc_ids() {
    auto g = csr<edge>(_n, edges);
    int now_ord = 0, group_num = 0;
    std::vector<int> visited, low(_n), ord(_n, -1), ids(_n);
    visited.reserve(_n);
    auto dfs = [&](auto self, int v) -> void {
      low[v] = ord[v] = now_ord++;
      visited.push_back(v);
      for (int i = g.start[v]; i < g.start[v + 1]; i++) {
        auto to = g.elist[i].to;
        if (ord[to] == -1) {
          self(self, to);
          low[v] = std::min(low[v], low[to]);
        } else {
          low[v] = std::min(low[v], ord[to]);
        }
      }
      if (low[v] == ord[v]) {
        while (true) {
          int u = visited.back();
          visited.pop_back();
          ord[u] = _n;
          ids[u] = group_num;
          if (u == v) break;
        }
        group_num++;
      }
    };
    for (int i = 0; i < _n; i++) {
      if (ord[i] == -1) dfs(dfs, i);
    }
    for (auto& x : ids) {
      x = group_num - 1 - x;
    }
    return {group_num, ids};
  }

  std::vector<std::vector<int>> scc() {
    auto ids = scc_ids();
    int group_num = ids.first;
    std::vector<int> counts(group_num);
    for (auto x : ids.second) counts[x]++;
    std::vector<std::vector<int>> groups(ids.first);
    for (int i = 0; i < group_num; i++) {
      groups[i].reserve(counts[i]);
    }
    for (int i = 0; i < _n; i++) {
      groups[ids.second[i]].push_back(i);
    }
    return groups;
  }

 private:
  int _n;
  struct edge {
    int to;
  };
  std::vector<std::pair<int, edge>> edges;
};

}  // namespace internal

}  // namespace atcoder

namespace atcoder {

struct two_sat {
 public:
  two_sat() : _n(0), scc(0) {}
  explicit two_sat(int n) : _n(n), _answer(n), scc(2 * n) {}

  void add_clause(int i, bool f, int j, bool g) {
    assert(0 <= i && i < _n);
    assert(0 <= j && j < _n);
    scc.add_edge(2 * i + (f ? 0 : 1), 2 * j + (g ? 1 : 0));
    scc.add_edge(2 * j + (g ? 0 : 1), 2 * i + (f ? 1 : 0));
  }
  bool satisfiable() {
    auto id = scc.scc_ids().second;
    for (int i = 0; i < _n; i++) {
      if (id[2 * i] == id[2 * i + 1]) return false;
      _answer[i] = id[2 * i] < id[2 * i + 1];
    }
    return true;
  }
  std::vector<bool> answer() { return _answer; }

 private:
  int _n;
  std::vector<bool> _answer;
  internal::scc_graph scc;
};

}  // namespace atcoder

using namespace std;

// https://qiita.com/Kutimoti_T/items/5b579773e0a24d650bdf
struct GabowEdmonds {
  struct edge {
    int to, idx;
  };

  vector<vector<edge>> g;
  vector<pair<int, int>> edges;
  vector<int> mate, label, first;
  queue<int> que;

  GabowEdmonds(int n) : g(n + 1), mate(n + 1), label(n + 1, -1), first(n + 1) {}

  void add_edge(int u, int v) {
    ++u, ++v;
    g[u].push_back((edge){v, (int)(edges.size() + g.size())});
    g[v].push_back((edge){u, (int)(edges.size() + g.size())});
    edges.emplace_back(u, v);
  }

  int find(int x) {
    if (label[first[x]] < 0) return first[x];
    first[x] = find(first[x]);
    return first[x];
  }

  void rematch(int v, int w) {
    int t = mate[v];
    mate[v] = w;
    if (mate[t] != v) return;
    if (label[v] < (int)g.size()) {
      mate[t] = label[v];
      rematch(label[v], t);
    } else {
      int x = edges[label[v] - g.size()].first;
      int y = edges[label[v] - g.size()].second;
      rematch(x, y);
      rematch(y, x);
    }
  }

  void assign_label(int x, int y, int num) {
    int r = find(x);
    int s = find(y);
    int join = 0;
    if (r == s) return;
    label[r] = -num;
    label[s] = -num;
    while (true) {
      if (s != 0) swap(r, s);
      r = find(label[mate[r]]);
      if (label[r] == -num) {
        join = r;
        break;
      }
      label[r] = -num;
    }
    int v = first[x];
    while (v != join) {
      que.push(v);
      label[v] = num;
      first[v] = join;
      v = first[label[mate[v]]];
    }
    v = first[y];
    while (v != join) {
      que.push(v);
      label[v] = num;
      first[v] = join;
      v = first[label[mate[v]]];
    }
  }

  bool augment_check(int u) {
    que = queue<int>();
    first[u] = 0;
    label[u] = 0;
    que.push(u);
    while (!que.empty()) {
      int x = que.front();
      que.pop();
      for (auto e : g[x]) {
        int y = e.to;
        if (mate[y] == 0 && y != u) {
          mate[y] = x;
          rematch(x, y);
          return true;
        } else if (label[y] >= 0) {
          assign_label(x, y, e.idx);
        } else if (label[mate[y]] < 0) {
          label[mate[y]] = x;
          first[mate[y]] = y;
          que.push(mate[y]);
        }
      }
    }
    return false;
  }

  vector<pair<int, int>> max_matching() {
    for (int i = 1; i < (int)g.size(); i++) {
      if (mate[i] != 0) continue;
      if (augment_check(i)) label.assign(g.size(), -1);
    }
    vector<pair<int, int>> ret;
    for (int i = 1; i < (int)g.size(); i++) {
      if (i < mate[i]) ret.emplace_back(i - 1, mate[i] - 1);
    }
    return ret;
  }
};

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector a(2 * n, vector<int>(n));
    for (auto&& v : a)
      for (auto&& e : v) cin >> e;
    vector<kactl::pii> edges;
    GabowEdmonds ge(2 * n);
    for (int i = 0; i < 2 * n; ++i)
      for (int j = i + 1; j < 2 * n; ++j) {
        bool any = false;
        for (int k = 0; k < n; ++k) any |= a[i][k] == a[j][k];
        if (any) {
          edges.emplace_back(i, j);
          ge.add_edge(i, j);
        }
      }
    // auto matching = kactl::generalMatching(2 * n, edges);
    auto matching = ge.max_matching();
    assert(int(size(matching)) == n);
    vector<pair<int, int>> pos(2 * n);
    for (int i = 0; i < n; ++i) {
      auto [u, v] = matching[i];
      pos[u] = {i, 0};
      pos[v] = {i, 1};
    }
    atcoder::two_sat ts(n);
    for (auto&& [u, v] : edges) {
      ts.add_clause(pos[u].first, pos[u].second, pos[v].first, pos[v].second);
    }
    ts.satisfiable();
    auto res = ts.answer();
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) ans[i] = res[i] ? matching[i].first : matching[i].second;
    vector<bool> used(2 * n);
    for (int v : ans) used[v] = true;
    vector<vector<int>> g(n);
    vector exists(n, vector<bool>(n));
    for (auto&& [u, v] : edges) {
      if (!used[u] && used[v]) g[pos[u].first].push_back(pos[v].first);
      if (!used[v] && used[u]) g[pos[v].first].push_back(pos[u].first);
      if (!used[u] && !used[v]) {
        int x = pos[u].first;
        int y = pos[v].first;
        exists[x][y] = exists[y][x] = true;
      }
    }
    for (auto&& v : g) sort(begin(v), end(v));
    int c = 0;
    vector<int> order(n);
    iota(begin(order), end(order), 0);
    sort(begin(order), end(order), [&](int i, int j) { return g[i] < g[j]; });
    for (int l = 0; l < n;) {
      int r = l;
      while (r < n && g[order[r]] == g[order[l]]) ++r;
      vector<int> temp;
      for (int i = l; i < r; ++i) temp.push_back(order[i]);
      sort(begin(temp), end(temp));
      if (temp == g[order[l]]) {
        bool ok = true;
        for (int x : temp)
          for (int y : temp) ok &= !exists[x][y];
        c += ok;
      }
      l = r;
    }
    cout << power(Fp(2), c) << '\n';
    for (int i = 0; i < n; ++i) cout << ans[i] + 1 << " \n"[i + 1 == n];
  }
}