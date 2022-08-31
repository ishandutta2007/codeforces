#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  int ans = n;
  vector<int> a(n - 1);
  for (int i = 0; i < n - 1; ++i) {
    a[i] = b[i + 1] - b[i] - 1;
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n - k; ++i) {
    ans += a[i];
  }
  cout << ans << "\n";
  return 0;
}