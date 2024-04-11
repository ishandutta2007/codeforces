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
  string f0 =
      "What are you doing at the end of the world? Are you busy? Will you save "
      "us?";
  string s0 = "What are you doing while sending \"";
  string s1 = "\"? Are you busy? Will you send \"";
  string s2 = "\"?";

  vector<int64_t> len{int(size(f0))};
  while (size(len) <= 1e5) {
    len.push_back(size(s0) + len.back() + size(s1) + len.back() + size(s2));
    chmin(len.back(), 1e18);
  }

  auto rec = Fix([&](auto self, int n, int64_t k) -> char {
    if (k >= len[n]) return '.';
    if (n == 0) return f0[k];
    if (k < int(size(s0))) return s0[k];
    k -= size(s0);
    if (k < len[n - 1]) return self(n - 1, k);
    k -= len[n - 1];
    if (k < int(size(s1))) return s1[k];
    k -= size(s1);
    if (k < len[n - 1]) return self(n - 1, k);
    k -= len[n - 1];
    assert(k < int(size(s2)));
    return s2[k];
  });

  for (int q = scan(); q--;) {
    int n = scan();
    auto k = scan<int64_t>() - 1;
    cout << rec(n, k);
  }
  cout << '\n';
}