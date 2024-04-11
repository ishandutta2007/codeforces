#include <bits/stdc++.h>

class Dsu {
 public:
  Dsu() {}
  explicit Dsu(int n) : dat(n, -1), num_components_(n) {}

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
    --num_components_;
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
  int num_components() const { return num_components_; }

 private:
  std::vector<int> dat;
  int num_components_;
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

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n = scan();
  vector<int> a(n), b(n);
  vector ia(2 * n, -1), ib(2 * n, -1);
  for (int i : Rep(n)) {
    a[i] = scan() - 1;
    b[i] = scan() - 1;
    ia[a[i]] = i;
    ib[b[i]] = i;
  }

  auto id = [&](int x) -> int { return max(ia[x], ib[x]); };
  auto other = [&](int x) -> int {
    int i = id(x);
    return a[i] ^ b[i] ^ x;
  };

  vector used(2 * n, false);

  Dsu d(n);
  vector col(n, -1);

  int mn = -1, mx = 2 * n;
  int x = -1, y = 2 * n;
  for (int p = 0, q = 2 * n - 1;;) {
    while (p < 2 * n and used[p]) ++p;
    while (q >= 0 and used[q]) --q;
    if (p > q) break;
    used[p] = true;
    used[q] = true;
    DUMP(mn + 1, mx + 1, x + 1, y + 1, p + 1, q + 1);
    if (id(p) == id(q)) {
      if (x < p and q < y) {
        mn = p, mx = q;
        x = p, y = q;
        col[id(p)] = p == a[id(p)];
      } else if (x < q and q < y) {
        d.unite(id(mn), id(p));
        mn = p;
        y = q;
        col[id(p)] = p == a[id(p)];
      } else if (x < p and p < y) {
        d.unite(id(mx), id(q));
        mx = q;
        x = p;
        col[id(q)] = q == a[id(q)];
      } else {
        cout << "-1\n";
        exit(0);
      }
    } else if (x < p and q < y) {
      d.unite(id(p), id(q));
      mn = p, mx = q;
      x = other(mx);
      y = other(mn);
      used[x] = true;
      used[y] = true;
      col[id(p)] = p == a[id(p)];
      col[id(q)] = q == a[id(q)];
    } else {
      if (other(q) < x or y < other(p)) {
        cout << "-1\n";
        exit(0);
      }
      d.unite(id(p), id(q));
      d.unite(id(mn), id(p));
      d.unite(id(mx), id(q));
      mn = p, mx = q;
      x = other(mx);
      y = other(mn);
      used[x] = true;
      used[y] = true;
      col[id(p)] = p == a[id(p)];
      col[id(q)] = q == a[id(q)];
    }
  }
  if (x > y) {
    cout << "-1\n";
    exit(0);
  }

  vector temp(2, vector<int>(n));
  for (int i : Rep(n)) ++temp[col[i]][d.root(i)];
  int ans = 0;
  for (int i : Rep(n))
    if (d.root(i) == i) ans += min(temp[0][i], temp[1][i]);
  cout << ans << '\n';
}