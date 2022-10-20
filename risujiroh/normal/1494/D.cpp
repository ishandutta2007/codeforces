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
  int k = scan();
  vector a(k, vector<int>(k));
  for (auto&& e : a) generate(ALL(e), scan<>);

  int n = k;
  vector<int> s(k);
  for (int i : Rep(k)) s[i] = a[i][i];
  vector<array<int, 2>> edges;

  vector<int> idx(k);
  iota(ALL(idx), 0);

  vector<int> cur(k);
  iota(ALL(cur), 0);

  while (size(idx) > 1) {
    int mi = -1, mj = -1;
    for (int i : idx)
      for (int j : idx)
        if (i < j)
          if (mi == -1 or a[i][j] < a[mi][mj]) mi = i, mj = j;

    vector<int> c;
    for (int i : idx)
      if (a[mi][i] <= a[mi][mj]) c.push_back(i);

    s.push_back(a[mi][mj]);
    for (int i : c) edges.push_back({cur[i], n});
    cur[mi] = n++;

    for (int i : c)
      if (i != mi) idx.erase(find(ALL(idx), i));
    DUMP(idx);
  }

  cout << n << '\n';
  for (int i : Rep(n)) cout << s[i] << " \n"[i + 1 == n];
  cout << n << '\n';
  for (auto&& [v, p] : edges) cout << v + 1 << ' ' << p + 1 << '\n';
}