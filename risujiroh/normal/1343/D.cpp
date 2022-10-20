#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto && e : a) {
      cin >> e;
      --e;
    }
    vector<int> imos(2 * k);
    for (int i = 0; i < n / 2; ++i) {
      int j = n - i - 1;
      if (a[i] > a[j]) {
        swap(a[i], a[j]);
      }
      imos[0] += 2, imos[2 * k - 1] -= 2;
      int mn = a[i], mx = (k - 1) + a[j];
      --imos[mn], ++imos[mx + 1];
      --imos[a[i] + a[j]], ++imos[a[i] + a[j] + 1];
    }
    for (int i = 0; i < 2 * k - 1; ++i) {
      imos[i + 1] += imos[i];
    }
    int res = *min_element(begin(imos), end(imos) - 1);
    cout << res << '\n';
  }
}