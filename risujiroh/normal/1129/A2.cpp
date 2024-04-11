#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;


int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  VV<> bs(n);
  while (m--) {
    int a, b; cin >> a >> b, --a, --b;
    bs[a].push_back(b);
  }
  V<lint> c(n, -1e18);
  for (int i = 0; i < n; ++i) if (!bs[i].empty()) {
    c[i] = (bs[i].size() - 1) * n;
    int r = n;
    for (int b : bs[i]) {
      r = min(r, (n + b - i) % n);
    }
    c[i] += r;
  }
  for (int i = 0; i < n; ++i) {
    lint res = 0;
    for (int j = 0; j < n; ++j) {
      lint curr = (n + j - i) % n + c[j];
      res = max(res, curr);
    }
    cout << res << " \n"[i == n - 1];
  }
}