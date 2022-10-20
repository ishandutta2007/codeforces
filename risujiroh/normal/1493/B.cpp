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
    int h = scan();
    int m = scan();
    auto s = scan<string>();
    int i = stoi(s.substr(0, 2));
    int j = stoi(s.substr(3));
    while (true) {
      auto check = [&] {
        for (char c : to_string(i))
          if (c != '0' and c != '1' and c != '2' and c != '5' and c != '8')
            return false;
        for (char c : to_string(j))
          if (c != '0' and c != '1' and c != '2' and c != '5' and c != '8')
            return false;
        {
          auto t = to_string(i);
          if (size(t) == 1) t = '0' + t;
          swap(t[0], t[1]);
          for (auto&& e : t)
            if (e == '2' or e == '5') e ^= '2' ^ '5';
          if (stoi(t) >= m) return false;
        }
        {
          auto t = to_string(j);
          if (size(t) == 1) t = '0' + t;
          swap(t[0], t[1]);
          for (auto&& e : t)
            if (e == '2' or e == '5') e ^= '2' ^ '5';
          if (stoi(t) >= h) return false;
        }
        return true;
      };
      if (check()) {
        cout << setw(2) << setfill('0') << i;
        cout << ':';
        cout << setw(2) << setfill('0') << j;
        cout << '\n';
        break;
      }
      if (++j == m) {
        j = 0;
        if (++i == h) i = 0;
      }
    }
  }
}