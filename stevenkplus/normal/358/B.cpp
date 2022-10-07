#include <cstdio>

const int MAXN = 300100;

char A[MAXN];
char B[MAXN];
int N;

void pt(char **ptr) {
  **ptr = '<';
  ++*ptr;
  **ptr = '3';
  ++*ptr;
}

int main() {
  scanf("%d", &N);
  char *ptr = A;
  pt(&ptr);
  for(int i = 0; i < N; ++i) {
    scanf("%s", ptr);
    while (*ptr) ++ptr;
    pt(&ptr);
  }


  scanf("%s", B);
  int cur = 0;
  bool ans = true;
  for(int i = 0; A[i]; ++i) {
    while (B[cur] && B[cur] != A[i]) ++cur;
    if (B[cur]) ++cur;
    else {
      ans = false;
      break;
    }
  }

  if (ans) printf("yes\n");
  else printf("no\n");

  return 0;
}