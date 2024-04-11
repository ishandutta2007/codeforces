#include <cstdio>

int N, X;
int main() {
  scanf("%d %d", &N, &X);
  if (N == 3) {
    printf(">.v\n...\n...\n");
  } else if (N == 5) {
    printf(">...v\nv.<..\n..^..\n>....\n..^.<\n");
  } else {
    for(int i = 0; i < 100; ++i) {
      if (i - 1 >= 0)
        printf("^");
      else printf(">");
      if (i & 1) {
        if (i + 1 < 100) printf("v");
        else printf(".");
        for(int j = 0; j < 34; ++j) {
          printf("<.");
        }
        for(int j = 0; j < 30; ++j) {
          printf("<");
        }
      } else {
        for(int j = 0; j < 30; ++j) {
          printf(">");
        }
        for(int j = 0; j < 34; ++j) {
          printf(".>");
        }
        printf("v");
      }
      printf("\n");
    }

  }
  printf("1 1\n");
  return 0;
}