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

constexpr int Inf = 0x3f3f3f3f;

constexpr int L = OjLocal<1000, 10>;

struct Parcel {
  int in, out, w, s, v;

  friend bool operator<(const Parcel& a, const Parcel& b) {
    return a.out - a.in < b.out - b.in;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n = scan(), ss = scan();
  vector<Parcel> p(n);
  for (auto&& [i, o, w, s, v] : p)
    i = scan(), o = scan(), w = scan(), s = scan(), v = scan();
  ++n;
  p.push_back({0, 2 * n, 0, ss, 0});
  sort(ALL(p));
  vector dp(n, vector(L + 1, -Inf));
  for (int i : Rep(n)) {
    vector<int> order;
    for (int j : Rep(i))
      if (p[i].in <= p[j].in and p[j].out <= p[i].out) order.push_back(j);
    sort(ALL(order), [&](auto&& a, auto&& b) { return p[a].out < p[b].out; });
    vector<int> f(p[i].out - p[i].in + 1);
    for (int x : Rep(p[i].w, L + 1)) {
      f[0] = 0;
      int r = p[i].in;
      for (int j : order) {
        while (r < p[j].out) {
          f[(r + 1) - p[i].in] = f[r - p[i].in];
          ++r;
        }
        chmax(f[p[j].out - p[i].in],
              f[p[j].in - p[i].in] + dp[j][min(x - p[i].w, p[i].s)]);
      }
      while (r < p[i].out) {
        f[(r + 1) - p[i].in] = f[r - p[i].in];
        ++r;
      }
      dp[i][x] = p[i].v + f.back();
      if (x > p[i].w) chmax(dp[i][x], dp[i][x - 1]);
    }
  }
  DUMP(dp);
  cout << dp.back()[ss] << '\n';
}