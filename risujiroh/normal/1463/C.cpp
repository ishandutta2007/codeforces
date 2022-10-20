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

constexpr auto Inf = numeric_limits<int64_t>::max() / 2;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  for (int tt = scan(); tt--;) {
    int n = scan();
    vector<int64_t> t(n), x(n);
    for (int i : Rep(n)) cin >> t[i] >> x[i];
    vector<array<int64_t, 2>> v{{0, 0}};
    for (int i : Rep(n)) {
      if (t[i] < v.back()[0]) {
        auto temp = v.back();
        v.pop_back();
        v.push_back({t[i], v.back()[1] + (temp[1] - v.back()[1]) /
                                             (temp[0] - v.back()[0]) *
                                             (t[i] - v.back()[0])});
        v.push_back(temp);
        continue;
      }
      if (v.back()[0] < t[i]) v.push_back({t[i], v.back()[1]});
      v.push_back({t[i] + abs(x[i] - v.back()[1]), x[i]});
    }
    DUMP(v);
    int ans = 0;
    for (int i : Rep(n)) {
      auto first = lower_bound(ALL(v), array{t[i], -Inf});
      auto last =
          i < n - 1 ? upper_bound(ALL(v), array{t[i + 1], +Inf}) : end(v);
      bool any = false;
      for (auto it = first; it != last and next(it) != last; ++it) {
        int a = (*it)[1];
        int b = (*next(it))[1];
        if (min(a, b) > x[i]) continue;
        if (max(a, b) < x[i]) continue;
        any = true;
        break;
      }
      ans += any;
    }
    // ans += v.back()[1] == x.back();
    cout << ans << '\n';
  }
}