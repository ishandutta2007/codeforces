#include <bits/stdc++.h>

template <class ForwardIterator, class F>
void bitwise_transform(ForwardIterator first, ForwardIterator last, F f) {
  int n = std::distance(first, last);
  assert((n & (n - 1)) == 0);
  for (int step = 1; step < n; step *= 2)
    for (auto i = first; i != last;) {
      auto j = std::next(i, step);
      for (auto end = j; i != end; ++i, ++j) f(*i, *j);
      i = j;
    }
}

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

template <class T>
struct foldable_deque {
  vector<T> l, r, cuml = {T()}, cumr = {T()};
  T fold() const { return cuml.back() * cumr.back(); }
  void build(vector<T> v) {
    l = r = {}, cuml = cumr = {T()};
    int n = v.size();
    for (int i = n / 2; i < n; ++i) push_back(v[i]);
    for (int i = n / 2; i--;) push_front(v[i]);
  }
  void push_front(T a) { l.push_back(a), cuml.push_back(a * cuml.back()); }
  void push_back(T a) { r.push_back(a), cumr.push_back(cumr.back() * a); }
  void pop_front() {
    if (l.empty())
      build({begin(r) + 1, end(r)});
    else
      l.pop_back(), cuml.pop_back();
  }
  void pop_back() {
    if (r.empty())
      build({rbegin(l), rend(l) - 1});
    else
      r.pop_back(), cumr.pop_back();
  }
  int size() const { return std::size(l) + std::size(r); }
};

struct Node {
  int v = 0;
  operator int() const { return v; }
  friend Node operator*(Node a, Node b) { return {a.v | b.v}; }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int m = scan();
  int n = scan();
  int d = scan();
  vector<int> a(m);
  for (int i : Rep(n))
    for (int s = scan(); s--;) a[scan() - 1] |= 1 << i;
  DUMP(a);
  foldable_deque<Node> deq;
  vector<int> b(1 << n);
  {
    int p = 0;
    for (int i : Rep(m - d + 1)) {
      while (size(deq) < d) deq.push_back({a[p++]});
      DUMP(deq.l, deq.r);
      DUMP(deq.cuml, deq.cumr);
      DUMP(deq.size(), deq.fold().v);
      ++b[deq.fold().v ^ ~-(1 << n)];
      deq.pop_front();
    }
  }
  bitwise_transform(ALL(b), [](auto&& lo, auto&& hi) { lo += hi; });
  int ans = n;
  for (int mask : Rep(1 << n))
    if (b[mask] == 0) chmin(ans, __builtin_popcount(mask));
  cout << ans << '\n';
}