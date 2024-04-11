#line 2 "C:/Users/W/c/lib/template.cpp"

#ifndef LOCAL
#pragma GCC diagnostic warning "-w"
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
#define dump(...)
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
};
#line 2 "C:/Users/W/c/lib/graph/graph.cpp"

#line 4 "C:/Users/W/c/lib/graph/graph.cpp"

struct Edge {
  int to; ll cost;
  Edge(int _to) : to(_to), cost(1) {}
  Edge(int _to, ll _cost) : to(_to), cost(_cost) {}
  operator int() const { return to; }
};

using Graph = vector<vector<Edge>>;
#line 4 "e.cpp"

int main() {
	cin.tie(0);	ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;
	int n1, n2, n3; cin >> n1 >> n2 >> n3;

	Graph graph(n);
	rep(m) {
		int u, v; cin >> u >> v;
		u--; v--;
		graph[u].emplace_back(v);
		graph[v].emplace_back(u);
	}

	vector<int> rts;

	{
		UnionFind uf(n);
		rep(v, n) for (auto e : graph[v]) uf.merge(v, e.to);
		rep(v, n) rts.push_back(uf.root(v));
		sort(all(rts)); rts.erase(unique(all(rts)), rts.end());
	}

	int k = rts.size();

	vector<array<int, 2>> twos(k);
	VI dist(n, -1);
	rep(i, k) {
		int rt = rts[i];
		dist[rt] = 0;
		queue<int> togo; togo.emplace(rt);
		array<int, 2> two = {};
		while (not togo.empty()) {
			int v = togo.front(); togo.pop();
			two[dist[v]]++;
			int d2 = dist[v] ^ 1;
			for (auto e : graph[v])
				if (dist[e.to] == -1) dist[e.to] = d2, togo.emplace(e.to);
				else if (d2 != dist[e.to]) { cout << "NO\n"; return 0; }
		}
		twos[i] = (two);
	}

	for (auto [a, b] : twos) dump(a, b);

	auto dp = make_v(k+1, n+1, false);
	auto choice = make_v(k+1, n+1, false);
	dp[0][0] = true;
	rep(i, k) {
		rep(s, n) if (dp[i][s])
			rep(j, 2) if (s + twos[i][j] <= n)
				dp[i+1][s+twos[i][j]] = true, choice[i+1][s+twos[i][j]] = j;
	}

	if (not dp[k][n2]) { cout << "NO\n"; return 0; }

	VI choice2(k);
	int at = n2;
	repr(i, k) {
		choice2[i] = choice[i+1][at];
		at -= twos[i][choice2[i]];
	}
	assert(at == 0);

	string res(n, '$');

	VB visited(n, false);
	rep(i, k) {
		int d = choice2[i];
		queue<int> togo; togo.emplace(rts[i]);
		visited[rts[i]] = true;
		while (not togo.empty()) {
			int v = togo.front(); togo.pop();
			if (dist[v] == d) res[v] = '2';
			for (auto e : graph[v])
				if (not visited[e.to])
					visited[e.to] = true, togo.push(e.to);
		}
	}

	assert(count(all(res), '2') == n2);

	rep(i, n) if (res[i] != '2') res[i] = n1 ? (n1--, '1') : '3';

	cout << "YES\n";
	cout << res << newl;
}