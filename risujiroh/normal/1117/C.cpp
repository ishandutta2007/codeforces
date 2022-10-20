#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;


int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  lint x1, y1; cin >> x1 >> y1;
  lint x2, y2; cin >> x2 >> y2;
  lint n; cin >> n;
  string s; cin >> s;
  if (x1 > x2) {
    swap(x1, x2);
    for (auto&& c : s) {
      if (c == 'L') c = 'R';
      else if (c == 'R') c = 'L';
    }
  }
  if (y1 > y2) {
    swap(y1, y2);
    for (auto&& c : s) {
      if (c == 'U') c = 'D';
      else if (c == 'D') c = 'U';
    }
  }
  V<lint> cx(n + 1), cy(n + 1);
  for (int i = 0; i < n; ++i) switch(s[i]) {
    case 'U': cx[i + 1] = cx[i], cy[i + 1] = cy[i] + 1; break;
    case 'D': cx[i + 1] = cx[i], cy[i + 1] = cy[i] - 1; break;
    case 'L': cx[i + 1] = cx[i] - 1, cy[i + 1] = cy[i]; break;
    case 'R': cx[i + 1] = cx[i] + 1, cy[i + 1] = cy[i]; break;
  }
  if (all_of(begin(s), end(s), [](char c) { return c == 'L' or c == 'D'; })) {
    // return cout << -1 << '\n', 0;
  }

  auto chk = [&](lint x) -> bool {
    lint q = x / n, r = x % n;
    return abs(x2 - x1 - cx[r] - q * cx[n]) + abs(y2 - y1 - cy[r] - q * cy[n]) <= x;
  };
  lint ng = 0, ok = 1e18;
  while (ok - ng > 1) {
    lint mid = ng + ok >> 1;
    (chk(mid) ? ok : ng) = mid;
  }
  cout << (ok > 1e17 ? -1 : ok) << '\n';
}