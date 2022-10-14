#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = -1e9;
  for (int i = 0; i < n; i++) {
    ans = max(ans, a[i] - a[(i + 1) % n]);
  }
  for (int i = 1; i < n; i++) {
    ans = max(ans, a[i] - a[0]);
  }
  for (int i = 0; i < n - 1; i++) {
    ans = max(ans, a[n - 1] - a[i]);
  }
  cout << ans;
  cout << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}