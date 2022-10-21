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
  vector<int> p(n);
  generate(ALL(p), scan<>);
  vector<int> l(n), r(n);
  for (int i : Per(n)) {
    r[i] = 1;
    if (i + 1 < n and p[i] > p[i + 1]) r[i] += r[i + 1];
  }
  for (int i : Rep(n)) {
    l[i] = 1;
    if (i and p[i - 1] < p[i]) l[i] += l[i - 1];
  }
  int li = max_element(ALL(l)) - begin(l);
  int ri = max_element(ALL(r)) - begin(r);
  for (int i : Rep(n)) {
    if (i != li and l[i] == l[li]) {
      cout << "0\n";
      exit(0);
    }
    if (i != ri and r[i] == r[ri]) {
      cout << "0\n";
      exit(0);
    }
  }
  if (li != ri or l[li] != r[ri]) {
    cout << "0\n";
    exit(0);
  }
  if (l[li] % 2 == 0) {
    cout << "0\n";
    exit(0);
  }
  cout << "1\n";
}