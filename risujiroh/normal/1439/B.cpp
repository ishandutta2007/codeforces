#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

struct Splitmix64Hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t r =
        std::chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + r);
  }
};
template <class Key, class T>
using HashMap = __gnu_pbds::gp_hash_table<Key, T, Splitmix64Hash>;
template <class Key>
using HashSet = HashMap<Key, __gnu_pbds::null_type>;

template <class T>
class Deque {
 public:
  Deque() {}
  explicit Deque(int n) : l(n) {}
  Deque(int n, const T& a) : l(n, a) {}
  template <class InputIterator>
  Deque(InputIterator first, InputIterator last)
      : l(std::distance(first, last)) {
    std::copy(first, last, std::rbegin(l));
  }
  Deque(std::initializer_list<T> il) : Deque(std::begin(il), std::end(il)) {}

  const T& operator[](int i) const {
    return i < int(std::size(l)) ? l[std::size(l) - i - 1]
                                 : r[i - std::size(l)];
  }
  T& operator[](int i) {
    return i < int(std::size(l)) ? l[std::size(l) - i - 1]
                                 : r[i - std::size(l)];
  }
  const T& front() const { return std::empty(l) ? r.front() : l.back(); }
  T& front() { return std::empty(l) ? r.front() : l.back(); }
  const T& back() const { return std::empty(r) ? l.front() : r.back(); }
  T& back() { return std::empty(r) ? l.front() : r.back(); }

  bool empty() const { return std::empty(l) and std::empty(r); }
  int size() const { return std::size(l) + std::size(r); }

  void clear() { l.clear(), r.clear(); }
  void push_front(const T& a) { l.push_back(a); }
  void push_front(T&& a) { l.push_back(std::move(a)); }
  template <class... Args>
  T& emplace_front(Args&&... args) {
    return l.emplace_back(std::forward<Args>(args)...);
  }
  void pop_front() {
    if (std::empty(l)) {
      int sz = std::size(r) / 2;
      std::move(std::rbegin(r) + sz, std::rend(r), std::back_inserter(l));
      std::move(std::end(r) - sz, std::end(r), std::begin(r));
      r.resize(sz);
    }
    l.pop_back();
  }
  void push_back(const T& a) { r.push_back(a); }
  void push_back(T&& a) { r.push_back(std::move(a)); }
  template <class... Args>
  T& emplace_back(Args&&... args) {
    return r.emplace_back(std::forward<Args>(args)...);
  }
  void pop_back() {
    if (std::empty(r)) {
      int sz = std::size(l) / 2;
      std::move(std::rbegin(l) + sz, std::rend(l), std::back_inserter(r));
      std::move(std::end(l) - sz, std::end(l), std::begin(l));
      l.resize(sz);
    }
    r.pop_back();
  }
  void resize(int sz) {
    if (sz < size())
      for (int _ = size() - sz; _--;) pop_back();
    else if (sz > size())
      r.resize(sz - std::size(l));
  }

 private:
  std::vector<T> l, r;
};
template <class InputIterator>
Deque(InputIterator, InputIterator)
    -> Deque<typename std::iterator_traits<InputIterator>::value_type>;

class StaticGraph {
 public:
  struct Edge {
    int dst;
  };

  StaticGraph() {}
  StaticGraph(int n, int m) : n_(n), m_(m), head(n + 1) { pool.reserve(m); }

  int n() const { return n_; }
  int m() const { return m_; }

  int add(int src, const Edge& e) {
    ++head[src];
    pool.emplace_back(src, e);
    if (int(std::size(pool)) == m()) build();
    return std::size(pool) - 1;
  }

  template <class Function>
  void for_each_outedge(int v, Function f) const {
    std::for_each(std::begin(edge) + head[v], std::begin(edge) + head[v + 1],
                  f);
  }
  int degree(int v) const { return head[v + 1] - head[v]; }

 private:
  void build() {
    std::partial_sum(std::begin(head), std::end(head), std::begin(head));
    edge.resize(m());
    for (auto&& [src, e] : pool) edge[--head[src]] = std::move(e);
    decltype(pool){}.swap(pool);
    for (int v = 0; v < n(); ++v)
      std::sort(std::begin(edge) + head[v], std::begin(edge) + head[v + 1],
                [](auto&& a, auto&& b) { return a.dst < b.dst; });
  }

  int n_, m_;
  std::vector<int> head;
  std::vector<Edge> edge;
  std::vector<std::pair<int, Edge>> pool;
};

#pragma region my_template

struct Rep {
  struct I {
    int i;
    void operator++() { ++i; }
    int operator*() const { return i; }
    bool operator!=(I o) const { return i < *o; }
  };
  const int l_, r_;
  Rep(int l, int r) : l_(l), r_(r) {}
  Rep(int n) : Rep(0, n) {}
  I begin() const { return {l_}; }
  I end() const { return {r_}; }
};
struct Per {
  struct I {
    int i;
    void operator++() { --i; }
    int operator*() const { return i; }
    bool operator!=(I o) const { return i > *o; }
  };
  const int l_, r_;
  Per(int l, int r) : l_(l), r_(r) {}
  Per(int n) : Per(0, n) {}
  I begin() const { return {r_ - 1}; }
  I end() const { return {l_ - 1}; }
};

template <class F>
struct Fix : private F {
  Fix(F f) : F(f) {}
  template <class... Args>
  decltype(auto) operator()(Args&&... args) const {
    return F::operator()(*this, std::forward<Args>(args)...);
  }
};

template <class T = int>
T scan() {
  T res;
  std::cin >> res;
  return res;
}

template <class T, class U = T>
bool chmin(T& a, U&& b) {
  return b < a ? a = std::forward<U>(b), true : false;
}
template <class T, class U = T>
bool chmax(T& a, U&& b) {
  return a < b ? a = std::forward<U>(b), true : false;
}

#ifndef LOCAL
#define DUMP(...) void(0)
template <int OnlineJudge, int Local>
constexpr int OjLocal = OnlineJudge;
#endif

using namespace std;

#define ALL(c) begin(c), end(c)

#pragma endregion

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  for (int tt = scan(); tt--;) {
    int n = scan();
    int m = scan();
    int k = scan();
    StaticGraph g(n, 2 * m);
    vector<HashSet<int>> hs(n);
    while (m--) {
      int u = scan() - 1;
      int v = scan() - 1;
      g.add(u, {v});
      g.add(v, {u});
      if (v < u) hs[u].insert(v);
      if (u < v) hs[v].insert(u);
    }

    vector alive(n, true);
    vector<int> ans;
    auto check = [&](int v) -> void {
      if (not empty(ans)) return;
      vector<int> vs;
      g.for_each_outedge(v, [&](auto e) {
        if (alive[e.dst]) vs.push_back(e.dst);
      });
      assert(int(size(vs)) == k - 1);
      for (int u : vs)
        for (int x : vs)
          if (x < u)
            if (hs[u].find(x) == std::end(hs[u])) return;
      ans = vs;
      ans.push_back(v);
    };

    Deque<int> que;
    vector<int> deg(n);
    for (int v : Rep(n)) {
      deg[v] = g.degree(v);
      if (deg[v] < k) {
        if (deg[v] == k - 1) check(v);
        que.push_back(v);
      }
    }

    while (not empty(que)) {
      int v = que.front();
      que.pop_front();
      alive[v] = false;
      g.for_each_outedge(v, [&](auto e) {
        int u = e.dst;
        if (not alive[u]) return;
        if (deg[u]-- == k) {
          check(u);
          que.push_back(u);
        }
      });
    }

    if (empty(ans)) {
      for (int v : Rep(n))
        if (alive[v]) ans.push_back(v);
      if (empty(ans))
        cout << "-1\n";
      else {
        cout << "1 " << size(ans) << '\n';
        for (int i : Rep(size(ans)))
          cout << ans[i] + 1 << " \n"[i == int(size(ans)) - 1];
      }
    } else {
      cout << "2\n";
      for (int i : Rep(k)) cout << ans[i] + 1 << " \n"[i == k - 1];
    }
  }
}