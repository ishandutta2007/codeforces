#include <bits/stdc++.h>

#define pb push_back
// #define int long long
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;
int d[122];

void solve() {
  for (int n = 1; n <= 11; n++) {
    vector<int> p(n);
    int fc = 1;
    for (int i = 0; i < n; i++) {
      p[i] = i;
      fc *= (i + 1);
    }
    vector<int> m(n);
    int ans = 0;
    for (int _ = 0; _ < fc; _++) {
      next_permutation(all(p));
      vector<int> q(n);
      for (int i = 0; i < n; i++) {
        q[p[i]] = i;
      }
      bool ok = true;
      for (int i = 0; i < n; i++) {
        if (abs(p[i] - q[i]) > 1) {
          ok = false;
        }
      }
      if (ok) {
        m[p[0]]++;
        ans++;
      }
    }
    cout << "for " << n << ": \n";
    d[n] = ans;
    cout << ans << ' ';
    if (n >= 4) {
      cout << d[n] - d[n - 1] - (n - 1) * d[n - 2] - (n - 3) * d[n - 4] << '\n';
    }
    for (int w = 0; w < n; w++) cout << m[w] << ' ';
    cout << "\n\n";
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  //solve();
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < 2 * n - 1; i++) {
      if (s[i] == s[i + 1] && s[i] == '(') {
        ans++;
      }
    }
    cout << ans + 1 << '\n';
  }
}