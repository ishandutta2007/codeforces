#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<lint> a(n); for (auto&& e : a) cin >> e;
  auto chk = [&](lint x) -> bool {
    auto b = a;
    lint s = 0;
    V<lint> u(n), l(n);
    for (int i = n - 1; i >= 0; --i) {
      lint curr = min(b[i] / 2, x - s);
      b[i] -= 2 * curr;
      s += curr;
      u[i] = curr;
    }
    if (s < x) return false;
    s = 0;
    for (int i = 0; i < n; ++i) {
      lint curr = min(b[i], x - s);
      b[i] -= curr;
      s += curr;
      l[i] = curr;
    }
    if (s < x) return false;
    V<lint> cu(n + 1), cl(n + 1);
    for (int i = 0; i < n; ++i) {
      cu[i + 1] = cu[i] + u[i];
      cl[i + 1] = cl[i] + l[i];
    }
    for (int i = 0; i <= n; ++i) {
      if (cl[i] < cu[i]) return false;
    }
    return true;
  };
  lint ok = 0, ng = accumulate(begin(a), end(a), 0LL) / 3 + 1;
  while (ng - ok > 1) {
    lint mid = ok + ng >> 1;
    (chk(mid) ? ok : ng) = mid;
  }
  cout << ok << '\n';
}