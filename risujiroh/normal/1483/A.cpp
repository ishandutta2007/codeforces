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

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  for (int tt = scan(); tt--;) {
    int n = scan();
    int m = scan();
    vector<vector<int>> f(m);
    vector<int> one(n + 1), all(n + 1);
    for (int i : Rep(m)) {
      f[i].resize(scan());
      generate(ALL(f[i]), scan<>);
      if (size(f[i]) == 1) ++one[f[i][0]];
      for (auto&& e : f[i]) ++all[e];
    }
    int lim = (m + 1) / 2;
    if (*max_element(ALL(one)) > lim) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    int mi = max_element(ALL(all)) - begin(all);
    lim -= one[mi];
    for (int i : Rep(m)) {
      auto it = find(ALL(f[i]), mi);
      if (size(f[i]) == 1) {
        cout << f[i][0] << " \n"[i + 1 == m];
      } else if (it != end(f[i]) and lim-- > 0) {
        cout << mi << " \n"[i + 1 == m];
      } else {
        for (auto&& e : f[i])
          if (e != mi) {
            cout << e << " \n"[i + 1 == m];
            break;
          }
      }
    }
  }
}