#include <cstdio>

const int MAXN = 222;
char s[MAXN];
char ans[MAXN];
int n;
int main() {
  scanf("%d", &n);
  scanf("%s", s);
  int best = 0;
  for(char a = 'A'; a <= 'Z'; ++a) {
    for(char b = 'A'; b <= 'Z'; ++b) {
      int cnt = 0;
      for(int i = 0; i + 1 < n; ++i) {
        if (s[i] == a && s[i+1] == b) {
          ++cnt;
        }
      }
      if (cnt > best) {
        best = cnt;
        sprintf(ans, "%c%c", a, b);
      }
    }
  }
  printf("%s\n", ans);
}