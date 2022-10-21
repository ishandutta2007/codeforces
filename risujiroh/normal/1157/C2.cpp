#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  auto solve = [&](const V<>& a, bool out = false) -> int {
    int l = 0;
    if (a[0] != -1) {
      l = 1;
      while (l < n and a[l - 1] < a[l]) ++l;
    }
    int r = n;
    if (a[n - 1] != -1) {
      r = n - 1;
      while (r > 0 and a[r - 1] > a[r]) --r;
    }
    r = max(r, l);
    string s(n, 0);
    V<> idx;
    for (int i = 0; i < l; ++i) {
      s[i] = 'L';
      idx.push_back(i);
    }
    for (int i = r; i < n; ++i) {
      s[i] = 'R';
      idx.push_back(i);
    }
    sort(begin(idx), end(idx), [&](int i, int j) { return a[i] < a[j]; });
    string res;
    for (int i : idx) {
      res += s[i];
    }
    if (!out) return res.size();
    cout << res.size() << '\n';
    cout << res << '\n';
    return res.size();
  };
  V<> a(n); for (auto&& e : a) cin >> e;
  int l = 1;
  while (l < n and a[l - 1] < a[l]) ++l;
  int r = n - 1;
  while (r > 0 and a[r - 1] > a[r]) --r;
  int p = 0, q = n - 1;
  while (p < l and r <= q and p < q) {
    if (a[p] < a[q]) ++p;
    else if (a[p] > a[q]) --q;
    else {
      auto b = a;
      for (auto&& e : b) e <<= 1;
      auto c = b;
      b[p] = -1;
      c[q] = -1;
      if (solve(b) > solve(c)) {
        solve(b, true);
      } else {
        solve(c, true);
      }
      return 0;
    }
  }
  solve(a, true);
}