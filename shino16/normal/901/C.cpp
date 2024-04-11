#line 2 "C:/Users/W/c/lib/template.cpp"

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
#define dump(...) ((void)0)
#endif
#pragma GCC diagnostic pop


#line 2 "c.cpp"


int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);

  int n, m; cin >> n >> m;
  VVI graph(n);
  VB loop(n);
  rep(m) {
    int u, v; cin >> u >> v;
    u--; v--;
    if (u == v) loop[u] = true;
    else {
      graph[u].emplace_back(v);
      graph[v].emplace_back(u);
    }
  }

  VI par(n, -1);
  VB visited(n, false);
  VI depth(n, 0);
  set<PII> pcs;
  auto dfs = [&](auto f, int v) -> void {
    visited[v] = true;
    for (auto c : graph[v]) if (c != par[v]) {
      dump(v, c);
      if (visited[c]) {
        if (depth[c] < depth[v]) pcs.emplace(c, v);
      } else par[c] = v, depth[c] = depth[v]+1, f(f, c);
    }
  };
  rep(i, n) if (not visited[i]) dfs(dfs, i);

  auto mm = [&](auto f, int p, int c) {
    if (p == c) return PII(p, c);
    else {
      auto [mi, ma] = f(f, p, par[c]);
      return minmax({mi, ma, c});
    }
  };

  dump(pcs);

  VLL R(n, n);
  for (auto [p, c] : pcs) {
    auto [mi, ma] = mm(mm, p, c);
    R[mi] = ma;
  }
  rep(i, n) if (loop[i]) R[i] = i;
  repr(i, n-1) chmin(R[i], R[i+1]);

  VLL acc(n+1); rep(i, n) acc[i+1] = acc[i] + R[i];
  VLL accix(n+1); rep(i, n) accix[i+1] = accix[i] + i;

  int q; cin >> q;
  rep(q) {
    ll x, y; cin >> x >> y;
    x--;
    int m = lower_bound(all(R), y) - R.begin();
    ll res;
    if (m < x) res = y*(y-x);
    else if (m < y) res = acc[m] - acc[x] + y*(y-m);
    else res = acc[y] - acc[x];
    res -= accix[y] - accix[x];
    cout << res << newl;
  }
}