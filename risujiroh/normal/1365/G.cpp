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

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> p(n);
  iota(begin(p), end(p), 0);
  shuffle(begin(p), end(p), mt_engine);
  auto query = [&](const auto& idx) {
    if (empty(idx)) {
      return 0LL;
    }
    cout << "? " << size(idx);
    for (int i : idx) {
      cout << ' ' << p[i] + 1;
    }
    cout << endl;
    long long res;
    cin >> res;
    return res;
  };
  vector<long long> a(10);
  for (int j = 0; j < 10; ++j) {
    vector<int> idx;
    for (int i = 0; i < n; ++i) {
      if (i >> j & 1) continue;
      idx.push_back(i);
    }
    a[j] = query(idx);
  }
  vector<int> and_i(63, 1023);
  vector<bool> exists(1024);
  for (int k = 0; k < 63; ++k) {
    for (int j = 0; j < 10; ++j) {
      if (a[j] >> k & 1) {
        and_i[k] &= ~(1 << j);
      }
    }
    exists[and_i[k]] = true;
  }
  vector<int> level(1024, -1);
  for (int i = 0; i < 1024; ++i) {
    if (not exists[i]) continue;
    level[i] = 0;
    for (int j = (i - 1) & i; ; j = (j - 1) & i) {
      if (exists[j]) {
        level[i] = max(level[i], level[j] + 1);
      }
      if (j == 0) break;
    }
    assert(level[i] < 8);
  }
  vector<long long> b(3);
  for (int t = 0; t < 3; ++t) {
    vector<int> idx;
    for (int i = 0; i < n; ++i) {
      if (not exists[i] or level[i] >> t & 1) {
        idx.push_back(i);
      }
    }
    b[t] = query(idx);
  }
  vector<long long> res(n);
  for (int k = 0; k < 63; ++k) {
    if (and_i[k] == 1023) continue;
    bool any = false;
    for (int t = 0; t < 3; ++t) {
      if (level[and_i[k]] >> t & 1) continue;
      any |= b[t] >> k & 1;
    }
    for (auto&& e : res) {
      e |= 1LL << k;
    }
    if (not any) {
      res[p[and_i[k]]] &= ~(1LL << k);
    }
  }
  cout << "! ";
  for (auto e : res) {
    cout << ' ' << e;
  }
  cout << endl;
}