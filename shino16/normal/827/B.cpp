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


#line 2 "C:/Users/W/c/lib/tree/dfs.cpp"

#line 2 "C:/Users/W/c/lib/graph/graph.cpp"

#line 4 "C:/Users/W/c/lib/graph/graph.cpp"

struct Edge {
  int to; ll cost;
  Edge(int _to) : to(_to), cost(1) {}
  Edge(int _to, ll _cost) : to(_to), cost(_cost) {}
  operator int() const { return to; }
};

using Graph = vector<vector<Edge>>;
#line 2 "C:/Users/W/c/lib/util/fix.cpp"

#line 4 "C:/Users/W/c/lib/util/fix.cpp"

template <typename F>
class FixPoint : private F {
 public:
  explicit constexpr FixPoint(F&& f) : F(forward<F>(f)) {}

  template <typename... Args>
  constexpr decltype(auto) operator()(Args&&... args) const {
    return F::operator()(*this, forward<Args>(args)...);
  }
};

template <typename F> decltype(auto) fix(F&& f) noexcept {
  return FixPoint<F>{forward<F>(f)};
}
#line 6 "C:/Users/W/c/lib/tree/dfs.cpp"

struct DFS {
  VI subtree_sz, par;
  VLL dist;
};

// tree
DFS dfs(const Graph& graph, int root = 0) {
  int n = graph.size();
  DFS res;
  res.subtree_sz = VI(n, 1);
  res.par = VI(n, -1);
  res.dist = VLL(n, INF_LL);
  res.dist[root] = 0;
  fix([&](auto f, auto v)->void{
    for (auto e : graph[v])
      if (e.to != res.par[v])
        res.dist[e.to] = res.dist[v] + e.cost,
        res.par[e.to] = v,
        f(e.to),
        res.subtree_sz[v] += res.subtree_sz[e.to];
  })(root);
  return res;
}
#line 3 "b.cpp"

int main() {
	cin.tie(0);	ios_base::sync_with_stdio(false);

	int n, k; cin >> n >> k;
	VI A, B;
	rep(i, 1, n-k) A.push_back(i);
	rep(i, n-k, n) B.push_back(i);


	VI rest;
	while (A.size() > B.size())
		rest.push_back(A.back()), A.pop_back();

	Graph graph(n);
	for (auto a : A) graph[a].emplace_back(0);
	if (A.size() == 1) A.push_back(0);

	rep(i, k) {
		graph[B[i]].emplace_back(A.size() == 0 ? 0 : A[min((int)A.size()-1, i)]);
	}

	VI tl = B;
	rep(i, rest.size()) {
		graph[rest[i]].emplace_back(tl[i % tl.size()]);
		tl[i % tl.size()] = rest[i];
	}

	Graph graph2(n);
	rep(i, n) for (auto e : graph[i])
		graph2[i].emplace_back(e), graph2[e.to].emplace_back(i);

	auto dep = dfs(graph2).dist;
	sort(rall(dep));

	cout << (dep[0] + dep[1]) << newl;
	rep(i, n) for (auto e : graph[i]) cout << i+1 << " " << e.to+1 << newl;
}