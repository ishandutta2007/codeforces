#include <bits/stdc++.h>

using namespace std;

const long long INF = (1ll << 62) - 1;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<long long> xs(n), ys(n), zs(n);
    for (int i = 0; i < n; ++i) {
      cin >> xs[i] >> ys[i] >> zs[i];
    }
    long long x0 = 0, y0 = 0, z0 = 0;
    auto check = [&](long long t) {
      for (int parity = 0; parity < 2; ++parity) {
        long long al = LLONG_MIN, ar = LLONG_MAX;
        long long bl = LLONG_MIN, br = LLONG_MAX;
        long long cl = LLONG_MIN, cr = LLONG_MAX;
        long long sl = LLONG_MIN, sr = LLONG_MAX;
        for (int i = 0; i < n; ++i) {
          al = max(al, ys[i] + zs[i] - xs[i] - t - parity);
          ar = min(ar, ys[i] + zs[i] - xs[i] + t - parity);
          bl = max(bl, zs[i] + xs[i] - ys[i] - t - parity);
          br = min(br, zs[i] + xs[i] - ys[i] + t - parity);
          cl = max(cl, xs[i] + ys[i] - zs[i] - t - parity);
          cr = min(cr, xs[i] + ys[i] - zs[i] + t - parity);
          sl = max(sl, xs[i] + ys[i] + zs[i] - t - parity * 3);
          sr = min(sr, xs[i] + ys[i] + zs[i] + t - parity * 3);
        }
        if (al & 1) ++al;
        if (ar & 1) --ar;
        if (bl & 1) ++bl;
        if (br & 1) --br;
        if (cl & 1) ++cl;
        if (cr & 1) --cr;
        if (sl & 1) ++sl;
        if (sr & 1) --sr;
        al >>= 1; ar >>= 1;
        bl >>= 1; br >>= 1;
        cl >>= 1; cr >>= 1;
        sl >>= 1; sr >>= 1;
        sl = max(sl, al + bl + cl);
        sr = min(sr, ar + br + cr);
        if (al <= ar && bl <= br && cl <= cr && sl <= sr) {
          long long a = min(ar, sl - bl - cl);
          long long b = min(br, sl - cl - a);
          long long c = sl - a - b;
          x0 = b + c + parity;
          y0 = a + c + parity;
          z0 = a + b + parity;
          return true;
        }
      }
      return false;
    };
    long long l = 0, r = INF;
    while (l < r) {
      long long mid = (l + r) >> 1;
      if (check(mid)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    cout << x0 << " " << y0 << " " << z0 << "\n";
  }
  return 0;
}