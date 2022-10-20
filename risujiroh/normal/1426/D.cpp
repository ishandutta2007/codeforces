// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt")
// #define NDEBUG

#include <bits/extc++.h>
#include <x86intrin.h>

struct rep {
  struct iterator {
    int i;
    void operator++() { ++i; }
    int operator*() const { return i; }
    friend bool operator!=(iterator a, iterator b) { return *a != *b; }
  };
  const int l, r;
  rep(int _l, int _r) : l(std::min(_l, _r)), r(_r) {}
  rep(int n) : rep(0, n) {}
  iterator begin() const { return {l}; }
  iterator end() const { return {r}; }
};
struct per {
  struct iterator {
    int i;
    void operator++() { --i; }
    int operator*() const { return i; }
    friend bool operator!=(iterator a, iterator b) { return *a != *b; }
  };
  const int l, r;
  per(int _l, int _r) : l(std::min(_l, _r)), r(_r) {}
  per(int n) : per(0, n) {}
  iterator begin() const { return {r - 1}; }
  iterator end() const { return {l - 1}; }
};
template <class C>
int sz(C&& c) {
  using std::size;
  return size(std::forward<C>(c));
}
template <class T, class U>
bool chmin(T& a, U&& b) {
  return b < a ? a = std::forward<U>(b), true : false;
}
template <class T, class U>
bool chmax(T& a, U&& b) {
  return a < b ? a = std::forward<U>(b), true : false;
}

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  int64_t sum{};
  map<int64_t, int> mp;
  mp[0] = 0;
  vector<pair<int, int>> lr;
  for (int i : rep(n)) {
    int a;
    cin >> a;
    sum += a;
    if (mp.count(sum)) {
      lr.emplace_back(mp[sum], i + 1);
    }
    mp[sum] = i + 1;
  }
  int last = -1, ans{};
  for (auto [l, r] : lr) {
    if (l < last) continue;
    ++ans;
    last = r - 1;
  }
  cout << ans << '\n';
}