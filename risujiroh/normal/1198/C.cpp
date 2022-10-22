#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    set<int> se;
    V<> idx;
    for (int i = 0; i < m; ++i) {
      int u, v; cin >> u >> v, --u, --v;
      if (se.count(u) or se.count(v)) continue;
      idx.push_back(i);
      se.insert(u);
      se.insert(v);
    }
    if ((int)idx.size() >= n) {
      cout << "Matching" << '\n';
      for (int i = 0; i < n; ++i) {
        cout << idx[i] + 1 << " \n"[!(n + ~i)];
      }
    } else {
      cout << "IndSet" << '\n';
      V<> vs;
      for (int v = 0; v < 3 * n; ++v) if (!se.count(v)) {
        vs.push_back(v);
      }
      assert((int)vs.size() >= n);
      for (int i = 0; i < n; ++i) {
        cout << vs[i] + 1 << " \n"[!(n + ~i)];
      }
    }
  }
}