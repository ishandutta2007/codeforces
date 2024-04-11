#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, q; cin >> n >> q;
  V<> a(n); for (auto&& e : a) cin >> e;
  struct Q { int id, x, y; };
  V<Q> qs(q);
  for (int i = 0; i < q; ++i) {
    int x, y; cin >> x >> y, --x, --y;
    qs[i] = {i, x, y};
  }
  bitset<300000> res;
  auto fn = [&](const auto& fn, int l, int r, const V<Q>& qs) -> void {
    if (r - l == 1) return;
    int m = l + r >> 1;
    V<> b(r - l);
    {
      V<> dp(20);
      for (int k = 0; k < 20; ++k) {
        if (a[m] >> k & 1) dp[k] = a[m];
        else dp[k] = 1 << k;
      }
      b[m - l] = a[m];
      for (int i = m + 1; i < r; ++i) {
        int t = 0;
        for (int k = 0; k < 20; ++k) if (a[i] >> k & 1) {
          b[i - l] |= dp[k];
          t |= dp[k];
        }
        for (int k = 0; k < 20; ++k) if (a[i] >> k & 1) {
          dp[k] |= t;
        }
      }
    }
    {
      V<> dp(20);
      for (int k = 0; k < 20; ++k) {
        if (a[m - 1] >> k & 1) dp[k] = a[m - 1];
        else dp[k] = 1 << k;
      }
      b[m - 1 - l] = a[m - 1];
      for (int i = m - 2; i >= l; --i) {
        int t = 0;
        for (int k = 0; k < 20; ++k) if (a[i] >> k & 1) {
          b[i - l] |= dp[k];
          t |= dp[k];
        }
        for (int k = 0; k < 20; ++k) if (a[i] >> k & 1) {
          dp[k] |= t;
        }
      }
    }
    V<Q> lq, rq;
    for (const auto& e : qs) {
      if (e.y < m) {
        lq.push_back(e);
      } else if (e.x >= m) {
        rq.push_back(e);
      } else {
        res[e.id] = b[e.x - l] & b[e.y - l];
      }
    }
    fn(fn, l, m, lq);
    fn(fn, m, r, rq);
  };
  fn(fn, 0, n, qs);
  for (int i = 0; i < q; ++i) cout << (res[i] ? "Shi" : "Fou") << '\n';
}