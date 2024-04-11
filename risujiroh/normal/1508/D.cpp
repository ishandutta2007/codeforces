#include <bits/stdc++.h>

class Dsu {
 public:
  Dsu() {}
  explicit Dsu(int n) : dat(n, -1), num_components_(n) {}

  int size() const { return std::size(dat); }
  int root(int v) {
    assert(0 <= v), assert(v < size());
    return dat[v] < 0 ? v : dat[v] = root(dat[v]);
  }
  std::pair<int, int> unite(int u, int v) {
    assert(0 <= u), assert(u < size());
    assert(0 <= v), assert(v < size());
    u = root(u), v = root(v);
    if (u == v) return {u, -1};
    --num_components_;
    if (-dat[u] < -dat[v]) std::swap(u, v);
    dat[u] += dat[v];
    dat[v] = u;
    return {u, v};
  }
  bool same(int u, int v) {
    assert(0 <= u), assert(u < size());
    assert(0 <= v), assert(v < size());
    return root(u) == root(v);
  }
  int size(int v) {
    assert(0 <= v), assert(v < size());
    return -dat[root(v)];
  }
  int num_components() const { return num_components_; }

 private:
  std::vector<int> dat;
  int num_components_;
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
  int n = scan();
  vector<int> x(n), y(n), a(n);
  for (int i : Rep(n)) {
    x[i] = scan();
    y[i] = scan();
    a[i] = scan() - 1;
  }

  Dsu d(n);
  for (int i : Rep(n)) d.unite(i, a[i]);

  vector<pair<int, int>> ans;
  auto add = [&](int i, int j) -> void {
    swap(a[i], a[j]);
    ans.emplace_back(i, j);
  };

  for (int c : Rep(n))
    if (d.size(c) > 1) {
      vector<int> order;
      for (int i : Rep(n))
        if (i != c) order.push_back(i);
      sort(ALL(order), [&](int i, int j) {
        return atan2(y[i] - y[c], x[i] - x[c]) <
               atan2(y[j] - y[c], x[j] - x[c]);
      });

      for (int z : Rep(n - 1)) {
        int i = order[z];
        int j = order[(z + 1) % (n - 1)];
        auto t =
            atan2(y[c] - y[j], x[c] - x[j]) - atan2(y[i] - y[j], x[i] - x[j]);
        if (t < -acos(-1)) t += 2 * acos(-1);
        if (0 < t and t < acos(-1)) continue;
        if (d.same(i, j)) continue;
        d.unite(i, j);
        add(i, j);
      }

      for (int _ = n - 1; _--;) add(c, a[c]);
      break;
    }

  cout << size(ans) << '\n';
  for (auto&& [i, j] : ans) cout << i + 1 << ' ' << j + 1 << '\n';

  assert(is_sorted(ALL(a)));
  for (auto&& [i, j] : ans)
    if (i > j) swap(i, j);
  sort(ALL(ans));
  assert(adjacent_find(ALL(ans), equal_to{}) == end(ans));
}