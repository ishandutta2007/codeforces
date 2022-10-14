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
  vector<string> A(n);
  for (int i = 0; i < n; i++) cin >> A[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m - 1; j++) {
      if (A[i][j] == A[i][j + 1] && A[i][j] != '.') {
        cout << "NO\n";
        return;
      }
    }
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m; j++) {
      if (A[1 + i][j] == A[i][j] && A[i][j] != '.') {
        cout << "NO\n";
        return;
      }
    }
  }
  bool b1 = false, b2 = false;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if ((i + j) % 2 == 0) {
        if (A[i][j] == 'R') {
          b2 = true;
        }
        if (A[i][j] == 'W') {
          b1 = true;
        }
      } else {
        if (A[i][j] == 'R') {
          b1 = true;
        }
        if (A[i][j] == 'W') {
          b2 = true;
        }
      }
    }
  }
  if (!b2) {
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if ((i + j) % 2 == 0) {
          cout << 'W';
        } else {
          cout << 'R';
        }
      }
      cout << '\n';
    }
  } else if (!b1) {
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if ((i + j) % 2 == 1) {
          cout << 'W';
        } else {
          cout << 'R';
        }
      }
      cout << '\n';
    }
  } else {
    cout << "NO\n";
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