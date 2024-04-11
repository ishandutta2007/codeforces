#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  if (n & 1) {
    for (int i = 0, d = 0; i < n; ++i) {
      for (int j = 0; j < n / 2; ++j) {
        cout << i * (n / 2) + j + 1 << ' ';
      }
      cout << n * n / 2 + 1 + d << ' ';
      if (d < 0) d = -d;
      else d = -d - 1;
      for (int j = 0; j < n / 2; ++j) {
        cout << n + (2 * n - 1 - i) * (n / 2) + j + 1 << " \n"[j == n / 2 - 1];
      }
    }
  } else {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n / 2; ++j) {
        cout << i * (n / 2) + j + 1 << ' ';
      }
      for (int j = 0; j < n / 2; ++j) {
        cout << (2 * n - 1 - i) * (n / 2) + j + 1 << " \n"[j == n / 2 - 1];
      }
    }
  }
}