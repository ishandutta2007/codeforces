#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> d(n);
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    ++d[--x];
    ++d[--y];
  }
  for (int i = 0; i < n; ++i) {
    if (d[i] == 2) {
      cout << "NO" << "\n";
      return 0;
    }
  }
  cout << "YES" << "\n";
  return 0;
}