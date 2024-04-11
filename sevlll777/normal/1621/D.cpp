#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>

#define pb push_back
#define int long long
#define ld long double
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> A(2 * n, vector<int>(2 * n));
  for (int i = 0; i < 2 * n; i++) {
    for (int j = 0; j < 2 * n; j++) {
      cin >> A[i][j];
    }
  }
  int ans = 0;
  for (int i = n; i < 2 * n; i++) {
    for (int j = n; j < 2 * n; j++) {
      ans += A[i][j];
    }
  }
  if (n == 1) {
    cout << A[1][1] + min(A[0][1], A[1][0]) << '\n';
    return;
  }
  int gigamin = (int) 1e18;
  vector<vector<int>> U(2 * n, vector<int>(2 * n)), D(2 * n, vector<int>(2 * n)), L(2 * n, vector<int>(2 * n)), R(2 * n,
                                                                                                                  vector<int>(
                                                                                                                      2 *
                                                                                                                      n));
  for (int j = 0; j < n; j++) {
    U[n][j] = A[n][j];
    D[2 * n - 1][j] = A[2 * n - 1][j];
  }
  for (int i = n; i < 2 * n; i++) {
    L[i][0] = A[i][0];
    R[i][n - 1] = A[i][n - 1];
  }
  for (int i = n + 1; i < 2 * n; i++) {
    for (int j = 0; j < n; j++) {
      U[i][j] = A[i][j] + U[i - 1][j];
    }
  }
  for (int i = 2 * n - 2; i >= n; i--) {
    for (int j = 0; j < n; j++) {
      D[i][j] = A[i][j] + D[i + 1][j];
    }
  }
  for (int j = 1; j < n; j++) {
    for (int i = n; i < 2 * n; i++) {
      L[i][j] = A[i][j] + L[i][j - 1];
    }
  }
  for (int j = n - 2; j >= 0; j--) {
    for (int i = n; i < 2 * n; i++) {
      R[i][j] = A[i][j] + R[i][j + 1];
    }
  }
  for (int i = n; i < 2 * n; i++) {
    for (int j = 0; j < n; j += n - 1) {
      gigamin = min(gigamin, min(U[i][j], D[i][j]) + min(L[i][j], R[i][j]) - A[i][j]);
    }
  }
  for (int j = n; j < 2 * n; j++) {
    U[0][j] = A[0][j];
    D[n - 1][j] = A[n - 1][j];
  }
  for (int i = 0; i < n; i++) {
    L[i][n] = A[i][n];
    R[i][2 * n - 1] = A[i][2 * n - 1];
  }
  for (int i = 1; i < n; i++) {
    for (int j = n; j < 2 * n; j++) {
      U[i][j] = A[i][j] + U[i - 1][j];
    }
  }
  for (int i = n - 2; i >= 0; i--) {
    for (int j = n; j < 2 * n; j++) {
      D[i][j] = A[i][j] + D[i + 1][j];
    }
  }
  for (int j = n + 1; j < 2 * n; j++) {
    for (int i = 0; i < n; i++) {
      L[i][j] = A[i][j] + L[i][j - 1];
    }
  }
  for (int j = 2 * n - 2; j >= n; j--) {
    for (int i = 0; i < n; i++) {
      R[i][j] = A[i][j] + R[i][j + 1];
    }
  }
  for (int i = 0; i < n; i += n - 1) {
    for (int j = n; j < 2 * n; j++) {
      gigamin = min(gigamin, min(U[i][j], D[i][j]) + min(L[i][j], R[i][j]) - A[i][j]);
    }
  }
  cout << ans + gigamin << '\n';
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