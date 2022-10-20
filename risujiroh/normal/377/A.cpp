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

constexpr array di{1, 0, -1, 0};
constexpr array dj{0, 1, 0, -1};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int h = scan();
  int w = scan();
  int k = scan();
  vector<string> s(h);
  generate(ALL(s), scan<string>);

  int si = -1, sj = -1;
  for (int i : Rep(h))
    for (int j : Rep(w))
      if (s[i][j] == '.') si = i, sj = j;
  vector<pair<int, int>> que{{si, sj}};
  vector dist(h, vector(w, -1));
  dist[si][sj] = 0;
  for (int z = 0; z < int(size(que)); ++z) {
    auto [i, j] = que[z];
    for (int d : Rep(4)) {
      int ni = i + di[d];
      int nj = j + dj[d];
      if (ni < 0 or ni >= h or nj < 0 or nj >= w) continue;
      if (s[ni][nj] != '.') continue;
      if (dist[ni][nj] == -1) {
        dist[ni][nj] = dist[i][j] + 1;
        que.emplace_back(ni, nj);
      }
    }
  }
  while (k--) {
    auto [i, j] = que.back();
    s[i][j] = 'X';
    que.pop_back();
  }

  for (auto&& e : s) cout << e << '\n';
}