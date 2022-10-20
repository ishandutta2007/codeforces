#include <bits/stdc++.h>

#pragma region my_template

struct Rep {
  struct I {
    int i;
    void operator++() { ++i; }
    int operator*() const { return i; }
    bool operator!=(I o) const { return i < *o; }
  };
  const int l, r;
  Rep(int _l, int _r) : l(_l), r(_r) {}
  Rep(int n) : Rep(0, n) {}
  I begin() const { return {l}; }
  I end() const { return {r}; }
};
struct Per {
  struct I {
    int i;
    void operator++() { --i; }
    int operator*() const { return i; }
    bool operator!=(I o) const { return i > *o; }
  };
  const int l, r;
  Per(int _l, int _r) : l(_l), r(_r) {}
  Per(int n) : Per(0, n) {}
  I begin() const { return {r - 1}; }
  I end() const { return {l - 1}; }
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
  int n = scan(), l = scan(), x = scan(), y = scan();
  vector<int> a(n);
  generate(ALL(a), scan<>);
  bool okx = false, oky = false;
  for (int e : a) {
    okx |= binary_search(ALL(a), e + x);
    oky |= binary_search(ALL(a), e + y);
  }
  if (okx and oky) {
    cout << "0\n";
    exit(0);
  }
  if (okx or oky) {
    cout << "1\n";
    cout << (okx ? y : x) << '\n';
    exit(0);
  }
  set<int> sx, sy;
  for (int e : a) {
    if (e - x >= 0) sx.insert(e - x);
    if (e + x <= l) sx.insert(e + x);
    if (e - y >= 0) sy.insert(e - y);
    if (e + y <= l) sy.insert(e + y);
  }
  for (int e : sx)
    if (sy.count(e)) {
      cout << "1\n";
      cout << e << '\n';
      exit(0);
    }
  cout << "2\n";
  cout << x << ' ' << y << '\n';
}