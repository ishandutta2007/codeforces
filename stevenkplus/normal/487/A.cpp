#include <cstdio>

int H1, A1, D1;
int H2, A2, D2;
int h, a, d;

int ceil(int a, int b) {
  return (a + b - 1) / b;
}

int get(int atk, int def) {
  int rate = atk - D2;
  if (rate <= 0) return -1;
  int rate2 = A2 - def;
  int turns = ceil(H2, rate);
  int dmg = turns * rate2;
  if (dmg >= H1) {
    return dmg - H1 + 1;
  } else {
    return 0;
  }
}

int main() {
  scanf("%d %d %d", &H1, &A1, &D1);
  scanf("%d %d %d", &H2, &A2, &D2);
  scanf("%d %d %d", &h, &a, &d);


  int ans = -1;
  for(int j = 0; j <= 1000; ++j) {
    for(int k = 0; k <= 1000; ++k) {
      int cost = j * a + k * d;
      int need = get(A1 + j, D1 + k);
      if (need == -1) continue;
      cost += need * h;

      if (cost < ans || ans == -1) {
        ans = cost;
      }
    }
  }

  printf("%d\n", ans);
  return 0;
}