#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, k; cin >> n >> k;
  V<lint> a(n); for (auto&& e : a) cin >> e;
  sort(rbegin(a), rend(a));
  auto chk = [&](lint x) -> bool {
    lint s = 0;
    for (int i = 0; i < n + 1 >> 1; ++i) {
      s += max<lint>(x - a[i], 0);
    }
    return s <= k;
  };
  lint ok = 0, ng = 1e10;
  while (ng - ok > 1) {
    lint mid = ok + ng >> 1;
    (chk(mid) ? ok : ng) = mid;
  }
  cout << ok << '\n';
}