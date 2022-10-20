// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt")
// #define NDEBUG

#include <bits/extc++.h>
#include <x86intrin.h>

struct rep {
  struct iter {
    int i;
    constexpr void operator++() { ++i; }
    constexpr int operator*() const { return i; }
    friend constexpr bool operator!=(iter a, iter b) { return *a != *b; }
  };
  const int l, r;
  constexpr rep(int _l, int _r) : l(std::min(_l, _r)), r(_r) {}
  constexpr rep(int n) : rep(0, n) {}
  constexpr iter begin() const { return {l}; }
  constexpr iter end() const { return {r}; }
};
struct per {
  struct iter {
    int i;
    constexpr void operator++() { --i; }
    constexpr int operator*() const { return i; }
    friend constexpr bool operator!=(iter a, iter b) { return *a != *b; }
  };
  const int l, r;
  constexpr per(int _l, int _r) : l(std::min(_l, _r)), r(_r) {}
  constexpr per(int n) : per(0, n) {}
  constexpr iter begin() const { return {r - 1}; }
  constexpr iter end() const { return {l - 1}; }
};
template <class T, class U>
constexpr bool chmin(T& a, U&& b) {
  return b < a ? a = std::forward<U>(b), true : false;
}
template <class T, class U>
constexpr bool chmax(T& a, U&& b) {
  return a < b ? a = std::forward<U>(b), true : false;
}

template <class T>
struct fenwick {
  fenwick() {}
  template <class Generator>
  fenwick(int n, Generator gen) : tree(n) {
    for (int i = 0; i < n; ++i) tree[i] = gen(i);
    for (int i = 0; i < n; ++i)
      if (int j = i | (i + 1); j < n) tree[j] += tree[i];
  }

  int size() const { return std::size(tree); }
  void add(int i, T a) {
    assert(0 <= i), assert(i < size());
    for (; i < size(); i |= i + 1) tree[i] += a;
  }
  T sum(int i) const {
    assert(0 <= i), assert(i <= size());
    T res{};
    for (; i; i &= i - 1) res += tree[i - 1];
    return res;
  }
  T sum(int l, int r) const {
    assert(0 <= l), assert(l <= r), assert(r <= size());
    return sum(r) - sum(l);
  }
  int kth(T k) const {
    static_assert(std::is_integral_v<T> and not std::is_same_v<T, bool>);
    assert(k >= 0);
    int i = 0;
    for (int w = 1 << std::__lg(size()); w; w >>= 1)
      if (i + w <= size() and tree[i + w - 1] <= k) k -= tree[(i += w) - 1];
    return i;
  }

 private:
  std::vector<T> tree;
};

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  string s;
  cin >> s;

  auto f = [&] {
    vector<int> res(n);
    vector<pair<char, int>> p(n);
    for (int i : rep(n)) p[i] = {s[i], i};
    sort(begin(p), end(p));
    for (int k : rep(n)) res[p[k].second] = k;
    return res;
  };

  auto p = f();
  reverse(begin(s), end(s));
  auto q = f();
  vector<int> iq(n);
  for (int i : rep(n)) iq[q[i]] = i;
  vector<int> a(n);
  for (int i : rep(n)) a[i] = iq[p[i]];

  int64_t ans{};
  fenwick<int> ft(n, [](int) { return 0; });
  for (int i : per(n)) {
    ans += ft.sum(a[i]);
    ft.add(a[i], +1);
  }
  cout << ans << '\n';
}