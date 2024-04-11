#include <bits/stdc++.h>

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

constexpr auto Inf = numeric_limits<int>::max() / 2;

struct S {
  map<int, int> mp{{-1, +Inf}, {+Inf, -1}};
  multiset<int> ms{0};

  void add(int x, int y) {
    if (mp.lower_bound(x)->second >= y) return;
    auto f = [](auto it) -> int { return it->first + next(it)->second + 2; };
    for (auto it = prev(mp.upper_bound(x)); it->second <= y;) {
      ms.erase(ms.find(f(prev(it))));
      ms.erase(ms.find(f(it)));
      it = prev(mp.erase(it));
      ms.insert(f(it));
    }
    ms.erase(ms.find(f(prev(mp.lower_bound(x)))));
    mp[x] = y;
    ms.insert(f(prev(mp.lower_bound(x))));
    ms.insert(f(mp.lower_bound(x)));
  }
  int get() {
    DUMP(mp);
    DUMP(ms);
    return *begin(ms);
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n = scan();
  vector<int> a(n), b(n), c(n);
  generate(ALL(a), scan<>);
  generate(ALL(b), scan<>);
  generate(ALL(c), scan<>);

  auto v = a;
  v.insert(end(v), ALL(b));
  v.insert(end(v), ALL(c));
  sort(ALL(v));
  v.erase(unique(ALL(v)), end(v));
  auto vi = [&](int e) -> int { return lower_bound(ALL(v), e) - begin(v); };

  int m = size(v);
  vector x(m, n), y(m, n), z(m, n);
  for (int i : Per(n)) {
    x[vi(a[i])] = i;
    y[vi(b[i])] = i;
    z[vi(c[i])] = i;
  }

  vector<int> order(m);
  iota(ALL(order), 0);
  sort(ALL(order), [&](int i, int j) { return z[i] > z[j]; });

  int ans = +Inf;
  auto it = begin(order);
  S s;
  for (int w : Per(n + 1)) {
    while (it != end(order) and z[*it] == w) {
      int i = *it;
      if (x[i] == n) x[i] = 10 * n;
      if (y[i] == n) y[i] = 10 * n;
      s.add(x[i], y[i]);
      ++it;
    }
    chmin(ans, s.get() + w);
  }
  cout << ans << '\n';
}