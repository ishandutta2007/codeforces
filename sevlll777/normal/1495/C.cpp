#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;
const int M = 1000000007;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<char>> A(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> A[i][j];
    }
  }
  for (int i = 0; i < n; i += 3) {
    for (int j = 0; j < m; j++) {
      A[i][j] = 'X';
    }
  }
  if (n % 3 == 0) {
    for (int j = 0; j < m; j++) {
      if (A[n - 1][j] == 'X') {
        A[n - 2][j] = 'X';
      }
    }
  }
  vector<int> f(n, -1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (A[i][j] == 'X') {
        f[i] = j;
        break;
      }
    }
  }
  for (int i = 1; i < n; i += 3) {
    if (f[i] != -1) {
      if (i != n - 1) {
        A[i + 1][f[i]] = 'X';
      }
    } else {
      if (i != n - 1) {
        if (f[i + 1] != -1) {
          A[i][f[i + 1]] = 'X';
        } else {
          A[i][0] = 'X';
          A[i + 1][0] = 'X';
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << A[i][j];
    }
    cout << '\n';
  }
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