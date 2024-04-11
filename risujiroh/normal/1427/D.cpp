// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt")
// #define NDEBUG

#include <bits/extc++.h>
#include <x86intrin.h>

struct rep {
  struct iter {
    int i;
    constexpr void operator++() { ++i; }
    constexpr int operator*() const { return i; }
    friend constexpr bool operator!=(iter a, iter b) { return *a != *b; }
  };
  const int l, r;
  constexpr rep(int _l, int _r) : l(std::min(_l, _r)), r(_r) {}
  constexpr rep(int n) : rep(0, n) {}
  constexpr iter begin() const { return {l}; }
  constexpr iter end() const { return {r}; }
};
struct per {
  struct iter {
    int i;
    constexpr void operator++() { --i; }
    constexpr int operator*() const { return i; }
    friend constexpr bool operator!=(iter a, iter b) { return *a != *b; }
  };
  const int l, r;
  constexpr per(int _l, int _r) : l(std::min(_l, _r)), r(_r) {}
  constexpr per(int n) : per(0, n) {}
  constexpr iter begin() const { return {r - 1}; }
  constexpr iter end() const { return {l - 1}; }
};
template <class T, class U>
constexpr bool chmin(T& a, U&& b) {
  return b < a ? a = std::forward<U>(b), true : false;
}
template <class T, class U>
constexpr bool chmax(T& a, U&& b) {
  return a < b ? a = std::forward<U>(b), true : false;
}

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto&& e : a) cin >> e, --e;

  vector<vector<int>> ans;
  auto f = [&](int l, int r) -> void {
    if (r == n) {
      ans.push_back({l, n - l});
      rotate(begin(a), begin(a) + l, end(a));
      return;
    }
    if (l == 0) {
      ans.push_back({r, n - r});
      rotate(begin(a), begin(a) + r, end(a));
      return;
    }
    assert(0 < l), assert(l < r), assert(r < n);
    ans.push_back({l, r - l, n - r});
    vector<int> na;
    na.reserve(n);
    na.insert(end(na), begin(a) + r, end(a));
    na.insert(end(na), begin(a) + l, begin(a) + r);
    na.insert(end(na), begin(a), begin(a) + l);
    a = move(na);
  };

  auto good = [&](int i) -> bool {
    assert(0 <= i), assert(i + 1 < n);
    return (a[i] + 1) % n == a[i + 1];
  };

  int l = 0, r = 1;
  while (r < n and good(r - 1)) ++r;
  while (not is_sorted(begin(a), end(a))) {
    if (l == 0 and r == n) {
      int pos = find(begin(a), end(a), 0) - begin(a);
      assert(pos);
      ans.push_back({pos, n - pos});
      rotate(begin(a), begin(a) + pos, end(a));
      break;
    }

    vector<int> ia(n);
    for (int i : rep(n)) ia[a[i]] = i;
    if (l == 0) {
      int j = ia[(a[0] + n - 1) % n];
      f(r, j + 1);
      l = n - (r - l + 1), r = n;
    } else {
      int j = ia[(a[n - 1] + 1) % n];
      f(j, l);
      r = r - l + 1, l = 0;
    }
  }

  cout << size(ans) << '\n';
  for (auto&& v : ans) {
    cout << size(v);
    for (int e : v) cout << ' ' << e;
    cout << '\n';
  }
}