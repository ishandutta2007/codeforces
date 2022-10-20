#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int q; cin >> q;
  while (q--) {
    int n; cin >> n;
    V<> a(n), f(n), c(n), c1(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i] >> f[i], --a[i];
      ++c[a[i]];
      c1[a[i]] += f[i];
    }
    VV<> d(n + 1);
    for (int i = 0; i < n; ++i) if (c[i]) {
      d[c[i]].push_back(c1[i]);
    }
    int res = 0, mx = 0;
    priority_queue<int> pque;
    for (int i = n; i; --i) {
      for (int e : d[i]) pque.push(e);
      if (!pque.empty()) {
        res += i;
        mx += min(pque.top(), i);
        pque.pop();
      }
    }
    cout << res << ' ' << mx << '\n';
  }
}