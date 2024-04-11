#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

auto divide(auto a, auto b) -> decltype(a / b) {
  if (a >= 0 and b > 0) return a / b;
  if (a < 0 and b > 0) return -((-a + b - 1) / b);
  if (a >= 0 and b < 0) return -((a - b - 1) / -b);
  if (a < 0 and b < 0) return -a / -b;
  return 0;
}

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  lint n, m, k; cin >> n >> m >> k;
  set<lint> se;
  while (m--) {
    lint p; cin >> p, --p;
    se.insert(p);
  }
  int res = 0;
  lint o = 0;
  while (!se.empty()) {
    lint x = *begin(se);
    se.erase(x);
    int t = 1;
    while (!se.empty() and divide(*begin(se) - o, k) == divide(x - o, k)) {
      se.erase(begin(se));
      ++t;
    }
    o += t;
    ++res;
  }
  cout << res << '\n';
}