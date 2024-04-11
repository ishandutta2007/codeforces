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

vector<int> min_factor;
void prepare(int n) {
  min_factor.assign(n + 1, 0);
  for (int p = 2; p <= n; ++p) {
    if (min_factor[p]) continue;
    for (int i = p; i <= n; i += p)
      if (min_factor[i] == 0) min_factor[i] = p;
  }
}
vector<int> factors(int n) {
  vector<int> res;
  while (int d = min_factor[n]) res.push_back(d), n /= d;
  return res;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  prepare(1e6);
  for (int tt = scan(); tt--;) {
    int n = scan();
    map<set<int>, int> mp;
    for (int _ = n; _--;) {
      set<int> se;
      for (int p : factors(scan()))
        if (se.count(p))
          se.erase(p);
        else
          se.insert(p);
      ++mp[se];
    }
    array<int, 2> ans{};
    for (auto&& e : mp) chmax(ans[0], e.second);
    ans[1] = ans[0];
    int sum = 0;
    for (auto&& [k, v] : mp)
      if (empty(k) or v % 2 == 0) sum += v;
    chmax(ans[1], sum);
    for (int q = scan(); q--;) {
      if (scan<int64_t>())
        cout << ans[1] << '\n';
      else
        cout << ans[0] << '\n';
    }
  }
}