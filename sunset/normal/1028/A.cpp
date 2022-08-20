#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  cin >> n >> m;
  int lx = n, rx = -1, ly = m, ry = -1;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < m; ++j) {
      if (s[j] == 'B') {
        lx = min(lx, i);
        rx = max(rx, i);
        ly = min(ly, j);
        ry = max(ry, j);
      }
    }
  }
  printf("%d %d\n", lx + rx + 2 >> 1, ly + ry + 2 >> 1);
  return 0;
}