#include <cstdio>

int C1,C2,C3,C4;
int N, M;

int main() {
  scanf("%d %d %d %d", &C1, &C2, &C3, &C4);
  if (C3 + C3 < C4) C4 = C3 + C3;
  scanf("%d %d", &N, &M);

  int s1 = 0;
  for(int i = 0; i < N; ++i) {
    int tmp;
    scanf("%d", &tmp);
    int cost = tmp * C1;
    if (C2 < cost) cost = C2;
    s1 += cost;
  }

  int s2 = 0;
  for(int i = 0; i < M; ++i) {
    int tmp;
    scanf("%d", &tmp);
    int cost = tmp * C1;
    if (C2 < cost) cost = C2;
    s2 += cost;
  }

  if (C3 < s1) s1 = C3;
  if (C3 < s2) s2 = C3;
  int ans = s1 + s2;
  if (C4 < ans) ans = C4;
  printf("%d\n", ans);
  return 0;
}