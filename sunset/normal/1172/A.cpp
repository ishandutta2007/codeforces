#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    --a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
    --b[i];
  }
  vector<int> p(n, -1);
  for (int i = 0; i < n; ++i) {
    if (b[i] != -1) {
      p[b[i]] = i;
    }
  }
  if (p[0] != -1) {
    int i = 1;
    while (i < n && p[i] == p[i - 1] + 1) {
      ++i;
    }
    if (b.back() == i - 1) {
      int j = i;
      while (j < n && p[j] < j - i) {
        ++j;
      }
      if (j == n) {
        cout << n - i << "\n";
        return 0;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans = max(ans, p[i] - i + 1);
  }
  cout << ans + n << "\n";
  return 0;
}