#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

template <class T> constexpr T inf = numeric_limits<T>::max() / 2.1;

mt19937 mt_engine(chrono::steady_clock::now().time_since_epoch().count());
template <class T> enable_if_t<is_integral_v<T>, T> rng(T l, T r) {
  return uniform_int_distribution<T>(l, r - 1)(mt_engine);
}
template <class T> enable_if_t<is_floating_point_v<T>, T> rng(T l, T r) {
  return uniform_real_distribution<T>(l, r)(mt_engine);
}

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

struct chash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ x >> 30) * 0xbf58476d1ce4e5b9;
    x = (x ^ x >> 27) * 0x94d049bb133111eb;
    return x ^ x >> 31;
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t r = rng<uint64_t>(0, 0);
    return splitmix64(x ^ r);
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  generate(begin(a), end(a), bind(rng<int>, -10, 10));
  for (auto&& e : a) cin >> e;
  a.push_back(0);
  for (int i = n; i--; ) {
    a[i] += a[i + 1];
  }
  map<array<int, 4>, int> mp;
  auto _ = [&](int l, int r, int k, int t) {
    uint64_t res = l;
    res = res * (n + 1) + r;
    res = res * n + k;
    res = res * 2 + t;
    return res;
  };
  gp_hash_table<uint32_t, int> ht;
  auto f = [&](auto&& self, int l, int r, int k, int t) -> int {
    // if (mp.count({l, r, k ,t})) {
    //   return mp[{l, r, k, t}];
    // }
    if (ht.find(_(l, r, k, t)) != end(ht)) {
      return ht[_(l, r, k, t)];
    }
    int res = -inf<int>;
    for (int x : {k, k + 1}) {
      if (x > r - l) break;
      if (t == 0) {
        res = max(res, a[l] - a[l + x] - self(self, l + x, r, x, 1));
      } else {
        res = max(res, a[r - x] - a[r] - self(self, l, r - x, x, 0));
      }
    }
    if (res == -inf<int>) {
      res = 0;
    }
    return ht[_(l, r, k, t)] = res;
    // return mp[{l, r, k, t}] = res;
  };
  cout << f(f, 0, n, 1, 0) << '\n';
  cerr << size(ht) << '\n';
}