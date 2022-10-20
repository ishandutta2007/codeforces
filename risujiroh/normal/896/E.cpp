#include <bits/stdc++.h>

class Dsu {
 public:
  Dsu() {}
  explicit Dsu(int n) : dat(n, -1) {}

  int size() const { return std::size(dat); }
  int root(int v) {
    assert(0 <= v), assert(v < size());
    return dat[v] < 0 ? v : dat[v] = root(dat[v]);
  }
  std::pair<int, int> unite(int u, int v) {
    assert(0 <= u), assert(u < size());
    assert(0 <= v), assert(v < size());
    u = root(u), v = root(v);
    if (u == v) return {u, -1};
    if (-dat[u] < -dat[v]) std::swap(u, v);
    dat[u] += dat[v];
    dat[v] = u;
    return {u, v};
  }
  bool same(int u, int v) {
    assert(0 <= u), assert(u < size());
    assert(0 <= v), assert(v < size());
    return root(u) == root(v);
  }
  int size(int v) {
    assert(0 <= v), assert(v < size());
    return -dat[root(v)];
  }

  void reset(int l, int r) {
    std::fill(std::begin(dat) + l, std::begin(dat) + r, -1);
  }

 private:
  std::vector<int> dat;
};

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

constexpr int L = OjLocal<int(1e5), 128>;
constexpr int B = OjLocal<1 << 8, 3>;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n = scan();
  int q = scan();
  vector<int> a(n);
  generate(ALL(a), scan<>);

  vector<int> p;
  for (int i = 0; i < n; i += B) p.push_back(i);
  p.push_back(n);
  int m = size(p) - 1;

  Dsu d(n);
  vector v(m, vector(L + 1, -1));
  vector<int> o(m);
  auto build = [&](int j) {
    for (int i : Rep(p[j], p[j + 1]))
      if (v[j][a[i]] != -1)
        v[j][a[i]] = d.unite(v[j][a[i]], i).first;
      else
        v[j][a[i]] = i;
    while (v[j].back() == -1) v[j].pop_back();
  };
  auto push = [&](int j) {
    for (int i : Rep(p[j], p[j + 1]))
      if (d.root(i) == i) v[j][a[i]] = -1, a[i] += o[j];
    for (int i : Rep(p[j], p[j + 1])) a[i] = a[d.root(i)];
    d.reset(p[j], p[j + 1]);
    o[j] = 0;
  };

  for (int j : Rep(m)) build(j);
  while (q--) {
    int tp = scan();
    int l = scan() - 1;
    int r = scan();
    int x = scan();
    if (tp == 1) {
      for (int j : Rep(m)) {
        int s = max(l, p[j]), t = min(r, p[j + 1]);
        if (s == p[j] and t == p[j + 1]) {
          int mx = o[j] + size(v[j]) - 1;
          if (mx > 2 * x) {
            for (int i : Rep(1, x + 1)) {
              i -= o[j];
              if (v[j][i] == -1) continue;
              if (v[j][i + x] != -1)
                v[j][i + x] = d.unite(v[j][i + x], v[j][i]).first;
              else
                v[j][i + x] = v[j][i];
              v[j][i] = -1;
              a[v[j][i + x]] = i + x;
            }
            o[j] -= x;
          } else if (mx > x) {
            for (int i : Rep(x + 1, mx + 1)) {
              i -= o[j];
              if (v[j][i] == -1) continue;
              if (v[j][i - x] != -1)
                v[j][i - x] = d.unite(v[j][i - x], v[j][i]).first;
              else
                v[j][i - x] = v[j][i];
              v[j][i] = -1;
              a[v[j][i - x]] = i - x;
            }
            while (v[j].back() == -1) v[j].pop_back();
          }
        } else if (s < t) {
          push(j);
          for (int i : Rep(s, t))
            if (a[i] > x) a[i] -= x;
          build(j);
        }
      }
    } else {
      int ans = 0;
      for (int j : Rep(m)) {
        int s = max(l, p[j]), t = min(r, p[j + 1]);
        if (s == p[j] and t == p[j + 1]) {
          if (x - o[j] < int(size(v[j])) and v[j][x - o[j]] != -1)
            ans += d.size(v[j][x - o[j]]);
        } else if (s < t) {
          push(j);
          for (int i : Rep(s, t)) ans += a[i] == x;
          build(j);
        }
      }
      cout << ans << '\n';
    }
  }
}