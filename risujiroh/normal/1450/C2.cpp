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
    vector<string> s(n);
    generate(ALL(s), scan<string>);

    vector<int> freq(3);
    for (int i : Rep(n))
      for (int j : Rep(n))
        if (s[i][j] != '.') ++freq[(i + j) % 3];

    int r = max_element(ALL(freq)) - begin(freq);

    vector<int> cnt(2);
    for (int z : Rep(2))
      for (int i : Rep(n))
        for (int j : Rep(n))
          if (z == 0) {
            cnt[z] += ((i + j) % 3 == (r + 1) % 3 and s[i][j] == 'O') or
                      ((i + j) % 3 == (r + 2) % 3 and s[i][j] == 'X');
          } else {
            cnt[z] += ((i + j) % 3 == (r + 1) % 3 and s[i][j] == 'X') or
                      ((i + j) % 3 == (r + 2) % 3 and s[i][j] == 'O');
          }

    int z = max_element(ALL(cnt)) - begin(cnt);
    for (int i : Rep(n))
      for (int j : Rep(n))
        if (s[i][j] != '.') {
          if (z == 0) {
            if ((i + j) % 3 == (r + 1) % 3) s[i][j] = 'O';
            if ((i + j) % 3 == (r + 2) % 3) s[i][j] = 'X';
          } else {
            if ((i + j) % 3 == (r + 1) % 3) s[i][j] = 'X';
            if ((i + j) % 3 == (r + 2) % 3) s[i][j] = 'O';
          }
        }

    for (auto&& e : s) cout << e << '\n';
  }
}