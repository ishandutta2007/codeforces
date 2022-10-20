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
  int n = scan();
  vector<int> a(n);
  generate(ALL(a), scan<>);

  {
    vector v(int(2.5e6) + 1, -1);
    vector<int> ans;
    for (int i : Rep(n)) {
      if (v[a[i]] != -1) {
        ans.push_back(v[a[i]]);
        ans.push_back(i);
        v[a[i]] = -1;
        if (size(ans) == 4) {
          swap(ans[1], ans[2]);
          cout << "YES\n";
          for (int z : Rep(4)) cout << ans[z] + 1 << " \n"[z == 3];
          exit(0);
        }
      } else {
        v[a[i]] = i;
      }
    }
  }

  vector good(n, false);
  {
    vector v(int(2.5e6) + 1, -1);
    int x = -1, y = -1;
    for (int i : Rep(n))
      if (v[a[i]] == -1) {
        v[a[i]] = i;
        good[i] = true;
      } else {
        x = v[a[i]], y = i;
      }
    if (x != -1)
      for (int i : Rep(n))
        if (a[i] != a[x])
          if (int t = 2 * a[x] - a[i];
              0 <= t and t < int(size(v)) and v[t] != -1) {
            cout << "YES\n";
            cout << x + 1 << ' ' << y + 1 << ' ' << v[t] + 1 << ' ' << i + 1
                 << '\n';
            exit(0);
          }
  }

  vector<array<int, 2>> v(int(5e6) + 1, {-1, -1});
  for (int j : Rep(n))
    if (good[j])
      for (int i : Rep(j))
        if (good[i]) {
          if (v[a[i] + a[j]] != array{-1, -1}) {
            cout << "YES\n";
            cout << v[a[i] + a[j]][0] + 1 << ' ' << v[a[i] + a[j]][1] + 1 << ' '
                 << i + 1 << ' ' << j + 1 << '\n';
            exit(0);
          }
          v[a[i] + a[j]] = {i, j};
        }

  cout << "NO\n";
}