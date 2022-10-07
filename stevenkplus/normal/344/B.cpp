#include <cstdio>

int a,b,c;
int main() {
  scanf("%d %d %d", &a, &b, &c);
  int x = a+b-c;
  int y = a+c-b;
  int z = b+c-a;
  if (x >= 0 && y >= 0 && z >= 0 && x % 2 == 0) {
    printf("%d %d %d\n", x/2, z/2, y/2);
  } else {
    printf("Impossible\n");
  }
  return 0;
}