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

int cdiv(int a, int b) { return (a + b - 1) / b; }

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int hy = scan(), ay = scan(), dy = scan();
  int hm = scan(), am = scan(), dm = scan();
  int h = scan(), a = scan(), d = scan();
  int ans = 0x3f3f3f3f;
  for (int hp : Rep(hy, 10001))
    for (int atk : Rep(ay, 201))
      for (int def : Rep(dy, 101)) {
        if (atk <= dm) continue;
        int cost = (hp - hy) * h + (atk - ay) * a + (def - dy) * d;
        int t = cdiv(hm, max(atk - dm, 0));
        if (hp - max(am - def, 0) * t > 0) chmin(ans, cost);
      }
  cout << ans << '\n';
}