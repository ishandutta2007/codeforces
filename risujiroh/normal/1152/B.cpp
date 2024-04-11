#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int x; cin >> x;
  auto chk = [](int x) -> bool {
    for (int i = 0; i < 30; ++i) {
      if (x == ~(~0 << i)) return true;
    }
    return false;
  };
  int t = 0;
  V<> res;
  while (!chk(x)) {
    for (int i = __lg(x); i >= 0; --i) {
      if (x >> i & 1) continue;
      res.push_back(i + 1);
      x ^= ~(~0 << i + 1);
      ++t;
      break;
    }
    if (chk(x)) break;
    ++x;
    ++t;
  }
  cout << t << '\n';
  int n = res.size();
  for (int i = 0; i < n; ++i) cout << res[i] << " \n"[!(n + ~i)];
}