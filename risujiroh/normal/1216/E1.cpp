#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  V<lint> t(20);
  for (int i = 1; i < 20; ++i) {
    t[i] = 10 * t[i - 1] + 9;
  }
  auto sl = [&](lint m) -> lint {
    lint res = 0;
    for (int i = 0; t[i] < m; ++i) {
      res += (m - t[i]) * (m - t[i] + 1) / 2;
    }
    return res;
  };
  auto len = [&](lint n) -> lint {
    lint res = 0;
    for (int i = 0; t[i] < n; ++i) {
      res += n - t[i];
    }
    return res;
  };

  int q; cin >> q;
  while (q--) {
    lint k; cin >> k, --k;
    int n = -1;
    {
      int ng = 0, ok = 1e9;
      while (ok - ng > 1) {
        int mid = ng + ok >> 1;
        (k < sl(mid) ? ok : ng) = mid;
      }
      n = ok;
    }
    k -= sl(n - 1);
    int ng = 0, ok = n;
    while (ok - ng > 1) {
      int mid = ng + ok >> 1;
      (k < len(mid) ? ok : ng) = mid;
    }
    k -= len(ok - 1);
    cout << to_string(ok)[k] << '\n';
  }
}