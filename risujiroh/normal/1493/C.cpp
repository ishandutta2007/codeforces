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
    int k = scan();
    auto s = scan<string>();
    array<int, 26> freq{};
    for (char c : s) ++freq[c - 'a'];

    if (n % k) {
      cout << "-1\n";
      continue;
    }

    {
      bool ok = true;
      for (auto&& e : freq)
        if (e % k) ok = false;
      if (ok) {
        cout << s << '\n';
        continue;
      }
    }

    [&] {
      for (int i : Per(n)) {
        --freq[s[i] - 'a'];
        for (char c : Rep(s[i] + 1, 'z' + 1)) {
          ++freq[c - 'a'];
          int need = 0;
          for (auto&& e : freq)
            if (e % k) need += k - e % k;
          if (need <= n - i - 1) {
            cout << s.substr(0, i) << c;
            string t;
            for (int z : Rep(26))
              if (freq[z] % k) t += string(k - freq[z] % k, 'a' + z);
            cout << string(n - i - 1 - size(t), 'a');
            cout << t << '\n';
            return;
          }
          --freq[c - 'a'];
        }
      }
      cout << "-1\n";
    }();
  }
}