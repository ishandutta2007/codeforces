#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    if (n & 1) {
      cout << "7" + string((n - 3) / 2, '1') << '\n';
    } else {
      cout << string(n / 2, '1') << '\n';
    }
  }
}