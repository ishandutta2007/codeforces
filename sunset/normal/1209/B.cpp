#include <bits/stdc++.h>

using namespace std;

const int MAX = 12345;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
  }
  vector<int> on(n);
  for (int i = 0; i < n; ++i) {
    on[i] = s[i] == '1';
  }
  int ans = 0;
  for (int t = 0; t < MAX; ++t) {
    int cur = 0;
    for (int i = 0; i < n; ++i) {
      if (t >= b[i] && (t - b[i]) % a[i] == 0) {
        on[i] ^= 1;
      }
      cur += on[i];
    }
    ans = max(ans, cur);
  }
  cout << ans << "\n";
  return 0;
}