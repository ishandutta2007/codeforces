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

#include <ext/pb_ds/assoc_container.hpp>

struct Splitmix64Hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t r =
        std::chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + r);
  }
};
template <class Key, class T>
using HashMap = __gnu_pbds::gp_hash_table<Key, T, Splitmix64Hash>;
template <class Key>
using HashSet = HashMap<Key, __gnu_pbds::null_type>;

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
    vector<vector<int>> g(n);
    for (int m = scan(); m--;) {
      int u = scan() - 1;
      int v = scan() - 1;
      g[u].push_back(v);
      g[v].push_back(u);
    }

    int mv = -1;
    for (int v : Rep(n))
      if (mv == -1 or size(g[v]) < size(g[mv])) mv = v;

    Dsu d(n);
    vector<HashSet<int>> t(n);
    {
      vector temp(n, true);
      temp[mv] = false;
      for (int u : g[mv]) temp[u] = false;
      for (int u : Rep(n))
        if (temp[u]) {
          d.unite(mv, u);
          t[mv].insert(u);
          t[u].insert(mv);
        }
    }
    for (int v : Rep(n)) {
      if (d.same(mv, v)) continue;
      vector temp(n, true);
      temp[v] = false;
      for (int u : g[v]) temp[u] = false;
      for (int u : Rep(n))
        if (temp[u] and not d.same(v, u)) {
          d.unite(v, u);
          t[v].insert(u);
          t[u].insert(v);
        }
    }

    vector p(n, -1), q(n, -1);
    int nxt = 1;
    vector<int> que;
    vector alive(n, true);
    for (int v : Rep(n)) {
      if (empty(t[v])) {
        p[v] = nxt;
        q[v] = nxt;
        ++nxt;
        alive[v] = false;
      } else if (size(t[v]) == 1) {
        que.push_back(v);
      }
    }

    auto disable = [&](int v) {
      alive[v] = false;
      for (int u : t[v]) {
        assert(t[u].find(v) != end(t[u]));
        t[u].erase(v);
        if (size(t[u]) == 1) que.push_back(u);
      }
      t[v].clear();
    };

    for (int v : Rep(n)) DUMP(v, t[v]);

    for (int z = 0; z < int(size(que)); ++z) {
      int v = que[z];
      if (not alive[v]) continue;
      DUMP(v);
      assert(size(t[v]) == 1);
      v = *begin(t[v]);
      DUMP(v);
      p[v] = nxt;
      vector<int> us;
      for (int u : t[v])
        if (alive[u] and size(t[u]) == 1) {
          q[u] = nxt;
          ++nxt;
          p[u] = nxt;
          us.push_back(u);
        }
      DUMP(us);
      q[v] = nxt;
      ++nxt;
      for (int u : us) disable(u);
      disable(v);
    }

    for (int i : Rep(n)) cout << p[i] << " \n"[i + 1 == n];
    for (int i : Rep(n)) cout << q[i] << " \n"[i + 1 == n];
  }
}