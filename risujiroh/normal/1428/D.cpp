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
  for (auto&& e : a) cin >> e;

  vector<pair<int, int>> ans;
  auto add = [&](int i, int h) -> void { ans.emplace_back(h, i); };

  vector<vector<int>> idx(4);
  for (int i : per(n)) {
    if (a[i] == 0) {
    } else if (a[i] == 1) {
      add(i, i);
    } else if (a[i] == 2) {
      if (empty(idx[1])) {
        cout << "-1\n";
        exit(0);
      }
      add(i, idx[1].back());
      idx[1].pop_back();
    } else if (a[i] == 3) {
      int j = -1;
      if (empty(idx[3])) {
        if (not empty(idx[2])) {
          j = idx[2].back();
        } else if (not empty(idx[1])) {
          j = idx[1].back();
          idx[1].pop_back();
        } else {
          cout << "-1\n";
          exit(0);
        }
      } else {
        j = idx[3].back();
      }
      add(i, i);
      add(j, i);
    } else
      assert(false);
    idx[a[i]].push_back(i);
  }

  cout << size(ans) << '\n';
  for (auto [i, j] : ans) cout << i + 1 << ' ' << j + 1 << '\n';
}