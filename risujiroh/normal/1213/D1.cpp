#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, k; cin >> n >> k;
  VV<> v(2e5 + 1);
  while (n--) {
    int a; cin >> a;
    int t = 0;
    while (true) {
      v[a].push_back(t++);
      if (!a) break;
      a >>= 1;
    }
  }
  int res = 2e9;
  for (auto&& e : v) if ((int)e.size() >= k) {
    sort(begin(e), end(e));
    res = min(res, accumulate(begin(e), begin(e) + k, 0));
  }
  cout << res << '\n';
}