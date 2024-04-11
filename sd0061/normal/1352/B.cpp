#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 200005;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, k;
    scanf("%d%d", &n, &k);
    if (k > n) {
      puts("NO");
    } else {
      if (n & 1) {
        if (k & 1) {
          puts("YES");
          for (int i = 1; i < k; ++i) {
            printf("%d ", 1);
          }
          printf("%d\n", n - k + 1);
        } else {
          puts("NO");
        }
      } else {
        if (k & 1) {
          if (n >= 2 * k) {
            puts("YES");
            for (int i = 1; i < k; ++i) {
              printf("%d ", 2);
            }
            printf("%d\n", n - (k - 1) * 2);
          } else {
            puts("NO");
          }
        } else {
          puts("YES");
          for (int i = 1; i < k; ++i) {
            printf("%d ", 1);
          }
          printf("%d\n", n - k + 1);
        }
      }
    }
  }
}