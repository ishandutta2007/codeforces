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
  cout << n * 3 + 4 << "\n";
  for (int i = 1; i <= n; ++i) {
    cout << i << " " << i - 1 << "\n";
    cout << i << " " << i << "\n";
    cout << i << " " << i + 1 << "\n";
  }
  cout << 0 << " " << 0 << "\n";
  cout << 0 << " " << 1 << "\n";
  cout << n + 1 << " " << n << "\n";
  cout << n + 1 << " " << n + 1 << "\n";
  return 0;
}