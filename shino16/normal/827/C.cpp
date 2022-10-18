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


#line 2 "C:/Users/W/c/lib/data-structure/bit.cpp"

#line 4 "C:/Users/W/c/lib/data-structure/bit.cpp"

class BIT {
 public:
  int n;

 private:
  vector<ll> data;

 public:
  BIT() = default;
  explicit BIT(int n_ = 0) : n(n_), data(n_ + 1) {}
  template <typename Iter>
  explicit BIT(Iter first, Iter last) : n(distance(first, last)) {
    data = vector<ll>(n + 1);
    copy(first, last, data.begin() + 1);
    auto zeroix = data.begin() + 1;
    rep(i, n) {
      int j = i | (i+1);
      if (j < n) zeroix[j] += zeroix[i];
    }
  }
  void add(int p, ll v = 1) {
    p++;
    while (p <= n) {
      data[p] += v;
      p += p & -p;
    }
  }
  // sum over [0, p)
  ll sum(int p) const {
    ll res = 0;
    while (p) {
      res += data[p];
      p -= p & -p;
    }
    return res;
  }
  // sum over [l, r)
  ll sum(int l, int r) const { return sum(r) - sum(l); }
  void clear() { fill(all(data), 0); }
  void assign(int p, ll v) { add(p, v - sum(p, p + 1)); }
  bool chmax(int p, ll v) {
    if (sum(p, p + 1) < v) {
      assign(p, v);
      return true;
    } else
      return false;
  }
  // min i s.t. sum over [0, i) >= v -- or n+1 if failed
  // requires data[i] >= 0 for any i
  int lower_bound(ll v) const {
    if (v <= 0) return 0;
    int l = 0;
    for (int k = 1 << (32 - __builtin_clz(n) - 1); k; k >>= 1)
      if (l + k <= n and data[l + k] < v) v -= data[l += k];
    return l + 1;
  }
  // min i s.t. sum over [0, i) > v -- or n+1 if failed
  // requires data[i] >= 0 for any i
  int upper_bound(ll v) const { return lower_bound(v + 1); }
};
#line 3 "c.cpp"

int main() {
	cin.tie(0);	ios_base::sync_with_stdio(false);

	string s; cin >> s;
	int n = s.size();
	map<char, int> mp = {{'A', 0}, {'T', 1}, {'G', 2}, {'C', 3}};


	vector<vector<vector<BIT>>> dat(4);
	rep(v, 4) {
		dat[v].resize(11);
		rep(i, 1, 11) {
			dat[v][i].assign(i, BIT(divceil(n, i)));
		}
	}

	auto load = [&](int ix, int v, int d) {
		rep(i, 1, 11) {
			dat[v][i][ix%i].add(ix/i, d);
		}
	};

	rep(i, n) load(i, mp[s[i]], 1);

	int q; cin >> q;
	rep(q) {
		int c; cin >> c;
		if (c == 1) {
			int x; char v; cin >> x >> v;
			x--;
			load(x, mp[s[x]], -1);
			s[x] = v;
			load(x, mp[s[x]], 1);
		} else {
			int l, r; string e; cin >> l >> r >> e;
			l--; int i = e.size();
			int res = 0;
			rep(j, i) {
				int v = mp[e[j]];
				int L = (l+j) / i;
				int R = (r+((l+j-r)%i+i)%i) / i;
				res += dat[v][i][(l+j)%i].sum(L, R);
				dump(l+j, r+j, L, R, dat[v][i][(l+j)%i].sum(L, R));
			}
			cout << res << newl;
		}
	}
}