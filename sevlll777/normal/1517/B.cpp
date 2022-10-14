#include <bits/stdc++.h>

#define pb push_back
// #define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;
const int M = 1000000007;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> B(n, vector<int>(m));
  vector<int> al;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> B[i][j];
      al.pb(B[i][j]);
    }
  }
  sort(all(al));
  map<int, int> nums;
  for (int i = 0; i < m; i++) nums[al[i]]++;
  int i = 0;
  for (int c = 0; c < n; c++) {
    vector<int> f = B[c];
    sort(all(f));
    for (int w = m - i; w < 2 * m - i; w++) {
      cout << f[w % m] << ' ';
    }
    int j = i;
    while (i < m && nums[f[i - j]] > 0) {
      nums[f[i - j]]--;
      i++;
    }
    cout << '\n';
  }
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