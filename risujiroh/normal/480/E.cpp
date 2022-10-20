#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,bmi,bmi2,lzcnt")
#define NDEBUG
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
  const int l, r;
  Rep(int _l, int _r) : l(_l), r(_r) {}
  Rep(int n) : Rep(0, n) {}
  I begin() const { return {l}; }
  I end() const { return {r}; }
};
struct Per {
  struct I {
    int i;
    void operator++() { --i; }
    int operator*() const { return i; }
    bool operator!=(I o) const { return i > *o; }
  };
  const int l, r;
  Per(int _l, int _r) : l(_l), r(_r) {}
  Per(int n) : Per(0, n) {}
  I begin() const { return {r - 1}; }
  I end() const { return {l - 1}; }
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

template <class T>
struct foldable_deque {
  vector<T> l, r, cuml = {T()}, cumr = {T()};
  T fold() const { return cuml.back() * cumr.back(); }
  void build(vector<T> v) {
    l = r = {}, cuml = cumr = {T()};
    int n = v.size();
    for (int i = n / 2; i < n; ++i) push_back(v[i]);
    for (int i = n / 2; i--;) push_front(v[i]);
  }
  void push_front(T a) { l.push_back(a), cuml.push_back(a * cuml.back()); }
  void push_back(T a) { r.push_back(a), cumr.push_back(cumr.back() * a); }
  void pop_front() {
    if (l.empty())
      build({begin(r) + 1, end(r)});
    else
      l.pop_back(), cuml.pop_back();
  }
  void pop_back() {
    if (r.empty())
      build({rbegin(l), rend(l) - 1});
    else
      r.pop_back(), cumr.pop_back();
  }
};
struct Min {
  int v = 0x3f3f3f3f;
  friend Min operator*(const Min& a, const Min& b) { return b.v < a.v ? b : a; }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int h = scan(), w = scan(), q = scan();
  vector<fenwick_set> f(h);
  for (int i : Rep(h)) {
    auto s = scan<string>();
    f[i] = w;
    for (int j : Rep(w))
      if (s[j] == 'X') f[i].set(j);
  }
  vector<array<int, 2>> queries(q);
  for (auto&& [x, y] : queries) {
    x = scan() - 1, y = scan() - 1;
    assert(f[x][y] == 0);
    f[x].set(y);
  }
  vector<int> ans;
  ans.reserve(q);
  reverse(ALL(queries));

  int cur = [&] {
    vector p(h + 1, vector<int>(w + 1));
    for (int i : Per(h))
      for (int j : Per(w))
        p[i][j] = f[i][j] + p[i + 1][j] + p[i][j + 1] - p[i + 1][j + 1];

    auto check = [&](int m) {
      for (int i : Rep(h - m + 1))
        for (int j : Rep(w - m + 1))
          if (p[i][j] - p[i + m][j] - p[i][j + m] + p[i + m][j + m] == 0)
            return true;
      return false;
    };

    int ok = 0, ng = min(h, w) + 1;
    while (ng - ok > 1) {
      int mid = (ok + ng) / 2;
      (check(mid) ? ok : ng) = mid;
    }
    return ok;
  }();

  auto go = [&](int li, int ri, int y, int m) -> bool {
    if (ri - li < m) return false;
    foldable_deque<Min> dl, dr;
    for (int i : Rep(li, ri)) {
      dr.push_back({f[i].succ(y) - y - 1});
      dl.push_back({y - f[i].pred(y) - 1});
      if (i + 1 - li >= m) {
        if (dl.fold().v + 1 + dr.fold().v >= m) return true;
        dr.pop_front();
        dl.pop_front();
      }
    }
    return false;
  };

  for (auto [x, y] : queries) {
    ans.push_back(cur);
    assert(f[x][y] == 1);
    f[x].reset(y);
    int li = x, ri = x + 1;
    while (li and f[li - 1][y] == 0) --li;
    while (ri < h and f[ri][y] == 0) ++ri;
    while (go(li, ri, y, cur + 1)) ++cur;
  }
  reverse(ALL(ans));
  for (auto&& e : ans) cout << e << '\n';
}