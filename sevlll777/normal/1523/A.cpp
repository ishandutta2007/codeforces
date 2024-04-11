#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  m = min(m, 2 * n + 777);
  string s;
  cin >> s;
  while (m--) {
    string t;
    for (int i = 0; i < n; i++) {
      int cnt = 0;
      if (i > 0) {
        if (s[i - 1] == '1') {
          cnt++;
        }
      }
      if (i < n - 1) {
        if (s[i + 1] == '1') {
          cnt++;
        }
      }
      if (cnt == 1 | s[i] == '1') {
        t += '1';
      } else {
        t += '0';
      }
    }
    s = t;
  }
  cout << s << '\n';

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