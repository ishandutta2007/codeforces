#include <bits/stdc++.h>
using namespace std;
char s[10000010];

int main() {
  //freopen("in.txt", "r", stdin);
  double x;
  scanf("%s", s + 1);
  int n = strlen(s + 1);

  int l = 1, r = n, pos = -1;

  for (int i = 1; i <= n; i++) if (s[i] == '.') pos = i;

  while (l <= n && s[l] == '0') l++;
  while (r && s[r] == '0') r--;

  if (pos == -1) {
    putchar(s[l]);
    int d = n - l;
    while (s[r] == '0') r--;
    if (l == r) {
      if (d && s[l] != '0') {
        putchar('E'); printf("%d\n", d);
      }
    }
    else {
      putchar('.');
      for (int i = l + 1; i <= r; i++) putchar(s[i]);
      putchar('E');
      printf("%d\n", d);
    }
    return 0;
  }



  if (pos > l) {
    if (pos - l == 1) {
      for (int i = l; i < pos; i++) putchar(s[i]);
      if (r != pos) {
        for (int i = pos; i <= r; i++) putchar(s[i]);
      }
    }
    else {
      putchar(s[l]);
      if (pos == r) {
        r = pos - 1; while (s[r] == '0') r--;
      }
      if (l != r) putchar('.');
      for (int i = l + 1; i <= r; i++) {
        if (s[i] == '.') continue;
        putchar(s[i]);
      }
      putchar('E');
      printf("%d\n", pos - l - 1);
    }
  }
  else {
    l = pos + 1;
    int cnt = 1;
    while (l <= n && s[l] == '0') {
      ++cnt; l++;
    }
    putchar(s[l]);
    if (l != r) putchar('.');
    for (int i = l + 1; i <= r; i++) {
      putchar(s[i]);
    }
    putchar('E'); printf("%d\n", -cnt);
  }
}