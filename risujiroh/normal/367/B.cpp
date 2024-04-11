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
  int p = scan();
  vector<int> a(n), b(m);
  generate(ALL(a), scan<>);
  generate(ALL(b), scan<>);
  {
    auto v = a;
    v.insert(end(v), ALL(b));
    sort(ALL(v));
    v.erase(unique(ALL(v)), end(v));
    for (auto&& e : a) e = lower_bound(ALL(v), e) - begin(v);
    for (auto&& e : b) e = lower_bound(ALL(v), e) - begin(v);
  }

  vector<int> cb(n + m);
  for (auto&& e : b) ++cb[e];

  vector<int> c(n + m);
  int same = count(ALL(cb), 0);
  auto add = [&](int x) {
    same -= c[x] == cb[x];
    ++c[x];
    same += c[x] == cb[x];
  };
  auto remove = [&](int x) {
    same -= c[x] == cb[x];
    --c[x];
    same += c[x] == cb[x];
  };

  vector<int> ans;
  for (int r : Rep(p)) {
    for (int i = r, j = r; i < n; i += p) {
      while (j < n and (j - i) / p < m) {
        add(a[j]);
        j += p;
      }
      if (same == n + m) ans.push_back(i);
      remove(a[i]);
    }
  }

  sort(ALL(ans));
  cout << size(ans) << '\n';
  for (int i : Rep(size(ans)))
    cout << ans[i] + 1 << " \n"[i + 1 == int(size(ans))];
}