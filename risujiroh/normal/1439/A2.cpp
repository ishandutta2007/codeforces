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
    int w = scan();
    vector<string> s(h);
    generate(ALL(s), scan<string>);

    vector<array<int, 6>> ans;
    auto go = [&](const array<int, 6>& a) {
      for (int i : {0, 2, 4}) {
        assert(0 <= a[i]), assert(a[i] < h);
        assert(0 <= a[i + 1]), assert(a[i + 1] < w);
        s[a[i]][a[i + 1]] ^= 1;
      }
      ans.push_back(a);
    };

    if (h & 1) {
      for (int j : Rep(w))
        if (s[h - 1][j] == '1')
          go({h - 1, j, h - 2, j, h - 2, j ? j - 1 : j + 1});
      --h;
    }
    if (w & 1) {
      for (int i : Rep(h))
        if (s[i][w - 1] == '1')
          go({i, w - 1, i, w - 2, i ? i - 1 : i + 1, w - 2});
      --w;
    }
    assert(~h & 1);
    assert(~w & 1);

    constexpr array<int, 4> op{0b1110, 0b1101, 0b1011, 0b0111};

    for (int i = 0; i < h; i += 2)
      for (int j = 0; j < w; j += 2) {
        int mask = 0;
        mask |= (s[i][j] - '0') << 0;
        mask |= (s[i][j + 1] - '0') << 1;
        mask |= (s[i + 1][j] - '0') << 2;
        mask |= (s[i + 1][j + 1] - '0') << 3;
        bool any = false;
        for (int bt : Rep(1 << 4)) {
          int cur = 0;
          for (int x : Rep(4))
            if (bt >> x & 1) cur ^= op[x];
          if (cur == mask) {
            for (int x : Rep(4))
              if (bt >> x & 1) {
                if (x == 0) go({i, j + 1, i + 1, j, i + 1, j + 1});
                if (x == 1) go({i, j, i + 1, j, i + 1, j + 1});
                if (x == 2) go({i, j, i, j + 1, i + 1, j + 1});
                if (x == 3) go({i, j, i, j + 1, i + 1, j});
              }
            any = true;
            break;
          }
        }
        assert(any);
        assert(s[i][j] == '0');
        assert(s[i][j + 1] == '0');
        assert(s[i + 1][j] == '0');
        assert(s[i + 1][j + 1] == '0');
      }

    cout << size(ans) << '\n';
    for (auto&& e : ans)
      for (int i : Rep(6)) cout << e[i] + 1 << " \n"[i == 5];
  }
}