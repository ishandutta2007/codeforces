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
  string c(2 * n, '?');
  vector<int> v(2 * n);
  for (int i : rep(2 * n)) {
    cin >> c[i];
    if (c[i] == '-') {
      cin >> v[i], --v[i];
    }
  }
  priority_queue<int, vector<int>, greater<>> pq;
  vector<int> ans;
  ans.reserve(n);
  for (int i : per(2 * n)) {
    if (c[i] == '-') {
      if (not(empty(pq) or v[i] < pq.top())) {
        cout << "NO\n";
        exit(0);
      }
      pq.push(v[i]);
    } else {
      if (empty(pq)) {
        cout << "NO\n";
        exit(0);
      }
      ans.push_back(pq.top());
      pq.pop();
    }
  }
  cout << "YES\n";
  for (int i : per(n)) cout << ans[i] + 1 << " \n"[i == 0];
}