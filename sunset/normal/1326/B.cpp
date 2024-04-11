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
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  vector<long long> x(n + 1);
  vector<long long> a(n);
  for (int i = 0; i < n; ++i) {
    a[i] = x[i] + b[i];
    x[i + 1] = max(x[i], a[i]);
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