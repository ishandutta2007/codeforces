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
  }
  long long ans = 0;
  for (int i = n - 1, j = n - 1, k = 0; ~i; --i) {
    j = min(j, i);
    while (a[i] >= 2) {
      while (j >= 0 && a[j] % 2 == 0) {
        --j;
      }
      if (j >= 0) {
        a[i] -= 2;
        a[j] -= 1;
        ++ans;
      } else {
        while (k < i && !a[k]) {
          ++k;
        }
        if (k == i) {
          ans += a[i] / 3;
          cout << ans << "\n";
          return 0;
        } else {
          int take = min(a[k], a[i] / 2);
          a[i] -= take * 2;
          a[k] -= take;
          ans += take;
        }
      }
    }
  }
  cout << ans << "\n";
  return 0;
}