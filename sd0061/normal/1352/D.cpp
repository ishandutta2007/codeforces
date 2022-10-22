#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 200005;
int n, a[N];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    int sa = 0, sb = 0, ca = 0, cb = 0, t = 0, pa = 0, pb = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
    }
    int l = 0, r = n - 1;
    while (l <= r) {
      ++t;
      if (sa <= sb) {
        pa = 0;
        while (l <= r && pa <= pb) {
          pa += a[l++];
          ++ca;
        }
        sa += pa;
      } else {
        pb = 0;
        while (l <= r && pb <= pa) {
          pb += a[r--];
          ++cb;
        }
        sb += pb;
      }
    }
    printf("%d %d %d\n", t, sa, sb);
  }
}