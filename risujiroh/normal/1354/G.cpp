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

bool query(int l0, int r0, int l1, int r1) {
  cout << "? " << r0 - l0 << ' ' << r1 - l1 << '\n';
  for (int i = l0; i < r0; ++i) {
    cout << i + 1 << " \n"[i == r0 - 1];
  }
  for (int i = l1; i < r1; ++i) {
    cout << i + 1 << " \n"[i == r1 - 1];
  }
  cout.flush();
  string s;
  cin >> s;
  return s[0] == 'F';
}

void answer(int i) {
  cout << "! " << i + 1 << endl;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    int mi = 0;
    for (int _ = 20; _--; ) {
      int i;
      do {
        i = rng(0, n);
      } while (i == mi);
      if (query(i, i + 1, mi, mi + 1)) {
        mi = i;
      }
    }
    if (mi and query(mi, mi + 1, 0, 1)) {
      answer(0);
      continue;
    }
    for (int l = 1; l < n; l *= 2) {
      int r = min(2 * l, n);
      if (query(0, r - l, l, r)) {
        auto chk = [&](int m) {
          return query(0, m - l, l, m);
        };
        int ng = l, ok = r;
        while (ok - ng > 1) {
          int mid = (ng + ok) / 2;
          (chk(mid) ? ok : ng) = mid;
        }
        answer(ng);
        break;
      }
    }
  }
}