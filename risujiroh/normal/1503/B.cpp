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
  int n = scan();
  vector<vector<pair<int, int>>> v(2);
  for (int i : Rep(n))
    for (int j : Rep(n)) v[(i + j) & 1].emplace_back(i + 1, j + 1);
  for (int _ = n * n; _--;) {
    int a = scan();
    if (a == 1) {
      if (empty(v[0])) {
        auto [i, j] = v[1].back();
        v[1].pop_back();
        cout << "3 " << i << ' ' << j << endl;
      } else {
        auto [i, j] = v[0].back();
        v[0].pop_back();
        cout << "2 " << i << ' ' << j << endl;
      }
    } else {
      if (empty(v[1])) {
        auto [i, j] = v[0].back();
        v[0].pop_back();
        if (a == 2) {
          cout << "3 " << i << ' ' << j << endl;
        } else {
          cout << "2 " << i << ' ' << j << endl;
        }
      } else {
        auto [i, j] = v[1].back();
        v[1].pop_back();
        cout << "1 " << i << ' ' << j << endl;
      }
    }
  }
}