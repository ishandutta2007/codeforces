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
    vector<int> H(n);
    for (int i = 0; i < n; i++) cin >> H[i];
    sort(all(H));
    if (n == 2) {
      cout << H[0] << ' ' << H[1] << '\n';
    } else {
      int m = 1e18;
      for (int i = 1; i < n; i++) {
        m = min(m, H[i] - H[i - 1]);
      }
      for (int i = 1; i < n; i++) {
        if (H[i] - H[i - 1] == m) {
          for (int j = i; j < i + n; j++) {
            cout << H[j % n] << ' ';
          }
          break;
        }
      }
      cout << '\n';
    }
  }
}