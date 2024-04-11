#include <bits/stdc++.h>

using namespace std;

const int M = 1234567;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (auto c : s) {
      if (c == 'B') {
        ++a[i];
      } else {
        ++b[i];
      }
    }
  }
  auto check = [&](int r) {
    int minA = 0, maxA = M;
    int minB = 0, maxB = M;
    int minC = -M, maxC = M;
    for (int i = 0; i < n; ++i) {
      minA = max(minA, a[i] - r);
      maxA = min(maxA, a[i] + r);
      minB = max(minB, b[i] - r);
      maxB = min(maxB, b[i] + r);
      minC = max(minC, b[i] - a[i] - r);
      maxC = min(maxC, b[i] - a[i] + r);
    }
    for (int i = minA; i <= maxA; ++i) {
      int l = max(minB, minC + i), r = min(maxB, maxC + i);
      if (!i) {
        l = max(l, 1);
      }
      if (l <= r) {
        return true;
      }
    }
    return false;
  };
  int l = 0, r = M;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (check(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << r << "\n";
  int minA = 0, maxA = M;
  int minB = 0, maxB = M;
  int minC = -M, maxC = M;
  for (int i = 0; i < n; ++i) {
    minA = max(minA, a[i] - r);
    maxA = min(maxA, a[i] + r);
    minB = max(minB, b[i] - r);
    maxB = min(maxB, b[i] + r);
    minC = max(minC, b[i] - a[i] - r);
    maxC = min(maxC, b[i] - a[i] + r);
  }
  for (int i = minA; i <= maxA; ++i) {
    int l = max(minB, minC + i), r = min(maxB, maxC + i);
    if (!i) {
      l = max(l, 1);
    }
    if (l <= r) {
      for (int j = 0; j < i; ++j) {
        cout << "B";
      }
      for (int j = 0; j < l; ++j) {
        cout << "N";
      }
      cout << "\n";
      return 0;
    }
  }
  return 0;
}