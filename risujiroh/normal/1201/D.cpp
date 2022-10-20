#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, m, k, q; cin >> n >> m >> k >> q;
  VV<> js(n);
  lint res = 0;
  while (k--) {
    int r, c; cin >> r >> c, --r, --c;
    js[r].push_back(c);
    res = max<lint>(res, r);
  }
  js[0].push_back(0);
  V<> l, r;
  for (int i = 0; i < n; ++i) {
    if (js[i].empty()) continue;
    sort(begin(js[i]), end(js[i]));
    l.push_back(js[i][0]);
    r.push_back(js[i].back());
  }
  n = l.size();
  V<> c(m + 1);
  while (q--) {
    int b; cin >> b, --b;
    c[b] = 1;
  }
  for (int j = m - 1; j >= 0; --j) c[j] += c[j + 1];

  auto fl = [&](int j) -> lint {
    int ok = -1, ng = j + 1;
    while (ng - ok > 1) {
      int mid = ok + ng >> 1;
      (c[mid] - c[j + 1] ? ok : ng) = mid;
    }
    return ok == -1 ? -1e9 : ok;
  };
  auto fr = [&](int j) -> lint {
    int ng = j - 1, ok = m;
    while (ok - ng > 1) {
      int mid = ng + ok >> 1;
      (c[j] - c[mid + 1] ? ok : ng) = mid;
    }
    return ok == m ? 1e9 : ok;
  };
  auto fn = [&](int x, int y) -> lint {
    if (x > y) swap(x, y);
    if (c[x] - c[y + 1]) return y - x;
    return y - x + 2 * min(x - fl(x - 1), fr(y + 1) - y);
  };

  lint cl = 2 * r[0] - l[0], cr = r[0];
  for (int i = 1; i < n; ++i) {
    lint ncl = min(cr + fn(r[i - 1], r[i]), cl + fn(l[i - 1], r[i])) + r[i] - l[i];
    lint ncr = min(cr + fn(r[i - 1], l[i]), cl + fn(l[i - 1], l[i])) + r[i] - l[i];
    cl = ncl;
    cr = ncr;
  }
  res += min(cl, cr);
  cout << res << '\n';
}