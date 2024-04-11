#include <bits/stdc++.h>

using namespace std;

const int L = 20;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(L);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    for (int j = 0; j < L; ++j) {
      if (a[i] >> j & 1) {
        b[j]++;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    a[i] = 0;
  }
  for (int i = 0; i < L; ++i) {
    for (int j = 0; j < b[i]; ++j) {
      a[j] |= 1 << i;
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += (long long) a[i] * a[i];
  }
  cout << ans << "\n";
  return 0;
}