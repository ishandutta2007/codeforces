#include <cstdio>

const int MAXN = 11;
char s[MAXN];
int n;
int main() {
  scanf("%s %d", s, &n);
  for(int i = 0; i < n; ++i) {
    int k;
    for(int j = 0; s[j]; ++j) {
      k = j;
    }
    if (s[k] == '0') s[k] = 0;
    else s[k]--;
  }

  printf("%s\n", s);
}