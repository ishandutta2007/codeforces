#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m, k;
  cin >> n >> m >> k;
  if (k > 4 * n * m - 2 * (n + m)) {
    cout << "NO\n";
    exit(0);
  }
  cout << "YES\n";
  vector<pair<char, int>> v;
  if (n == 1) {
    v.emplace_back('R', m - 1);
    v.emplace_back('L', m - 1);
  } else if (m == 1) {
    v.emplace_back('D', n - 1);
    v.emplace_back('U', n - 1);
  } else {
    for (int i = 1; i < n; ++i) {
      v.emplace_back('D', 1);
      v.emplace_back('R', m - 1);
      v.emplace_back('L', m - 1);
    }
    v.emplace_back('U', n - 1);
    for (int j = 1; j < m; ++j) {
      v.emplace_back('R', 1);
      v.emplace_back('D', n - 1);
      v.emplace_back('U', n - 1);
    }
    v.emplace_back('L', m - 1);
  }
  vector<pair<int, string>> res;
  auto it = begin(v);
  while (k) {
    int c = min(k, it->second);
    k -= c;
    res.emplace_back(c, string(1, it->first));
    ++it;
  }
  cout << res.size() << '\n';
  for (auto e : res) {
    cout << e.first << ' ' << e.second << '\n';
  }
}