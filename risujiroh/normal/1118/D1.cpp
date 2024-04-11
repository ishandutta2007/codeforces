#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;


int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  V<> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
  lint s = accumulate(begin(a), end(a), 0LL);
  if (s < m) return cout << -1 << '\n', 0;
  sort(rbegin(a), rend(a));

  auto chk = [&](int x) -> bool {
    lint c = 0;
    for (int i = 0; i < n; ++i) {
      c += max(a[i] - i / x, 0);
    }
    return c >= m;
  };
  int ng = 0, ok = n;
  while (ok - ng > 1) {
    int mid = ng + ok >> 1;
    (chk(mid) ? ok : ng) = mid;
  }
  cout << ok << '\n';
}