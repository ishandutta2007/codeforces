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
    if (*max_element(ALL(freq)) > (n + 1) / 2) {
      cout << "-1\n";
      continue;
    }

    fill(ALL(freq), 0);
    {
      vector<int> pos{0};
      for (int i : Rep(1, n))
        if (a[i - 1] == a[i]) pos.push_back(i);
      pos.push_back(n);
      for (int z : Rep(1, size(pos))) {
        int l = pos[z - 1];
        int r = pos[z];
        ++freq[a[l]];
        ++freq[a[r - 1]];
      }
    }

    int sum = accumulate(ALL(freq), 0);
    int mx = *max_element(ALL(freq));

    int ans = 0;
    for (int i : Rep(n - 1)) ans += a[i] == a[i + 1];

    ans += max((mx - 2) - (sum - 2) / 2, 0);

    cout << ans << '\n';
  }
}