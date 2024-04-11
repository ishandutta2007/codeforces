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
};

constexpr auto Inf = numeric_limits<int64_t>::max() / 2;

struct Node {
  int64_t mx = -Inf;
  friend Node operator*(Node a, Node b) { return a.mx < b.mx ? b : a; }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n = scan();
  int m = scan();
  int d = scan();

  vector<int64_t> f(n), nf(n);
  int prv = 1;
  while (m--) {
    int pos = scan() - 1;
    int b = scan();
    int t = scan();
    foldable_deque<Node> deq;
    auto w = d * int64_t(t - prv);
    int l = 0, r = 0;
    for (int i : Rep(n)) {
      while (l and i - w < l) deq.push_front({f[--l]});
      while (r < n and r <= i + w) deq.push_back({f[r++]});
      while (l < i - w) deq.pop_front(), l++;
      while (i + w + 1 < r) deq.pop_back(), --r;
      nf[i] = deq.fold().mx + b - abs(i - pos);
    }
    swap(f, nf);
    prv = t;
  }
  cout << *max_element(ALL(f)) << '\n';
}