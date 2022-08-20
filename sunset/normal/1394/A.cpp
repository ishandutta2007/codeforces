#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, d, m;
  cin >> n >> d >> m;
  vector<int> a, b;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (x > m) {
      a.push_back(x);
    } else {
      b.push_back(x);
    }
  }
  sort(a.begin(), a.end(), greater<int>());
  sort(b.begin(), b.end(), greater<int>());
  vector<long long> pref(b.size() + 1);
  for (int i = 0; i < (int) b.size(); ++i) {
    pref[i + 1] = pref[i] + b[i];
  }
  long long ans = 0;
  long long sum = 0;
  for (int i = 0; i <= (int) a.size() && (i - 1) * d + i <= n; ++i) {
    int remain = min((int) b.size(), n - (i - 1) * d - i);
    ans = max(ans, sum + pref[remain]);
    if (i < (int) a.size()) {
      sum += a[i];
    }
  }
  cout << ans << "\n";
  return 0;
}