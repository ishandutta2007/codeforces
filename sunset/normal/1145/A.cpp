#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = 1; i <= n; i <<= 1) {
    for (int j = 0; j < n; j += i) {
      if (is_sorted(a.begin() + j, a.begin() + j + i)) {
        ans = i;
      }
    }
  }
  cout << ans << endl;
  return 0;
}