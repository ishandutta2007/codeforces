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
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] >= 0) {
      a[i] = -(a[i] + 1);
    }
  }
  if (n & 1) {
    int p = min_element(a.begin(), a.end()) - a.begin();
    a[p] = -(a[p] + 1);
  }
  for (int i = 0; i < n; ++i) {
    if (i) {
      cout << " ";
    }
    cout << a[i];
  }
  cout << "\n";
  return 0;
}