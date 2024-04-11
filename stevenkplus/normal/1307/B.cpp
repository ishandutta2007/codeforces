#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n, d;
    cin >> n >> d;
    int max = 0;
    int same = 0;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      if (x > max) max = x;
      if (x == d) same = 1;
    }
    int ans = (d + max - 1) / max;
    if (ans < 2 && !same) ans = 2;
    cout << ans << "\n";
  }
}