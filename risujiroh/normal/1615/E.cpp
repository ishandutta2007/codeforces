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
  solve(0);
}

struct Graph {
  struct Edge {
    int src, dst;
    int64_t cost;

    int other(int v) const {
      __glibcxx_assert(v == src or v == dst);
      return src ^ dst ^ v;
    }
  };

  std::vector<Edge> edges;
  std::vector<std::vector<std::pair<int, int>>> adj;

  Graph() {}
  explicit Graph(int n) : adj(n) {}

  int n() const { return std::size(adj); }
  int m() const { return std::size(edges); }
  int add_edge(const Edge& e, bool directed) {
    __glibcxx_assert(0 <= e.src and e.src < n());
    __glibcxx_assert(0 <= e.dst and e.dst < n());
    int id = m();
    edges.push_back(e);
    adj[e.src].emplace_back(e.dst, id);
    if (not directed) adj[e.dst].emplace_back(e.src, id);
    return id;
  }
};

struct DfsTree : Graph {
  using T = decltype(Edge::cost);

  std::vector<int> root;
  std::vector<int> pv;
  std::vector<int> pe;
  std::vector<int> order;
  std::vector<int> in;
  std::vector<int> out;
  std::vector<int> sub;
  std::vector<int> depth;
  std::vector<int> min_depth;
  std::vector<T> dist;
  std::vector<int> last;
  int num_trials;

  DfsTree() {}
  explicit DfsTree(int n)
      : Graph(n),
        root(n, -1),
        pv(n, -1),
        pe(n, -1),
        in(n, -1),
        out(n, -1),
        sub(n, -1),
        depth(n, -1),
        min_depth(n, -1),
        dist(n, std::numeric_limits<T>::max()),
        last(n, -1),
        num_trials(0) {}

  int add_edge(const Edge& e) { return Graph::add_edge(e, false); }
  void dfs(int r, bool clear_order = true) {
    __glibcxx_assert(0 <= r and r < n());
    root[r] = r;
    pv[r] = -1;
    pe[r] = -1;
    if (clear_order) order.clear();
    depth[r] = 0;
    dist[r] = T{};
    dfs_impl(r);
    ++num_trials;
  }
  void dfs_all() {
    std::fill(std::begin(root), std::end(root), -1);
    for (int v = 0; v < n(); ++v)
      if (root[v] == -1) dfs(v, v == 0);
  }

  int deeper(int id) const {
    __glibcxx_assert(0 <= id and id < m());
    int a = edges[id].src;
    int b = edges[id].dst;
    return depth[a] < depth[b] ? b : a;
  }
  bool is_tree_edge(int id) const {
    __glibcxx_assert(0 <= id and id < m());
    return id == pe[deeper(id)];
  }
  bool is_ancestor(int u, int v) const {
    __glibcxx_assert(0 <= u and u < n());
    __glibcxx_assert(0 <= v and v < n());
    return in[u] <= in[v] and out[v] <= out[u];
  }

 private:
  void dfs_impl(int v) {
    in[v] = std::size(order);
    order.push_back(v);
    sub[v] = 1;
    min_depth[v] = depth[v];
    last[v] = num_trials;
    for (auto&& [u, id] : adj[v]) {
      if (id == pe[v]) continue;
      if (last[u] == num_trials) {
        min_depth[v] = std::min(min_depth[v], depth[u]);
        continue;
      }
      root[u] = root[v];
      pv[u] = v;
      pe[u] = id;
      depth[u] = depth[v] + 1;
      dist[u] = dist[v] + edges[id].cost;
      dfs_impl(u);
      sub[v] += sub[u];
      min_depth[v] = std::min(min_depth[v], min_depth[u]);
    }
    out[v] = std::size(order);
  }
};

namespace atcoder {

namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
constexpr int bsf_constexpr(unsigned int n) {
    int x = 0;
    while (!(n & (1 << x))) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsf(unsigned int n) {

    return __builtin_ctz(n);

}

} // namespace internal

} // namespace atcoder

namespace atcoder {

template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct lazy_segtree {
  public:
    lazy_segtree() : lazy_segtree(0) {}
    explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
    explicit lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <bool (*g)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*g)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;
    std::vector<F> lz;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        d[k] = mapping(f, d[k]);
        if (k < size) lz[k] = composition(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};

} // namespace atcoder

namespace segtree {
using s = array<int, 2>;
s op(s x, s y) { return max(x, y); }
s e() { return {-inf, -1}; }
s map(int f, s x) {
  x[0] += f;
  return x;
}
int comp(int g, int f) { return f + g; }
int id() { return 0; }
using type = atcoder::lazy_segtree<s, op, e, int, map, comp, id>;
} // namespace segtree

void solve(int) {
  i64 n, k;
  cin >> n >> k;
  auto g = DfsTree(n);
  for (auto e : rep(0, n - 1)) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g.add_edge({u, v, 1});
  }
  g.dfs_all();
  auto seg = segtree::type(n);
  auto num_leaves = 0;
  for (auto v : rep(0, n)) {
    if (g.sub[v] == 1) {
      seg.set(g.in[v], {0, v});
      ++num_leaves;
    }
  }
  if (num_leaves <= k) {
    auto r = min(n / 2, k);
    cout << r * (n - r) << '\n';
    return;
  }
  for (auto v : rep(0, n)) {
    seg.apply(g.in[v], g.out[v], 1);
  }
  auto alive = vector(n, true);
  auto b = n;
  for (auto _ : rep(0, k)) {
    auto [c, v] = seg.all_prod();
    DUMP(c, v);
    for (auto i = v; ~i && alive[i]; i = g.pv[i]) {
      alive[i] = false;
      seg.apply(g.in[i], g.out[i], -1);
    }
    seg.set(g.in[v], {-inf, -1});
    b -= c;
  }
  chmin(b, n / 2);
  cout << (n - k - b) * (k - b) << '\n';
}