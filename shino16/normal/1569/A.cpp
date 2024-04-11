#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int T, n;
char s[51];

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%s", &n, s);
    rep(i, n+1) rep(j, i)
      if (count(s+j, s+i, 'a') == count(s+j, s+i, 'b')) {
        printf("%d %d\n", j+1, i);
        goto s16;
      }
    printf("-1 -1\n");
    s16:;
  }
}