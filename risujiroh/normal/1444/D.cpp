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

  constexpr int L = 5e6;

  auto divide = [&](const vector<int>& a) -> array<vector<int>, 2> {
    int n = size(a);
    vector<bitset<L + 1>> dp(n + 1);
    dp[n][0] = 1;
    for (int i : per(n)) dp[i] = dp[i + 1] | dp[i + 1] << a[i];
    int sum = accumulate(begin(a), end(a), 0);
    if (sum & 1 or dp[0][sum / 2] == 0) return {};
    array<vector<int>, 2> res;
    int cur = sum / 2;
    for (int i : rep(n)) {
      assert(dp[i][cur]);
      if (a[i] <= cur and dp[i + 1][cur - a[i]]) {
        res[0].push_back(i);
        cur -= a[i];
      } else {
        res[1].push_back(i);
      }
    }
    if (size(res[0]) > size(res[1])) swap(res[0], res[1]);
    for (auto&& v : res)
      sort(begin(v), end(v), [&](int i, int j) { return a[i] < a[j]; });
    return res;
  };

  int tt;
  cin >> tt;
  while (tt--) {
    int num_h;
    cin >> num_h;
    vector<int> len_h(num_h);
    for (auto&& e : len_h) cin >> e;
    int num_v;
    cin >> num_v;
    vector<int> len_v(num_v);
    for (auto&& e : len_v) cin >> e;
    if (num_h != num_v) {
      cout << "No\n";
      continue;
    }
    assert(num_h == num_v);

    auto idx_h = divide(len_h);
    auto idx_v = divide(len_v);
    if (empty(idx_h[0]) or empty(idx_v[0])) {
      cout << "No\n";
      continue;
    }
    cout << "Yes\n";

    bool transposed = size(idx_h[0]) < size(idx_v[0]);
    if (transposed) {
      swap(num_h, num_v);
      swap(len_h, len_v);
      swap(idx_h, idx_v);
    }
    assert(size(idx_h[0]) >= size(idx_v[0]));
    int m = size(idx_v[0]);

    vector<pair<int, int>> ans{{0, 0}};
    auto add = [&](int dx, int dy) -> void {
      auto [x, y] = ans.back();
      ans.emplace_back(x + dx, y + dy);
    };

    reverse(begin(idx_h[0]), end(idx_h[0]));
    reverse(begin(idx_h[1]), end(idx_h[1]));
    for (int i : rep(num_h - m)) {
      if (i < int(size(idx_h[1]))) {
        add(len_h[idx_h[1][i]], 0);
      } else {
        add(-len_h[idx_h[0][i - size(idx_h[1])]], 0);
      }
      add(0, len_v[idx_v[1][i]]);
    }
    for (int i : rep(m)) {
      add(-len_h[idx_h[0][size(idx_h[0]) - m + i]], 0);
      add(0, -len_v[idx_v[0][i]]);
    }

    assert(ans.back() == ans.front());
    ans.pop_back();
    for (auto [x, y] : ans) {
      if (transposed) swap(x, y);
      cout << x << ' ' << y << '\n';
    }
  }
}