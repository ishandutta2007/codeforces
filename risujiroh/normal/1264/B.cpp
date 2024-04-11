#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int even = a + c, odd = b + d;
  if (abs(even - odd) > 1) {
    cout << "NO\n";
    return 0;
  }
  int n = a + b + c + d;
  vector<int> res(n);
  if (even == odd) {
    if (a + d > n / 2) {
      cout << "NO\n";
      return 0;
    }
    for (int i = a; i < a + c; ++i) {
      res[2 * i] = 2;
    }
    for (int i = 0; i < b; ++i) {
      res[2 * i + 1] = 1;
    }
    for (int i = b; i < b + d; ++i) {
      res[2 * i + 1] = 3;
    }
  } else if (even > odd) {
    if (d and a + d > n / 2) {
      cout << "NO\n";
      return 0;
    }
    for (int i = a; i < a + c; ++i) {
      res[2 * i] = 2;
    }
    for (int i = 0; i < b; ++i) {
      res[2 * i + 1] = 1;
    }
    for (int i = b; i < b + d; ++i) {
      res[2 * i + 1] = 3;
    }
  } else {
    if (a and a + d > n / 2) {
      cout << "NO\n";
      return 0;
    }
    for (int i = 0; i < b; ++i) {
      res[2 * i] = 1;
    }
    for (int i = b; i < b + d; ++i) {
      res[2 * i] = 3;
    }
    for (int i = a; i < a + c; ++i) {
      res[2 * i + 1] = 2;
    }
  }
  cout << "YES\n";
  for (int i = 0; i < n; ++i) {
    cout << res[i] << " \n"[i == n - 1];
  }
}