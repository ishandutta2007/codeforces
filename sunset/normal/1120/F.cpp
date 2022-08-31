#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, c, d;
  cin >> n >> c >> d;
  vector<int> t(n + 1);
  vector<string> p(n + 1);
  for (int i = 0; i < n; ++i) {
    cin >> t[i] >> p[i];
  }
  cin >> t[n];
  long long sum = 0;
  long long ans = (long long) d * n;
  for (int i = n - 1, last = -1; ~i; --i) {
    if (p[i] == p[i + 1]) {
      sum += min(d, c * (last - t[i + 1]));
    } else {
      last = t[i + 1];
    }
    ans = min(ans, sum + c * (t[n] - t[i]) + (long long) d * i);
  }
  cout << ans << "\n";
  return 0;
}