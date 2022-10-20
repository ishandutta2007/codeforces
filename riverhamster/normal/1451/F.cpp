#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, m, x;
    cin >> n >> m;
    vector<int> xs(n + m);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) {
        cin >> x;
        xs[i + j] ^= x;
      }
    if (accumulate(xs.begin(), xs.end(), 0LL) > 0) puts("Ashish");
    else puts("Jeel");
  }
  return 0;
}