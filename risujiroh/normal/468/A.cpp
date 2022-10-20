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
  if (n <= 3) {
    cout << "NO\n";
    exit(0);
  }
  cout << "YES\n";
  if (n == 4) {
    cout << "1 * 2 = 2\n";
    cout << "2 * 3 = 6\n";
    cout << "6 * 4 = 24\n";
  } else if (n == 5) {
    cout << "4 * 5 = 20\n";
    cout << "20 - 1 = 19\n";
    cout << "19 + 2 = 21\n";
    cout << "21 + 3 = 24\n";
  } else {
    cout << "6 - 5 = 1\n";
    cout << "1 - 1 = 0\n";
    for (int i : Rep(7, n + 1)) cout << i << " * 0 = 0\n";
    cout << "2 * 3 = 6\n";
    cout << "6 * 4 = 24\n";
    cout << "24 + 0 = 24\n";
  }
}