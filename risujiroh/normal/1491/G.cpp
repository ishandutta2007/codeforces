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
  vector<int> c(n);
  for (auto&& e : c) e = scan() - 1;

  vector visited(n, false);
  vector<vector<int>> cycles;
  for (int s : Rep(n)) {
    if (c[s] == s or visited[s]) continue;
    int i = s;
    cycles.emplace_back();
    do {
      visited[i] = true;
      cycles.back().push_back(i);
      i = c[i];
    } while (i != s);
  }

  vector<array<int, 2>> ans;
  auto op = [&](int i, int j) -> void {
    swap(c[i] = ~c[i], c[j] = ~c[j]);
    ans.push_back({i, j});
  };

  auto go = [&](const vector<int>& l, const vector<int>& r) -> void {
    int nl = size(l);
    int nr = size(r);
    op(l[0], r[0]);
    op(l[1], r[1]);
    for (int z : Rep(2, nl)) op(l[z], r[1]);
    for (int z : Rep(2, nr)) op(l[1], r[z]);
    op(l[0], r[1]);
    op(l[1], r[0]);
  };

  while (size(cycles) >= 2) {
    go(cycles[size(cycles) - 2], cycles.back());
    cycles.pop_back();
    cycles.pop_back();
  }
  if (not empty(cycles)) {
    assert(size(cycles) == 1);
    auto&& v = cycles[0];
    if (size(v) == 2) {
      int t = 0;
      while (t == v[0] or t == v[1]) ++t;
      op(v[0], t);
      op(v[1], t);
      op(v[0], t);
    } else {
      // tie(v[0], v[1], v.back()) = tuple{v.back(), v[0], v[1]};
      swap(v[0], v[1]);
      op(v[0], v.back());
      op(v[1], v.back());
      for (int z : Rep(1, size(v))) op(v[0], v[z]);
    }
  }
  DUMP(c);

  cout << size(ans) << '\n';
  for (auto&& [i, j] : ans) cout << i + 1 << ' ' << j + 1 << '\n';
}