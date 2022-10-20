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
  int n, m;
  cin >> n >> m;
  vector<int64_t> l(n), r(n);
  for (int i : rep(n)) cin >> l[i] >> r[i];
  vector<int64_t> a(m);
  for (auto&& e : a) cin >> e;

  map<int64_t, vector<int>> add, remove, ids;
  auto v = a;
  for (int i : rep(n - 1)) {
    tie(l[i], r[i]) = pair{l[i + 1] - r[i], r[i + 1] - l[i]};
    add[l[i]].push_back(i);
    remove[r[i]].push_back(i);
    v.push_back(l[i]);
    v.push_back(r[i]);
  }
  sort(begin(v), end(v));
  v.erase(unique(begin(v), end(v)), end(v));
  for (int id : rep(m)) ids[a[id]].push_back(id);

  vector<int> ans(n - 1);
  priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<>> pq;
  for (auto e : v) {
    if (add.count(e))
      for (int i : add[e]) pq.emplace(r[i], i);
    if (ids.count(e))
      for (int id : ids[e])
        if (not empty(pq)) {
          ans[pq.top().second] = id;
          pq.pop();
        }
    while (not empty(pq) and pq.top().first == e) {
      cout << "No\n";
      exit(0);
    }
  }

  cout << "Yes\n";
  for (int i : rep(n - 1)) cout << ans[i] + 1 << " \n"[i == n - 2];
}