#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> b, c;
    for (auto x : a) {
      if (x % 2 == 0) {
        b.pb(x);
      } else {
        c.pb(x);
      }
    }
    sort(all(b));
    sort(all(c));
    a = b;
    for (auto x : c) a.pb(x);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (gcd(a[i], 2 * a[j]) > 1) {
          ans++;
        }
      }
    }
    cout << ans << '\n';
  }
}