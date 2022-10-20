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
    array<string, 3> s;
    generate(ALL(s), scan<string>);
    for (char c : {'0', '1'}) {
      vector<int> v;
      for (int i : Rep(3))
        if (count(ALL(s[i]), c) >= n) v.push_back(i);
      if (size(v) >= 2) {
        v.resize(2);
        vector<int> x{-1}, y{-1};
        for (int j : Rep(2 * n)) {
          if (int(size(x)) <= n and s[v[0]][j] == c) {
            x.push_back(j);
          }
          if (int(size(y)) <= n and s[v[1]][j] == c) {
            y.push_back(j);
          }
        }
        DUMP(x, y);
        string ans;
        for (int j : Rep(n)) {
          ans += s[v[0]].substr(x[j] + 1, x[j + 1] - x[j] - 1);
          ans += s[v[1]].substr(y[j] + 1, y[j + 1] - y[j] - 1);
          ans += c;
        }
        ans += s[v[0]].substr(x.back() + 1);
        ans += s[v[1]].substr(y.back() + 1);
        cout << ans << '\n';
        break;
      }
    }
  }
}