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
  vector<long long> a(n);
  long long s = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    s += a[i];
  }
  long long x = (s - (long long) (n - 2) * (n - 1) / 2) / n;
  int t = n - (x * n + (long long) n * (n - 1) / 2 - s);
  for (int i = 0; i < n; ++i) {
    if (i) {
      cout << " ";
    }
    cout << x + i - (i >= t);
  }
  cout << "\n";
  return 0;
}