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
template <class C>
constexpr int isize(C&& c) {
  using std::size;
  return size(std::forward<C>(c));
}
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
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (auto&& e : s) cin >> e;
  int si = -1, sj = -1, ti = -1, tj = -1;
  for (int i : rep(h))
    for (int j : rep(w)) {
      if (s[i][j] == 'S') si = i, sj = j;
      if (s[i][j] == 'T') ti = i, tj = j;
    }

  constexpr int inf = 0x3f3f3f3f;
  constexpr array<int, 4> di{1, 0, -1, 0};
  constexpr array<int, 4> dj{0, 1, 0, -1};

  vector d(h, vector<array<int, 4>>(w));
  for (int i : rep(h))
    for (int j : rep(w)) d[i][j].fill(inf);
  deque<array<int, 3>> deq;
  for (int k : rep(4)) {
    d[si][sj][k] = 0;
    deq.push_back({si, sj, k});
  }
  while (not empty(deq)) {
    auto [i, j, k] = deq.front();
    deq.pop_front();
    for (int dk : {1, 3}) {
      int nk = (k + dk) & 3;
      if (chmin(d[i][j][nk], d[i][j][k] + 1)) deq.push_back({i, j, nk});
    }
    {
      int ni = i + di[k], nj = j + dj[k];
      if (ni < 0 or ni >= h or nj < 0 or nj >= w) continue;
      if (s[ni][nj] == '*') continue;
      if (chmin(d[ni][nj][k], d[i][j][k])) deq.push_front({ni, nj, k});
    }
  }
  for (int k : rep(4)) {
    if (d[ti][tj][k] <= 2) {
      cout << "YES\n";
      exit(0);
    }
  }
  cout << "NO\n";
}