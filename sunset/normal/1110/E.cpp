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
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  vector<int> c(n - 1), d(n - 1);
  for (int i = 0; i < n - 1; ++i) {
    c[i] = a[i + 1] - a[i];
    d[i] = b[i + 1] - b[i];
  }
  sort(c.begin(), c.end());
  sort(d.begin(), d.end());
  cout << (a[0] == b[0] && c == d ? "Yes" : "No") << "\n";
  return 0;
}