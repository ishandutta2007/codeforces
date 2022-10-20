#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  auto go = [](auto f) -> int64_t {
    int64_t res = 0;
    for (int i = 0; i <= 100; ++i) res += i * f[i];
    auto n = accumulate(begin(f), end(f), int64_t(0));
    int pos = 0;
    for (int _ = n / 4; _--;) {
      while (f[pos] == 0) ++pos;
      --f[pos];
      res -= pos;
    }
    return res;
  };
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int64_t> fa(101), fb(101);
    for (int _ = n; _--;) {
      int a;
      cin >> a;
      ++fa[a];
    }
    for (int _ = n; _--;) {
      int b;
      cin >> b;
      ++fb[b];
    }
    auto check = [&](int64_t m) -> bool {
      fa[100] += m;
      fb[0] += m;
      bool res = go(fa) >= go(fb);
      fa[100] -= m;
      fb[0] -= m;
      return res;
    };
    int ng = -1, ok = n;
    while (ok - ng > 1) {
      int mid = (ng + ok) / 2;
      (check(mid) ? ok : ng) = mid;
    }
    cout << ok << '\n';
  }
}