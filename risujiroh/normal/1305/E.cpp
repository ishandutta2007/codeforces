#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  int t = 0;
  for (int i = 0; i < n; ++i) {
    t += i / 2;
    if (t >= m) {
      for (int j = 0; j < n; ++j) {
        if (j < i) {
          cout << j + 1;
        } else if (j == i) {
          cout << i + 1 + 2 * (t - m);
        } else {
          cout << (int)1e8 + (int)1e4 * j;
        }
        cout << " \n"[j == n - 1];
      }
      exit(0);
    }
  }
  cout << "-1\n";
}