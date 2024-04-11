#ifdef ONLINE_JUDGE
#pragma GCC target("bmi,bmi2,lzcnt,popcnt")
#endif

#include <bits/stdc++.h>
#include <x86intrin.h>

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

struct fenwick_set {
  int n, m, sz = 0;
  vector<uint64_t> dat;
  vector<int> tree;
  fenwick_set(int _n = 0) : n(_n), m(n / 64 + 1), dat(m), tree(m + 1) {}
  int operator[](int i) const { return dat[i / 64] >> i % 64 & 1; }
  void set() {
    sz = n;
    fill(begin(dat), end(dat), -1);
    for (int j = 1; j <= m; ++j) {
      tree[j] = _blsi_u64(j) * 64;
    }
  }
  void set(int i) {
    if ((*this)[i]) return;
    ++sz;
    dat[i / 64] |= 1uLL << i % 64;
    for (int j = i / 64 + 1; j <= m; j += _blsi_u64(j)) {
      ++tree[j];
    }
  }
  void reset() {
    sz = 0;
    fill(begin(dat), end(dat), 0);
    fill(begin(tree), end(tree), 0);
  }
  void reset(int i) {
    if ((*this)[i] == 0) return;
    --sz;
    dat[i / 64] &= ~(1uLL << i % 64);
    for (int j = i / 64 + 1; j <= m; j += _blsi_u64(j)) {
      --tree[j];
    }
  }
  int rank(int i) const {
    i = clamp(i, 0, n);
    int res = _popcnt64(_bzhi_u64(dat[i / 64], i % 64));
    for (int j = i / 64; j; j = _blsr_u64(j)) {
      res += tree[j];
    }
    return res;
  }
  int select(int k) const {
    if (k < 0) return -1;
    if (k >= sz) return n;
    int j = 0;
    for (int w = 1 << __lg(m); w; w >>= 1) {
      if (j + w <= m and tree[j + w] <= k) {
        j += w;
        k -= tree[j];
      }
    }
    return j * 64 + _tzcnt_u64(_pdep_u64(1uLL << k, dat[j]));
  }
  int pred(int i) const { return select(rank(i) - 1); }
  int succ(int i) const { return select(rank(i + 1)); }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  for (int tt = scan(); tt--;) {
    int n = scan();
    vector<int> a(n);
    generate(ALL(a), scan<>);

    fenwick_set f(n);
    for (int i : Rep(n))
      if (a[i] > 1) f.set(i);

    int cnt = 0;
    auto go = Fix([&](auto self, int i) -> void {
      ++cnt;
      int to = a[i] > 1 ? i + a[i] : f.succ(i);
      a[i] -= a[i] > 1;
      if (a[i] == 1) f.reset(i);
      if (to >= n) return;
      self(to);
    });

    int64_t ans = 0;
    for (int i : Rep(n)) {
      if (a[i] > 1 and i + a[i] >= n) {
        ans += a[i] - max(n - i - 1, 1);
        a[i] = max(n - i - 1, 1);
      }
      while (a[i] > 1) {
        ++ans;
        go(i);
      }
    }
    cout << ans << '\n';
    DUMP(cnt, ans);
  }
}