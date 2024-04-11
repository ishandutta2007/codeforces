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
    vector<int> a(n);
    generate(ALL(a), scan<>);

    vector<int> freq(n + 1);
    for (auto&& e : a) ++freq[e];

    vector<int> pos(n + 1, -1);
    for (int i : Rep(n)) pos[a[i]] = i;

    int chain = 0;
    {
      int l = 0, r = n;
      for (int x : Rep(1, n + 1)) {
        if (freq[x] != 1) break;
        if (pos[x] == l)
          ++l;
        else if (pos[x] == r - 1)
          --r;
        else
          break;
        chain = x;
      }
    }
    DUMP(chain);

    for (int k : Rep(1, n + 1)) {
      if (k == 1) {
        cout << (count(ALL(freq), 1) == n);
      } else {
        cout << (chain >= n - k and freq[n - k + 1]);
      }
    }
    cout << '\n';
  }
}