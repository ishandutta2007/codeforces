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

struct Vec {
  int n;
  vector<int> v;

  Vec(int n) : n(n), v(2 * n) {}

  int& operator[](int i) { return -n <= i and i < n ? v[n + i] : i; }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  auto s = scan<string>();
  int n = size(s);
  for (int q = scan(); q--;) {
    int k = scan();
    int d = scan();

    Vec p1(n);
    {
      for (int i : Rep(-n, n)) p1[i] = i;
      int to = 0;
      for (int r : Rep(d))
        for (int i = r; i < k; i += d) p1[i] = to++;
      for (int i : Rep(-n, n)) --p1[i];
    }

    auto op = [&](auto&& a, auto&& b) {
      Vec res(n);
      for (int i : Rep(-n, n)) res[i] = b[a[i]];
      return res;
    };

    auto p = p1;
    {
      int m = n - k;
      if (m & 1) p = op(p, p1);
      while (m >>= 1) {
        p1 = op(p1, p1);
        if (m & 1) p = op(p, p1);
      }
    }

    string ns(n, '?');
    for (int i : Rep(n)) ns[p[i] + (n - k + 1)] = s[i];
    s = move(ns);

    cout << s << '\n';
  }
}