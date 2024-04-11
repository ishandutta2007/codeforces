#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;
const int M = 1000000007;

void solve() {
  int n;
  cin >> n;
  vector<int> X, Y;
  for (int i = 0; i < 2 * n; i++) {
    int x, y;
    cin >> x >> y;
    if (x == 0) {
      Y.pb(abs(y));
    } else {
      X.pb(abs(x));
    }
  }
  sort(all(X));
  sort(all(Y));
  ld ans = 0;
  for (int i = 0; i < n; i++) {
    int num = X[i] * X[i] + Y[i] * Y[i];
    ans += sqrt(num);
  }
  cout << fixed;
  cout << setprecision(21) << ans;
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