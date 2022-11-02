#include <bits/stdc++.h>
using namespace std;
char s[111111];

int main() {
  //freopen("in.txt", "r", stdin);
  scanf("%s", s);
  int n = strlen(s);
  int st = -1;
  for (int i = 0; i < n; i++) {
    if (s[i] != 'a') {st = i; break;}
  }
  if (st < 0) {
    for (int i = 0; i < n - 1; i++) putchar('a'); putchar('z');
    return 0;
  }
  int en = n;
  for (int i = st; i < n; i++) {
    if (s[i] == 'a') {en = i; break;}
  }
    for (int i = 0; i < st; i++) putchar('a');
    for (int i = st; i < en; i++) putchar(s[i] - 1);
    for (int i = en; i < n; i++) putchar(s[i]);
}