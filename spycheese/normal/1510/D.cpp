#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

using namespace std;
typedef long double ld;

int main() {
  int n, dig;
  cin >> n >> dig;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  vector<ld> d[10];
  vector<int> dp[10];
  for (int i = 0; i < 10; ++i) d[i].resize(n + 1, -1e100);
  for (int i = 0; i < 10; ++i) dp[i].resize(n + 1);

  d[1][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 10; ++j) {
      d[j][i + 1] = d[j][i];
      dp[j][i + 1] = -1;
    }
    for (int j = 0; j < 10; ++j) {
      ld nd = d[j][i] + log((ld)a[i]);
      int nj = (j * a[i]) % 10;
      if (nd > d[nj][i + 1]) {
        d[nj][i + 1] = nd;
        dp[nj][i + 1] = j;
      }
    }
  }
  if (d[dig][n] <= 0) {
    cout << "-1\n";
    return 0;
  }
  vector<int> ans;
  for (int i = n; i > 0; --i) {
    if (dp[dig][i] != -1) {
      ans.push_back(a[i - 1]);
      dig = dp[dig][i];
    }
  }
  cout << sz(ans) << "\n";
  for (int x : ans) cout << x << " ";
  cout << "\n";
}