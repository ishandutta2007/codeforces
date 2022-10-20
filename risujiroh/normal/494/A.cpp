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
  return std::cin >> res, res;
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
  auto s = scan<string>();
  int d = count(ALL(s), '(') - count(ALL(s), ')');
  int n = count(ALL(s), '#');
  if (d < n) {
    cout << "-1\n";
    exit(0);
  }
  string t;
  {
    int a = n;
    for (auto&& c : s)
      if (c == '#')
        t += string(--a ? 1 : d - n + 1, ')');
      else

        t += c;
  }
  int h = 0;
  bool ok = true;
  for (char c : t) {
    h += c == '(';
    h -= c == ')';
    if (h < 0) {
      ok = false;
      break;
    }
  }
  ok &= h == 0;
  if (ok) {
    int a = n;
    for (char c : s)
      if (c == '#') cout << (--a ? 1 : d - n + 1) << '\n';
  } else {
    cout << "-1\n";
  }
}