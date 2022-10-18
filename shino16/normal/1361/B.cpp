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


#line 2 "C:/Users/W/c/lib/math/modint.cpp"

#line 4 "C:/Users/W/c/lib/math/modint.cpp"

template <ll> class modint;
template <ll MOD> constexpr modint<MOD> pow(modint<MOD>, ll);

template <ll MOD = 1000000007>
class modint {
public:
  ll value;
  static constexpr ll Mod = MOD;

  constexpr modint(const ll x = 0) noexcept : value(x) {
    value %= MOD;
    if (value < 0) value += MOD;
  }
  constexpr bool operator==(const modint& rhs) {
    return value == rhs.value;
  }
  constexpr bool operator!=(const modint& rhs) {
    return value != rhs.value;
  }
  constexpr modint operator-() const {
    return modint(0) - *this;
  }
  constexpr modint operator+(const modint& rhs) const {
    return modint(*this) += rhs;
  }
  constexpr modint operator-(const modint& rhs) const {
    return modint(*this) -= rhs;
  }
  constexpr modint operator*(const modint& rhs) const {
    return modint(*this) *= rhs;
  }
  constexpr modint operator/(const modint& rhs) const {
    return modint(*this) /= rhs;
  }
  constexpr modint& operator+=(const modint& rhs) {
    value += rhs.value;
    if (value >= MOD) value -= MOD;
    return *this;
  }
  constexpr modint& operator-=(const modint& rhs) {
    if (value < rhs.value) value += MOD;
    value -= rhs.value;
    return *this;
  }
  constexpr modint& operator*=(const modint& rhs) {
    value = value * rhs.value % MOD;
    return *this;
  }
  constexpr modint& operator/=(const modint& rhs) {
    return *this *= pow(rhs, MOD - 2);
  }
  constexpr modint& operator++() {
    return *this += 1;
  }
  constexpr modint operator++(int) {
    modint tmp(*this);
    ++(*this);
    return tmp;
  }
  constexpr modint& operator--() {
    return *this -= 1;
  }
  constexpr modint operator--(int) {
    modint tmp(*this);
    --(*this);
    return tmp;
  }
  constexpr operator int() const {
    return (int)value;
  }
  constexpr operator ll() const {
    return value;
  }
};


template <typename OutStream, ll MOD>
OutStream& operator<<(OutStream& out, modint<MOD> n) {
  out << n.value;
  return out;
}

template <typename InStream, ll MOD>
InStream& operator>>(InStream& in, modint<MOD>& n) {
  ll var; in >> var; n = modint<MOD>(var);
  return in;
}

template <ll MOD>
constexpr modint<MOD> pow(modint<MOD> base, ll exp) {
  modint<MOD> res = 1;
  while (exp) {
    if (exp % 2) res *= base;
    base *= base;
    exp /= 2;
  }
  return res;
}

// O(r + log MOD)
template <ll MOD>
modint<MOD> choose(int n, int r) {
  chmin(r, n-r);
  if (r < 0) return modint<MOD>(0);
  modint<MOD> nu = 1, de = 1;
  rep(i, r) nu *= n-i, de *= i+1;
  return nu / de;
}
#line 3 "b.cpp"

ll checkpow(ll base_, ll exp) {
  __int128 res = 1;
  __int128 base = base_;
  for (; exp; base *= base, exp >>= 1) {
    if (base > INF) return -1;
    if (exp & 1) res *= base;
    if (res > INF) return -1;
  }
  return (ll)res;
}

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);

  int t; cin >> t;
  const int MaxN = 1000000;
  VLL k(MaxN), kk(MaxN), cn(MaxN), gather(MaxN);
  rep(t) {
    int n, p; cin >> n >> p;
    rep(i, n) cin >> k[i];

    if (p == 1) {
      cout << n % 2 << newl;
      continue;
    }

    map<int, int> k_cnt;
    rep(i, n) k_cnt[k[i]]++;

    int m = 0;
    for (auto [ki, c] : k_cnt) kk[m] = ki, cn[m] = c, m++;
    gather[0] = cn[0];
    rep(i, 1, m) {
      ll po = checkpow(p, kk[i]-kk[i-1]);
      gather[i] = po >= 0 ? gather[i-1] / po + cn[i] : cn[i];
    }
    int I = -1;
    ll subtract = 0;
    repr(i, m) {
      if (subtract) {
        ll po = checkpow(p, kk[i+1] - kk[i]);
        assert(po != -1);
        subtract *= po;
        ll consume = min(subtract, cn[i]);
        cn[i] -= consume;
        gather[i] -= consume;
        subtract -= consume;
      }
      if (cn[i] % 2 == 0) continue;
      if (gather[i] > cn[i]) {
        assert(i != 0);
        subtract++;
        continue;
      }
      I = i; break;
    }
    if (I == -1) { assert(subtract == 0); cout << 0 << newl; continue; }

    dump(I);

    repr(i, I) if (subtract) {
      ll po = checkpow(p, kk[i+1] - kk[i]);
      assert(po != -1);
      subtract *= po;
      ll consume = min(subtract, cn[i]);
      cn[i] -= consume;
      gather[i] -= consume;
      subtract -= consume;
    }

    assert(subtract == 0);

    modint diff = pow(modint(p), kk[I]);
    dump(cn, kk);
    rep(i, I) dump(diff), diff -= modint(cn[i]) * pow(modint(p), kk[i]);

    cout << diff << newl;
  }
}