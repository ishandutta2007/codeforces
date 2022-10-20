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
  vector<int> a(n);
  generate(ALL(a), scan<>);

  stack<int, vector<int>> upper, lower;
  multiset<int64_t> ms_upper, ms_lower;
  vector<int64_t> f(n + 1);
  for (int i : Rep(n)) {
    {
      while (not(empty(upper) or a[upper.top()] > a[i])) {
        ms_upper.erase(ms_upper.find(f[upper.top()] + a[upper.top()]));
        upper.pop();
      }
      upper.push(i);
      ms_upper.insert(f[upper.top()] + a[upper.top()]);
    }
    {
      while (not(empty(lower) or a[lower.top()] < a[i])) {
        ms_lower.erase(ms_lower.find(f[lower.top()] - a[lower.top()]));
        lower.pop();
      }
      lower.push(i);
      ms_lower.insert(f[lower.top()] - a[lower.top()]);
    }
    chmax(f[i + 1], *rbegin(ms_upper) - a[i]);
    chmax(f[i + 1], *rbegin(ms_lower) + a[i]);
  }

  cout << f[n] << '\n';
}