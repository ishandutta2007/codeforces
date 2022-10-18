#line 1 "c.cpp"
#include <random>
#line 2 "C:/Users/W/c/lib/template.cpp"

#ifndef LOCAL
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx")
#endif
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VLL = vector<ll>;
using VVLL = vector<vector<ll>>;
using VB = vector<bool>;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;
constexpr int INF = 1000000007;
constexpr ll INF_LL = 1'000'000'000'000'000'007;
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define newl '\n'

// loops rep(until) / rep(var, until) / rep(var, from, until) / repr (reversed order)
#define OVERLOAD3(_1, _2, _3, name, ...) name
#define rep(...) OVERLOAD3(__VA_ARGS__, REPEAT_FROM_UNTIL, REPEAT_UNTIL, REPEAT)(__VA_ARGS__)
#define REPEAT(times) REPEAT_CNT(_repeat, __COUNTER__, times)
#define REPEAT_CNT(_repeat, cnt, times) REPEAT_CNT_CAT(_repeat, cnt, times)
#define REPEAT_CNT_CAT(_repeat, cnt, times) REPEAT_FROM_UNTIL(_repeat ## cnt, 0, times)
#define REPEAT_UNTIL(name, times) REPEAT_FROM_UNTIL(name, 0, times)
#define REPEAT_FROM_UNTIL(name, from, until) for (int name = from, name ## __until = (until); name < name ## __until; name++)
#define repr(...) OVERLOAD3(__VA_ARGS__, REPR_FROM_UNTIL, REPR_UNTIL, REPEAT)(__VA_ARGS__)
#define REPR_UNTIL(name, times) REPR_FROM_UNTIL(name, 0, times)
#define REPR_FROM_UNTIL(name, from, until) for (int name = (until)-1, name ## __from = (from); name >= name ## __from; name--)

template <typename T, typename U>
bool chmin(T& var, U x) { if (var > x) { var = x; return true; } else return false; }
template <typename T, typename U>
bool chmax(T& var, U x) { if (var < x) { var = x; return true; } else return false; }
ll power(ll e, ll t, ll mod = INF_LL) {
  ll res = 1; for (; t; t >>= 1, (e *= e) %= mod) if (t & 1) (res *= e) %= mod; return res;
}
ll choose(ll n, int r) {
  chmin(r, n-r); if (r < 0) return 0; ll res = 1; rep(i, r) res *= n-i, res /= i+1; return res;
}
template <typename T, typename U> T divceil(T m, U d) { return (m + d - 1) / d; }
template <typename T> vector<T> make_v(size_t a, T b) { return vector<T>(a, b); }
template <typename... Ts> auto make_v(size_t a, Ts... ts) {
  return vector<decltype(make_v(ts...))>(a, make_v(ts...));
}

// debugging stuff
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmisleading-indentation"
#define repi(it, ds) for (auto it = ds.begin(); it != ds.end(); it++)
class DebugPrint { public: template <typename T> DebugPrint& operator <<(const T& v) {
#ifdef LOCAL
    cerr << v;
#endif
return *this; } } debugos; template <typename T> DebugPrint& operator<<(DebugPrint& os, const
vector<T>& vec) { os << "{"; for (int i = 0; i < vec.size(); i++) os << vec[i] << (i + 1 ==
vec.size() ? "" : ", "); os << "}"; return os; } template <typename T, typename U> DebugPrint&
operator<<(DebugPrint& os, const map<T, U>& map_var) { os << "{"; repi(itr, map_var) { os << *
itr; itr++; if (itr != map_var.end()) os << ", "; itr--; } os << "}"; return os; } template <
typename T> DebugPrint& operator<<(DebugPrint& os, const set<T>& set_var) { os << "{"; repi(
itr, set_var) { os << *itr; itr++; if (itr != set_var.end()) os << ", "; itr--; } os << "}";
return os; } template <typename T, typename U> DebugPrint& operator<<(DebugPrint& os, const
pair<T, U>& p) { os << "(" << p.first << ", " << p.second << ")"; return os; } void dump_func(
) { debugos << newl; } template <class Head, class... Tail> void dump_func(Head &&head, Tail
&&... tail) { debugos << head; if (sizeof...(Tail) > 0) { debugos << ", "; } dump_func(forward
<Tail>(tail)...); }
#ifdef LOCAL
#define dump(...) debugos << "  " << string(#__VA_ARGS__) << ": " << "[" << to_string(__LINE__) \
<< ":" << __FUNCTION__ << "]" << newl << "    ", dump_func(__VA_ARGS__)
#else
#define dump(...) ({})
#endif
#pragma GCC diagnostic pop


#line 2 "C:/Users/W/c/lib/data-structure/union-find.cpp"

#line 4 "C:/Users/W/c/lib/data-structure/union-find.cpp"

class UnionFind {
 private:
  int n, cnt;
  vector<int> par, rank, sz;

 public:
  UnionFind(int _n) : n(_n), cnt(_n), par(_n), rank(_n), sz(_n, 1) {
    iota(all(par), 0);
  }
  int root(int x) { return par[x] == x ? x : par[x] = root(par[x]); }
  void merge(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return;
    if (rank[x] < rank[y]) swap(x, y);
    par[y] = x;
    if (rank[x] == rank[y]) rank[x]++;
    sz[x] += sz[y];
    cnt--;
  }
  bool same(int x, int y) { return root(x) == root(y); }
  int size(int x) { return sz[root(x)]; }
  int count() { return cnt; }
  void reset(int n2) {
    n = cnt = n2;
    iota(par.begin(), par.begin()+n2, 0);
    fill(rank.begin(), rank.begin()+n2, 0);
    fill(sz.begin(), sz.begin()+n2, 1);
  }
};
#line 4 "c.cpp"

struct chash {
  random_device rd;
  const ull RANDOM = uniform_int_distribution<ull>(0)(rd);
  template <typename T>
  ull operator()(T x) const {
    return x ^ RANDOM;
  }
  template <typename T, typename U>
  ull operator()(pair<T, U> x) const {
    return (*this)(x.first) * 31 + (*this)(x.second);
  }
};


int beauty(int u, int v) {
  return u == v ? 20 : __builtin_ffs(u^v) - 1;
}


int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);

  vector<map<int, set<int>>> entry(20);

  int n; cin >> n;
  VI a(n), b(n); rep(i, n) cin >> a[i] >> b[i];

  UnionFind uf(1 << 20);
  VI sz(1 << 20);
  auto check = [&](int t) {
    int m = 1 << t;
    int mask = m - 1;
    uf.reset(m);
    fill(sz.begin(), sz.begin()+m, 0);
    set<int> mod;
    rep(i, n)
      uf.merge(a[i] & mask, b[i] & mask), sz[a[i] & mask]++, sz[b[i] & mask]++, mod.insert(a[i]&mask), mod.insert(b[i]&mask);
    for (int i : mod) if (sz[i] % 2 == 1) return false;
    for (int i : mod) if (sz[i] and not uf.same(i, a[0] & mask)) return false;
    return true;
  };

  int ok = 0, ng = 21;
  while (ng - ok > 1) {
    int m = (ok + ng) / 2;
    (check(m) ? ok : ng) = m;
  }

  int t = ok;
  cout << t << newl;
  if (t == 0) {
    rep(i, n*2) cout << i+1 << " \n"[i == n*2-1];
    exit(0);
  }

  int m = 1 << t;
  int mask = m - 1;
  vector<multiset<int>> graph(m);
  unordered_map<PII, VI, chash> edges;
  VVI loop(m);
  rep(i, n) {
    a[i] &= mask, b[i] &= mask;
    if (a[i] == b[i]) {
      loop[a[i]].push_back(i);
      continue;
    }
    graph[a[i]].insert(b[i]);
    graph[b[i]].insert(a[i]);
    edges[minmax(a[i], b[i])].push_back(i);
  }

  VI trail;
  auto dfs = [&](auto f, int v) -> void {
    for (auto it = graph[v].begin(); not graph[v].empty();) {
      int to = *it;
      it = graph[v].erase(it);
      auto itr = graph[to].find(v);
      assert(itr != graph[to].end());
      graph[to].erase(itr);
      f(f, to);
    }
    trail.push_back(v);
  }; dfs(dfs, a[0]);

  VI res;
  int at = a[0];
  rep(i, trail.size()) {
    for (int e : loop[at]) {
      res.push_back(e*2);
      res.push_back(e*2+1);
    }
    loop[at].clear();
    if (i) {
      VI& es = edges[minmax(trail[i-1], trail[i])];
      int e = es.back(); es.pop_back();
      bool rev = a[e] != at;
      res.push_back(e*2|rev);
      res.push_back(e*2|rev^1);
      at = rev ? a[e] : b[e];
    }
  }
  rep(i, res.size()) cout << res[i]+1 << " \n"[i == res.size()-1];
}