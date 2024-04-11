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
  for (int tt = scan(); tt--;) {
    int n = scan();
    int m = scan();
    vector<int> r(m), c(m);
    for (int z : Rep(m)) {
      r[z] = scan() - 1;
      c[z] = scan() - 1;
    }
    if (m & 1) {
      cout << "NO\n";
      continue;
    }
    auto v = c;
    v.push_back(-1);
    v.push_back(n);
    sort(ALL(v));
    v.erase(unique(ALL(v)), end(v));
    vector<int> cs;
    for (int z : Rep(1, size(v))) {
      int d = v[z] - v[z - 1];
      if (d & 1)
        d = 1;
      else
        d = 2;
      cs.push_back((empty(cs) ? -1 : cs.back()) + d);
    }
    v.erase(begin(v));
    for (int z : Rep(m)) c[z] = cs[lower_bound(ALL(v), c[z]) - begin(v)];
    n = cs.back();

    vector s(2, string(n, '.'));
    for (int z : Rep(m)) s[r[z]][c[z]] = '#';

    cout << ([&] {
      for (int j : Rep(n)) {
        if (s[0][j] == s[1][j]) continue;
        if (s[0][j] == '#') {
          if (j + 1 == n or s[1][j + 1] == '#') return false;
          s[1][j + 1] = '#';
        } else {
          if (j + 1 == n or s[0][j + 1] == '#') return false;
          s[0][j + 1] = '#';
        }
        DUMP(j);
        DUMP(s[0]);
        DUMP(s[1]);
      }
      return true;
    }()
                 ? "YES\n"
                 : "NO\n");
  }
}