#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

struct Splitmix64Hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t r = std::chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + r);
  }
};
template <class Key, class T> using HashMap = __gnu_pbds::gp_hash_table<Key, T, Splitmix64Hash>;
template <class Key> using HashSet = HashMap<Key, __gnu_pbds::null_type>;

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

namespace sieve {

std::vector<int> primes, lpf;
void init(int n) {
  if (n < int(std::size(lpf))) return;
  if (n < 2 * int(std::size(lpf))) n = 2 * std::size(lpf);
  lpf.resize(n + 1, -1);
  for (int d = 2; d <= n; ++d) {
    if (lpf[d] == -1) lpf[d] = d, primes.push_back(d);
    for (int p : primes) {
      if (p * d > n or p > lpf[d]) break;
      lpf[p * d] = p;
    }
  }
}
std::vector<int> factor(int n) {
  __glibcxx_assert(n >= 1);
  std::vector<int> res;
  for (init(n); n > 1; n /= res.back()) res.push_back(lpf[n]);
  return res;
}

}  // namespace sieve

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  constexpr int L = 1e6;
  sieve::init(L);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto&& e : a) cin >> e;
  Dsu d(n + size(sieve::primes));
  vector<int> rank(L, -1);
  for (int i = 0; i < int(size(sieve::primes)); ++i) rank[sieve::primes[i]] = i;
  for (int i = 0; i < n; ++i) {
    for (int p : sieve::factor(a[i])) d.unite(i, n + rank[p]);
  }
  vector<HashSet<int>> h(size(d));
  for (auto&& e : a) {
    auto f = sieve::factor(e);
    for (int p : sieve::factor(e + 1)) f.push_back(p);
    sort(begin(f), end(f));
    f.erase(unique(begin(f), end(f)), end(f));
    for (int p : f)
      for (int pp : f) {
        int s = d.root(n + rank[p]);
        int t = d.root(n + rank[pp]);
        if (s > t) swap(s, t);
        h[s].insert(t);
      }
  }
  while (q--) {
    int s, t;
    cin >> s >> t;
    --s, --t;
    if (d.same(s, t)) {
      cout << "0\n";
      continue;
    }
    s = d.root(s);
    t = d.root(t);
    if (s > t) swap(s, t);
    cout << 1 + (h[s].find(t) == h[s].end()) << '\n';
  }
}