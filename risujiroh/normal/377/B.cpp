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
  int m = scan();
  int s = scan();
  vector<int> a(m), b(n), c(n);
  generate(ALL(a), scan<>);
  generate(ALL(b), scan<>);
  generate(ALL(c), scan<>);
  vector<int> order(m);
  iota(ALL(order), 0);
  sort(ALL(order), [&](int i, int j) { return a[i] > a[j]; });
  vector<int> ord(n);
  iota(ALL(ord), 0);
  sort(ALL(ord), [&](int i, int j) { return b[i] > b[j]; });

  vector<int> ans(m);
  auto check = [&](int days, bool out = false) -> bool {
    int64_t need = 0;
    int i = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    for (int z = 0; z < m; z += days) {
      int j = order[z];
      while (i < n and b[ord[i]] >= a[j]) {
        pq.emplace(c[ord[i]], ord[i]);
        ++i;
      }
      if (empty(pq)) return false;
      auto [mn, mi] = pq.top();
      pq.pop();
      need += mn;
      if (out)
        for (int k : Rep(z, min(z + days, m))) ans[order[k]] = mi + 1;
    }
    return need <= s;
  };

  int ng = 0, ok = m + 1;
  while (ok - ng > 1) {
    int mid = (ng + ok) / 2;
    (check(mid) ? ok : ng) = mid;
  }
  if (ok > m) {
    cout << "NO\n";
    exit(0);
  }
  cout << "YES\n";
  check(ok, true);
  for (int i : Rep(m)) cout << ans[i] << " \n"[i + 1 == m];
}