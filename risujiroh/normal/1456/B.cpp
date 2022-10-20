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

constexpr int Inf = 0x3f3f3f3f;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n = scan();
  vector<int> a(n);
  generate(ALL(a), scan<>);

  {
    int r = 0;
    for (int l : Rep(n)) {
      while (r < n and __lg(a[l]) == __lg(a[r])) ++r;
      if (r - l >= 3) {
        cout << "1\n";
        exit(0);
      }
    }
  }

  vector<int> suff(n + 1);
  for (int i : Per(n)) suff[i] = a[i] ^ suff[i + 1];

  assert(n <= 60);
  int ans = +Inf;

  for (int m : Rep(1, n))
    for (int l : Rep(m))
      for (int r : Rep(m + 1, n + 1))
        if ((suff[l] ^ suff[m]) > (suff[m] ^ suff[r]))
          chmin(ans, (m - l - 1) + (r - m - 1));

  if (ans == +Inf) ans = -1;
  cout << ans << '\n';
}