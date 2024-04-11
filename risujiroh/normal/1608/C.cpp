#define NDEBUG

#include <unistd.h>
#include <x86intrin.h>
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <charconv>
#include <map>
#include <queue>
#include <random>
#include <set>

using namespace std::literals;

#define DUMP(...) void(0)

namespace scan_impl {

char buf[1 << 15];
char* ptr = buf;
char* end = buf;

bool scan(char& c) {
  for (;; ++ptr) {
    if (end - ptr < 64) {
      end = std::move(ptr, end, buf);
      ptr = buf;
      end += read(STDIN_FILENO, end, std::end(buf) - end - 1);
      *end = '\0';
    }
    if (ptr == end) return false;
    if (' ' < *ptr) {
      c = *ptr++;
      return true;
    }
  }
}
bool scan(std::string& s) {
  char c;
  if (!scan(c)) return false;
  for (s = c; ' ' < *ptr; s += c) scan(c);
  return true;
}
template <class T> std::enable_if_t<std::is_integral_v<T>, bool> scan(T& x) {
  char c;
  if (!scan(c)) return false;
  auto u = std::make_unsigned_t<std::common_type_t<T, int>>((c == '-' ? *ptr++ : c) & 15);
  while ('0' <= *ptr && *ptr <= '9') (u *= 10) += *ptr++ & 15;
  x = T(c == '-' ? -u : u);
  return true;
}
template <class T> std::enable_if_t<std::is_floating_point_v<T>, bool> scan(T& x) {
  char c;
  if (!scan(c)) return false;
  --ptr;
  if constexpr (std::is_same_v<T, float>) x = std::strtof(ptr, &ptr);
  if constexpr (std::is_same_v<T, double>) x = std::strtod(ptr, &ptr);
  if constexpr (std::is_same_v<T, long double>) x = std::strtold(ptr, &ptr);
  return true;
}

bool scan(std::vector<bool>::reference r) {
  bool b;
  auto ret = scan(b);
  if (ret) r = b;
  return ret;
}
template <class T1, class T2> bool scan(std::pair<T1, T2>&);
template <class... Ts> bool scan(std::tuple<Ts...>&);
template <class R> auto scan(R&& r) -> decltype(std::begin(r), bool()) {
  return std::all_of(std::begin(r), std::end(r), [](auto&& e) { return scan(std::forward<decltype(e)>(e)); });
}
template <class... Ts> std::enable_if_t<sizeof...(Ts) != 1, bool> scan(Ts&&... xs) {
  return (... && scan(std::forward<Ts>(xs)));
}
template <class T1, class T2> bool scan(std::pair<T1, T2>& p) { return scan(p.first, p.second); }
template <class... Ts> bool scan(std::tuple<Ts...>& t) {
  return std::apply([](auto&... es) { return scan(es...); }, t);
}

} // namespace scan_impl

using scan_impl::scan;

template <class T, class... Args> T input(Args&&... args) {
  auto ret = T(std::forward<Args>(args)...);
  scan(ret);
  return ret;
}
template <template <class...> class C, class... Args> auto input(Args&&... args) {
  auto ret = C(std::forward<Args>(args)...);
  scan(ret);
  return ret;
}

namespace print_impl {

char buf[1 << 15];
char* ptr = buf;

__attribute__((destructor)) void flush() {
  if (write(STDOUT_FILENO, buf, ptr - buf) == -1) std::abort();
  ptr = buf;
}

template <char = 0> void print(char c) {
  if (std::end(buf) - ptr < 64) flush();
  if (c) *ptr++ = c;
}
template <char = 0, class T> std::enable_if_t<std::is_integral_v<T>> print(T x) {
  print('\0');
  ptr = std::to_chars(ptr, std::end(buf), std::common_type_t<T, int>(x)).ptr;
}
template <char = 0, class T> std::enable_if_t<std::is_floating_point_v<T>> print(T x) {
  print('\0');
  if constexpr (std::is_same_v<T, float>) ptr += std::snprintf(ptr, std::end(buf) - ptr, "%.6f", x);
  if constexpr (std::is_same_v<T, double>) ptr += std::snprintf(ptr, std::end(buf) - ptr, "%.15f", x);
  if constexpr (std::is_same_v<T, long double>) ptr += std::snprintf(ptr, std::end(buf) - ptr, "%.18Lf", x);
}

template <char = 0> void print(std::vector<bool>::reference r) { print(bool(r)); }
template <char Sep = ' ', class T1, class T2> void print(const std::pair<T1, T2>&);
template <char Sep = ' ', class... Ts> void print(const std::tuple<Ts...>&);
template <char Sep = ' ', class R> auto print(R&& r) -> decltype(std::begin(r), void()) {
  [[maybe_unused]] auto c = '\0';
  for (auto&& e : r) {
    if constexpr (!std::is_same_v<std::decay_t<decltype(e)>, char>) print(std::exchange(c, Sep));
    print(e);
  }
}
template <char Sep = ' ', class... Ts> std::enable_if_t<sizeof...(Ts) != 1> print(Ts&&... xs) {
  [[maybe_unused]] auto c = '\0';
  (..., (print(std::exchange(c, Sep)), print(std::forward<Ts>(xs))));
}
template <char Sep, class T1, class T2> void print(const std::pair<T1, T2>& p) { print<Sep>(p.first, p.second); }
template <char Sep, class... Ts> void print(const std::tuple<Ts...>& t) {
  std::apply([](const auto&... es) { print<Sep>(es...); }, t);
}

} // namespace print_impl

using print_impl::print;

template <char Sep = ' ', char End = '\n', class... Ts> void println(Ts&&... xs) {
  print<Sep>(std::forward<Ts>(xs)...);
  print(End);
}

using Z = std::ptrdiff_t;

template <class T> Z sz(T&& x) {
  using std::size;
  return Z(size(std::forward<T>(x)));
}

namespace range_impl {

template <class T, class B> class iter_base : public std::iterator_traits<B> {
  T& t() { return static_cast<T&>(*this); }
  const T& t() const { return static_cast<const T&>(*this); }

 public:
  const B& base() const { return t().b_; }
  decltype(auto) operator*() const { return *base(); }
  auto operator->() const { return std::addressof(*t()); }
  T& operator++() { return t().inc(), t(); }
  T& operator--() { return t().dec(), t(); }
  T operator++(int) { return std::exchange(t(), std::move(++T(t()))); }
  T operator--(int) { return std::exchange(t(), std::move(--T(t()))); }
  T& operator+=(Z n) { return t().adv(n), t(); }
  T& operator-=(Z n) { return t().adv(-n), t(); }
  T operator+(Z n) const { return std::move(T(t()) += n); }
  T operator-(Z n) const { return std::move(T(t()) -= n); }
  decltype(auto) operator[](Z n) const { return *(t() + n); }
  friend T operator+(Z n, const T& x) { return x + n; }

#define DEF(op)   friend bool operator op(const T& x, const T& y) { return x.base() op y.base(); }

  DEF(==)
  DEF(!=)
  DEF(<)
  DEF(>)
  DEF(<=)
  DEF(>=)
#undef DEF
};

struct view_tag {};

template <class T> class view_base : public view_tag {
  auto b() const { return static_cast<const T&>(*this).begin(); }
  auto e() const { return static_cast<const T&>(*this).end(); }

 public:
  bool empty() const { return b() == e(); }
  explicit operator bool() const { return !empty(); }
  auto data() const { return std::addressof(*b()); }
  Z size() const { return std::distance(b(), e()); }
  decltype(auto) front() const { return *b(); }
  decltype(auto) back() const { return *std::prev(e()); }
  decltype(auto) operator[](Z n) const { return b()[n]; }
};

template <class R> class ref_view : public view_base<ref_view<R>> {
 public:
  ref_view(R& r) : r_(&r) {}
  auto begin() const { return std::begin(*r_); }
  auto end() const { return std::end(*r_); }
  Z size() const { return sz(*r_); }

 private:
  R* r_;
};
template <class R> class owning_view : public view_base<owning_view<R>> {
 public:
  owning_view(R&& r) : r_(std::move(r)) {}
  owning_view(owning_view&&) = default;
  owning_view& operator=(owning_view&&) = default;
  auto begin() const { return std::begin(r_); }
  auto end() const { return std::end(r_); }
  Z size() const { return sz(r_); }

 private:
  mutable R r_;
};
class all_t {
  template <class R> friend auto operator|(R&& r, all_t) {
    if constexpr (std::is_base_of_v<view_tag, std::decay_t<R>>)
      return std::forward<R>(r);
    else if constexpr (std::is_reference_v<R>)
      return ref_view<std::remove_reference_t<R>>(r);
    else
      return owning_view<R>(std::move(r));
  }
} all;

template <class T> class adaptor_base {
  template <class R> class view : public view_base<view<R>> {
   public:
    view(R r, T t) : r_(std::move(r)), t_(std::move(t)) {}
    auto begin() const { return t_.b(r_); }
    auto end() const { return t_.e(r_); }
    Z size() const { return t_.s(r_); }

   private:
    R r_;
    T t_;
  };
  template <class R> friend auto operator|(R&& r, T t) {
    auto v = std::forward<R>(r) | all;
    return view<decltype(v)>(std::move(v), std::move(t));
  }
};

template <class R> using iter = decltype(std::begin(std::declval<R&>()));

template <class F> class filtered : public adaptor_base<filtered<F>> {
 public:
  explicit filtered(F f) : f_(std::move(f)) {}

 private:
  template <class B> class i : public iter_base<i<B>, B> {
   public:
    using iterator_category = std::common_type_t<typename i::iterator_category, std::bidirectional_iterator_tag>;
    i(B b, B end, const filtered* p) : b_(std::move(b)), end_(std::move(end)), p_(p) {}

   private:
    friend class i::iter_base;
    void inc() { b_ = std::find_if(std::move(++b_), end_, std::ref(p_->f_)); }
    void dec() {
      for (--b_; !std::invoke(p_->f_, *b_);) --b_;
    }
    B b_, end_;
    const filtered* p_;
  };
  friend class filtered::adaptor_base;
  template <class R> i<iter<R>> b(R& r) const { return {std::find_if(r.begin(), r.end(), std::ref(f_)), r.end(), this}; }
  template <class R> i<iter<R>> e(R& r) const { return {r.end(), r.end(), this}; }
  template <class R> Z s(R& r) const { return std::count_if(r.begin(), r.end(), std::ref(f_)); }
  F f_;
};

template <class F> class mapped : public adaptor_base<mapped<F>> {
 public:
  explicit mapped(F f) : f_(std::move(f)) {}

 private:
  template <class B> class i : public iter_base<i<B>, B> {
   public:
    using reference = std::invoke_result_t<F, typename i::reference>;
    using value_type = std::decay_t<reference>;
    using pointer = value_type*;
    i(B b, const mapped* p) : b_(std::move(b)), p_(p) {}
    reference operator*() const { return std::invoke(p_->f_, *b_); }

   private:
    friend class i::iter_base;
    void inc() { ++b_; }
    void dec() { --b_; }
    void adv(Z n) { b_ += n; }
    friend Z operator-(const i& x, const i& y) { return x.b_ - y.b_; }
    B b_;
    const mapped* p_;
  };
  friend class mapped::adaptor_base;
  template <class R> i<iter<R>> b(R& r) const { return {r.begin(), this}; }
  template <class R> i<iter<R>> e(R& r) const { return {r.end(), this}; }
  template <class R> Z s(R& r) const { return sz(r); }
  F f_;
};

class reversed_t : public adaptor_base<reversed_t> {
  friend class adaptor_base;
  template <class R> auto b(R& r) const { return std::make_reverse_iterator(r.end()); }
  template <class R> auto e(R& r) const { return std::make_reverse_iterator(r.begin()); }
  template <class R> Z s(R& r) const { return sz(r); }
} reversed;

class rle_t : public adaptor_base<rle_t> {
  template <class B> class i : public iter_base<i<B>, B> {
   public:
    using iterator_category = std::common_type_t<typename i::iterator_category, std::forward_iterator_tag>;
    using value_type = std::pair<typename i::value_type, Z>;
    using reference = std::pair<typename i::reference, Z>;
    using pointer = void;
    i(B b, B next, B end) : b_(std::move(b)), next_(std::move(next)), end_(std::move(end)) {}
    reference operator*() const { return {*b_, std::distance(b_, next_)}; }

   private:
    friend class i::iter_base;
    void inc() {
      b_ = next_;
      if (next_ != end_)
        for (++next_; next_ != end_ && *b_ == *next_;) ++next_;
    }
    B b_, next_, end_;
  };
  friend class adaptor_base;
  template <class R> i<iter<R>> b(R& r) const {
    auto next = r.begin();
    if (!r.empty())
      for (++next; next != r.end() && r.front() == *next;) ++next;
    return {r.begin(), std::move(next), r.end()};
  }
  template <class R> i<iter<R>> e(R& r) const { return {r.end(), r.end(), r.end()}; }
  template <class R> Z s(R& r) { return std::distance(b(r), e(r)); }
} rle;

class sliced : public adaptor_base<sliced> {
 public:
  sliced(Z l, Z r) : l_(l), r_(r) { assert(l <= r); }

 private:
  friend class adaptor_base;
  template <class R> auto b(R& r) const { return r.begin() + l_; }
  template <class R> auto e(R& r) const { return r.begin() + r_; }
  template <class R> Z s(R&) const { return r_ - l_; }
  Z l_, r_;
};

class strided : public adaptor_base<strided> {
 public:
  explicit strided(Z n) : n_(n) { assert(1 <= n); }

 private:
  template <class B> class i : public iter_base<i<B>, B> {
   public:
    i(B b, B end, Z n, Z sz) : b_(std::move(b)), end_(std::move(end)), n_(n), sz_(sz) {}

   private:
    friend class i::iter_base;
    void inc() {
      if constexpr (std::is_base_of_v<std::random_access_iterator_tag, typename i::iterator_category>)
        b_ += std::min(n_, end_ - b_);
      else
        for (auto _ = n_; _-- && b_ != end_;) ++b_;
    }
    void dec() { std::advance(b_, b_ == end_ ? (sz_ - 1) / n_ * n_ - sz_ : -n_); }
    void adv(Z n) {
      if (n < 0) dec(), ++n;
      b_ += std::min(n_ * n, end_ - b_);
    }
    friend Z operator-(const i& x, const i& y) { return (x.b_ - y.b_ + x.n_ - 1) / x.n_; }
    B b_, end_;
    Z n_, sz_;
  };
  friend class adaptor_base;
  template <class R> i<iter<R>> b(R& r) const { return {r.begin(), r.end(), n_, sz(r)}; }
  template <class R> i<iter<R>> e(R& r) const { return {r.end(), r.end(), n_, sz(r)}; }
  template <class R> Z s(R& r) const { return (sz(r) + n_ - 1) / n_; }
  Z n_;
};

template <class F> class folded {
 public:
  explicit folded(F f) : f_(std::move(f)) {}
  template <class R> friend auto operator|(R&& r, folded f) {
    assert(!std::empty(r));
    return std::accumulate(std::next(std::begin(r)), std::end(r), *std::begin(r), std::ref(f.f_));
  }

 private:
  F f_;
};

class to_vector_t {
  template <class R> friend auto operator|(R&& r, to_vector_t) { return std::vector(std::begin(r), std::end(r)); }
} to_vector;

template <class I> class subrange : public view_base<subrange<I>> {
 public:
  subrange(I first, I last) : b_(std::move(first)), e_(std::move(last)) {}
  I begin() const { return b_; }
  I end() const { return e_; }

 private:
  I b_, e_;
};

template <class T> class int_iter : public iter_base<int_iter<T>, T> {
 public:
  using iterator_category = std::random_access_iterator_tag;
  using value_type = T;
  using difference_type = Z;
  using reference = T;
  using pointer = void;
  int_iter(T b) : b_(b) {}
  T operator*() const { return b_; }

 private:
  friend class int_iter::iter_base;
  void inc() { ++b_; }
  void dec() { --b_; }
  void adv(Z n) { b_ += T(n); }
  friend Z operator-(const int_iter& x, const int_iter& y) { return Z(x.b_ - y.b_); }
  T b_;
};

} // namespace range_impl

using range_impl::all;
using range_impl::filtered;
using range_impl::folded;
using range_impl::int_iter;
using range_impl::mapped;
using range_impl::reversed;
using range_impl::rle;
using range_impl::sliced;
using range_impl::strided;
using range_impl::subrange;
using range_impl::to_vector;

subrange<int_iter<Z>> rep(Z l, Z r) { return {std::min(l, r), r}; }
auto rep(Z n = 0) { return rep(0, n); }
auto rep(Z l, Z r, Z d) { return rep(l, r) | strided(d); }
template <class... Args> auto per(Args... args) { return rep(args...) | reversed; }

void solve(Z);

int main() {
  for (auto i : rep(input<Z>())) solve(i);
}

namespace atcoder {
namespace internal {

template <class E> struct csr {
    std::vector<int> start;
    std::vector<E> elist;
    explicit csr(int n, const std::vector<std::pair<int, E>>& edges)
        : start(n + 1), elist(edges.size()) {
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

} // namespace internal

} // namespace atcoder

namespace atcoder {
namespace internal {

// Reference:
// R. Tarjan,
// Depth-First Search and Linear Graph Algorithms
struct scc_graph {
  public:
    explicit scc_graph(int n) : _n(n) {}

    int num_vertices() { return _n; }

    void add_edge(int from, int to) { edges.push_back({from, {to}}); }

    // @return pair of (# of scc, scc id)
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

} // namespace internal

} // namespace atcoder

namespace atcoder {

struct scc_graph {
  public:
    scc_graph() : internal(0) {}
    explicit scc_graph(int n) : internal(n) {}

    void add_edge(int from, int to) {
        int n = internal.num_vertices();
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);
        internal.add_edge(from, to);
    }

    std::vector<std::vector<int>> scc() { return internal.scc(); }

  private:
    internal::scc_graph internal;
};

} // namespace atcoder

#define ALL(f, r, ...) [&](auto _v_) { return f(_v_.begin(), _v_.end(), ##__VA_ARGS__); }(r | all)
#define ALL2(f, r1, r2, ...) [&](auto _v2_) { return ALL(f, r1, _v2_.begin(), _v2_.end(), ##__VA_ARGS__); }(r2 | all)
#define LAMBDA(...) [&]([[maybe_unused]] auto&& _) -> decltype(auto) { return __VA_ARGS__; }
#define LAMBDA2(...) [&](auto&& _1, auto&& _2) -> decltype(auto) { return __VA_ARGS__; }
#define IF(...) filtered(LAMBDA(__VA_ARGS__))
#define MAP(...) mapped(LAMBDA(__VA_ARGS__))
#define FOLD(...) folded(LAMBDA2(__VA_ARGS__))

void solve(Z) {
  auto n = input<Z>();
  auto a = input<std::vector<Z>>(n);
  auto b = input<std::vector<Z>>(n);
  auto ord_a = rep(n) | to_vector;
  ALL(std::sort, ord_a, LAMBDA2(a[_2] < a[_1]));
  auto ord_b = rep(n) | to_vector;
  ALL(std::sort, ord_b, LAMBDA2(b[_2] < b[_1]));
  auto g = atcoder::scc_graph(n);
  for (auto i : rep(n - 1)) {
    g.add_edge(ord_a[i], ord_a[i + 1]);
    g.add_edge(ord_b[i], ord_b[i + 1]);
  }
  auto res = g.scc();
  auto id = std::vector<Z>(n);
  for (auto x : rep(sz(res))) {
    for (auto i : res[x]) {
      id[i] = x;
    }
  }
  auto d = std::vector<Z>(sz(res));
  auto go = [&](Z i, Z j) {
    if (id[i] == id[j]) {
      return;
    }
    ++d[id[j]];
  };
  for (auto i : rep(n - 1)) {
    go(ord_a[i], ord_a[i + 1]);
  }
  auto ans = std::string(n, '?');
  for (auto i : rep(n)) {
    ans[i] = char('0' + (id[i] == 0));
  }
  println(ans);
}