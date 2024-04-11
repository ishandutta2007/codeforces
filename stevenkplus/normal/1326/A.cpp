#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  ios_base::sync_with_stdio(0);
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    int n;
    cin >> n;
    if (n == 1) cout << "-1\n";
    else {
      int m = 0;
      for(int i = 0; i < n - 2; ++i) {
        m = (m * 10 + 2) % 3;
        cout << "2";
      }
      if (m == 1) cout << "33\n";
      else cout << "23\n";
    }
  }
}