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
  auto query = [&](int i, int j) {
    assert(0 <= min(i, j) and max(i, j) < n);
    assert(i != j);
    cout << "? " << i + 1 << ' ' << j + 1 << endl;
    int res;
    cin >> res;
    return res;
  };
  vector<int> zi(11, -1);
  while (find(begin(zi), end(zi), -1) != end(zi)) {
    int i, j;
    do {
      i = rng(0, n), j = rng(0, n);
    } while (i == j);
    int x = query(i, j);
    for (int k = 0; k < 11; ++k) {
      if (zi[k] != -1 or x >> k & 1) continue;
      zi[k] = i;
    }
  }
  auto specify = [&](int i) {
    int res = 0;
    for (int k = 0; k < 11; ++k) {
      if (i == zi[k]) continue;
      res |= query(i, zi[k]) & (1 << k);
    }
    return res;
  };
  int best = -1, bi = -1;
  for (int i = 0; i < n; ++i) {
    if (best == -1 or query(bi, i) == best) {
      best = specify(i);
      bi = i;
    }
    if (best == 0) break;
  }
  vector<int> res(n);
  for (int i = 0; i < n; ++i) {
    if (i != bi) {
      res[i] = query(i, bi);
    }
  }
  cout << "!";
  for (auto e : res) {
    cout << ' ' << e;
  }
  cout << endl;
}