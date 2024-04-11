static_assert(R"("

void main(int) {
  int n, q;
  scan(n, q);
  HldTree g(n);
  for (int _ : rep(n - 1)) {
    int u, v;
    scan(u, v);
    --u, --v;
    g.add_edge({u, v, 1});
  }
  g.build_all();
  vector<int> x(q), y(q);
  vector<string> s(q);
  vector<vector<pair<int, array<char, 2>>>> a(n);
  atcoder::dsu d(2 * q + 1);
  for (int i : rep(q)) {
    scan(x[i], y[i], s[i]);
    --x[i], --y[i];
    assert(sz(s[i]) == g.d(x[i], y[i]) + 1);
    {
      int pos = 0;
      for (int v = x[i];; v = g.next(v, y[i])) {
        a[v].emplace_back(i, array{s[i][pos], s[i][sz(s[i]) - pos - 1]});
        if (v == y[i]) { break; }
        ++pos;
      }
    }
  }
  DUMP(a);
  for (int v : rep(n)) {
    if (empty(a[v])) { continue; }
    string t;
    for (char c : rep1('a', 'z')) {
      bool ok = true;
      for (auto [i, arr] : a[v]) { ok &= arr[0] == c || arr[1] == c; }
      if (!ok) { continue; }
      t += c;
    }
    if (empty(t)) { return println("NO"); }
    if (sz(t) == 1) {
      for (auto [i, arr] : a[v]) {
        if (arr[0] == arr[1]) {
        } else {
          if (arr[0] == t[0]) {
            d.merge(2 * i, 2 * q);
          } else {
            d.merge(2 * i + 1, 2 * q);
          }
        }
      }
    } else {
      int i0 = a[v][0].first;
      for (auto [i, arr] : a[v]) {
        if (arr[0] == a[v][0].second[0]) {
          d.merge(2 * i0, 2 * i);
          d.merge(2 * i0 + 1, 2 * i + 1);
        } else {
          d.merge(2 * i0, 2 * i + 1);
          d.merge(2 * i0 + 1, 2 * i);
        }
      }
    }
  }
  for (int i : rep(q)) {
    if (d.same(2 * i, 2 * i + 1)) { return println("NO"); }
    if (!d.same(2 * i, 2 * q) && !d.same(2 * i + 1, 2 * q)) { d.merge(2 * i, 2 * q); }
  }
  println("YES");
  string ans(n, 'z');
  for (int i : rep(q)) {
    if (d.same(2 * i + 1, 2 * q)) { reverse(all(s[i])); }
    {
      int pos = 0;
      for (int v = x[i];; v = g.next(v, y[i])) {
        ans[v] = s[i][pos];
        if (v == y[i]) { break; }
        ++pos;
      }
    }
  }
  println(ans);
}

")");

#define MULTI_CASES 0
#define INTERACTIVE 0

#ifndef LOCAL
#define LOCAL 0
#endif

#if !LOCAL
#define NDEBUG
#endif

#ifndef __GLIBCXX_TYPE_INT_N_0
#define __GLIBCXX_TYPE_INT_N_0 __int128
#endif

#include <bits/stdc++.h>
#include <unistd.h>
#include <x86intrin.h>

namespace r7h {

using namespace std;

void main(int);

}  // namespace r7h

#if LOCAL
#include <utility/dump.hpp>
#else
#define DUMP(...) void(0)
#endif

#define LIFT(FN) \
  []<class... Ts_>(Ts_&&... xs_) -> decltype(auto) { return FN(static_cast<Ts_&&>(xs_)...); }

#define LAMBDA(...) \
  [&]<class T1_ = void*, class T2_ = void*>([[maybe_unused]] T1_&& _1 = nullptr, [[maybe_unused]] T2_&& _2 = nullptr) \
      -> decltype(auto) { \
    return __VA_ARGS__; \
  }

namespace r7h {

template <class F>
class fix : F {
 public:
  explicit fix(F f) : F(move(f)) {}

  template <class... Ts>
  decltype(auto) operator()(Ts&&... xs) const {
    return F::operator()(ref(*this), forward<Ts>(xs)...);
  }
};

template <class T>
decay_t<T> decay_copy(T&& x) {
  return forward<T>(x);
}

template <class T>
auto ref_or_move(remove_reference_t<T>& x) {
  if constexpr (is_reference_v<T> && !is_placeholder_v<decay_t<T>>) {
    return ref(x);
  } else {
    return move(x);
  }
}

template <class T, class D = decay_t<T>>
bool const is_lambda_expr = is_placeholder_v<D> || is_bind_expression_v<D>;

#define UNARY_LAMBDA(OP) \
  template <class T, enable_if_t<is_lambda_expr<T>>* = nullptr> \
  auto operator OP(T&& x) { \
    return bind([]<class T_>(T_&& x_) -> decltype(auto) { return OP forward<T_>(x_); }, ref_or_move<T>(x)); \
  }

#define BINARY_LAMBDA(OP) \
  template <class T1, class T2, enable_if_t<is_lambda_expr<T1> || is_lambda_expr<T2>>* = nullptr> \
  auto operator OP(T1&& x, T2&& y) { \
    auto f = []<class T1_, class T2_>(T1_&& x_, T2_&& y_) -> decltype(auto) { \
      return forward<T1_>(x_) OP forward<T2_>(y_); \
    }; \
    return bind(move(f), ref_or_move<T1>(x), ref_or_move<T2>(y)); \
  }

BINARY_LAMBDA(+=)
BINARY_LAMBDA(-=)
BINARY_LAMBDA(*=)
BINARY_LAMBDA(/=)
BINARY_LAMBDA(%=)
BINARY_LAMBDA(&=)
BINARY_LAMBDA(|=)
BINARY_LAMBDA(^=)
BINARY_LAMBDA(<<=)
BINARY_LAMBDA(>>=)

UNARY_LAMBDA(++)
UNARY_LAMBDA(--)

UNARY_LAMBDA(+)
UNARY_LAMBDA(-)
BINARY_LAMBDA(+)
BINARY_LAMBDA(-)
BINARY_LAMBDA(*)
BINARY_LAMBDA(/)
BINARY_LAMBDA(%)

UNARY_LAMBDA(~)
BINARY_LAMBDA(&)
BINARY_LAMBDA(|)
BINARY_LAMBDA(^)
BINARY_LAMBDA(<<)
BINARY_LAMBDA(>>)

BINARY_LAMBDA(==)
BINARY_LAMBDA(!=)
BINARY_LAMBDA(<)
BINARY_LAMBDA(>)
BINARY_LAMBDA(<=)
BINARY_LAMBDA(>=)

UNARY_LAMBDA(!)
BINARY_LAMBDA(&&)
BINARY_LAMBDA(||)

#undef UNARY_LAMBDA
#undef BINARY_LAMBDA

using namespace placeholders;

using i8 = signed char;
using u8 = unsigned char;
using i16 = short;
using u16 = unsigned short;
using i32 = int;
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;

template <int> struct signed_int;
template <int> struct unsigned_int;

#define INT_TYPE(N) \
  template <> struct signed_int<N> { using type = i##N; }; \
  template <> struct unsigned_int<N> { using type = u##N; };

INT_TYPE(8)
INT_TYPE(16)
INT_TYPE(32)
INT_TYPE(64)
INT_TYPE(128)

#undef INT_TYPE

template <int N> using signed_int_t = typename signed_int<N>::type;
template <int N> using unsigned_int_t = typename unsigned_int<N>::type;

namespace scan_impl {

#if INTERACTIVE || LOCAL

bool scan(char& c) { return scanf(" %c", &c) != EOF; }

bool scan(string& s) {
  char c;
  if (!scan(c)) { return false; }
  for (s = c;; s += c) {
    c = char(getchar());
    if (c <= ' ') {
      ungetc(c, stdin);
      break;
    }
  }
  return true;
}

template <class T>
enable_if_t<is_integral_v<T>, bool> scan(T& x) {
  char c;
  if (!scan(c)) { return false; }
  make_unsigned_t<decltype(+x)> u = (c == '-' ? getchar() : c) & 15;
  while (true) {
    if (int t = getchar(); '0' <= t && t <= '9') {
      (u *= 10) += t & 15;
    } else {
      ungetc(t, stdin);
      break;
    }
  }
  x = T(c == '-' ? -u : u);
  return true;
}

template <class T>
enable_if_t<is_floating_point_v<T>, bool> scan(T& x) {
  return scanf(is_same_v<T, float> ? "%f" : is_same_v<T, double> ? "%lf" : "%Lf", &x) != EOF;
}

#else

char buf[1 << 15];
char* ptr = buf;
char* last = buf;

bool scan(char& c) {
  for (;; ++ptr) {
    if (last - ptr < 64) {
      last = move(ptr, last, buf);
      ptr = buf;
      last += read(STDIN_FILENO, last, end(buf) - last - 1);
      *last = '\0';
    }
    if (ptr == last) { return false; }
    if (' ' < *ptr) {
      c = *ptr++;
      return true;
    }
  }
}

bool scan(string& s) {
  char c;
  if (!scan(c)) { return false; }
  for (s = c; ' ' < *ptr; s += c) { scan(c); }
  return true;
}

template <class T>
enable_if_t<is_integral_v<T>, bool> scan(T& x) {
  char c;
  if (!scan(c)) { return false; }
  make_unsigned_t<decltype(+x)> u = (c == '-' ? *ptr++ : c) & 15;
  while ('0' <= *ptr && *ptr <= '9') { (u *= 10) += *ptr++ & 15; }
  x = T(c == '-' ? -u : u);
  return true;
}

template <class T>
enable_if_t<is_floating_point_v<T>, bool> scan(T& x) {
  char c;
  if (!scan(c)) { return false; }
  int n;
  sscanf(--ptr, is_same_v<T, float> ? "%f%n" : is_same_v<T, double> ? "%lf%n" : "%Lf%n", &x, &n);
  ptr += n;
  return true;
}

#endif

template <class R>
auto scan(R&& r) -> decltype(begin(r), end(r), true) {
  return all_of(begin(r), end(r), LIFT(scan));
}

template <class... Ts>
enable_if_t<sizeof...(Ts) != 1, bool> scan(Ts&&... xs) {
  return (... && scan(forward<Ts>(xs)));
}

}  // namespace scan_impl

using scan_impl::scan;

namespace print_impl {

#if INTERACTIVE || LOCAL

template <char = 0>
void print(char c) {
  if (c) { putchar(c); }
  if (c == '\n') { fflush(stdout); }
}

template <char = 0, class T>
enable_if_t<is_integral_v<T>> print(T x) {
  char buf[64];
  char* ptr = to_chars(buf, end(buf), +x).ptr;
  for_each(buf, ptr, LIFT(print));
}

template <char = 0, class T>
enable_if_t<is_floating_point_v<T>> print(T x) {
  printf(is_same_v<T, float> ? "%.6f" : is_same_v<T, double> ? "%.15f" : "%.18Lf", x);
}

#else

char buf[1 << 15];
char* ptr = buf;

__attribute__((destructor)) void flush() {
  if (write(STDOUT_FILENO, buf, ptr - buf) == -1) { abort(); }
  ptr = buf;
}

template <char = 0>
void print(char c) {
  if (end(buf) - ptr < 64) { flush(); }
  if (c) { *ptr++ = c; }
}

template <char = 0, class T>
enable_if_t<is_integral_v<T>> print(T x) {
  print('\0');
  ptr = to_chars(ptr, end(buf), +x).ptr;
}

template <char = 0, class T>
enable_if_t<is_floating_point_v<T>> print(T x) {
  print('\0');
  ptr += snprintf(ptr, end(buf) - ptr, is_same_v<T, float> ? "%.6f" : is_same_v<T, double> ? "%.15f" : "%.18Lf", x);
}

#endif

template <char = 0>
void print(char const*);

template <char Sep = ' ', class R>
auto print(R&& r) -> void_t<decltype(begin(r), end(r))> {
  [[maybe_unused]] char c = '\0';
  for (auto&& e : r) {
    if constexpr (!is_same_v<decay_t<decltype(e)>, char>) { print(exchange(c, Sep)); }
    print(e);
  }
}

template <char = 0>
void print(char const* s) {
  print(string_view(s));
}

template <char Sep = ' ', class... Ts>
enable_if_t<sizeof...(Ts) != 1> print(Ts&&... xs) {
  [[maybe_unused]] char c = '\0';
  (..., (print(exchange(c, Sep)), print(forward<Ts>(xs))));
}

}  // namespace print_impl

using print_impl::print;

template <char Sep = ' ', char End = '\n', class... Ts>
void println(Ts&&... xs) {
  print<Sep>(forward<Ts>(xs)...);
  print(End);
}

template <class T>
auto operator++(T& x, int) -> decltype(++x, T(x)) {
  T ret = x;
  ++x;
  return ret;
}

template <class T>
auto operator--(T& x, int) -> decltype(--x, T(x)) {
  T ret = x;
  --x;
  return ret;
}

#define BINARY_ARITH_OP(OP) \
  template <class T1, class T2, class T = common_type_t<T1, T2>> \
  auto operator OP(T1 const& x, T2 const& y) -> decltype(declval<T&>() OP##= y, T(x)) { \
    T ret = T(x); \
    ret OP##= y; \
    return ret; \
  }

BINARY_ARITH_OP(+)
BINARY_ARITH_OP(-)
BINARY_ARITH_OP(*)
BINARY_ARITH_OP(/)
BINARY_ARITH_OP(%)
BINARY_ARITH_OP(&)
BINARY_ARITH_OP(|)
BINARY_ARITH_OP(^)
BINARY_ARITH_OP(<<)
BINARY_ARITH_OP(>>)

#undef BINARY_ARITH_OP

#define COMPARISON_OP(OP, E) \
  template <class T1, class T2> \
  auto operator OP(T1 const& x, T2 const& y) -> decltype(E) { \
    return E; \
  }

COMPARISON_OP(!=, !(x == y))
COMPARISON_OP(>, y < x)
COMPARISON_OP(<=, !(y < x))
COMPARISON_OP(>=, !(x < y))

#undef COMPARISON_OP

template <class D, class C, class R>
class iter_base {
  D& derived() { return static_cast<D&>(*this); }
  D const& derived() const { return static_cast<D const&>(*this); }

 public:
  using iterator_category = C;
  using value_type = decay_t<R>;
  using difference_type = int;
  using pointer = void;
  using reference = R;

#define REQUIRE(CAT) template <class C_ = C, enable_if_t<is_convertible_v<C_, CAT##_iterator_tag>>* = nullptr>

  R operator*() const { return derived().deref(); }
  REQUIRE(random_access) R operator[](int n) const { return *(derived() + n); }

  D& operator++() & {
    derived().inc();
    return derived();
  }
  REQUIRE(bidirectional) D& operator--() & {
    derived().dec();
    return derived();
  }
  REQUIRE(random_access) D& operator+=(int n) & {
    derived().adv(n);
    return derived();
  }
  REQUIRE(random_access) D& operator-=(int n) & {
    derived().adv(-n);
    return derived();
  }

  REQUIRE(random_access) friend D operator+(D const& x, int n) {
    D ret = x;
    ret += n;
    return ret;
  }
  REQUIRE(random_access) friend D operator+(int n, D const& x) { return x + n; }
  REQUIRE(random_access) friend D operator-(D const& x, int n) {
    D ret = x;
    ret -= n;
    return ret;
  }
  REQUIRE(random_access) friend int operator-(D const& x, D const& y) { return y.dist_to(x); }

  friend bool operator==(D const& x, D const& y) { return x.eq(y); }
  REQUIRE(random_access) friend bool operator<(D const& x, D const& y) { return x - y < 0; }

#undef REQUIRE
};

struct int_iter : iter_base<int_iter, random_access_iterator_tag, int> {
  int v;
  int_iter() = default;
  int_iter(int v) : v(v) {}
  int deref() const { return v; }
  bool eq(int_iter const& x) const { return v == x.v; }
  void inc() { ++v; }
  void dec() { --v; }
  void adv(int n) { v += n; }
  int dist_to(int_iter const& x) const { return x.v - v; }
};

template <class I>
class range {
  I b, e;

 public:
  explicit range(I first, I last) : b(move(first)), e(move(last)) {}
  I begin() const { return b; }
  I end() const { return e; }
};

auto rep(int l, int r) { return range<int_iter>(min(l, r), r); }

auto rep(int n) { return rep(0, n); }

auto rep1(int l, int r) { return rep(l, r + 1); }

auto rep1(int n) { return rep(1, n + 1); }

template <class R>
auto rev(R&& r) {
  return range(make_reverse_iterator(end(r)), make_reverse_iterator(begin(r)));
}

template <class R>
auto sz(R&& r) -> decltype(int(size(forward<R>(r)))) {
  return int(size(forward<R>(r)));
}

template <class T, class N, class Op>
T power1(T x, N n, Op op) {
  assert(1 <= n);
  for (; ~n & 1; n >>= 1) { x = op(x, x); }
  T ret = x;
  while (n >>= 1) {
    x = op(x, x);
    if (n & 1) { ret = op(move(ret), x); }
  }
  return ret;
}

template <class T, class N>
T power(T x, N n) {
  if (n == 0) { return T{1}; }
  if (n < 0) { return T{1} / power1(move(x), -n, multiplies{}); }
  return power1(move(x), n, multiplies{});
}

template <class T>
T div_floor(T x, T y) {
  return T(x / y - ((x ^ y) < 0 && x % y));
}

template <class T>
T div_ceil(T x, T y) {
  return T(x / y + (0 <= (x ^ y) && x % y));
}

template <class T, class U = T>
bool chmin(T& x, U&& y) {
  return y < x ? x = forward<U>(y), true : false;
}

template <class T, class U = T>
bool chmax(T& x, U&& y) {
  return x < y ? x = forward<U>(y), true : false;
}

template <class T>
T const inf_v = numeric_limits<T>::max() / 2;

int const inf = inf_v<int>;

mt19937_64 mt(_rdtsc());

template <class T>
T rand(T a, T b) {
  if constexpr (is_integral_v<T>) {
    return uniform_int_distribution(a, b)(mt);
  } else {
    return uniform_real_distribution(a, b)(mt);
  }
}

}  // namespace r7h

int main() {
  int t = 1;
  if (MULTI_CASES) { r7h::scan(t); }
  for (int i : r7h::rep(t)) { r7h::main(i); }
  assert(!r7h::scan(t));
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

struct HldTree : DfsTree {
  std::vector<int> head;

  HldTree() {}
  explicit HldTree(int n) : DfsTree(n), head(n, -1) {}

  void build(int r, bool clear_order = true) {
    __glibcxx_assert(0 <= r and r < n());
    dfs(r, clear_order);
    order.erase(std::end(order) - sub[r], std::end(order));
    head[r] = r;
    build_impl(r);
  }
  void build_all() {
    std::fill(std::begin(root), std::end(root), -1);
    for (int v = 0; v < n(); ++v)
      if (root[v] == -1) build(v, v == 0);
  }

  int lca(int u, int v) const {
    __glibcxx_assert(0 <= u and u < n());
    __glibcxx_assert(0 <= v and v < n());
    __glibcxx_assert(root[u] == root[v]);
    while (true) {
      if (in[u] > in[v]) std::swap(u, v);
      if (head[u] == head[v]) return u;
      v = pv[head[v]];
    }
  }
  int d(int u, int v) const {
    __glibcxx_assert(0 <= u and u < n());
    __glibcxx_assert(0 <= v and v < n());
    __glibcxx_assert(root[u] == root[v]);
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
  }
  T distance(int u, int v) const {
    __glibcxx_assert(0 <= u and u < n());
    __glibcxx_assert(0 <= v and v < n());
    __glibcxx_assert(root[u] == root[v]);
    return dist[u] + dist[v] - 2 * dist[lca(u, v)];
  }
  int la(int v, int d) const {
    __glibcxx_assert(0 <= v and v < n());
    __glibcxx_assert(0 <= d and d <= depth[v]);
    while (depth[head[v]] > d) v = pv[head[v]];
    return order[in[head[v]] + (d - depth[head[v]])];
  }
  int next(int src, int dst) const {
    __glibcxx_assert(0 <= src and src < n());
    __glibcxx_assert(0 <= dst and dst < n());
    __glibcxx_assert(root[src] == root[dst]);
    __glibcxx_assert(src != dst);
    if (not is_ancestor(src, dst)) return pv[src];
    return la(dst, depth[src] + 1);
  }
  int next(int src, int dst, int k) const {
    __glibcxx_assert(0 <= src and src < n());
    __glibcxx_assert(0 <= dst and dst < n());
    __glibcxx_assert(root[src] == root[dst]);
    __glibcxx_assert(k >= 0);
    int v = lca(src, dst);
    if (k <= depth[src] - depth[v]) return la(src, depth[src] - k);
    k -= depth[src] - depth[v];
    __glibcxx_assert(k <= depth[dst] - depth[v]);
    return la(dst, depth[v] + k);
  }
  template <class Function>
  void apply(int src, int dst, bool vertex, Function f) const {
    __glibcxx_assert(0 <= src and src < n());
    __glibcxx_assert(0 <= dst and dst < n());
    __glibcxx_assert(root[src] == root[dst]);
    int v = lca(src, dst);
    while (head[src] != head[v]) {
      f(in[src] + 1, in[head[src]]);
      src = pv[head[src]];
    }
    if (vertex)
      f(in[src] + 1, in[v]);
    else if (src != v)
      f(in[src] + 1, in[v] + 1);
    auto rec = [&](auto self, int to) -> void {
      if (head[v] == head[to]) {
        if (v != to) f(in[v] + 1, in[to] + 1);
        return;
      }
      self(self, pv[head[to]]);
      f(in[head[to]], in[to] + 1);
    };
    rec(rec, dst);
  }
  template <class Searcher>
  int search(int src, int dst, bool vertex, Searcher f) const {
    __glibcxx_assert(0 <= src and src < n());
    __glibcxx_assert(0 <= dst and dst < n());
    __glibcxx_assert(root[src] == root[dst]);
    int res = -1;
    apply(src, dst, vertex, [&](int l, int r) {
      if (res != -1) return;
      int i = f(l, r);
      if (l > r) std::swap(l, r);
      if (l <= i and i < r) res = vertex ? order[i] : pe[order[i]];
    });
    return res;
  }

 private:
  void build_impl(int v) {
    in[v] = std::size(order);
    order.push_back(v);
    auto pos = std::partition(std::begin(adj[v]), std::end(adj[v]), [&](auto&& e) { return e.second == pe[e.first]; });
    auto it =
        std::max_element(std::begin(adj[v]), pos, [&](auto&& a, auto&& b) { return sub[a.first] < sub[b.first]; });
    if (it != std::begin(adj[v])) std::iter_swap(std::begin(adj[v]), it);
    std::partition(pos, std::end(adj[v]), [&](auto&& e) { return e.second == pe[v]; });
    for (auto&& [u, id] : adj[v]) {
      if (id != pe[u]) break;
      head[u] = u == adj[v].front().first ? head[v] : u;
      build_impl(u);
    }
    out[v] = std::size(order);
  }
};

namespace atcoder {

// Implement (union by size) + (path compression)
// Reference:
// Zvi Galil and Giuseppe F. Italiano,
// Data structures and algorithms for disjoint set union problems
struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
};

}  // namespace atcoder

#define all(c) begin(c), end(c)

namespace r7h {

void main(int) {
  int n, q;
  scan(n, q);
  HldTree g(n);
  for (int _ : rep(n - 1)) {
    int u, v;
    scan(u, v);
    --u, --v;
    g.add_edge({u, v, 1});
  }
  g.build_all();
  vector<int> x(q), y(q);
  vector<string> s(q);
  vector<vector<pair<int, array<char, 2>>>> a(n);
  atcoder::dsu d(2 * q + 1);
  for (int i : rep(q)) {
    scan(x[i], y[i], s[i]);
    --x[i], --y[i];
    assert(sz(s[i]) == g.d(x[i], y[i]) + 1);
    {
      int pos = 0;
      for (int v = x[i];; v = g.next(v, y[i])) {
        a[v].emplace_back(i, array{s[i][pos], s[i][sz(s[i]) - pos - 1]});
        if (v == y[i]) { break; }
        ++pos;
      }
    }
  }
  DUMP(a);
  for (int v : rep(n)) {
    if (empty(a[v])) { continue; }
    string t;
    for (char c : rep1('a', 'z')) {
      bool ok = true;
      for (auto [i, arr] : a[v]) { ok &= arr[0] == c || arr[1] == c; }
      if (!ok) { continue; }
      t += c;
    }
    if (empty(t)) { return println("NO"); }
    if (sz(t) == 1) {
      for (auto [i, arr] : a[v]) {
        if (arr[0] == arr[1]) {
        } else {
          if (arr[0] == t[0]) {
            d.merge(2 * i, 2 * q);
          } else {
            d.merge(2 * i + 1, 2 * q);
          }
        }
      }
    } else {
      int i0 = a[v][0].first;
      for (auto [i, arr] : a[v]) {
        if (arr[0] == a[v][0].second[0]) {
          d.merge(2 * i0, 2 * i);
          d.merge(2 * i0 + 1, 2 * i + 1);
        } else {
          d.merge(2 * i0, 2 * i + 1);
          d.merge(2 * i0 + 1, 2 * i);
        }
      }
    }
  }
  for (int i : rep(q)) {
    if (d.same(2 * i, 2 * i + 1)) { return println("NO"); }
    if (!d.same(2 * i, 2 * q) && !d.same(2 * i + 1, 2 * q)) { d.merge(2 * i, 2 * q); }
  }
  println("YES");
  string ans(n, 'z');
  for (int i : rep(q)) {
    if (d.same(2 * i + 1, 2 * q)) { reverse(all(s[i])); }
    {
      int pos = 0;
      for (int v = x[i];; v = g.next(v, y[i])) {
        ans[v] = s[i][pos];
        if (v == y[i]) { break; }
        ++pos;
      }
    }
  }
  println(ans);
}

}  // namespace r7h