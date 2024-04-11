#include <bits/stdc++.h>

#define pb push_back
// #define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;
const int M = 1000000007;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> A(n, vector<int>(m - 1)), B(n - 1, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m - 1; j++) {
      cin >> A[i][j];
    }
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m; j++) {
      cin >> B[i][j];
    }
  }
  if (k % 2) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << "-1 ";
      }
      cout << '\n';
    }
    exit(0);
  }
  k /= 2;
  vector<vector<int>> d(n, vector<int>(m)), d2(n, vector<int>(m));
  while (k--) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        d2[i][j] = (int) 1e9;
        for (int di = -1; di <= 1; di++) {
          for (int dj = -1; dj <= 1; dj++) {
            if (abs(di) + abs(dj) == 1) {
              if (0 <= i + di && i + di < n && 0 <= j + dj && j + dj < m) {
                int val = d[i + di][j + dj];
                if (di == -1) {
                  val += B[i - 1][j];
                } else if (di == 1) {
                  val += B[i][j];
                } else if (dj == -1) {
                  val += A[i][j - 1];
                } else {
                  val += A[i][j];
                }
                d2[i][j] = min(d2[i][j], val);
              }
            }
          }
        }
      }
    }
    d = d2;
  }
  for (auto p : d2) {
    for (auto x : p) cout << x * 2 << ' ';
    cout << '\n';
  }
}