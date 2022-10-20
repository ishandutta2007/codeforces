#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

mt19937 mt_engine(chrono::steady_clock::now().time_since_epoch().count());
template <class T> enable_if_t<is_integral_v<T>, T> rng(T l, T r) {
  return uniform_int_distribution<T>(l, r - 1)(mt_engine);
}
template <class T> enable_if_t<is_floating_point_v<T>, T> rng(T l, T r) {
  return uniform_real_distribution<T>(l, r)(mt_engine);
}

struct rolling_hash {
  static constexpr uint64_t mod = 2e9 + 33;
  static long long base[2];
  static vector<int> powb[2];
  vector<int> h[2];
  template <class S = string> rolling_hash(const S& s = "") : h{{0}, {0}} {
    assert(all_of(begin(s), end(s), [](uint64_t c) { return c < mod; }));
    for (int k : {0, 1}) {
      for (auto c : s) h[k].push_back((h[k].back() * base[k] + c) % mod);
      while (powb[k].size() <= s.size())
        powb[k].push_back(powb[k].back() * base[k] % mod);
    }
  }
  int get(int l, int r, int k) const {
    return (h[k][r] + (mod - h[k][l]) * powb[k][r - l]) % mod;
  }
  auto get(int l, int r) const { return make_pair(get(l, r, 0), get(l, r, 1)); }
  int size() const { return h[0].size() - 1; }
};
long long rolling_hash::base[]{rng<int>(1e9, 2e9), rng<int>(1e9, 2e9)};
vector<int> rolling_hash::powb[]{{1}, {1}};

template <class T> constexpr T inf = numeric_limits<T>::max() / 2.1;

auto chmax = [](auto&& a, auto b) { return a < b ? a = b, 1 : 0; };

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  using ll = long long;
  int n;
  cin >> n;
  ll l;
  cin >> l;
  vector<int> a(n);
  for (auto&& e : a) cin >> e;
  vector<string> s(n), suff;
  vector<rolling_hash> rhs;
  for (auto&& e : s) {
    cin >> e;
    for (int i = 0; i < (int)size(e); ++i) {
      suff.push_back(e.substr(i));
    }
    rhs.emplace_back(e);
  }
  int sz = size(suff);
  suff.emplace_back();
  vector pre(sz, vector<int>(sz + 1));
  for (int j = 0; j < sz; ++j) {
    for (int k = 0; k <= sz; ++k) {
      rolling_hash rh(suff[j] + suff[k]);
      for (int pos = 0; pos < (int)size(suff[j]); ++pos) {
        for (int i = 0; i < n; ++i) {
          if (pos + rhs[i].size() > rh.size()) continue;
          if (rh.get(pos, pos + rhs[i].size()) != rhs[i].get(0, rhs[i].size())) continue;
          pre[j][k] += a[i];
        }
      }
    }
  }
  constexpr int lim = 40000;
  vector dp(lim + 1, vector(sz, -inf<ll>));
  vector<ll> b(lim + 1);
  for (int m = 1; m <= lim; ++m) {
    for (int j = 0; j < sz; ++j) {
      if ((int)size(suff[j]) > m) continue;
      if ((int)size(suff[j]) == m) {
        dp[m][j] = pre[j][sz];
        continue;
      }
      for (int k = 0; k < sz; ++k) {
        chmax(dp[m][j], pre[j][k] + dp[m - size(suff[j])][k]);
      }
    }
    b[m] = *max_element(begin(dp[m]), end(dp[m]));
  }
  for (int len = 200; ; --len) {
    vector<ll> d0(len), d1(len);
    adjacent_difference(end(b) - len, end(b), begin(d0));
    adjacent_difference(end(b) - 2 * len, end(b) - len, begin(d1));
    d0[0] = d1[0] = 0;
    if (d0 == d1) {
      DEBUG(len);
      ll res = l <= lim ? b[l] : b[800 + (l - 800) % len] + (b[800 + len] - b[800]) * ((l - 800) / len);
      cout << res << '\n';
      break;
    }
  }
}