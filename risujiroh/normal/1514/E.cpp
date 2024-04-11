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

bool query(int i, int j) {
  cout << "1 " << i << ' ' << j << endl;
  return scan();
}
bool query(int i, const vector<int>& js) {
  cout << "2 " << i << ' ' << size(js);
  for (int j : js) cout << ' ' << j;
  cout << endl;
  return scan();
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  for (int tt = scan(); tt--;) {
    int n = scan();

    vector<int> order(n);
    iota(ALL(order), 0);
    stable_sort(ALL(order), [](int i, int j) { return query(j, i); });

    vector cmp(n, -1);
    int t = 0;

    int r = -1;
    for (int l : Rep(n)) {
      chmax(r, l);
      while (r + 1 < n and query(order[l], {(r + 1) + ALL(order)})) ++r;
      cmp[order[l]] = t;
      t += r == l;
    }

    cout << 3;
    for (int i : Rep(n)) {
      cout << '\n';
      for (int j : Rep(n)) cout << (cmp[i] >= cmp[j]);
    }
    cout << endl;
    scan();
  }
}