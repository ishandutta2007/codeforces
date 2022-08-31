#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    vector<bool> d(n * 2);
    for (int i = 0; i < m; ++i) {
      cin >> a[i] >> b[i];
      d[--a[i]] = true;
      d[--b[i]] = true;
      if (a[i] > b[i]) {
        swap(a[i], b[i]);
      }
    }
    vector<int> t;
    for (int i = 0; i < n * 2; ++i) {
      if (!d[i]) {
        t.push_back(i);
      }
    }
    for (int i = 0; i < n - m; ++i) {
      a.push_back(t[i]);
      b.push_back(t[i + n - m]);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (!(b[j] < a[i] || b[i] < a[j] || (a[i] < a[j] && b[j] < b[i]) || (a[j] < a[i] && b[i] < b[j]))) {
          ++ans;
        }
      }
    }
    cout << ans << "\n";
  }
  return 0;
}