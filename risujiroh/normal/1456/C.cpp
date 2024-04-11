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
  int k = scan();
  vector<int64_t> a(n);
  generate(ALL(a), scan<>);
  sort(ALL(a));
  DUMP(a);

  vector<int64_t> suff(n + 1);
  for (int i : Per(n)) suff[i] = a[i] + suff[i + 1];

  vector<int64_t> suff2(n + 1);
  for (int i : Per(n)) suff2[i] = suff[i + 1] + suff2[i + 1];
  DUMP(suff2);

  vector<int64_t> pref(n + 1);
  for (int i : Rep(n)) pref[i + 1] = pref[i] + a[i] * (i / (k + 1));

  auto ans = numeric_limits<int64_t>::min();
  for (int m : Rep(n + 1)) {
    auto cur = suff[m] * ((m + k) / (k + 1)) + suff2[m];
    // for (int i : Rep(m)) cur += a[i] * (i / (k + 1));
    cur += pref[m];
    chmax(ans, cur);
  }
  cout << ans << '\n';
}