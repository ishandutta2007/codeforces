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
  int h = scan();
  int w = scan();
  vector a(h, vector<int>(w));
  vector b(h, vector<int>(w));
  for (int i : Rep(h)) generate(ALL(a[i]), scan<>);
  for (int i : Rep(h)) generate(ALL(b[i]), scan<>);

  vector<int> sum(w);
  for (int j : Rep(w))
    for (int i : Rep(h - 1)) sum[j] += b[i][j] > b[i + 1][j];

  vector<bool> chosen(w), exists(h - 1);
  vector<int> order;
  while (true) {
    bool any = false;
    for (int j : Rep(w)) {
      if (chosen[j] or sum[j]) continue;
      chosen[j] = true;
      order.push_back(j);
      for (int i : Rep(h - 1))
        if (not exists[i] and b[i][j] != b[i + 1][j]) {
          exists[i] = true;
          for (int c : Rep(w)) sum[c] -= b[i][c] > b[i + 1][c];
        }
      any = true;
      break;
    }
    if (not any) break;
  }
  reverse(ALL(order));

  for (int j : order)
    stable_sort(ALL(a), [&](auto&& l, auto&& r) { return l[j] < r[j]; });
  if (a == b) {
    cout << size(order) << '\n';
    for (int z : Rep(size(order)))
      cout << order[z] + 1 << " \n"[z + 1 == int(size(order))];
  } else {
    cout << "-1\n";
  }
}