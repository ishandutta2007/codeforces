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

template <bool Max = false>
struct line_set {
  using ld = long double;
  struct line {
    mutable ld a, b, r = numeric_limits<ld>::max();
    ld operator()(ld x) const { return a * x + b; }
    friend bool operator<(const line& a, const line& b) { return a.a < b.a; }
    friend bool operator<(const line& a, ld b) { return a.r < b; }
  };
  multiset<line, less<>> ms;
  bool add(ld a, ld b) {
    if (not Max) a = -a, b = -b;
    auto needs = [&](auto it) {
      if (it == begin(ms)) return true;
      if (next(it) == end(ms)) return *prev(it) < *it or prev(it)->b < it->b;
      line l = *prev(it), r = *next(it);
      return it->b * (r.a - l.a) > l.b * (r.a - it->a) + r.b * (it->a - l.a);
    };
    auto it = ms.insert({a, b});
    if (not needs(it)) return ms.erase(it), false;
    while (it != begin(ms) and not needs(prev(it))) ms.erase(prev(it));
    if (it != begin(ms)) prev(it)->r = (prev(it)->b - b) / (a - prev(it)->a);
    while (next(it) != end(ms) and not needs(next(it))) ms.erase(next(it));
    if (next(it) != end(ms)) it->r = (b - next(it)->b) / (next(it)->a - a);
    return true;
  }
  ld operator()(ld x) const {
    assert(not empty(ms));
    ld res = (*ms.lower_bound(x))(x);
    return Max ? res : -res;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n = scan();
  auto s = scan<int64_t>();
  vector<int> v(n), c(n);
  for (int i : Rep(n)) {
    v[i] = scan();
    c[i] = scan();
  }
  {
    vector<int> order(n);
    iota(ALL(order), 0);
    sort(ALL(order), [&](int i, int j) {
      return c[i] != c[j] ? c[i] < c[j] : v[i] > v[j];
    });
    vector<int> nv, nc;
    for (int i : order) {
      if (not empty(nv) and not(nv.back() < v[i])) continue;
      nv.push_back(v[i]);
      nc.push_back(c[i]);
    }
    v = move(nv);
    c = move(nc);
    n = size(v);
  }
  DUMP(v);
  DUMP(c);

  line_set<true> ls;
  assert(c[0] == 0);
  ls.add(v[0], c[0]);
  for (int i : Rep(1, n)) {
    int64_t ng = 0, ok = c[i];
    while (ok - ng > 1) {
      auto mid = (ng + ok) / 2;
      (ls(mid) >= c[i] ? ok : ng) = mid;
    }
    DUMP(i, ok);
    ls.add(v[i], int64_t(round(ls(ok))) - c[i] - v[i] * ok);
  }

  int64_t ng = 0, ok = s;
  while (ok - ng > 1) {
    auto mid = (ng + ok) / 2;
    (ls(mid) >= s ? ok : ng) = mid;
  }
  cout << ok << '\n';
}