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
  int n = scan(), s = scan(), l = scan();
  vector<int> a(n);
  generate(ALL(a), scan<>);
  vector<int> f(n + 1);
  {
    multiset<int> ms;
    auto check = [&](int x) {
      if (empty(ms)) return true;
      int mn = *begin(ms);
      int mx = *prev(end(ms));
      return mx - s <= x and x <= mn + s;
    };

    for (int i : Rep(n + 1)) {
      f[i] = i;
      if (i) chmax(f[i], f[i - 1]);
      while (f[i] < n and check(a[f[i]])) ms.insert(a[f[i]++]);
      if (i < n) ms.erase(ms.find(a[i]));
    }
  }
  DUMP(f);
  vector<vector<int>> add(n + 1), remove(n + 1);
  add[0].push_back(0);
  remove[0].push_back(0);
  multiset<int> ms;
  for (int i : Rep(n + 1)) {
    for (int x : add[i]) ms.insert(x);
    int cur = empty(ms) ? 0x3f3f3f3f : *begin(ms);
    DUMP(i, cur);
    if (i == n) {
      if (cur >= 0x3f3f3f3f) cur = -1;
      cout << cur << '\n';
      exit(0);
    }
    if (i + l <= f[i]) {
      add[i + l].push_back(cur + 1);
      remove[f[i]].push_back(cur + 1);
    }
    for (int x : remove[i]) ms.erase(ms.find(x));
  }
}