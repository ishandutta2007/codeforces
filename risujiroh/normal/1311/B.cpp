#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto&& e : a) {
      cin >> e;
    }
    vector<bool> b(n + 1);
    while (m--) {
      int p;
      cin >> p;
      --p;
      b[p + 1] = true;
    }
    vector<int> v;
    for (int i = 0; i <= n; ++i) {
      if (not b[i]) {
        v.push_back(i);
      }
    }
    for (int t = 0; t < (int)v.size() - 1; ++t) {
      sort(begin(a) + v[t], begin(a) + v[t + 1]);
    }
    if (is_sorted(begin(a), end(a))) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}