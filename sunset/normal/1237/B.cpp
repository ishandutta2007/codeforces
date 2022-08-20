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
  for (int i = n - 1; ~i; --i) {
    cin >> a[i];
    --a[i];
  }
  vector<int> b(n);
  for (int i = n - 1; ~i; --i) {
    int x;
    cin >> x;
    b[--x] = i;
  }
  for (int i = 0; i < n; ++i) {
    a[i] = b[a[i]];
  }
  int ans = 0;
  for (int i = n - 2; ~i; --i) {
    if (a[i] > a[i + 1]) {
      ++ans;
      a[i] = a[i + 1];
    }
  }
  cout << ans << "\n";
  return 0;
}