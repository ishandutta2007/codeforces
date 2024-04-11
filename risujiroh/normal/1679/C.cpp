#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);

  int n, q;
  cin >> n >> q;

  vector<int> cx(n);
  vector<int> cy(n);

  vector<int> fx(n);
  vector<int> fy(n);

  while (q--) {
    int tp;
    cin >> tp;
    if (tp == 1) {
      int x, y;
      cin >> x >> y;
      --x, --y;
      if (cx[x]++ == 0) {
        for (int i = x + 1; i; i &= i - 1) {
          ++fx[i - 1];
        }
      }
      if (cy[y]++ == 0) {
        for (int i = y + 1; i; i &= i - 1) {
          ++fy[i - 1];
        }
      }
    } else if (tp == 2) {
      int x, y;
      cin >> x >> y;
      --x, --y;
      if (--cx[x] == 0) {
        for (int i = x + 1; i; i &= i - 1) {
          --fx[i - 1];
        }
      }
      if (--cy[y] == 0) {
        for (int i = y + 1; i; i &= i - 1) {
          --fy[i - 1];
        }
      }
    } else {
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      --x1, --y1;
      int sx = 0;
      for (int i = x1; i < n; i |= i + 1) {
        sx += fx[i];
      }
      for (int i = x2; i < n; i |= i + 1) {
        sx -= fx[i];
      }
      int sy = 0;
      for (int i = y1; i < n; i |= i + 1) {
        sy += fy[i];
      }
      for (int i = y2; i < n; i |= i + 1) {
        sy -= fy[i];
      }
      cout << (sx == x2 - x1 || sy == y2 - y1 ? "Yes\n" : "No\n");
    }
  }
}