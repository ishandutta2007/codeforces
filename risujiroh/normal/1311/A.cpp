#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int a, b;
    cin >> a >> b;
    if (a == b) {
      cout << "0\n";
    } else if (a < b) {
      if ((b - a) & 1) {
        cout << "1\n";
      } else {
        cout << "2\n";
      }
    } else {
      if ((b - a) % 2 == 0) {
        cout << "1\n";
      } else {
        cout << "2\n";
      }
    }
  }
}