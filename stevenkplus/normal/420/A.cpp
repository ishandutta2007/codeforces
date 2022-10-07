#include <cstdio>

char str[111111];
char good[] = "AHIMOTUVWXY";

int N;

bool m(char c) {
  for(int i = 0; i < 11; ++i) {
    if (good[i] == c) return false;
  }
  return true;
}

int main() {
  scanf("%s", str);
  while (str[N]) ++N;
  bool bad = false;
  for(int a = 0, b = N - 1; a <= b; ++a, --b) {
    if (str[a] != str[b]) bad = true;
    if (m(str[a])) bad = true;
  }
  if (bad) printf("NO\n");
  else printf("YES\n");
  return 0;
}