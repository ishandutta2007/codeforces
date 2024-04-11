#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int q; cin >> q;
  while (q--) {
    lint k, n, a, b; cin >> k >> n >> a >> b;
    if (k - b * n <= 0) cout << -1 << '\n';
    else {
      lint ok = 0, ng = n + 1;
      while (ng - ok > 1) {
        lint mid = ok + ng >> 1;
        (k - a * mid - b * (n - mid) > 0 ? ok : ng) = mid;
      }
      cout << ok << '\n';
    }
  }
}