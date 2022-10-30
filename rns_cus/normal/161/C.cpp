#include <bits/stdc++.h>
using namespace std;

int a, b, c, d, ans;
int l, r, L, R;
int po[50];

inline bool in(int i, int a, int b) {
  int st = ((a - 1) / po[i] + 1);
  int en = b / po[i], tot = 0;
  for (int i = st; i <= en; i++) {
    if (i & 1) tot++;
    if (tot >= 3) return 1;
  }
  return 0;
}

int main() {
  //freopen("in.txt", "r", stdin);
  scanf("%d %d %d %d", &a, &b, &c, &d);

  for (int i = 0; i <= 30; i++) po[i] = (1 << i);

  for (int i = 0; i <= 30; i++) {
    int fi = in(i, a, b), se = in(i, c, d);
    if (fi && se) ans = max(ans, po[i + 1] - 1);
    else if (se) {
      int st = ((a - 1) / po[i] + 1);
      int en = b / po[i];
      if (en < st) continue;
      for (int j = st; j <= en; j++) {
        if (j % 2 == 0) continue;
        int pos = po[i] * j;
        l = max(a, pos - po[i] + 1);
        r = min(b, pos + po[i] - 1);
        ans = max(ans, r - l + 1);
      }
    }
    else if (fi) {
      int st = ((c - 1) / po[i] + 1);
      int en = d / po[i];
      if (en < st) continue;
      for (int j = st; j <= en; j++) {
        if (j % 2 == 0) continue;
        int pos = po[i] * j;
        l = max(c, pos - po[i] + 1);
        r = min(d, pos + po[i] - 1);
        ans = max(ans, r - l + 1);
      }
    }
    else {
      int sa = ((c - 1) / po[i] + 1);
      int ea = d / po[i];
      int sb = ((a - 1) / po[i] + 1);
      int eb = b / po[i];
      //printf("%d %d\n", sa, ea);
      //printf("%d %d\n", sb, eb);
      for (int j = sa; j <= ea; j++) {
        for (int k = sb; k <= eb; k++) {
          if (j % 2 == 0 || k % 2 == 0) continue;
          int pa = po[i] * j, pb = po[i] * k;
          //printf("%d %d\n", j, k);
          l = max(c, pa - po[i] + 1);
          r = min(d, pa + po[i] - 1);
          L = max(a, pb - po[i] + 1);
          R = min(b, pb + po[i] - 1);
          ans = max(ans, min(pa - l, pb - L) + min(r - pa, R - pb) + 1);
        }
      }
    }
    //printf("i = %d %d %d %d\n", i, fi, se, ans);
  }
  printf("%d\n", ans);
}