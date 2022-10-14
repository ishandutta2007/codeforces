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
  vector<int> a(n), b(n), x, y;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    if (a[i] == 0) {
      x.pb(b[i]);
    } else {
      y.pb(b[i]);
    }
  }
  sort(rall(x));
  sort(rall(y));
  int ans = 0;
  for (int i = 0; i < (int) x.size(); i++) {
    if (i < (int) y.size()) {
      ans += x[i];
    }
    ans += x[i];
  }
  for (int i = 0; i < (int) y.size(); i++) {
    if (i < (int) x.size()) {
      ans += y[i];
    }
    ans += y[i];
  }
  if (x.size() == y.size()) {
    ans -= *min_element(all(b));
  }
  cout << ans << '\n';
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