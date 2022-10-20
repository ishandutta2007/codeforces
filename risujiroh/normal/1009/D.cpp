#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using P = pair<int, int>;

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  if (m < n - 1) return cout << "Impossible" << '\n', 0;
  vector<P> res(m);
  int p = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (__gcd(i, j) == 1) {
        res[p] = P(i, j);
        p++;
        if (p == m) {
          cout << "Possible" << '\n';
          for (auto&& k : res) {
            cout << k.first << " " << k.second << '\n';
          }
          return 0;
        }
      }
    }
  }
  cout << "Impossible" << '\n';
  return 0;
}